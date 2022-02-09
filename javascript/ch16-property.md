## 내부 슬롯과 내부 매소드

    ECMAScript 사양에서 사용하는 프로퍼티, 메소드

    자바스크립트 엔진의 내부 로직이고 원칙적으로 직접적인 접근과 호출을 제공하지 않는다.

    모든 객체는 [[Prototype]]이라는 내부 슬롯을 갖는다.
    (접근은 객체.__proto__)

#

## 프로퍼티 어트리뷰트와 프로퍼티 디스크립터 객체

    자바스크립트 엔진은 프로퍼티를 생성할 때 프로퍼티의 상태를 나타내는 어트리뷰트를 기본값으로 자동 정의한다.

    값 - [[Value]]
    갱신 가능 여부 - [[Writable]]
    열거 가능 여부 - [[Enumerable]]
    정의 가능 여부 - [[Configurable]]

```javascript
const person = { name: "Lee" };

console.log(Object.getOwnPropertyDescriptors(person));
// name: {value: "Lee", writable: true, enumerable: true, configurable: true}
```

#

## 데이터 프로퍼티와 접근자 프로퍼티

    데이터 프로퍼티 - value, writable, enumerable, configurable
    접근자 프로퍼티 - get, set, enumerable, configurable

#

## 프로퍼티 정의 (Object.defineProperty)

```javascript
const person = {};

Object.defineProperty(person, "name", {
    value: "Lee", // default: undefined
    wirtable: true, // defaultL: false
    enumerable: true, // defaultL: false
    configurable: true, // defaultL: false
    // get // defaultL: undefined
    // set // defaultL: undefined
});
```

#

## 객체 변경 방지

```javascript
const person = {};

// 객체 확장 금지(프로퍼티 추가 안됨)
Object.preventExtensions(person); // person.name = 'Lee' - 무시, strict mode에서는 에러

// 객체 밀봉(읽기, 쓰기만 가능)
Object.seal(person);
// person.name = 'Lee' - 무시, strict mode에서는 에러
// delete person.name = 'Lee' - 무시, strict mode에서는 에러
// Object.defineProperty(person, 'name', {configurable: true}) - 에러

// 객체 동결(읽기만 가능, 얕은 변경 금지)
Object.freeze(person);

// 불변 객체(깊은 변경 금지)
const deepFreeze = (target) => {
    if (target && typeof target === "object" && !Object.isFrozen(target)) {
        Object.freeze(target);

        Object.keys(target).forEach((key) => deepFreeze(target[key]));
    }

    return target;
};

deepFreeze(person);
```
