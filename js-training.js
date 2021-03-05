window.onload = () => {
    let color = document.getElementById("color");
    let dropbox = document.getElementById("dropbox");

    color.ondragstart = (e) => {
        e.dataTransfer.setData("text/plain", e.target.value);
    };

    dropbox.ondragover = (e) => {
        e.preventDefault();
    };

    dropbox.ondrop = (e) => {
        e.preventDefault();
        e.target.style.backgroundColor = e.dataTransfer.getData("text/plain");
    };
};
