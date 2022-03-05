## Set

    중복되지 않는 유일한 값들의 집합

    순서에도 의미가 있고 인덱스로 접근할 수 없다.

    생성자 함수는 이터러블을 인수로 전달받아
    객체를 생성한다. 이때 중복되 값은 저장되지 않는다.

```javascript
const set = new Set("hello");

console.log(set); // Set(4) ["h", "e", "l", "o"]
console.log(set.size); // 4

// set 중복제거
const uniq = (arr) => [...new Set(arr)];
console.log(uniq([2, 1, 2, 3, 4, 3, 4])); // [2, 1, 3, 4]
```

#

## Map

    키와 값의 쌍으로 이루어진 컬렉션

    객체와 유사하지만
    객체를 포함한 모든 값을 키로 사용할 수 있고
    이터러블이다.

```javascript
const map = new Map([
    ["key", "value"],
    ["key2", "value2"],
]);

console.log(map); // Map(2) {'key' => 'value', 'key2' => 'value2'}
console.log(map.size); // 2
```
