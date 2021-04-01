window.onload = function () {
    var N = "10000000";
    var mainstart = document.getElementById("mainstart");
    var workerstart = document.getElementById("workerstart");
    var clear = document.getElementById("clear");
    var output = document.getElementById("output");
    startClock();

    // Worker 객체를 생성한다
    var worker = new Worker("worker.js");
    // message 이벤트 처리기를 등록한다
    worker.onmessage = function (e) {
        console.log("recieved: " + new Date());
        output.innerHTML = N + " 이하의 최대 소수 = " + e.data;
    };
    // 워커로 처리한다
    workerstart.onclick = function () {
        console.log("send: " + new Date());
        worker.postMessage(N);
    };
    // 메인 스레드로 처리한다
    mainstart.onclick = function () {
        output.innerHTML = N + " 이하의 최대 소수 = " + prime(N);
    };
    // 결과를 지운다
    clear.onclick = function () {
        output.innerHTML = "";
    };
};
function startClock() {
    var clock = document.getElementById("clock");
    var startTime = new Date();
    setInterval(function () {
        clock.innerHTML = ((new Date() - startTime) / 1000).toFixed(1);
    }, 100);
}
