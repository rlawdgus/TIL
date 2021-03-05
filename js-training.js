window.onload = () => {
    let frameWindow = document.getElementById("frame").contentWindow;
    let message = document.getElementById("message");
    let button = document.getElementById("button");

    let targetOrigin = "/";

    button.addEventListener(
        "click",
        () => {
            frameWindow.postMessage(message.nodeValue, targetOrigin);
        },
        false
    );
};
