import { useEffect } from "react";
import { useDispatch, useSelector } from "react-redux";

import { RootState } from "../store";
import { increase, decrease } from "../store/counter";

const CounterRedux = () => {
    const dispatch = useDispatch();

    const num = useSelector((state: RootState) => state.counter.num);

    const dispatchIncrease = () => {
        dispatch(increase());
    };

    const dispatchDecrease = () => {
        dispatch(decrease());
    };

    useEffect(() => {
        console.log("CounterRedux componentDidUpdate");
    }, [num]);

    return (
        <>
            <h1>redux</h1>
            <p>num: {num}</p>

            <button onClick={dispatchIncrease}>+1</button>
            <button onClick={dispatchDecrease}>-1</button>
            {console.log("CounterRedux render")}
        </>
    );
};

export default CounterRedux;
