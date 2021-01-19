import React from "react";
import {useRouter} from 'next/router'

import ASD from '../../components/ASD'
import QWE from '../../components/QWE'

const Main: React.FC = () => {
    const router = useRouter()
    const {pagename} = router.query

    console.log(router)

    return (
        <>
        {
            pagename === 'asd' ? <ASD /> : <QWE />
        }
        </>
    )
};

export default Main;
