# ESNext

-   비구조화 - 구조화된 객체에서 필요한 내용만 구조를 풀어 변수에 저장
-   화살표 함수
-   클래스 - 객체 지향
-   모듈 - export, import
-   생성기(function\*) - 제너레이터 함수라고 함, yeild 제공
-   promise, async/await

# 타입스크립트

-   ECMAScript5 - 표준 자바스크립트
-   신 버전, ES5 포함 - ESNext (ES6 ~)
-   ESNext + type기능 = TypeScript
-   복잡한 프로젝트에서 다른 개발자의 소스에 접근하기 좋다
-   타입스크립트 컴파일러가 오류 원인을 알려준다
-   타입 주석(: type), 타입 주석 생략시 값을 분석해 타입 추론
-   인터페이스
-   튜플
-   제네릭 타입 - 여러 타입 취급
-   대수 타입 - 합집합 타입(|), 교집합 타입(&)
-   템플릿 - `(backtick), ${변수}, 변수 값과 문자열 조합

# 타입스크립트 기본 제공 타입

-   number
-   boolean
-   string
-   object - 객체, (interface, class ..)
-   any - 타입추론을 할 수 없거나 필요없는 변수, 최상위 타입
-   undefined - undefined만 가짐, 최하위 타입

# 인터페이스

-   대상이 객체일 때 any타입처럼 동작하지 않게 하기 위함
-   선택 속성 구문(?) - 속성이 있어도 없어도 됨
-   익명 인터페이스 - 함수 구현이나 재사용하지 않을 때 사용

# 클래스

-   캡슐화, 상속, 다형성
-   접근 제한자 - private, protected, public(default)
    -   private - class 내부에서만 접근, 자식class 안됨(상속 x)
    -   protected - 자식class 접근 가능(상속 o, 인터페이스 x)
    -   public - 모두 접근 가능
    -   readonly - 읽기전용
-   생성자(constructor)
