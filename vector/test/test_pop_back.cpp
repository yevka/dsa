#include <vector>
#include <iostream>
#include "catch.hpp"
#include "vector.h"


TEST_CASE("pop_back", "vector") {
  std::vector<int> etalon;
  yevka::vector<int> verifiable;

  for (int i = 0; i < 5; ++i) {
    etalon.push_back(i);
    verifiable.push_back(i);
  }

  for (int i = 0; i < 4; ++i) {
    etalon.pop_back();
    verifiable.pop_back();
  }

  REQUIRE_NOTHROW(etalon.at(0) == verifiable.at(0));
  REQUIRE_THROWS(etalon.at(1));
  REQUIRE_THROWS(verifiable.at(1));
}
