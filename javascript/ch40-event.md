## 이벤트 핸들러

    이벤트가 발생 했을 때 호출될 함수

#

## 이벤트 핸들러 등록

```html
<p>어트리뷰트 방식</p>

<button onclick="sayHi()">Click me!</button>

<p>함수 참조가 아닌 호출문을 할당했으므로</p>
<p>암묵적으로 생성될 함수 몸체가 어트리뷰트 값이 된다.</p>
```

```javascript
// <button>Click me</button>

const $button = document.querySelector("button");

// 프로퍼티 방식
$button.onclick = function () {};

// 리스너 방식
$button.addEventListener("click", function () {});
```

#

## 이벤트 전파

### 버블링

    한 요소에서 이벤트가 발생해서 할당된 핸들러가 동작하고
    이어서 부모 요소의 핸들러가 동작하여
    최상단의 요소(window)까지의 핸들러가 동작하는 것

    캡쳐링 - 최상단 요소부터 핸들러가 동작하는 것

```html
<html>
    <body>
        <ul>
            <li></li>
            <li></li>
            <li></li>
        </ul>
    </body>
</html>

<!-- li => ul => body => html => window -->
```

#

## event.target

    이벤트가 발생한 가장 안쪽 요소

    event.currentTarget(=== this): (버블링 중)현재 실행 중인 핸들러가 할당된 요소

#

### 참고

-   [버블링, evnet,target] https://ko.javascript.info/bubbling-and-capturing
