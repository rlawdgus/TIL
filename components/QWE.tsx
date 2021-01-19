import React from "react";
import {useRouter} from 'next/router'

const QWE: React.FC = () => {
    const router = useRouter()
    const {id} = router.query

    return <>qwe{id}</>;
};

export default QWE;
