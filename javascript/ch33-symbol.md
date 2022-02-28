## Symbol

    다른 값과 중복되지 않는 유일무이한 값

    ES6에서 도입된 7번 째 원시 타입

```javascript
// 함수를 호출하여 생성, new를 쓰면 에러
const mySymbol = Symbol("mySymbol");
const mySymbol2 = Symbol("mySymbol");

console.log(mySymbol); // Symbol(mySymbol)
console.log(typeof mySymbol); // symbol

console.log(mySymbol === mySymbol2); // false

console.log(mySymbol.description); // mySymbol
console.log(mySymbol.toString()); // Symbol(mySymbol)

// boolean 타입 외엔 변환 불가
if (mySymbol) console.log("not empty");
```

#

## for, keyFor

```javascript
// 키와 심벌 값의 쌍으로 저장된
// 전역 심벌 레지스트리에서
// 검색 성공시 검색된 값 반환
// 실패시 생성
const s = Symbol.for("asd");
const s2 = Symbol.for("asd");

console.log(s === s2); // true

console.log(Symbol.keyFor(s)); // asd

// for로 검색 및 생성하지 않으면
// 심벌 레지스트리에서 관리하지 않는다.
const s3 = Symbol("asdf");
console.log(Symbol.keyFor(s3)); // undefined
```

#

## 심벌, 상수

```javascript
const Direction = {
    UP: 1,
    DOWN: 2,
    LEFT: 3,
    RIGHT: 4,
};

const DirectionSymbol = {
    UP: Symbol("up"),
    DOWN: Symbol("down"),
    LEFT: Symbol("left"),
    RIGHT: Symbol("right"),
};

console.log(Direction.UP); // 1
console.log(DirectionSymbol.UP); // up
```

#

## 심벌 프로퍼티 키

```javascript
// 다른 프로퍼티와 절대 충돌하지 않는다.
// for in, Object.keys, Object.getOwnPropertyNames로 찾을 수 없다.
const obj = {
    [Symbol.for("asd")]: 1,
};

obj[Symbol.for("asd")]; // 1

Object.getOwnPropertySymbols(obj); // [Symbol(asd)]

const v = Object.getOwnPropertySymbols(obj)[0];

console.log(obj[v]); // 1
```
