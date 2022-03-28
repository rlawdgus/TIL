import { useState } from "react";

const Counter = () => {
    const [count, setCount] = useState<number>(0);

    const increase = () => setCount(count + 1);
    const decrease = () => setCount(count - 1);

    return (
        <>
            {count}
            <button onClick={increase}>+</button>
            <button onClick={decrease}>-</button>
        </>
    );
};

export default Counter;
