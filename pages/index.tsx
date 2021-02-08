import { NextPage } from "next";
import { useSelector } from 'react-redux'

const Index: NextPage = () => {
    const counter = useSelector((state: any) => state)
    return <>{console.log(counter)}</>;
};

export default Index;
