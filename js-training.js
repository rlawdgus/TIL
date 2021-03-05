const a1 = document.getElementById("a1");
const blob1 = new Blob(["Hello ", "download!"], { type: "text/plain" });
a1.href = URL.createObjectURL(blob1);
