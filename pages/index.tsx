import React from "react";
import Link from 'next/link'

const Home: React.FC = () => {
    return (
        <ul>
            <li>
                <Link href="/[main]?id=1" as="qwe">
                    <a>qwe</a>
                </Link>
            </li>
            <li>
                <Link href="/[main]" as="asd">
                    <a>asd</a>
                </Link>
            </li>
        </ul>
    )
};

export default Home;
