const io = new IntersectionObserver((entries) => {
    console.log(entries);

    entries.forEach((entry) => {
        if (entry.isIntersecting) {
            entry.target.classList.add("tada");
            console.log("add");
        } else {
            entry.target.classList.remove("tada");
            console.log("remove");
        }
    });
});

const boxElementList = document.querySelectorAll(".box");

boxElementList.forEach((element) => {
    io.observe(element);
});
