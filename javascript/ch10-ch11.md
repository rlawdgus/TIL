## 원시 값

    원시 타입의 값, 변경 불가능한 값

1. 원시 값들은 식별자를 가지며 메모리에 저장된다.(값은 변경할 수 없다.)

    ```javascript
    let score = 80;
    // 0xscore - 식별자: score, 값: 80
    ```

2. 원시 값을 갖는 변수를 다른 변수에 할당하면 값을 복사하고 새 메모리에 저장한다.(값에 의한 전달)

    ```javascript
    const copy = score;
    // 0xcopy - 식별자: copy, 값: 80, score와 별개(주소 다름)
    ```

    2'. 식별자들은 주소를 기억하므로 같은 주소를 갖게 된다. javascript에 명시되지 않아서 2, 2' 둘 중 어느 것이라고 할 수 없다.

    ```javascript
    const copy = score;
    // 0xscore - 식별자: score || copy, 값: 80
    ```

3. 변수에 새로운 값을 할당하면 또 새로운 메모리에 저장한다.

    ```javascript
    score = 100;
    // 0xscore2 - 식별자: score, 값: 80
    // 맨 처음의 80은(주소 0xscore) 사용하지 않으니 가비지 컬렉터가 삭제한다.
    ```

    3'. 2`의 경우

    ```javascript
    score = 100;
    // 0xscore - 식별자: copy, 값: 80
    // 0xscore2 - 식별자: score, 값: 100
    ```

#

## 객체

    객체(참조) 타입의 값, 변경 가능한 값

1. 변수에 객체 할당하면 객체의 주소를 갖는다.

    ```javascript
    const scoreInstance = {
        score: 80,
    };
    // 0xscore80 - 식별자: '', 값: {score: 80}
    // 0xscoreInstance - 식별자: scoreInstance, 값: 0xscore80
    ```

2. 객체는 변경할 수 있다.(CRUD)

    ```javascript
    scoreInstance.score = 100;
    scoreInstance.checked = true;
    // 0xscore80 - 식별자: '', 값: {score: 100, checked: true}
    // 0xscoreInstance - 식별자: scoreInstance, 값: 0xscore80
    ```

    2'. 얕은 복사 - 객체의 한 단계까지만 복사

    2''. 깊은 복사 - 객체 전체를 복사

-   얕은 복사와 깊은 복사로 생성된 객체는 원본과 다른 객체이다.

3. 여러 개의 식별자가 객체를 공유할 수 있다.

    ```javascript
    const copy = scoreInstance;
    // 0xcopy - 식별자: copy, 값: 0xscore80
    // 참조에 의한 전달

    scoreInstance.scoreModify = true;
    copy.copyModify = true;

    console.log(copy === scoreInstance); // true
    console.log(copy);
    //{
    //    score: 100,
    //    checked: true,
    //    scoreModify: true,
    //    copyModify: true,
    //}
    ```
