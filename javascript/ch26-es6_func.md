## ES6 함수의 구분

| ---    | constructor | prototype | super | arguments |
| ------ | ----------- | --------- | ----- | --------- |
| 일반   | O           | O         | X     | X         |
| 메소드 | X           | X         | O     | O         |
| 화살표 | X           | X         | X     | X         |

#

## 일반함수와 화살표 함수 차이

-   화살표 함수는 함수 자체의 this, super, arguments 바인딩을 갖지 않는다.
-   상위 스코프의 this, super, arguents를 참조한다.(lexical this)
-   메소드가 화살표 함수일 때 상위 스코프를 참조하므로 메소드를 화살표 함수로 정의하는 것은 좋지 않다.

```javascript
function Person(name) {
    this.name = name;
}

Person.prototype.sayHi = () => console.log(`Hi ${this.name}`);

const person = new Person("asd");

// this.name === window.name (현재 빈 문자열)
person.sayHi(); // Hi
```

#

## Rest 파라미터

```javascript
// 배열로 직접 전달받는다.
// 마지막 파라미터로만 하나 쓸 수 있다.
function foo(param, param2, ...rest) {
    console.log(param); // 1
    console.log(param2); // 2
    console.log(rest); // [3, 4, 5]
}

foo(1, 2, 3, 4, 5);
```

#

## 매개변수 기본값

    기본값은 undefined이기 때문에
    값이 전달되지 않을 경우 처리가 필요하다.

    rest 파라미터에는 기본값을 지정할 수 없고
    length와 arguments에 영향을 주지 않는다.
