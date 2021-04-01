import { combineReducers } from 'redux'
import { all } from 'redux-saga/effects'

import counter, {counterSaga} from './counter'
import loading from './loading'

const rootReducer = combineReducers({
    counter,
    loading
})

export function* rootSaga() {
    yield all([counterSaga()])
}

export default rootReducer