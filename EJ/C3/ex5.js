var count = 0;

function chicken() {
    count++;
    console.log("call chicken: " + count);
    return egg();
}

function egg() {
    count++;
    console.log('call egg: ' + count);
    return chicken();
}

console.log(chicken() + " came first.");
