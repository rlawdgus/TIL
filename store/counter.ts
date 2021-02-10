import { createAction, handleActions } from "redux-actions";
import { call, delay, put, takeLatest } from "redux-saga/effects";

//import loading
//import api ..

const INCREASE = "counter/INCREASE" as const;
const DECREASE = "counter/DECREASE" as const;
const STORE_VALUE = "counter/STORE_VALUE" as const;

const INCREASE_ASYNC = "counter/INCREASE_ASYNC" as const;
const DECREASE_ASYNC = "counter/DECREASE_ASYNC" as const;

export const increase = createAction(INCREASE);
export const decrease = createAction(DECREASE);
export const storeValue = createAction(STORE_VALUE, (value: number) => value);

export const increaseAsync = createAction(INCREASE_ASYNC, () => undefined);
export const decreaseAsync = createAction(DECREASE_ASYNC, () => undefined);

type CounterAction =
    | ReturnType<typeof increase>
    | ReturnType<typeof decrease>
    | ReturnType<typeof storeValue>;

function* increaseSaga() {
    //yield loading
    try {
        yield delay(1000);
        yield put({ type: INCREASE });
    } catch (e) {
        yield console.log(e);
    }
    //yield loading
}

function* decreaseSaga() {
    //yield loading
    try {
        yield delay(1000);
        yield put({ type: DECREASE });
    } catch (e) {
        yield console.log(e);
    }
    //yield loading
}

export function* counterSaga() {
    yield takeLatest(INCREASE_ASYNC, increaseSaga);
    yield takeLatest(DECREASE_ASYNC, decreaseSaga);
}

interface CounterState {
    value: number;
}

const initialState: CounterState = {
    value: 0,
};

const counter = handleActions(
    {
        [INCREASE]: (state: CounterState) => ({
            value: state.value + 1,
        }),
        [DECREASE]: (state: CounterState) => ({
            value: state.value - 1,
        }),
        [STORE_VALUE]: (state: CounterState, action: CounterAction) => ({
            ...state,
            value: action.payload
        }),
    },
    initialState
);

export default counter;
