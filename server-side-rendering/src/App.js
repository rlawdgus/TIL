import React, { useEffect, useState } from "react";
import Home from "./Home";
import About from "./About";
import styled from "styled-components";

const Container = styled.div`
    background-color: #aaaaaa;
    border: 1px solid blue;
`;

const App = ({ initPage }) => {
    const [page, setPage] = useState(initPage);

    useEffect(() => {
        window.onpopstate = (e) => {
            setPage(e.state);
        };
    }, []);

    const onChangePage = (e) => {
        const newPage = e.target.dataset.page;
        window.history.pushState(newPage, "", `/${newPage}`);
        setPage(newPage);
    };

    const PageComponent = page === "home" ? Home : About;

    return (
        <Container>
            <button data-page="home" onClick={onChangePage}>
                Home
            </button>
            <button data-page="about" onClick={onChangePage}>
                About
            </button>
            <PageComponent />
        </Container>
    );
};

export default App;
