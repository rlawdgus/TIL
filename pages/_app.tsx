import { AppProps, AppContext } from "next/app";
import Head from "next/head";
import withRedux from "next-redux-wrapper";
import { Provider } from "react-redux";
import { createStore, compose, applyMiddleware } from "redux";
import { composeWithDevTools } from "redux-devtools-extension";

import rootReducer from "../store";

import "../style.css";

interface InitialProps {
    Component: any;
    pageProps: AppProps;
    store: any;
}

const NextJsTraining = ({ Component, pageProps, store }: InitialProps) => {
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

// NextJsTraining.getInitialProps = async (context: AppContext) => {
//     const { ctx } = context;
//     const { store } = ctx;
//     store.dispatch(increase());

//     console.log(store.getState());
// };

const configureStore = (initialState: any) => {
    const middlewares = [];
    const enhancer =
        process.env.NODE_ENV === "production"
            ? compose(applyMiddleware(...middlewares))
            : composeWithDevTools(applyMiddleware(...middlewares));
    const store = createStore(rootReducer, initialState, enhancer);
    return store;
};

export default withRedux(configureStore)(NextJsTraining);
