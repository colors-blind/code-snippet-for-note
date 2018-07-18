// Write a loop that makes seven calls to console.log to output the following triangle:

// #
// ##
// ###
// ####
// #####
// ######
// #######

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function draw_triangle(lines) {
  let line_list = [];
  let i;
  for (i = 0; i < lines; i++) {
    line_list.push("#");
    console.log(line_list.join(""));
  }
}


rl.question('Line of stars? ', (answer) => {
  var lines = parseInt(answer);
  draw_triangle(lines);

  rl.close();
});

