const timer = setTimeout(() => {
    console.log("3s wait");

    const interval = setInterval(() => {
        console.log("3s");
    }, 3000);

    setTimeout(() => {
        clearInterval(interval);
    }, 12000);
}, 3000);

//3초 기다리고 나서 3초마다 3s 찍는 중에 12초가 되면 setInterval 취소

//clearTimeout(timer) setTimeout 취소
