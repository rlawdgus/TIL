const babel = require("@babel/core");
const fs = require("fs");

const filename = "./code.js";
const source = fs.readFileSync(filename, "utf-8");
const presets = ["@babel/preset-react"];
const plugins = [
    "@babel/plugin-transform-template-literals",
    "@babel/plugin-transform-arrow-functions",
];

const useBabel = async () => {
    const { code } = await babel.transformAsync(source, {
        filename,
        presets,
        plugins,
        configFile: false,
    });

    console.log(code);
};

useBabel();
