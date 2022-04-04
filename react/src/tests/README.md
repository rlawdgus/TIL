# Jest

## TDD(Test Driven Development)

    테스트 주도 개발
    선 테스트 코드 작성, 후 구현

1. 실패: 실패하는 테스트 케이스를 만든다.
2. 성공: 테스트를 통과하는 케이스를 만든다.
3. 리팩토링: 개선시키면서 테스트를 통과하는지 확인한다.

#

## 사용 권장 쿼리 우선 순위

1. getByRole
2. getByLabelText
3. getByPlaceholderText
4. getByText
5. getByDisplayValue
6. getByAltText
7. getByTitle
8. getByTestId

#

## Test code

-   test runner: 테스트 실행시 \*.test.js 파일 테스트 진행
-   describe: 테스트 그룹화
-   it: 개별 테스트 수행( === test)
-   render: 특정 컴포넌트를 jsdom에 렌더링
-   fireEvent: 특정 이벤트 발생
-   expect(query).matcher(): query로 가져온 요소를 matcher 규칙에 맞게 결과 확인
-   컴포넌트 렌더링 -> 액션 발생시키기 -> 결과 확인 패턴

#

## Query

    렌더링 된 DOM 노드에 접근하여 엘리먼트를 가져오는 메소드

-   get: 동기적 처리, 타켓을 찾지 못할 경우 에러 처리
-   find: 비동기적 처리, 타켓을 찾지 못할 경우 에러 처리
-   query: 동기적 처리, 타겟을 찾지 못할 경우 null 반환
-   all: 다수 엘리먼트 탐색시 메소드 뒤에 All 붙여서 사용

#

## matchers

-   toBe~: 원시타입
-   toEqual~: 객체타입(깊은 복사 비교)
-   toMatch~: 문자열
-   toContain: 배열 내 포함 여부
-   toThrow~: 에러

#

## 비동기 코드 테스트

-   done

    done이 호출되기 전까지 테스트코드는 끝내지 않는다.

```javascript
test("test", (done) => {
    done();
});
```

-   then, promise, async await, reject..

    비동기 함수를 비동기적으로 실행시켜서 확인한다.

```javascript
test('test', async() => {
    await () => {}
})
```

#

## beforeEach, afterEach

```javascript
// 각 test 함수 실행 직전에 실행
beforeEach(() => {});

// 각 test 함수 실행 직후에 실행
AfterEach(() => {});

test();

test();

test();
```

#

## beforeAll, afterAll

```javascript
// 모든 test 함수 실행 직전에 한 번 실행(DB SELECT ...)
beforeEach(() => {});

// 모든 test 함수 실행 후에 마지막으로 실행
AfterEach(() => {});

test();

test();

test();
```

#

## mock 함수

    테스트를 위해 흉내만 낸 함수

```javascript
// Date.now같이 항상 변해서 테스트하기 까다롭다.
// 함수를 지정해줘서 테스트할 수 있게 한다.
Date.now = jest.fn(() => 123456789); // 36초
```

#

## 스냅샷 테스팅

    성공한 케이스를 찍어두고 그 결과와 비교하면서 테스트한다.

    실패할 경우 스냅샷을 업데이트할 수 있다.

[test code base] https://learn-react-test.vlpt.us/#/01-javascript-testing

[## Test code, ## Query] https://tecoble.techcourse.co.kr/post/2021-10-22-react-testing-library/

[## matchers ~] https://www.youtube.com/watch?v=snFRUjYR6j4
