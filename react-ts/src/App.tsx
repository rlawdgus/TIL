import { useState } from "react";

import CounterState from "./components/CounterState";
import CounterProps from "./components/CounterProps";

import { ContextExample } from "./contexts/ContextExample";

const App = () => {
    const [num, setNum] = useState<number>(0);

    const increase = () => setNum(num + 1);
    const decrease = () => setNum(num - 1);

    return (
        <ContextExample.Provider value={{ num }}>
            <CounterState />
            <CounterProps num={num} increase={increase} decrease={decrease} />
            {console.log("App render")}
        </ContextExample.Provider>
    );
};

export default App;
