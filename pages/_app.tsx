import { AppContext } from "next/app";
import Head from "next/head";
import { useEffect } from "react";
import { applyMiddleware, createStore, Middleware, StoreEnhancer } from "redux";
import createSagaMiddleware from "redux-saga";
import { MakeStore, createWrapper } from "next-redux-wrapper";
import { composeWithDevTools } from "redux-devtools-extension";
import { useDispatch } from "react-redux";

import rootReducer, { rootSaga } from "../store";
import { increase, storeValue } from "../store/counter";

import "../style.css";

const bindMiddleware = (middleware: Middleware[]): StoreEnhancer => {
    if (process.env.NODE_ENV !== "production") {
        return composeWithDevTools(applyMiddleware(...middleware));
    }
    return applyMiddleware(...middleware);
};

const makeStore: MakeStore<{}> = () => {
    const sagaMiddleware = createSagaMiddleware();
    const middlewares = [sagaMiddleware];

    const store = createStore(
        rootReducer,
        {},
        bindMiddleware([...middlewares])
    );
    sagaMiddleware.run(rootSaga);
    return store;
};

const NextJsTraining = ({ Component, pageProps, initStore }) => {
    const dispatch = useDispatch();

    useEffect(() => {
        dispatch(storeValue(initStore.counter.value));
    }, []);

    return (
        <>
            <Head>
                <title>Next.js training</title>
            </Head>
            <Component {...pageProps} />
        </>
    );
};

NextJsTraining.getInitialProps = async ({ ctx }: AppContext) => {
    const { store } = ctx;
    store.dispatch(increase());
    const initStore = store.getState();

    return { initStore };
};

export default createWrapper<{}>(makeStore, { debug: true }).withRedux(
    NextJsTraining
);
