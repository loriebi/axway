//
//  Shuffle.cpp
//  Shuffling cards
//
//  Created by Levan Loria on 22/11/17.
//



#include <iostream>

#include "../include/shuffling.h"

using namespace std;


int main(int argc, const char **argv)
{

  int numberOfCards;

  /*-------------------------- checking command line arguments -------------------------*/
  if(argc != 2){
    cout<<"Program takes one integer argument!"<<endl;
    exit(1);
  }

  numberOfCards = atoi(argv[1]);
  if(numberOfCards<=0){
    cout<<"Program takes one integer argument!"<<endl;
    exit(1);
  }


  /*-------------------------- shuffling cards -------------------------*/
  Shuffling *shuffling = new Shuffling(numberOfCards);

  shuffling->start();

  cout<<shuffling->getRounds()<<endl;

  return 0;
}
