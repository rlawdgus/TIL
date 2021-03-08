class Container<T> {
    constructor(public vlaue: T) {}
}

let numberContainer: Container<number> = new Container<number>(1);
let stringContainer: Container<string> = new Container<string>("Hello world !");
