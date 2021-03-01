const getScrollTop = () => {
    if (window.pageYOffset !== undefined) return window.pageYOffset;
    else return document.documentElement.scrollTop || document.body.scrollTop;
};

const getScrollLeft = () => {
    if (window.pageXOffset != undefined) return window.pageXOffset;
    else return document.documentElement.scrollLeft || document.body.scrollLeft;
};

if ("scrollRestoration" in history) {
    history.scrollRestoration = "manual";
}

const element = document.getElementById("sec3");
const rect = element.getBoundingClientRect();
scrollTo(rect.left + getScrollLeft(), rect.top + getScrollTop());
