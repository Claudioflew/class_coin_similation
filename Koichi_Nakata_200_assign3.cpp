#include "Koichi_Nakata_Coin.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

// Comment 6: In this program. class objects has to be passed by reference otherwise the sideUp value won't change.
void tossAll(Coin&, Coin&, Coin&);
float getTotalVal(Coin&, Coin&, Coin&);
void displayVal(int&, float, float);
void displayEndVal(float, float);

int main() {
  float playerVal = 0;
  float CPUVal = 0;

  // Comment 7: We want the outcome with the format of 0.00
  cout << fixed << setprecision(2);

  srand(time(NULL));

  Coin quarter = Coin();
  Coin dime = Coin();
  Coin nickel = Coin();

  cout << "Your starting balance: $" << playerVal << endl;
  cout << "The computer's starting balance: $" << CPUVal << endl;
  cout << endl;

  bool end = false; // Comment 8: Flag variable to end while loop
  int count = 1;

  while (!end) {
    // Comment 9: We don't want to write codes for tossing 3 times for 2 people i.e. tossing 6 times. So, we should make a function.
    tossAll(quarter, dime, nickel);
    // Comment 10: Also, we want to make the main function easier to examine, so this calculation also should be put in a function.
    playerVal += getTotalVal(quarter, dime, nickel);

    tossAll(quarter, dime, nickel);
    CPUVal += getTotalVal(quarter, dime, nickel);

    displayVal(count, playerVal, CPUVal);

    
    // Comment 11: This judging algorithm is not that complicated, but there are 3 patterns where the game is end i.e. either a player or CPU exceeds 1, or both exceed 1.
    if (playerVal >= 1 && CPUVal < 1) {
      displayEndVal(playerVal, CPUVal);
      cout << "Congratulations! You won." << endl;
      end = true;
    } else if (CPUVal >= 1 && playerVal < 1) {
      displayEndVal(playerVal, CPUVal);
      cout << "Sorry! The computer won." << endl;
      end = true;
    } else if (playerVal >= 1 && CPUVal >= 1) {
      if (playerVal == CPUVal) {
        displayEndVal(playerVal, CPUVal);
        cout << "Tie! Nobody wins." << endl;
      } else if (playerVal > CPUVal) {
        displayEndVal(playerVal, CPUVal);
        cout << "Sorry! The computer won." << endl;
      } else {
        displayEndVal(playerVal, CPUVal);
        cout << "Congratulations! You won." << endl;
      }
      end = true;
    }
    count++;
  }
}

void tossAll(Coin& qrt, Coin& dim, Coin& nic) {
  qrt.toss();
  dim.toss();
  nic.toss();
}

float getTotalVal(Coin& qrt, Coin& dim, Coin& nic) {
  float qrtVal = 0, dimVal = 0, nicVal = 0;
  if (qrt.getSideUp() == "heads")
    qrtVal = 0.25;
  if (dim.getSideUp() == "heads")
    dimVal = 0.10;
  if (nic.getSideUp() == "heads")
    nicVal = 0.05;
  return qrtVal + dimVal + nicVal;
}

void displayVal(int& count, float playerVal, float CPUVal) {
  cout << "Your balance after round " << count << " : $" << playerVal << endl;
  cout << "The computer's balance after round " << count << " : $" << CPUVal
       << endl;
  cout << endl;
}

void displayEndVal(float playerVal, float CPUVal) {
  cout << "Your ending balance: $" << playerVal << endl;
  cout << "The computer's ending balance: $" << CPUVal << endl;
  cout << endl;
}