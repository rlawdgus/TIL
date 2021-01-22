const INCREASE = "counter/INCREASE" as const;
const DECREASE = "counter/DECREASE" as const;

export const increase = () => ({
    type: INCREASE,
});

export const decrease = () => ({
    type: DECREASE,
});

type CounterAction = ReturnType<typeof increase> | ReturnType<typeof decrease>;

type CounterState = {
    count: number;
};

const initialState: CounterState = {
    count: 0,
};

const counter = (
    state: CounterState = initialState,
    action: CounterAction
): CounterState => {
    switch (action.type) {
        case INCREASE: // case 라고 입력하고 Ctrl + Space 를 누르면 어떤 종류의 action.type들이 있는지 확인 할 수 있습니다.
            return { count: state.count + 1 };
        case DECREASE:
            return { count: state.count - 1 };
        default:
            return state;
    }
};

export default counter;
