const address: any = {
    country: "Korea",
    city: "Busan",
    address1: "Dong-gu",
    address2: "Choryang",
};

const { country, city, ...detail } = address;
//잔여 연산자(rest operator)

console.log(detail);

const part = { country: "Korea" };
const part2 = { city: "Busan" };
const part3 = {
    address1: "Dong-gu",
    address2: "Choryang",
};

const address2: any = { ...part, ...part2, ...part3 };
//전개 연산자(spread operator)

console.log(address2);
