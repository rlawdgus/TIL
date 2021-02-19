const card = {
    suit: "heart",
    rank: "A",
};

console.log(card);

card.value = 14;

console.log(card);

delete card.rank;

console.log(card);

console.log("rank" in card);
console.log("value" in card);
