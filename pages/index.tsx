import React, { useCallback } from "react";
import { useSelector, useDispatch } from "react-redux";

import { RootState } from "../store";
import { increase, decrease } from "../store/counter";

const Index: React.FC = () => {
    const value = useSelector((state: RootState) => state.counter.value);
    const dispatch = useDispatch();

    const onIncrease = useCallback(() => {
        dispatch(increase());
    }, []);

    const onDecrease = useCallback(() => {
        dispatch(decrease());
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
