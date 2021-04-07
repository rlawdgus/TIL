# 1. type => 액션 이름, 업데이트시 참고할 데이터

    const INCREASE = 'counter/INCREASE'

# 2. 액션 생성 함수

    const increase = createAction(INCREASE)

    createAction(type, action)
    action의 내부 구조는 type과 payload가 있다
    type은 첫번째 파라미터인 type과 같고
    payload를 통해 매개변수를 넣을 수 있다

    ex) createAction(OPEN, (title, description)
        => (type: OPEN, payload: {title: "", description: ""}))
    	=> action.payload === {title: "", description: ""}

# 3. 리듀서 => 업데이트 시키는 함수

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

### 1 + 2 + 3 => 리덕스 모듈

# 4. 스토어

    1스토어 / 1프로젝트, 상태와 리듀서가 있음

# 5. 디스패치

    스토어 내장함수, 액션 발생 dispatch(increase())

# 6. 구독 => 리스너를 파라미터로 넣어 호출, 상태가 업데이트 될 때마다 호출

# 7. 리덕스 3규칙

    1. 단일 스토어
    2. 읽기전용, 기존 상태 유지
    3. 리듀서는 이전 상태, 액션 파라미터 이외에는 의존성이 없음
       기존 상태 유지, 똑같은 호출은 똑같은 결과

### 구조

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
