// Write a program that creates a string that represents an 8×8 grid, using newline characters to separate lines. At each position of the grid there is either a space or a "#" character. The characters should form a chess board.

// Passing this string to console.log should show something like this:

//  # # # #
// # # # # 
//  # # # #
// # # # # 
//  # # # #
// # # # # 
//  # # # #
// # # # #
// When you have a program that generates this pattern, define a binding size = 8 and change the program so that it works for any size, outputting a grid of the given width and height.


const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function draw_chess_board(lines) {
    let odd_char = ' #';
    let even_char = '# ';

    let odd_line = "";
    let even_line = "";

    let i = 1;
    for (i = 1; i <= lines; i++) {
        odd_line += odd_char;
        even_line += even_char;
    }
    for (i = 1; i <= lines; i++) {
        if (i % 2 === 0) {
            console.log(even_line);
        } else {
            console.log(odd_line);
        }
    }
}


rl.question('Line of chess board? ', (answer) => {
  var lines = parseInt(answer);
  draw_chess_board(lines);

  rl.close();
});

