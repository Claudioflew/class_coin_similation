#include "Koichi_Nakata_Coin.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Comment 3: The principle that if there is a function in the class, we should use that. This constructor should use the member function, instead of tossing a coin by itself.
Coin::Coin() { toss(); }

void Coin::toss() {
  int num = rand();
  // Comment 4: If the random number is even, it is heads. And if it is odd, the coin is tails.
  if (num % 2 == 0) {
    sideUp = "heads";
  } else {
    sideUp = "tails";
  }
}

// Comment 5: We always want to protect the data member by const keyword if possible.
string Coin::getSideUp() const {
  return sideUp;
}