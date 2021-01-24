import { createAction, handleActions } from "redux-actions";
import { call, put, takeLatest } from "redux-saga/effects";

//import loading
//import api ..

const INCREASE = "counter/INCREASE" as const;
const DECREASE = "counter/DECREASE" as const;

export const increase = createAction(INCREASE);
export const decrease = createAction(DECREASE);

type CounterAction = ReturnType<typeof increase> | ReturnType<typeof decrease>;

// function* increaseSaga() {
//     //yield loading
//     try {
//         yield put({ type: INCREASE });
//     } catch (e) {
//         yield console.log(e);
//     }
//     //yield loading
// }

// function* decreaseSaga() {
//     //yield loading
//     try {
//         yield put({ type: DECREASE });
//     } catch (e) {
//         yield console.log(e);
//     }
//     //yield loading
// }

// export function* counterSaga() {
//     yield takeLatest(INCREASE, increaseSaga);
//     yield takeLatest(DECREASE, decreaseSaga);
// }

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
