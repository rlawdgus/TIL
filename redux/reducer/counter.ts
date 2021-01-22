import { ActionProps, CounterProps } from "../../types/state";

const INCREASE = "counter/INCREASE";
const DECREASE = "counter/DECREASE";

export const increase = () => ({
    type: INCREASE,
});

export const decrease = () => ({
    type: DECREASE,
});

const initialState: CounterProps = { value: 0 };

const counter = (state = initialState, action: ActionProps) => {
    switch (action.type) {
        case INCREASE:
            return { ...state, value: state.value + 1 };
        case DECREASE:
            return { ...state, value: state.value - 1 };
        default:
            return state;
    }
};

export default counter;
