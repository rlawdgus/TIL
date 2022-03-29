import { createContext } from "react";

interface ContextType {
    num: number;
}

export const ContextExample = createContext<ContextType | null>(null);
