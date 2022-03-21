const { sum, sumOf } = require("./sum");

// test === it
// it("테스트 케이스 설명", () => {
//     expect(sum(1, 2)).toBe(3);
// });

describe("sum", () => {
    it("calculates 1 + 2", () => {
        expect(sum(1, 2)).toBe(3);
    });

    it("calculates all numbers", () => {
        const array = [1, 2, 3, 4, 5];
        expect(sumOf(array)).toBe(15);
    });
});
