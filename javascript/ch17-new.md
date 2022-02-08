## 생성자 함수에 의한 객체 생성 방식의 장점

```javascript
function Circle(radius) {
    // this는 생성할 인스턴스
    this.radius = radius;
    this.getDiameter = () => 2 * this.radius;
}

const circle1 = new Circle(5); // new 사용시 생성자 함수로 동작한다.
const circle2 = new Circle(10); // 재사용성
```

```javascript
function Circle(radius) {
    if (new.target === Circle) {
        this.radius = radius;
        this.getDiameter = () => 2 * this.radius;
    }

    return "abc";
}

const circleObj = new Circle(1); // {radius: 1, getDiameter}
const circleNoObj = Circle(1); // abc
```

#

## 생성자 함수의 인스턴스 생성 과정

    생성자 함수의 역할 - 인스턴스 생성, 초기화
    바인딩 - 식별자와 값은 연결하는 과정

    1. 암묵적으로 빈 객체 생성
    2. 인스턴스 this바인딩(런타임 이전에 실행)
    3. 암묵적으로 this 반환,
    3-2. 명시적 객체 반환시 명시한 객체 반환
    3-3. 명시적 원시값 반환시 무시하고 this 반환

    호출([[Call]])할 수도 있고
    생성사 함수로(new) 사용([[Construct]])할 수도 있다.

    - callable: [[Call]]을 갖는 함수 객체
    - constructor: [[Constructor]]를 갖는 함수 객체(함수 선언문, 함수 표현식, 클래스)
    - non-constructor: [[Constructor]]가 없는 함수 객체(메소드, 화살표 함수)

#

## 스코프 세이프 생성자 패턴

```javascript
function Circle(radius) {
    // new 없이 호출 되었을 때 this는 전역 객체 window를 가리킨다.

    // new를 붙여 다시 호출(if(Circle의 인스턴스가 아닌 경우))
    if (!(this instanceof Circle)) return new Circle(radius);

    // new로 호출 했다면 this는 인스턴스이고 바인딩한다.
    this.radius = radius;
    this.getDiameter = () => 2 * this.radius;
}
```
