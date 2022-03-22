import { useEffect } from "react";

const Example = () => {
    console.log("Example constructor");

    useEffect(() => {
        console.log("Example componentDidMount");
    }, []);

    return <>{console.log("Example render")}</>;
};

export default Example;
