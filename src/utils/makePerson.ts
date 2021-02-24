export const makePerson = (name: string, age: number) => {
    return { name: name, age: age };
};

export const testMakePerson = () => {
    console.log(makePerson("Jane", 22), makePerson("Jack", 23));
};
