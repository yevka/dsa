#include <vector>
#include <iostream>
#include "catch.hpp"
#include "vector.h"


TEST_CASE("push_back", "vector") {
  std::vector<int> etalon;
  yevka::vector<int> verifiable;

  for(int i = 0; i < 5 ; ++i) {
    etalon.push_back(i);
    verifiable.push_back(i);
  }

  const int* etalon_data = etalon.data();
  const int* verifiable_data = verifiable.data();

  REQUIRE(etalon_data);
  REQUIRE(verifiable_data);
  for(int i = 0; i < 5 ; ++i) {
    REQUIRE(etalon_data[i] == verifiable_data[i]);
    REQUIRE_NOTHROW(etalon.at(i) == verifiable.at(i));
  }
}
