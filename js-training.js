window.onload = () => {
    let w;

    document.getElementById("open").onclick = () => {
        w = open("newpage.html", "new page", "width=400, height=300");
    };

    document.getElementById("close").onclick = () => {
        if (w) w.close();
    };
};
