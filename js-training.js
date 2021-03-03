let x = 1;

function foo() {
    let x = 10;
    let y = 100;
    bar();
}

function bar() {
    console.log(x);
    console.log(y); //undefined
}

foo(); // 10? 1?
bar(); // 1
