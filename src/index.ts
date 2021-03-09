interface INameable {
    name: string;
}

const obj: object = { name: "Jack" };

const name1 = (<INameable>obj).name;
const name2 = (obj as INameable).name;

console.log(name1 === name2);
