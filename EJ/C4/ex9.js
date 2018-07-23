let string = JSON.stringify({
    squirrel: false,
    events: ["weekend"]
});

console.log(string, typeof(string));
// → {"squirrel":false,"events":["weekend"]} string
console.log(JSON.parse(string).events);
// → ["weekend"]