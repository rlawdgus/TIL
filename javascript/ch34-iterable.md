## 이터레이션 프로토콜

    순회 가능한 자료구조를 만들기 위해 ES6에서 도입됨

    이터레이션 프로토콜에는
    이터러블 프로토콜, 이터레이터 프로토콜이 있다.

1.  이터러블

    이터러블 프로토콜을 준수한 객체
    for of로 순회할 수 있으며, 스프레드, 배열 디스트럭처링 할당의 대상으로 사용할 수 있다.

2.  이터레이터

    이터러블의 Symbol.iterator 메소드를 호출하면
    이터레이터 프로토콜을 준수한 이터레이터를 반환한다.

    next 메소드를 갖는다.

#

## for of

```javascript
for (const item of [1, 2, 3]) {
    console.log(item); // 1 2 3
}

// ===

const iterable = [1, 2, 3];

const iterator = iterable[Symbol.iterator]();

for (;;) {
    const res = iterator.next();

    if (res.done) break;

    const item = res.value;
    console.log(item);
}
```

#

## 사용자 정의 이터러블

```javascript
// 이터러블 구현
const fibonacci = {
    [Symbol.iterator]() {
        let [pre, cur] = [0, 1];
        const max = 10;

        return {
            next() {
                [pre, cur] = [cur, pre + cur];
                return { value: cur, done: cur >= max };
            },
        };
    },
};

for (const num of fibonacci) {
    console.log(num); // 1 2 3 5 8
}

// const iter = fibonacci[Symbol.iterator]();
```

```javascript
// 이터러블 생성 함수
const fibonacciFunc = function (max) {
    let [pre, cur] = [0, 1];

    return {
        [Symbol.iterator]() {
            return {
                next() {
                    [pre, cur] = [cur, pre + cur];
                    return { value: cur, done: cur >= max };
                },
            };
        },
    };
};

for (const num of fibonacciFunc(10)) {
    console.log(num); // 1 2 3 5 8
}
```

```javascript
// 이터러블이면서 이터레이터인 객체를 생성하는 함수
const fibonacciFunc = function (max) {
    let [pre, cur] = [0, 1];

    return {
        [Symbol.iterator]() {
            return this;
        },
        next() {
            return {
                next() {
                    [pre, cur] = [cur, pre + cur];
                    return { value: cur, done: cur >= max };
                },
            };
        },
    };
};
```
