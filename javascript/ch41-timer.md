## setTimeout / clearTimeout

```javascript
setTimout((name) => console.log(name), 1000, "asd"); // 1초 후 asd

let count = 0;

const timeoutId = setInterval(() => {
    console.log(count);

    if (count++ === 5) clearInterval(timeoutId);
}, 1000);
```

#

## 디바운스

    연이어 발생한 이벤트를 하나의 그룹으로 묶어서 처리
    주로 마지막, 혹은 처음에 처리한다.

#

## 스로틀

    연이어 발생한 이벤트에 대해 delay를 포함시키고
    delay동안 발생한 이벤트는 무시한다.

#

### 참고

-   [디바운스, 스로틀] https://programming119.tistory.com/241
