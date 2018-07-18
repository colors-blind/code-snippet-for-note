// Define a recursive function isEven corresponding to this description. 
// The function should accept a single parameter (a positive, whole number) and return a Boolean.

function isEven(number) {
    let new_number = number >= 0 ? number: -number;
    if (new_number === 0) {
        return true;
    } else if (new_number === 1){
        return false;
    } else { 
        return isEven(new_number - 2);
    }
}

console.log(isEven(50));
// → true
console.log(isEven(75));
// → false
console.log(isEven(-1));
// → false