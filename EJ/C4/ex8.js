// pass more than one arguments
function mymax(...numbers) {
    let result = -Infinity;
    for (let number of numbers) {
        if (number > result) result = number;
    }
    return result;
}
console.log(mymax(4, 1, 9, -2));
// → 9

// ---------

let words = ["never", "fully"];
console.log(["will", ...words, "understand"]);
