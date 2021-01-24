import type { AppProps } from "next/app";
import Head from "next/head";
import { createStore, applyMiddleware, Middleware, StoreEnhancer } from "redux";
import { MakeStore, createWrapper } from "next-redux-wrapper";
import createSagaMiddleware from "redux-saga";

import rootReducer, {  } from "../store";

import "../style.css";

const bindMiddleware = (middleware: Middleware[]): StoreEnhancer => {
    if (process.env.NODE_ENV !== "production") {
        const { composeWithDevTools } = require("redux-devtools-extension");
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
        // bindMiddleware([...middlewares])
    );
    // sagaMiddleware.run(rootSaga);
    return store;
};

const App = ({ Component, pageProps }: AppProps) => {
    return (
        <>
            <Head>
                <title>Next.js training</title>
            </Head>
            <Component {...pageProps} />
        </>
    );
};

export default createWrapper<{}>(makeStore, { debug: true }).withRedux(App);
