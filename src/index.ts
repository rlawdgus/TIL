const makeNames = (): (() => string) => {
    const names = ["A", "B", "C"];
    let index = 0;

    return (): string => {
        if (index === names.length) index = 0;

        return names[index++];
    };
};

const makeName: () => string = makeNames();

console.log([1, 2, 3, 4, 5, 6].map(() => makeName()));
