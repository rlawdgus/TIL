import { DetailedHTMLProps } from "react";

interface ButtonProps
    extends DetailedHTMLProps<
        React.ButtonHTMLAttributes<HTMLButtonElement>,
        HTMLButtonElement
    > {}

const Button = ({
    children,
    type,
    className,
    onClick,
    disabled,
}: ButtonProps) => {
    return (
        <button
            type={type}
            className={className}
            onClick={onClick}
            disabled={disabled}
        >
            {children}
        </button>
    );
};

export default Button;
