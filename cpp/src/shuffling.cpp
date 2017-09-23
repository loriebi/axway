//
//  Shuffling.cpp
//  Shuffling cards
//
//  Created by Levan Loria on 22/11/17.
//

#include <iostream>

#include "../include/shuffling.h"

using namespace std;
/* -------------------------------- Deck structure ----------------------------------------- */


Deck::Deck(){
  size = 0;
  top_card = NULL;
  bottom_card = NULL;
}

// adding card on the top of the deck
void Deck::addCardOnTop(Card* card){
  size++;

  if(top_card == NULL){
    bottom_card = top_card = card;
  }else{

    top_card->next = card;
    card->previous = top_card;
    top_card = card;

  }
}

// removing top card of the deck
Card* Deck::removeTopCard(){

  Card *card = top_card;

  // If only 1 card left in the deck
  if(size == 1){
    top_card = NULL;
    bottom_card = NULL;
    size = 0;

    return card;
  }


  // else removing top card from deck
  size--;
  top_card = card->previous;
  top_card->next = NULL;

  card->previous = NULL;     // removing link from old deck

  return card;    //returns old top card
}

// putting top card  on the bottom
void Deck::putBottom(){

  // new bottom card
  Card* card = top_card;

  // top pointing on 2nd card from top
  top_card = card->previous;
  top_card->next = NULL;

  card->previous = NULL;

  // adding old top card on the bottom
  bottom_card->previous = card;
  card->next = bottom_card;
  bottom_card = card;

}


/* -------------------------------- Shuffling class ----------------------------------------- */

// initialization of Shuffling object
Shuffling::Shuffling(int numberOfCards){

  nCards = numberOfCards;
  rounds = 0;

  handDeck = new Deck();
  tableDeck = new Deck();

  cards = new Card[numberOfCards];
  // Initialization of cards with values [1 -- numberOfCards]
  for(int i=0;i<numberOfCards;i++){
    cards[i].value = (i+1);
    cards[i].next = NULL;
    cards[i].previous = NULL;

    handDeck->addCardOnTop(cards+i);
  }
}

// shuffle 1 round
void Shuffling::shuffle(){

  while(handDeck->size != 2){
    Card* card = handDeck->removeTopCard();            // removing card form the handDeck
    tableDeck->addCardOnTop(card);                     // putting removed card on the tableDeck
    handDeck->putBottom();                             // putting top card of handDeck on the bottom of handDeck

  }



  // if only 2 cards left in the handDeck, putting them on the tableDeck
  tableDeck->addCardOnTop(handDeck->removeTopCard());
  tableDeck->addCardOnTop(handDeck->removeTopCard());

  rounds++;

  handDeck = tableDeck;         // taking cards from table
  tableDeck = new Deck();       // 0 cards on the table
}

// compares initial and current handDeck
bool Shuffling::compareDecks(){


  Card* top = handDeck->top_card;

  // values of card in array = [1,2,..,nCards] and initial handDeck values were [nCards,..,1]
  for(int i=nCards-1; i>=0; i--){

    if(top->value != cards[i].value){
      return false;
    }

    top = top->previous;

  }

  return true;
}


// starts shuffling
void Shuffling::start(){

  // If only 1 card in the deck ==> 1
  if(nCards == 1){
    rounds++;
    return;
  }

  // shuffle -> rounds++ -> check -> shuffle ...
  do {
    shuffle();
  } while (!compareDecks());

}


// Shuffling class getters
int Shuffling::getRounds(){
  return rounds;
}

Deck* Shuffling::getHandDeck(){
  return handDeck;
}

Deck* Shuffling::getTableDeck(){
  return tableDeck;
}

Card* Shuffling::getCards(){
  return cards;
}
