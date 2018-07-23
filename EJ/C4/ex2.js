let day1 = {
    // if key is not string, can not cantians space such as day event
    squirrel: false,
    events: ["work", "touched tree", "pizza", "running"],
    'work': 'test',
};
console.log(day1.squirrel);
// → false
console.log(day1.wolf);
// → undefined
day1.wolf = false;
console.log(day1.wolf);
// → false
console.log(day1['work']);
