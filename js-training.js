window.onload = () => {
    const input = document.getElementById("input");

    input.addEventListener(
        "change",
        (e) => {
            const reader = new FileReader();
            reader.onload = () => {
                const img = new Image();
                img.onload = () => {
                    const canvas = document.createElement("canvas");
                    const context = canvas.getContext("2d");
                    context.drawImage(img, 0, 0);

                    //back & white
                    // const imageData = context.getImageData(
                    //     0,
                    //     0,
                    //     canvas.width,
                    //     canvas.height
                    // );
                    // const data = imageData.data;

                    // for (let i = 0; i <= data.length; i += 4) {
                    //     const avg = (data[i] + data[i + 1] + data[i + 2]) / 3;
                    //     data[i] = avg;
                    //     data[i + 1] = avg;
                    //     data[i + 2] = avg;
                    // }

                    // context.putImageData(imageData, 0, 0);

                    document.body.appendChild(img);
                };

                img.src = reader.result;
            };

            // reader.readAsText(input.files[0]);
            reader.readAsDataURL(input.files[0]);
        },
        false
    );
};
