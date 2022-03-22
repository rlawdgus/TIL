## expect

    사전에 정의를 하고, 통과를 하면 테스트를 성공시키고 통과를 하지 않으면 테스트를 실패시킵니다.

#

## toBe

    toBe 는 matchers 라고 부르는 함수인데요,
    특정 값이 어떤 조건을 만족하는지, 또는 어떤 함수가 실행이 됐는지, 에러가 났는지 등을 확인 할 수 있게 해줍니다.

#

## describe

    describe 라는 키워드를 사용하면 여러 테스트 케이스를 묶을 수 있습니다.

#

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
