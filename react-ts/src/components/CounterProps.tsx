import { useEffect } from "react";

interface Props {
    num: number;
    increase: () => void;
    decrease: () => void;
}

const CounterProps = ({ num, increase, decrease }: Props) => {
    useEffect(() => {
        console.log("CounterProps componentDidUpdate");
    }, [num]);

    return (
        <>
            <h1>props</h1>
            <p>{num}</p>
            <button onClick={increase}>+1</button>
            <button onClick={decrease}>-1</button>
            {console.log("CounterProps render")}
        </>
    );
};

export default CounterProps;
