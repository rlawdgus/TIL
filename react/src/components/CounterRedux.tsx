import { useEffect } from "react";
import { useDispatch, useSelector } from "react-redux";

import Button from "./Button";

import { FlexContainer } from "./_styledComponent";

import type { RootReducer } from "../store";
import { increase, decrease } from "../store/counter";

const CounterRedux = () => {
    const dispatch = useDispatch();

    const num = useSelector((state: RootReducer) => state.counter.num);

    const dispatchIncrease = () => {
        console.clear();
        dispatch(increase());
    };

    const dispatchDecrease = () => {
        console.clear();
        dispatch(decrease());
    };

    useEffect(() => {
        console.log("CounterRedux componentDidUpdate");
    }, [num]);

    return (
        <>
            <h1>redux</h1>
            <p>redux num: {num}</p>

            <FlexContainer>
                <Button onClick={dispatchIncrease}>+1</Button>
                <Button onClick={dispatchDecrease}>-1</Button>
            </FlexContainer>

            {console.log("CounterRedux render")}
        </>
    );
};

export default CounterRedux;
