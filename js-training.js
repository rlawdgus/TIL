const makeCounter = () => {
    let count = 0;

    const f = () => {
        return count++;
    };

    return f;
};

let counter = makeCounter();
let counter2 = makeCounter();

console.log(counter()); //0
console.log(counter()); //1
console.log(counter()); //2

console.log(counter2()); //0
