## 함수 정의

1. 함수 선언문
    ```javascript
    function add(x, y) {
        return x + y;
    }
    // 내용까지 호이스팅됨
    ```
2. 함수 표현식

    ```javascript
    let add = function (x, y) {
        return x + y;
    };
    ```

3. 생성자 함수
    ```javascript
    let add = new Function("x", "y", "return x + y");
    ```
4. 화살표 함수
    ```javascript
    let add = (x, y) => {
        return x + y;
    };
    ```

#

## 참조에 의한 전달

    함수 내부에서 외부의 상태를 변경할 때
    원시 값은 복사한 값을 전달되어 원본이 유지되고
    객체는 참조 값이 전달되어 원본이 훼손된다.

#

## 다양한 함수의 형태

-   즉시 실행 함수(IIFE)

    정의와 동시에 실행, 그룹 연산자로 감싸야 하며
    리터럴로 평가되기 때문에 다시 호출할 수 없다.

    ```javascript
    (function () {
        let a = 3;
        let b = 5;

        return a * b;
    })();
    ```

    -   private 한 변수를 만들 수 있다.(IIFE 내부에서 정의된 변수는 외부 범위에서 접근이 불가능하다. => 라이브러리 변수와 충돌하지 않는다.)
    -   변수에 즉시 실행 함수를 저장할 수 있다.(변수를 전역으로 선언하는 것을 피하기 위함)

-   재귀 함수

    자기 자신을 호출하는 함수

    ```javascript
    const factorial = (n) => {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    };
    ```

-   중첩 함수

    함수 내부에 정의된 함수

-   콜백 함수

    함수의 매개변수로 전달되는 함수

    콜백 함수를 전달받은 함수를 고차 함수라고 한다.

    ```javascript
    function repeat(n, f) {
        for (let i = 0; i < n; i++) f(i);
    }

    let logAll = function (i) {
        console.log(i);
    };

    repeat(5, logAll);
    ```

-   순수 함수

    외부 상태에 의존하지도 변경하지도 않고

    매개변수로 전달된 인수에게만 의존해 반환값을 만든다.

    (똑같은 호출에는 똑같은 반환을 한다.)

    ```javascript
    let n = 0;
    const increase = (n) => ++n;

    // vs

    let n = 0;
    const increase = () => ++n;
    // 항상 매개변수 없이 호출해도 결과가 다름
    // 외부 n을 변경함
    ```

#

### 참고

[즉시 실행 함수 쓰는 이유]https://velog.io/@tlatjdgh3778/%EC%A6%89%EC%8B%9C-%EC%8B%A4%ED%96%89-%ED%95%A8%EC%88%98IIFE%EC%97%90-%EB%8C%80%ED%95%9C-%EC%A0%95%EB%A6%AC
