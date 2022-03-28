## TDD(Test Driven Development)

    테스트 주도 개발
    선 테스트 코드 작성, 후 구현

1. 실패: 실패하는 테스트 케이스를 만든다.
2. 성공: 테스트를 통과하는 케이스를 만든다.
3. 리팩토링: 개선시키면서 테스트를 통과하는지 확인한다.

#

## 스냅샷 테스팅

    렌더링된 결과가 이전에 렌더링한 결과와 일치하는지 확인하는 작업을 의미합니다.

#

## 사용 권장 쿼리 우선 순위

    1. getByLabelText
    2. getByPlaceholderText
    3. getByText
    4. getByDisplayValue
    5. getByAltText
    6. getByTitle
    7. getByRole
    8. getByTestId

[testing] https://learn-react-test.vlpt.us/#/01-javascript-testing

#

## Test code

-   test runner: 테스트 실행시 \*.test.js 파일 테스트 진행
-   describe: 테스트 그룹화
-   it: 개별 테스트 수행( === test)
-   render: 특정 컴포넌트를 jsdom에 렌더링
-   컴포넌트 렌더링 -> 액션 발생시키기 -> 결과 확인 패턴

[참고] https://tecoble.techcourse.co.kr/post/2021-10-22-react-testing-library/

#

## Query

    렌더링 된 DOM 노드에 접근하여 엘리먼트를 가져오는 메소드

-   get: 동기적 처리, 타켓을 찾지 못할 경우 에러 처리
-   find: 비동기적 처리, 타켓을 찾지 못할 경우 에러 처리
-   query: 동기적 처리, 타겟을 찾지 못할 경우 null 반환
-   all: 다수 엘리먼트 탐색시 메소드 뒤에 All 붙여서 사용

[참고] https://tecoble.techcourse.co.kr/post/2021-10-22-react-testing-library/
