# 자바스크립트 특징

-   인터프리터 - JIT(Just In Time) Compiler => 실행 속도 증가
-   동적 프로토타입 기반 객체 지향
-   동적 타입 - 실행 도중에 타입이 바뀐다
-   함수는 일급 객체 - 함수에 함수를 인수로 넘길 수 있다
-   함수가 클로저(변수 은닉, 영속성 보장) 정의

# window - 브라우저, 창 조작

# DOM - HTML 문서 요소 제어

# XMLHttpRequest - 비동기 통신 기능

# let, const - es6부터 추가된 변수 선언자

var, let 차이

-   let으로 선언헌 변수의 유효 범위는 블록 안
-   var은 블록 밖에서 읽어도 에러가 나지 않는다

# 익명함수(무명함수)

재사용하지 않을 때 사용, 호이스팅이 되지 않고 리터럴로 이름이 붙으면 재사용할 수 있다

# 객체 분류

-   네이티브 객체 - es사양에 정의된 객체, Object String Number Boolean Array Function JSON Math Reflect
-   호스트 객체 - 자바스크립트 실행 환경에 정의된 객체, Window Navigator History Location XMLHttpRequest API(HTML)
-   사용자 정의 객체

# new

1. 빈 오브젝트 생성
2. this를 오브젝트에 바인드
3. 오브젝트의 프로퍼티에 생성자 함수의 프로토타입 오브젝트(proto) 추가
4. 반환될 수 있도록 return this를 마지막에 추가

# ProtoType - 모든 오브젝트가 가지고 있고 여기서 메소드, 프로퍼티를 상속받는다

# this

-   함수가 호출되어 실행되는 시점에 this값이 결정, 그 함수가 속해 있던 객체 참조
-   최상위 레벨 - 전역 객체(Window)
-   이벤트 처리기 - 이벤트가 발생한 요소 객체
-   생성자 함수 - 그 생성자로 생성한 객체
-   protoType 메소드 - 그 생성자로 생성한 객체
-   직접 호출한 함수 - 코드 앞의 객체 없을 경우 전역 객체

# scope

-   변수 접근 범위
-   scope chain - 현재 스코프에 찾는 변수가 없을 때 상위 스코프에서 찾는다
-   lexical scope - 블록마다 가지는 스코프, 함수는 실행시에 렉시컬 스코프가 생긴다
-   closure - 함수와 그 함수가 선언됐을 때의 렉시컬 환경
    -   변수 은닉, 지속성 보장
    -   데이터와 데이터를 조작하는 함수를 하나로 사용 가능
    -   다양한 매개변수를 쓰는 함수를 여러 개 생성 (팩토리)
    -   여러 번 실행시 두 번째 이후로는 연산 없이 연산 했던 결과 이용 (초기화)

# 함수 리터럴과 화살표 함수의 차이점

-   this의 값이 정의할 때 결정(함수 리터럴은 호출할 때)
-   arguments가 없음
-   생성자로 사용할 수 없음
-   내부에서 yield를 쓸 수 없음

# 이벤트 전파 과정

1. 캡처링
   Window객체에서 출발해서 DOM트리를 타고 이벤트 타겟(이벤트가 발생한 요소)까지 전파
2. 타겟
   이벤트가 이벤트 나겟에 전파되는 단계, 등록된 처리기나 리스너는 이 시점에서 실행
3. 버블링

-   이벤트가 이벤트 타겟에서 DOM트리를 타고 Window객체까지 전파
-   이벤트 리스너의 useCapture가 true면 캡처링, 타겟 단계일 때만 실행
-   false면 타겟, 버블링 단계일 때만 실행

# 비동기 처리

-   실행을 예약해두고 호출 스택에 남아 있는 작업이 끝나면 실행
-   Promise - 비동기 처리를 실행하고 그 처리가 끝난 후에 다음 처리를 실행
    -   resolve - 함수 안의 처리가 끝났을 때 호출해야 하는 콜백
    -   reject - 함수 안의 처리가 실패했을 때 호출해야 하는 콜백

# GET

웹 서버에 페이지 요청, 필요한 데이터는 URL에 덧붙여(텍스트만 가능) 보냄

# POST

-   데이터 갱신할 때
-   데이터 량이 많을 때
-   비밀번호같은 개인정보를 보낼 때 사용
-   텍스트 바이너리 모두 가능

# Ajax

-   XMLHttpRequest라는 자바스크립트 객체를 이용하여 우베 서버와 비동기로 통신하고 DOM을 이용하여 웹페이지를 동적으로 갱신하는 프로그래밍 기법
-   최소한의 통신으로 처리 속도가 빠르고 서버, 트래픽 부하가 적다
-   클라이언트 측에서 다른 작업을 할 수 있다.
-   갱신을 클라이언트 측이 담당한다. 일부분만 변경하므로 고속 렌더링이 가능하다.
-   화면 전체를 전환하는 빈도가 줄어들어 편의성 제공

# XMLHttpRequest

-   Ajax 기법을 사용할 때 필요, 데이터 송수신 수단
-   객체 생성
-   서버와 통신할 때 처리 방법 등록
-   요청을 전송하고 통신을 시작
-   동일 출처 정책 준수 => 크로스 오리진 통신 불가 => JSONP, CORS, postMessage

# JSONP - JSON 데이터 + 함수명, 상속 비보안 문제로 CORS로 대체

# CORS(Cross Origin Resource Sharing)

-   도메인, 프로토콜, 포트가 다른 곳에 리소스 교환이 가능하도록 하는 기술
-   XMLHttpRequest level 1에서는 크로스 오리진 통신 금지이고 level 2에서는 제한적으로 허용하는데 이 사양을 CORS라 한다
-   데이터를 가져오는 대상의 신뢰도에 따라 허용
-   Access-Control-Allow-Origin이라는 HTTP 헤더를 추가해야 한다

# postMessage

open으로 창을 열면 부모 창과 자식 창이 서로 Window객체를 참조해 조작할 수 있
두 창 서로 페이지 출처가 다르기 때문에 상대의 콘텐츠를 가져올 수 없는
postMessage로 메세지를 비동기적으로 주고받을 수 있다(프로퍼티 참조, 메소드 실행은 불가)

# MVC 모델

-   Model - 데이터와 처리 로직
-   View - 사용자가 볼 수 있는 형태로 표현
-   Controller - 사용자의 입력을 메세지로 전달

# Web Workers

자바스크립트에서 멀티스레드로 병렬 처리를 할 수 있는 API
