const show = (data) => {
    console.log(data.name);
    console.log(data.price);
};

window.onload = () => {
    let url = "jsonp.js";
    let script = document.createElement("script");
    script.setAttribute("src", url);
    document.getElementsByTagName("head")[0].appendChild(script);
};
