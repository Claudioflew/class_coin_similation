#include <string>
// Comment 1: We want to include "include guard" although this is not a complicated project.
#ifndef KOICHI_NAKATA_COIN
#define KOICHI_NAKATA_COIN

class Coin {
public:
  Coin();
  void toss();
  // Comment 2: We need const keyword in prototype as well.
  std::string getSideUp() const;

private:
  std::string sideUp;
};



#endif