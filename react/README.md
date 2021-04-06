# useMemo

    //app.js
    const [color, setColor] = setState()
    const [color, setMovie] = setState()

    <Info color={color} movie={movie} />

    //Info.js
    ({ color, movie }) => {
    const colorKor = getColorKor(color)
    const movieKor = getMovieKor(movie)
    	color의 상태가 변할 때
    	하위 컴보넌트는 props의 상태가 변했기 때문에
    	컴포넌트 내부 모두 다시 실행(리렌더링) 한다 => color와 상관없는 getMovieKor도 실행 한다

    const colorKor = useMemo(() => getColorKor(color), [color])
    const movieKor = useMemo(() => getMovieKor(movie), [movie])
    	getColor를 기억해 뒀다가 color의 변화가 있을 때만 실행한다
        => movieKor은 color가 바뀌어도 movie가 변하지 않았기 때문에 실행하지 않는다
    	=> 기억을 해놓는 작업이 있어서 오히려 부하가 더 걸리는 경우가 있기 때문에 적절한 상황에 써야 한다

# useCallback

    리렌더링시 함수들도 항상 새로 생성되는데
    의존성에 의해서만 리렌더링 되게 한다

    새로 생성되는 함수는 코드가 완벽히 같더라도
    하위 컴포넌트는 함수가 달라졌다고 인식한다
        => 하위 컴포넌트는 함수가 React.memo()와 같은 최적화가 되어있고
        그 컴포넌트에 콜백함수를 props로 넘길 때 useCallback이 유용하다

    const increase = () => setCount(count + 1)	//항상 리렌더링
    const increase = useCallback(() => setCount(count + 1), [])	//첫 렌더링시 생성, 리렌더링 하지 않음

    const returnValue = () => console.log(count)	// 항상 리렌더링
    const returnValue = useCallback(() => console.log(count), [])
        //첫 렌더링시 생성, 리렌더링 하지 않음, count가 바뀌어도 첫 렌더링 때의 count다 (갱신 x)
    const returnValue = useCallback(() => console.log(count), [count])
        //첫 렌더링시 생성, count가 바뀔 때만 리렌더링 => count값 갱신됨

### useCallback(fn, deps) is equivalent to useMemo(() => fn, deps). from) React doc

# React.memo

    props가 바뀌지 않으면 리렌더링을 하지 않게 한다.
    메모이제이션하는 비용이 발생하기 때문에 상황에 맞게 써야한다.
    props가 자주 바뀌는 컴포넌트라면 어차피 계속 리렌더링하는데
    메모이제이션하는 만큼 비용이 더 발생하는 것이다.
