import React from "react";
import { useSelector, useDispatch } from "react-redux";
import { RootState } from "../store";
import { increase, decrease } from "../store/counter";

const Home: React.FC = () => {
    const count = useSelector((state: RootState) => state.counter.count);
    const dispatch = useDispatch();

    const onIncrease = () => {
        dispatch(increase());
    };
    const onDecrease = () => {
        dispatch(decrease());
    };

    return (
        <>
            <h1>{count}</h1>

            <button onClick={onIncrease}>increase</button>
            <button onClick={onDecrease}>decrease</button>
        </>
    );
};

export default Home;
