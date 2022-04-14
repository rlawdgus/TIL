import { useEffect } from "react";

import Button from "../Button";

import { FlexContainer } from "../_styledComponent";

interface CounterPropsProps {
    num: number;
    increase: () => void;
    decrease: () => void;
}

const CounterProps = ({ num, increase, decrease }: CounterPropsProps) => {
    useEffect(() => {
        console.log("CounterProps componentDidUpdate");
    }, [num]);

    return (
        <>
            <h1>props</h1>
            <p>App's num: {num}</p>

            <FlexContainer>
                <Button onClick={increase}>+1</Button>
                <Button onClick={decrease}>-1</Button>
            </FlexContainer>

            {console.log("CounterProps render")}
        </>
    );
};

export default CounterProps;
