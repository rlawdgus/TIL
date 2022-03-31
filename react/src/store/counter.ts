import { createSlice } from "@reduxjs/toolkit";

type CounterState = {
    num: number;
};

const initialState: CounterState = {
    num: 0,
};

const counterSlice = createSlice({
    name: "counter",
    initialState,
    reducers: {
        increase(state) {
            state.num += 1;
        },
        decrease(state) {
            state.num -= 1;
        },
    },
});

export const { increase, decrease } = counterSlice.actions;

export default counterSlice;
