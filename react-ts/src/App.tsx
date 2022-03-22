import { useEffect } from "react";

const App = () => {
    console.log("App constructor");

    useEffect(() => {
        console.log("App componentDidMount");
    }, []);

    return <>{console.log("App render")}</>;
};

export default App;
