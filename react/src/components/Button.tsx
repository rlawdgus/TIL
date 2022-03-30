import { DetailedHTMLProps } from "react";

import { StyledButton } from "./_styledComponent";

interface ButtonProps
    extends DetailedHTMLProps<
        React.ButtonHTMLAttributes<HTMLButtonElement>,
        HTMLButtonElement
    > {}

const Button = ({ type, onClick, disabled, children }: ButtonProps) => {
    return (
        <StyledButton type={type} onClick={onClick} disabled={disabled}>
            {children}
        </StyledButton>
    );
};

export default Button;
