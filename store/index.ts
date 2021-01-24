import { combineReducers } from "redux";
import { all } from "@redux-saga/core/effects";
import counter, { } from "./counter";

const rootReducer = combineReducers({
    counter,
});

// export function* rootSaga() {
//     yield all([counterSaga()]);
// }

export default rootReducer;

export type RootState = ReturnType<typeof rootReducer>;
