/* ------------------- Structure of Deck (Double - LinkedList) ----------------------------- */
function Card(value){
  this.value = value;   // value of the card
  this.next = null;     // next card (node)
  this.previous = null;     // previous card (node)
};


function Deck(){
  this._length = 0;           // number of cards in the deck
  this.top_card = null;       // top card of the deck
  this.bottom_card = null;    // bottom card of the deck
};


// adding card on the top of the deck
Deck.prototype.add = function(card){

  if(this._length){                   // length > 0 adding on the top
    this.top_card.next = card;
    card.previous = this.top_card;
    this.top_card = card;
  }else{                              // length = 0
    this.top_card = card;
    this.bottom_card = card;
  }

  this._length++;

};


// removing card from top of the deck
Deck.prototype.removeTop = function(){

  let card = this.top_card;

  // If only 1 card left in the deck
  if(this._length == 1){
    this.top_card = null;
    this.bottom_card = null;
    this._length = 0;

    return card;
  }

  this._length--;
  this.top_card = card.previous;
  this.top_card.next = null;

  card.previous = null;

  return card;  // returns removed card
};

// putting card on bottom of the deck
Deck.prototype.putBottom = function(){
  let newBottom = this.top_card;

  this.top_card = newBottom.previous;       // top pointing on 2nd card from top
  this.top_card.next = null;

  newBottom.previous = null;

  this.bottom_card.previous = newBottom;    // adding old top card on the bottom
  newBottom.next = this.bottom_card;
  this.bottom_card = newBottom;

};




/* -------------------------------- Structure of Shuffling ----------------------------------------- */

function Shuffling(){

  this.cards = [];                // all cards

  this.rounds = 0;                 // number of rounds

  this.handDeck = new Deck();     // holding deck

  this.tableDeck = new Deck();    // table deck

};


// initialization of cards and handDeck
Shuffling.prototype.initDecks = function(numberOfCards){

  for(let i=0; i<numberOfCards; i++){
    this.cards.push(new Card(i+1));    // values of cards are 1 -- numberOfCards for this program
    this.handDeck.add(this.cards[i]);
  }

};

// shuffling decks
Shuffling.prototype.shuffle = function(){

  while(this.handDeck._length != 2){
    let card = this.handDeck.removeTop();       // removing card form the handDeck
    this.tableDeck.add(card);                   // putting removed card on the tableDeck
    this.handDeck.putBottom();                  // putting top card of handDeck on the bottom of handDeck
  }

  // if only 2 cards left in the handDeck, putting them on the tableDeck
  this.tableDeck.add(this.handDeck.removeTop());
  this.tableDeck.add(this.handDeck.removeTop());

  this.rounds++;

  this.handDeck = this.tableDeck;    // taking cards from table
  this.tableDeck = new Deck();       // 0 cards on the table

};


// comparing initial and hand decks
Shuffling.prototype.compareDecks = function(){

  let top_card = this.handDeck.top_card;


  // values of card in array = [1,2,..,numberOfCards] and initial handDeck values were [numberOfCards,..,1]
  for(let i = this.cards.length-1; i>=0; i--){

    if(top_card.value !== this.cards[i].value)  {
      return false;
    }

    top_card = top_card.previous;

  }

  return true;
};


// function to start shuffling
Shuffling.prototype.start = function(){

  // If only 1 card in the deck ==> 1
  if(this.cards.length == 1){
    this.rounds++;
    return;
  }

  // shuffle -> rounds++ -> check -> shuffle ...
  do {
    this.shuffle();
  } while (!this.compareDecks());

};


module.exports = Shuffling;
