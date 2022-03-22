import { useState } from "react";

import CounterState from "./components/CounterState";
import CounterProps from "./components/CounterProps";

const App = () => {
    const [num, setNum] = useState<number>(0);

    const increase = () => setNum(num + 1);
    const decrease = () => setNum(num - 1);

    return (
        <>
            <CounterState />
            <CounterProps num={num} increase={increase} decrease={decrease} />
            {console.log("App render")}
        </>
    );
};

export default App;
