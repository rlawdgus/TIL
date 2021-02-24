function* gen() {
    yield 1;
    yield 2;
    yield 3;
    try {
        yield 4;
    } catch (e) {
        console.log("error");
    }
    yield* [2, 4];
    yield* "AB";
    yield 5;
}

let iter = gen();

console.log(iter.next());
console.log(iter.next());

// console.log(iter.return(10))

for (let i of iter) console.log(i);

iter.throw(new Error("ERROR"));

