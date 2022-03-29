## 라이프사이클

![lifecycle](assets/lifecycle.png)
![lifecycle_example](assets/lifecycle_example.png)

[라이프사이클 이미지] https://projects.wojtekmaj.pl/react-lifecycle-methods-diagram/

#

## 브라우저 렌더링 과정

    1. DOM 트리 생성
    2. CSSOM 트리 생성
    3. render 트리 생성
    4. javascript 적용
    5. reflow(layout, 뷰포트 내 위치 계산)
    6. repaint

    => DOM 트리 수정할 때마다 3, 4, 5 반복 => 성능 저하

#

## Virtual DOM: DOM 구조와 비슷한 react 객체

    1. Virtual DOM 트리 생성
    2. DOM, Virtual DOM 차이점 파악
    3. 한 번에 반영(리렌더링)

#

## react 첫 렌더링

![rendering_example](assets/rendering_example.png)

    1.  DOM -> CSSOM -> render 생성
    2.  javascript(react) 적용

        1. App render
           1. Example render
           2. Example2 render
           3. App render 완료
        2. DOM에 적용(마운트)
        3. 각 componentDidMount 실행

    3.  reflow(layout, 뷰포트 내 위치 계산)
    4.  repaint

[참고] https://react.vlpt.us/basic/25-lifecycle.html

#

## react 리렌더링

    -   조건
        1. state 업데이트
        2. props 업데이트
        3. 부모 컴포넌트 렌더링시
        4. shouldComponentUpdate에서 true 반환시
        5. forceUpdate 실행

![rerendering_example](assets/rerendering_example.png)

=> CounterProps update의 경우 App의 State의 변경이기 때문에 App을 리렌더링한다.

#

## useState

```javascript
const [state, setState] = useState();

setState((prevState) => {}); // 새로 바뀌는 상태가 이전 상태와 연관 있을 때

const [state, setState] = useState(heavyWork()); // 리렌더링 마다 실행
const [state, setState] = useState(() => heavyWork()); // 처음 한 번만 실행
```

#

## useEffeect

```javascript
useEffect(() => {}, [dependencies]);

useEffect(() => {
    return () => {}; // clean up
}, [dependencies]);
```

#

## useRef

```javascript
// 컴포넌트가 unmount되기 전까지 값을 유지 및 변경할 수 있고
// 리렌더링이 발생하지 않는다.
// 저장공간으로 이용, DOM 요소 접근

const ref = useRef(refValue); // ref 객체 반환 ({current: refValue})
```

|                        | const, let     | state | ref |
| ---------------------- | -------------- | ----- | --- |
| 리렌더링 발생          | x              | o     | x   |
| 리렌더링시 변경값 유지 | x(다시 초기화) | o     | o   |

#

## useContext

```javascript
// ContextExample.js
import { createContext } from "react";

export const ContextExample = createContext(null);
```

```javascript
// App.jsx
import { ContextExample } from "./contexts/ContextExample";

const App = () => {
    return (
        <ContextExample.Provider value={{ num }}>
            <div>
                {
                    // const context = useContext(ContextExample)
                    // <p>{context.num}</p>
                }
            </div>
        </ContextExample.Provider>
    );
};

export default App;
```

    Context.Provider의 자식노드는 Context에 해당하는 상태와 상관없어도 리렌더링이 발생한다.

    관련있는 Provider로 각각 감싸주더라도 코드량, 가독성 등의 문제가 있다.

#

## useMemo

```javascript
const obj = useMemo(() => {
    return {};
}, [dependencies]);

const fn = useMemo(() => {}, [dependencies]);
```

#

## useCallback

```javascript
const obj = useCallback(() => {
    return {};
}, [dependencies]);

const fn = useCallback(() => {}, [dependencies]);
```

#

## useMemo useCallback 차이

```javascript
// dependencies가 변경되었을 때 fn을 실행한 결과를 반환한다.
useMemo(fn, [dependencies]);

// dependencies가 변경되었을 때 새로운 fn을 반환한다.
useCallback(fn, [dependencies]);
```

#

## 리덕스

### 1. type => 액션 이름, 업데이트시 참고할 데이터

    const INCREASE = 'counter/INCREASE'

### 2. 액션 생성 함수

    const increase = createAction(INCREASE)

    createAction(type, action)
    action의 내부 구조는 type과 payload가 있다
    type은 첫번째 파라미터인 type과 같고
    payload를 통해 매개변수를 넣을 수 있다

    ex) createAction(OPEN, (title, description)
        => (type: OPEN, payload: {title: "", description: ""}))
    	=> action.payload === {title: "", description: ""}

### 3. 리듀서 => 업데이트 시키는 함수

    reduce(누산기, 현재 값, 현재 인덱스, 원본 배열)
        [TYPE]: (state, action) => ({
        	...state,	//불변성 유지를 위해 전개연산자 사용
        	...action.payload	//현재 값, 이 것을 첫 번째 파라미터에 누적
        )}
    -----------------------------------------------------------------------
    const counter = handleActions(
    	{
    		[INCREASE]: (state, action) => ({
    			...state,	//불변성 유지를 위해 전개연산자 사용
    			...action.payload	//현재 값, 이 것을 첫 번째 파라미터에 누적
    		)},
    		[DECREASE]: (state, action) => ({
    			...state,	//불변성 유지를 위해 전개연산자 사용
    			...action.payload	//현재 값, 이 것을 첫 번째 파라미터에 누적
    		)},
    	},
    	initialState
    )

#### 1 + 2 + 3 => 리덕스 모듈

### 4. 스토어

    1스토어 / 1프로젝트, 상태와 리듀서가 있음

### 5. 디스패치

    스토어 내장함수, 액션 발생 dispatch(increase())

### 6. 구독 => 리스너를 파라미터로 넣어 호출, 상태가 업데이트 될 때마다 호출

### 7. 리덕스 3규칙

    1. 단일 스토어
    2. 읽기전용, 기존 상태 유지
    3. 리듀서는 이전 상태, 액션 파라미터 이외에는 의존성이 없음
       기존 상태 유지, 똑같은 호출은 똑같은 결과

### 구조

    (리덕스)    redux, react-redux, @types/react-redux, redux-actions, @types/redux-actions
    (사가)      redux-saga,
    (디버깅)    redux-devtools-extension

    store/
    	counter.js (리덕스 모듈)
            => 액션타입 + 생성함수 (createAction) + 리듀서 (handleActions)

    	index.js (rootReducer) => combineReducers로 리덕스 모듈들을 추가

    index.js
    	{ createStore } 'redux'
    	{ Provider } 'react-redux'
    	rootReducer './store'

    	const store = createStore(rootReducer)

    	<Provider store={ store }>
    		<App /> => useSelector (상태 사용), useDispatch (리듀서 사용)
    	</Provider>
