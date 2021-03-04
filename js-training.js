window.onload = () => {
    let req = new XMLHttpRequest();

    let jsonObj;
    req.addEventListener(
        "load",
        () => {
            jsonObj = req.response;
            console.log(jsonObj);
        },
        false
    );

    req.responseType = "json";

    req.open("GET", "data.json", true);
    req.send(null);

    console.log(req);
};
