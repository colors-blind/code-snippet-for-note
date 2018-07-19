// Your code here.

// Write a function countBs that takes a string as its only argument and returns a number that indicates how many uppercase “B” characters there are in the string.

// Next, write a function called countChar that behaves like countBs, except it takes a second argument that indicates the character that is to be counted (rather than counting only uppercase “B” characters). Rewrite countBs to make use of this new function.

function countBs(text) {
    let count = 0;
    for (let index in text) {
        if (text[index] === 'B') {
            count++;
        }
    }
    return count;
}

function countChar(text, char) {
    let count = 0;
    for (let index in text) {
        if (text[index] === char) {
            count++;
        }
    }
    return count;
}


console.log(countBs("BBC"));
// → 2
console.log(countChar("kakkerlak", "k"));
// → 4