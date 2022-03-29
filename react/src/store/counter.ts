import { createAction, handleActions } from "redux-actions";

const INCREASE = "counter/INCREASE" as const;
const DECREASE = "counter/DECREASE" as const;

export const increase = createAction(INCREASE);
export const decrease = createAction(DECREASE);

export type CounterAction =
    | ReturnType<typeof increase>
    | ReturnType<typeof decrease>;

export type CounterState = {
    num: number;
};

const initialState: CounterState = {
    num: 0,
};

const counter = handleActions(
    {
        [INCREASE]: (state: CounterState) => ({
            num: state.num + 1,
        }),
        [DECREASE]: (state: CounterState) => ({
            num: state.num - 1,
        }),
    },
    initialState
);

export default counter;
