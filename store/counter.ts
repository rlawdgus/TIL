import { createAction, handleActions } from "redux-actions";

const INCREASE = "counter/INCREASE" as const;
const DECREASE = "counter/DECREASE" as const;

export const increase = createAction(INCREASE);
export const decrease = createAction(DECREASE);

type CounterAction = ReturnType<typeof increase> | ReturnType<typeof decrease>;

interface CounterState {
    value: number;
}

const initialState: CounterState = {
    value: 0,
};

const counter = handleActions(
    {
        [INCREASE]: (state: CounterState, action: CounterAction) => ({
            value: state.value + 1,
        }),
        [DECREASE]: (state: CounterState, action: CounterAction) => ({
            value: state.value - 1,
        }),
    },
    initialState
);

export default counter;
