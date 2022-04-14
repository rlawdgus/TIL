// yarn add @emotion/react @emotion/styled
// yarn add -D @emotion/babel-plugin

import styled from "@emotion/styled";

export const FlexContainer = styled.div<{
    col?: boolean;
    jus?: string;
    centerJus?: boolean;
    ali?: string;
    centerAli?: boolean;
}>`
    display: flex;
    flex-direction: ${(props) => (props.col ? "column" : "row")};
    justify-content: ${(props) => {
        if (props.centerJus) return "center";

        switch (props.jus) {
            case "sb":
                return "space-between";
            case "sa":
                return "space-around";
            case "se":
                return "space-evenly";
            case "fs":
                return "flex-start";
            case "fe":
                return "flex-end";
            case "st":
                return "stretch";
            default:
                return "unset";
        }
    }};
    align-items: ${(props) => {
        if (props.centerAli) return "center";

        switch (props.ali) {
            case "fs":
                return "flex-start";
            case "fe":
                return "flex-end";
            case "st":
                return "stretch";
            default:
                return "unset";
        }
    }};
`;

export const StyledButton = styled.button`
    width: 120px;
    height: 50px;
    border: none;
    border-radius: 5px;
`;

export const StyledList = styled.ul`
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
    background-color: bisque;
    width: 300px;
    margin-top: 50px;
    padding: 20px;
`;

export const StyledListItem = styled.li`
    width: 100%;
    text-align: center;
    padding: 10px;
    margin-bottom: 10px;
    color: white;
    background-color: salmon;
    user-select: none;

    &:last-child {
        margin-bottom: 0;
    }
`;
