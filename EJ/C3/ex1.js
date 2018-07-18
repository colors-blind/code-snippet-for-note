const makeNoise = function() {
    console.log("Pling!");
}

makeNoise();

const power = function(base, exponent) {
    let res = 1;
    for (let count = 0; count < exponent; count++) {
        res *= base;
    }
    return res;
}

console.log(power(2, 10));
// 1024
