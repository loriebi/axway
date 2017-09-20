let Shuffling = require('./lib/shuffling');


/* ------------------------ reading command line arguments --------------------------------- */
let args = process.argv;

if(args.length != 3){
  console.log("Program takes one integer argument!");
  return;
}
if(isNaN(process.argv[2])){
  console.log("Program takes one positive integer argument!");
  return;
}

let numberOfCards = parseFloat(process.argv[2]);

if(numberOfCards === undefined || !Number.isInteger(numberOfCards) || numberOfCards <= 0){
  console.log("Program takes one positive integer argument!");
  return;
}



/* ------------------------ shuffling cards --------------------------------- */

let shaffleCards = new Shuffling();       // Initialization of Shuffling object
shaffleCards.initDecks(numberOfCards);    // Initialization of decks
let rounds = shaffleCards.start();        // start shuffling


console.log(rounds);
