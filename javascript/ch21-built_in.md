## 표준 빌트인 객체

    ECMAScript 사양에 정의된 객체, 전역의 공통 기능 제공

    Object, String, Number, Boolean, Array, ...

```javascript
const strObj = new String("asd");

// 생성자 함수로 생성하면 객체의 프로토타입은 String.Prototype이다.
console.log(Object.getPrototypeOf(strObj) === String.Prototype); // true
```

#

## 호스트 객체

    ECMAScript에는 정의되어 있지 않고
    자바스크립트 실행 환경(브라우저, Node.js)에 따라 추가로 제공하는 객체

    브라우저 - DOM, XMLHttpRequest, Web Worker, ...

#

## 원시값과 래퍼 객체

    문자열, 숫자, 불리언 값을 객체처럼 접근하면 생성되는 임시 객체

```javascript
const str = "asd";

// 문자열에 마침표 접근하면
// 래퍼 객체인 String 생성자 함수의 인스턴스가 생성되고
// 문자열은 래퍼 객체의 [[StringData]] 내부 슬롯에 할당된다.

console.log(str.length); // String 인스턴스로 변환
console.log(str.toUpperCase()); // String 인스턴스로 변환

// 래퍼 객체로 접근 후엔 다시 원시 값으로 되돌린다.
console.log(typeof string); // string
```

#

## var, let

    var은 전역 객체의 프로퍼티(메소드)가 되고
    let은 전역 렉시컬 환경의 선언적 환경 레코드에 존재한다.

```javascript
var foo = 1;

bar = 2; // 암묵적 전역

console.log(window.foo); // 1
console.log(window.bar); // 2

delete foo;
delete bar;

console.log(window.foo); // 1 - 전역 변수는 삭제되지 않는다.
console.log(window.bar); // undefined
```

```javascript
let foo = 1;

console.log(window.foo); // undefined
```

#

## 빌트인 전역

    - 프로퍼티
        1. Infinity
        2. Nan
        3. undefined

    - 함수
        1. eval - 전달받은 문자열 코드가 표현식이면 값 생성(런타임때 스코프 수정)
        2. isFinite - 유한 수 true, 무한 수 false(null은 0으로 검사해서 true)
        3. isNaN
        4. parseFloat - 문자열을 실수로 해석, 공백 있을 시 첫 번째만 변환
        5. parseInt - 두 번째 인수에 진법 기수를 넣어 해당 진법으로 해석
        6. encodeURI, decodeURI - URI에 있는 알파벳 외 글자 이스케이프 처리
        7. encodeURIComponent,decodeURIComponent - 쿼리부분만 처리
