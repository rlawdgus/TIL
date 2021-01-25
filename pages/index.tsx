import { useCallback } from "react";
import { useSelector, useDispatch } from "react-redux";
import { NextPage } from "next";

import { RootState } from "../store";
import { increaseAsync, decreaseAsync } from "../store/counter";

interface Props {
    userAgent?: string;
}

const Index: NextPage<Props> = ({ userAgent }) => {
    const value = useSelector((state: RootState) => state.counter.value);
    const dispatch = useDispatch();

    const onIncrease = useCallback(() => {
        dispatch(increaseAsync());
    }, []);

    const onDecrease = useCallback(() => {
        dispatch(decreaseAsync());
    }, []);

    return (
        <>
            <h1>{userAgent}</h1>
            <h1>{value}</h1>

            <button onClick={onIncrease}>increase</button>
            <button onClick={onDecrease}>decrease</button>
        </>
    );
};

Index.getInitialProps = async ({ req }) => {
    console.log(req);
    const userAgent = req ? req.headers["user-agent"] : navigator.userAgent;

    return { userAgent };
};

export default Index;
