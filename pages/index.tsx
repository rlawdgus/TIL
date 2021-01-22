import React from "react";
import { useSelector, useDispatch } from "react-redux";
import { increase, decrease } from "../redux/reducer/counter";

const Home: React.FC = () => {
    const value = useSelector((state: any) => state.counter.value);
    const dispatch = useDispatch();

    const onIncrease = () => {
        dispatch(increase());
    };
    const onDecrease = () => {
        dispatch(decrease());
    };

    return (
        <>
            <h1>{value}</h1>

            <button onClick={onIncrease}>increase</button>
            <button onClick={onDecrease}>decrease</button>
        </>
    );
};

export default Home;
