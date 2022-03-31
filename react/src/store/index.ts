import { combineReducers, configureStore } from "@reduxjs/toolkit";

import counterSlice from "./counter";

const rootReducer = combineReducers({
    counter: counterSlice.reducer,
});

const store = configureStore({
    reducer: rootReducer,
});

export type RootReducer = ReturnType<typeof store.getState>;

export type AppDispatch = typeof store.dispatch;

export default store;
