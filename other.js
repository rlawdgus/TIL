window.onload = () => {
    let result = document.getElementById("display");
    window.addEventListener(
        "message",
        (e) => {
            let sourceOrigin = location.origin;

            if (e.origin !== sourceOrigin) return;
            display.textContent = e.data;
        },
        false
    );
};
