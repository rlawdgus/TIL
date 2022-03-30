import { useEffect, useState } from "react";

import CounterState from "./components/CounterState";
import CounterProps from "./components/CounterProps";
import CounterRedux from "./components/CounterRedux";

import { FlexContainer } from "./components/_styledComponent";

import { ContextExample } from "./contexts/ContextExample";

const App = () => {
    const [num, setNum] = useState<number>(0);

    const increase = () => {
        console.clear();
        setNum(num + 1);
    };
    const decrease = () => {
        console.clear();
        setNum(num - 1);
    };

    useEffect(() => {
        console.log("App componentDidMount");
    }, []);

    return (
        <FlexContainer col centerAli>
            <ContextExample.Provider value={{ num }}>
                <CounterState />
            </ContextExample.Provider>

            <CounterProps num={num} increase={increase} decrease={decrease} />

            <CounterRedux />

            {console.log("App render")}
        </FlexContainer>
    );
};

export default App;
