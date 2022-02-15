## 객체지향 프로그래밍

-   객체: 상태나 동작을 하나의 단위로 구성한 복합적 자료구조
-   추상화: 프로그램에 필요한 속성을 간추려 표현하는 것
-   상속: 어떤 객체의 프로퍼티 및 메소드를 다른 객체가 받아 사용

#

## 프로토타입 객체

    객체의 상위 객체 역할을 하는 객체
    프로토타입의 하위 객체는 프로퍼티를 상속받아 쓴다.

    모든 객체는 [[Prototype]] 내부 슬롯을 갖고
    모든 프로토타입은 생성자 함수와 연결되어 있다.

    __proto__ 접근자를 통해 자신의 [[Prototype]]에 간접적으로 접근할 수 있다.

```javascript
function Circle(radius) {
    this.radius = radius;
    this.getArea = function () {
        Math.PI * this.radius ** 2;
    };
}

// Circle로 만들어진 circle, circle2는
// getArea가 중복 생성된다.
const circle = new Circle(1);
const circle2 = new Circle(2);
```

```javascript
function Circle(radius) {
    this.radius;
}

// Circle의 프로토타입 객체에 getArea를 추가
Circle.prototype.getArea = function getArea() {
    return Math.PI * this.radius ** 2;
};

// Circle 생성자 함수는
// 프로토타입인 Circle.prototype의 getArea를 상속받는다.
// Circle로 만든 모든 인스턴스는 하나의 getArea를 공유한다.
const circle = new Circle(1);
const circle2 = new Circle(2);
```

#

## Object.prototype

    모든 객체는 프로토타입의 계측 구조인 프로토타입 체인에 묶여있다.
    프로퍼티(메소드)에 접근할 때 해당 객체에 없다면
    __proto__가 가리키는 참조를 따라
    프로토타입의 프로퍼티를 순차적으로 검색한다.
    최상위 객체는 Object.prototype이며 모든 객체에 상속된다.

    *   프로토타입 체인은 단방향이다.(순환 참조가 있으면 체인의 종점이 없기 때문)

#

## 함수 객체의 prototype 프로퍼티

    함수만 가지는 prototype은 생성자 함수가 생성할 인스턴스의 prototype을 가리킨다.

    Object.prototype으로부터 상속받은 __proto__와 함수 객체가 갖고 있는 prototype은 동일하다.

```javascript
// 생성자 함수(이 객체의 프로토타입(__proto__)은 Function.prototype)
// 이 생성자 함수가 만들 인스턴스의 프로토타입(prototype)은 Person.prototype
function Person(name) {
    this.name = name;
}

// Person으로 생성한 인스턴스, 프로토타입은(__proto__) Person.prototype
const me = new Person("asd");

// Function.prototype, Person.prototype 프로토타입 체인 끝에는 Object.prototype

// 모든 프로토타입은 constructor 프로퍼티를 갖는다.
// 자신을 참조하고 있는 생성자 함수를 가리킨다.
console.log(me.constructor === Person); // true
// me는 프로토타입이 아니므로 constructor가 없다.
```

#

## 리터럴 표기법으로 생성한 객체의 생성자 함수와 프로토타입

```javascript
// obj.constructor === Object
const obj = {};

// add.constructor === Function
const add = function (a, b) {
    return a + b;
};

// arr.constructor === Array
const arr = [1, 2, 3];

// regexp.constructor === RegExp
const regexp = /is/gi;
```

#

## 프로토타입 생성시점

    프로토타입은 생성자 함수가 생성되는 시점에 더불어 생성된다.

    생성자 함수 정의가 평가되어 함수 객체를 생성하는 시점에 프로토타입도 생성된다.
    (non-constructor는 프로토타입이 생성되지 않는다.)

#

## 프로토타입 체인

    객체의 프로퍼티(메소드)에 접근하려고 할 때
    해당 객체에 접근하려는 프로퍼티가 없다면
    프로토타입의 프로퍼티를 순차적으로 검색한다.

```javascript
const Person = function () {
    function Person(name) {
        this.name = name;
    }

    Person.prototype.sayHello = function () {
        console.log(`Hi! My name is ${this.name}`);
    };

    return Person;
};

const me = new Person("asd");

// 오버라이딩
me.sayHello = function () {
    console.log(`Hey! My name is ${this.name}`);
};

// 인스턴스의 메소드 호출
me.sayHello(); // Hey! ...

delete me.sayHello;

me.sayHello(); // Hi! ...

delete me.sayHello;

// 프로토타입의 프로퍼티(메소드)는 삭제되지 않는다.
me.sayHello(); // Hi ...

// 직접 접근하여 삭제할 수 있다.
delete Person.prototype.sayHello;

me.sayHello(); // error
```

-   오버라이딩: 상위 클래스가 갖고 있는 메소드를 재정의 하여 사용
-   오버로딩: 함수 이름은 동일하고 매개변수의 형태를 달리하여 여러가지로 사용

#

## instance of

    생성자 함수의 prototype에 바인딩된 객체가 프로토타입 체인 상에 존재하는지 확인한다.

```javascript
A instance of B

// B 생성자 함수의 prototype에 바인딩된 객체가
// A 객체의 프로토타입 체인상에 존하면 true
```

#
