## Promise

```javascript
const promise = new Promise((resolve, reject) => {
    if(/* status === 200 */) resolve();
    else reject();
}).then( () => {/* fulfilled(resolve 호출 후) */})
.catch(e => {/* rejected(reject 호출 후) */})
.finally(() => {/* always */});
// 프로미스 체이닝: then, catch, finally는 언제나 프로미스를 반환하여 연속적 호출 가능

// fetch
const fetchPromise = fetch(URL).then(() => {});
```

### 상태 정보

-   pending: 비동기 처리가 아직 수행되지 않은 상태
-   fulfilled: 비동기 처리가 성공한 상태, resolve 호출
-   rejected: 비동기 처리가 실패한 상태, reject 호출

#

## 마이크로태스크 큐

    태스크 큐와는 별도로 프로미스 후속 처리 메소드의 콜백 함수가 일시 저장된다.
    태스크 큐보다 우선순위가 높다.
    (이벤트 루프는 콜 스택이 비면 먼저 마이크로태스크 큐에서 가져와 실행한다.)

```javascript
setTimeout(() => console.log(1), 0); // 태스크 큐

Promise.resolve()
    .then(() => console.log(2)) // then은 후속 처리 메소드이므로
    .then(() => console.log(3)); // 마이크로태스크 큐에서 관리한다.

// 2 3 1
```
