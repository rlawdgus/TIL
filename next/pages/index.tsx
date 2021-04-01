import { NextPage } from "next";
import { useCallback } from "react";
import { useDispatch, useSelector } from 'react-redux'

import { RootState } from "../store";
import { increaseAsync, decreaseAsync } from "../store/counter";

const Index: NextPage = () => {
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
            <h1>{value}</h1>

            <button onClick={onIncrease}>increase</button>
            <button onClick={onDecrease}>decrease</button>
        </>
    );
};

export default Index;
