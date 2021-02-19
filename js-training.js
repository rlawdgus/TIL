function func(a, b, c) {
    console.log(arguments)
    console.log(arguments.length)
    console.log(arguments.callee)
}

func("a", 2, "3", 4, 5)

// 화살표 함수는 arguments가 없음