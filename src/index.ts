const test = async () => {
    const value = await Promise.resolve(1);
    console.log(value);
    return [1, 2, 3];
};

const test2 = async () => {
    const value = await Promise.resolve("Hello");
    console.log(value);
};

const test3 = async () => {
    throw new Error("test3 error");
};

const test4 = async () => {
    await Promise.reject(new Error("test4 error"));
};

const test5 = async () => {
    console.log("일반 함수처럼 사용, (1)");
    await test();

    console.log("Promise 객체처럼 사용, (2)");
    await test().then(() => test2());

    await test().then((value) => console.log(value, "(3)"));

    await test3().catch((err) => console.log(err.message, "(4)"));

    await test4().catch((err) => console.log(err.message, "(5)"));
};

test5();

// test5(async await) 적용 전
// 일반 함수처럼 사용, (1)
// Promise 객체처럼 사용, (2)
// 1
// 1
// 1
// test3 error (4)
// [ 1, 2, 3 ] (3)
// test4 error (5)
// Hello

// 적용 후
// 일반 함수처럼 사용, (1)
// 1
// Promise 객체처럼 사용, (2)
// 1
// Hello
// 1
// [ 1, 2, 3 ] (3)
// test3 error (4)
// test4 error (5)

Promise.all([test(), test2(), test3(), test4()]).then((values) => {
    console.log(values);
    //test3에서 에러 발생후 종료
});
