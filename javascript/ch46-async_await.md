## 제너레이터

    코드 블록의 실행을 일시 중지했다가 필요한 시점에 재개할 수 있는 함수

    - 함수 호출자에게 함수 실행의 제어권을 양도할 수 있다.
    - 제너레이터 함수와 함수 호출자는 함수의 상태를 주고받을 수 있다.
    - 제너레이터 함수를 호출하면 제너레이터 체를 반환한다.(이터러블이면서 이터레이터이다.)
    - 화살표 함수, new 연산자로 사용할 수 없다.

```javascript
function* gen() {
    yield 1;
    yield 2;
    yield 3;
}

const generator = gen();

console.log(generator.next()); // {value:1, done: false}
console.log(generator.next()); // {value:2, done: false}
console.log(generator.next()); // {value:3, done: false}
console.log(generator.next()); // {value:undefined, done: true}

// next 호출시 yield 표현식까지 실행 후 일시중지하고
// value, done 프로퍼티를 갖는 이터레이터 리절트 객체를 반환한다.
// value는 yield 키워드 뒤의 값이고 done은 함수가 끝까지 실행되었는지 나타낸다.
```

#

## async/await

    프로미스 기반으로 제너레이터, 프로미스 등 비동기 처리를 가독성 좋게 하기 위해 도입되었다.

    async: async 함수 내부에서 await를 쓸 수 있다. resolve하는 프로미스를 반환한다.
    await: 프로미스가 settled 상태가 될 때까지 대기하고 처리되면 프로미스가 resolve한 처리결과를 반환한다.
