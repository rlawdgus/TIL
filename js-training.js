let promise = new Promise((resolve, reject) => {
    setTimeout(() => {
        let n = parseInt(prompt("input"));

        if (n <= 10) {
            resolve(n);
        } else {
            reject("error");
        }
    }, 1000);
});

promise.then(
    (num) => {
        console.log(num);
    },
    (error) => {
        console.log(error);
    }
);
