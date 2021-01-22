import type { AppProps } from "next/app";
import Head from "next/head";
import { wrapper } from '../redux/store';

import "../style.css";

const App = ({ Component, pageProps }: AppProps) => {
    return (
        <>
            <Head>
                <title>asd</title>
            </Head>
            <Component {...pageProps} />
        </>
    );
};

export default wrapper.withRedux(App);
