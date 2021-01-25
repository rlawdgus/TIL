import type { AppProps } from "next/app";
import Head from "next/head";
import { applyMiddleware, createStore } from "redux";
import { Provider } from "react-redux";
import createSagaMiddleware from "redux-saga";
import { composeWithDevTools } from "redux-devtools-extension";

import rootReducer, { rootSaga } from "../store";

import "../style.css";

const sagaMiddleware = createSagaMiddleware();
const store = createStore(
    rootReducer,
    composeWithDevTools(applyMiddleware(sagaMiddleware))
);

sagaMiddleware.run(rootSaga);

const NextJsTraining = ({ Component, pageProps }: AppProps) => {
    return (
        <>
            <Head>
                <title>Next.js training</title>
            </Head>
            <Provider store={store}>
                <Component {...pageProps} />
            </Provider>
        </>
    );
};

export default NextJsTraining;
