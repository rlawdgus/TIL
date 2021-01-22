import type { AppProps } from "next/app";
import Head from "next/head";
import { Provider } from "react-redux";
import { createStore } from "redux";

import rootReducer from "../store";

import "../style.css";

const store = createStore(rootReducer);

const App = ({ Component, pageProps }: AppProps) => {
    return (
        <>
            <Head>
                <title>asd</title>
            </Head>
            <Provider store={store}>
                <Component {...pageProps} />
            </Provider>
        </>
    );
};

export default App;
