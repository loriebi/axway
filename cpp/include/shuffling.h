//
//  Shuffling.h
//  Shuffling cards
//
//  Created by Levan Loria on 22/11/17.
//

#ifndef SHUFLLING_H
#define SHUFLLING_H


/* ------------------- Structure of Deck (Double - LinkedList) ----------------------------- */


struct Card{
  int value;              // value of the card
  Card *next;             // next card
  Card *previous;         // previous card
};

typedef struct Card Card;


struct Deck{
  int size;                       // size of deck
  Card* top_card;                 // card on the top of the deck
  Card* bottom_card;              // card on the bottom of the deck
  Deck();
  void addCardOnTop(Card*);       // adding card on the top of the deck
  Card* removeTopCard();          // removing card from top of the deck
  void putBottom();               // putting the top card on the bottom of the deck
};

typedef struct Deck Deck;


void addCardOnTop(Deck *deck, Card *card);        // adding card on the top of the deck
Card* removeTopCard();                            // removing top card from the deck
void putBottom();                                 // putting top card on the bottom


/* -------------------------------- class of Shuffling ----------------------------------------- */

class Shuffling
{
private:
  int nCards;                     // number of cards
  int rounds;                     // rounds
  Deck* handDeck;                 // hand deck
  Deck* tableDeck;                // table deck
  Card* cards;                    // array of all cards   (initial position of cards depends on this array indices)
public:
  Shuffling(int numberOfCards);
  void shuffle();                 // shuffle 1 round
  bool compareDecks();            // comparing initial and current hand positions
  void start();                   // starting shuffle

  int getRounds();                // get rounds
  Deck* getHandDeck();            // get handDeck
  Deck* getTableDeck();           // get tableDeck
  Card* getCards();               // get cards array
};


#endif
