import { useContext, useEffect, useState } from "react";

import { ContextExample } from "../contexts/ContextExample";

const CounterState = () => {
    const [num, setNum] = useState<number>(0);
    const numContext = useContext(ContextExample);

    const increase = () => setNum(num + 1);
    const decrease = () => setNum(num - 1);

    useEffect(() => {
        console.log("CounterState componentDidUpdate");
    }, [num]);

    return (
        <>
            <h1>state</h1>
            <p>state: {num}</p>
            <p>context: {numContext?.num}</p>

            <button onClick={increase}>+1</button>
            <button onClick={decrease}>-1</button>
            {console.log("CounterState render")}
        </>
    );
};

export default CounterState;
