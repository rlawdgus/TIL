import styled from "styled-components";

export const Button = styled.button`
    width: 100%;
    height: 50px;
    color: white;
    cursor: pointer;
    background-color: ${(props) => (props.salmon ? "salmon" : "skyblue")};
`;
