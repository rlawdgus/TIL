## 디스트럭처링 할당

    구조화된 이터러블이나 객체를 비구조화하여
    1개 이상의 변수에 개별적으로 할당한다.

```javascript
const arr = [1, 2, 3];

const [one, two, three] = arr;

console.log(one, two, three); // 1 2 3

//
const [a, b, c = 3] = [1, 2];
const [d, e = 10, f = 3] = [1, 2];

console.log(a, b, c); // 1 2 3
console.log(d, e, f); // 1 2 3
```

```javascript
const user = {
    firstName: "asd",
    lastName: "qwe",
};

const { firstName: fn, lastName: ln } = uesr;

console.log(firstName, lastName); // asd qwe
console.log(fn, ln); // asd qwe
```
