#include <vector>
#include <iostream>
#include "catch.hpp"
#include "vector.h"


TEST_CASE("pop_back", "vector") {
  std::vector<int> sample;
  dsa::vector<int> verifiable;

  for (int i = 0; i < 5; ++i) {
    sample.push_back(i);
    verifiable.push_back(i);
  }

  for (int i = 0; i < 4; ++i) {
    sample.pop_back();
    verifiable.pop_back();
  }

  REQUIRE_NOTHROW(sample.at(0) == verifiable.at(0));
  REQUIRE_THROWS(sample.at(1));
  REQUIRE_THROWS(verifiable.at(1));
}
