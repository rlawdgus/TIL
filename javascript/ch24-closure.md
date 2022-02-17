## 렉시컬 스코프

```javascript
const x = 1;

function outer() {
    const x = 10;

    function inner() {
        console.log(x);
    }

    inner(); // 10
}

outer();
```

```javascript
const x = 1;

function outer() {
    const x = 10;

    // 렉시컬 스코프: 정의 위치에 따라 상위 스코프를 결정
    inner(); // 1
}

function inner() {
    console.log(x);
}

outer();
```

#

## 함수 객체 내부 슬롯 [[Enviroment]]

    정의된 환경을 기억한다.
    상위 스코프 참조를 저장한다.

#

## 클로저

    외부 함수보다 중첩 함수가 더 오래 유지되는 경우(예 - 중첩 함수 반환 후 함수 종료)
    중첩 함수는 생명 주기가 종료된 외부 함수의 변수를 참조할 수 있는데
    이 중첩 함수를 클로저라고 한다.

    자바스크립트의 모든 함수는 상위 스코프를 기억하므로 이론상 모두 클로저인데
    상위 스코프의 어떤 식별자도 참조하지 않는 경우
    모던 브라우저의 최적화를 통해 상위 스코프를 기억하지 않게 된다.
    이런 함수는 클로저라고 하지 않는다.

#

## 클로저의 활용

    상태를 안전하게 변경하고 유지하기 위해 사용한다.
    특정 함수에게만 상태 변경을 허용

    캡슐화: 객체의 프로퍼티 및 메소드를 하나로 묶음
    정보은닉: 객체 접근을 제한하여 상태 변경을 방지해 정보를 보호함
    정보은닉 목적: 객체간 상호 의존성, 즉 결합도를 낮춤

```javascript
// num을 변경하기 쉽다.
let num = 0;

const increase = function () {
    return ++num;
};

console.log(increase()); // 1
console.log(increase()); // 2
```

```javascript
// num 변경을 increase외에서는 할 수 없다.
const increase = function () {
    let num = 0;

    return ++num;
};

console.log(increase()); // 1
// 지역 변수가 다시 선언되고 초기화되므로
// 이전 상태를 유지할 수 없다.
console.log(increase()); // 1
```

```javascript
// num 변경을 increase외에서는 할 수 없다.
const increase = (function () {
    let num = 0;

    return function () {
        return ++num;
    };
})();

console.log(increase()); // 1
// 이전 상태를 유지한다.
console.log(increase()); // 2
```

```javascript
// 상태를 기억하는 클로저를 반환하는 즉시 실행 함수
const counter = (function () {
    // 상태 변수
    // 즉시 실행 함수가 끝나고 나서는
    // 접근할 방법이 없음 => counter만 접근 가능
    let counter_num = 0;

    // counter가 최종적으로 할당받은 함수
    return function (predicate) {
        counter_num = predicate(counter_num);

        return counter_num;
    };
})();

function increase(n) {
    return ++n;
}

function decrease(n) {
    return --n;
}

console.log(counter(increase));
console.log(counter(decrease));
```
