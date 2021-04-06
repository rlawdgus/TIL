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
    	getColor를 기억해 뒀다가 color의 변화가 있을 때만 실행한다
    	=> 기억을 해놓는 작업이 있어서 오히려 부하가 더 걸리는 경우가 있기 때문에 적절한 상황에 써야 한다
