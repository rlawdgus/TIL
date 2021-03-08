class Person {
    constructor(public name: string, public age?: number) {}
}

class Person2 {
    name: string;
    age?: number;
    constructor(name: string, age?: number) {
        this.name = name;
        this.age = age;
    }
}


//Person === Person2