import { useEffect } from "react";

const Example2 = () => {
    console.log("Example2 constructor");

    useEffect(() => {
        console.log("Example2 componentDidMount");
    }, []);

    return <>{console.log("Example2 render")}</>;
};

export default Example2;
