import { useEffect, useState } from "react";

const CounterState = () => {
    const [num, setNum] = useState<number>(0);

    const increase = () => setNum(num + 1);
    const decrease = () => setNum(num - 1);

    useEffect(() => {
        console.log("CounterState componentDidUpdate");
    }, [num]);

    return (
        <>
            <h1>state</h1>
            <p>{num}</p>
            <button onClick={increase}>+1</button>
            <button onClick={decrease}>-1</button>
            {console.log("CounterState render")}
        </>
    );
};

export default CounterState;
