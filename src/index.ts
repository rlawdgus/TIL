type FirstOrderFunc<T, R> = (T: T) => R;
type SecondOrderFunc<T, R> = (T: T) => FirstOrderFunc<T, R>;
type ThirdOrderFunc<T, R> = (T: T) => SecondOrderFunc<T, R>;

const inc: FirstOrderFunc<number, number> = (x: number): number => x + 1;

const add: SecondOrderFunc<number, number> = (
    x: number
): FirstOrderFunc<number, number> => (y: number) => x + y;

const add3: ThirdOrderFunc<number, number> = (
    x: number
): SecondOrderFunc<number, number> => (
    y: number
): FirstOrderFunc<number, number> => (z: number): number => x + y + z;

console.log(inc(1));

console.log(add(1)(2));

console.log(add3(1)(2)(3));

const add2: SecondOrderFunc<number, number> = add3(1);
const add1: FirstOrderFunc<number, number> = add2(2);

console.log(add1(3), add2(2)(3), add3(1)(2)(3));
