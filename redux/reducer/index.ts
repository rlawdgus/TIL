import { combineReducers } from "redux";
import counter from "./counter";
import {CounterProps} from '../../types/state'

export type RootState = {
    counter: CounterProps
}

export default combineReducers({counter})