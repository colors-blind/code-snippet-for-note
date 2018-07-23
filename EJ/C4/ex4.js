// how to get an object keys

let dict = {'a': 'apple', 'b': 'banana'};

console.log(Object.keys(dict));

// how to update an object

let objectA = {a: 1, b: 2};
Object.assign(objectA, {b: 3, c: 4});

console.log(objectA);
// → {a: 1, b: 3, c: 4}
