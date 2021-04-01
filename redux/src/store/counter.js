import { createAction, handleActions } from 'redux-actions'
import { delay, put, takeEvery, takeLatest } from 'redux-saga/effects'

import { startLoading, finishLoading } from './loading'

const INCREASE = 'counter/INCREASE'
const DECREASE = 'counter/DECREASE'

const INCREASE_ASYNC = 'counter/INCREASE_ASYNC'
const DECREASE_ASYNC = 'counter/DECREASE_ASYNC'

export const increase = createAction(INCREASE)
export const decrease = createAction(DECREASE)

export const increaseAsync = createAction(INCREASE_ASYNC)
export const decreaseAsync = createAction(DECREASE_ASYNC)

function* increaseSaga(action) {
    yield put(startLoading())
    yield delay(1000)
    yield put(increase(action.payload))
    yield put(finishLoading())
}

function* decreaseSaga(action) {
    yield delay(1000)
    yield put(decrease(action.payload))
}

export function* counterSaga() {
    yield takeEvery(INCREASE_ASYNC, increaseSaga)
    yield takeLatest(DECREASE_ASYNC, decreaseSaga)
}

const initialState = {
    num: 0
}

const counter = handleActions(
    {
        [INCREASE]: (state, action) => ({
            num: state.num + action.payload
        }),
        [DECREASE]: (state, action) => ({
            num: state.num - action.payload
        })
    },
    initialState
)

export default counter