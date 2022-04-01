import { useContext, useEffect, useState } from "react";

import Button from "./Button";

import { FlexContainer } from "./_styledComponent";

import { ContextExample } from "../contexts/ContextExample";

const CounterState = () => {
    const [num, setNum] = useState<number>(0);
    const numContext = useContext(ContextExample);

    const increase = () => {
        console.clear();
        setNum(num + 1);
    };
    const decrease = () => {
        console.clear();
        setNum(num - 1);
    };

    useEffect(() => {
        console.log("CounterState componentDidUpdate");
    }, [num]);

    return (
        <>
            <h1>state</h1>
            <p data-testid="state">state num: {num}</p>
            <p>context num: {numContext?.num}</p>

            <FlexContainer jus="se">
                <Button onClick={increase}>+1</Button>
                <Button onClick={decrease}>-1</Button>
            </FlexContainer>

            {console.log("CounterState render")}
        </>
    );
};

export default CounterState;
