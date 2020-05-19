#include <vector>
#include <iostream>
#include "catch.hpp"
#include "vector.h"


TEST_CASE("at", "vector") {
  std::vector<int> sample;
  dsa::vector<int> verifiable;
  REQUIRE_THROWS(sample.at(0));
  REQUIRE_THROWS(verifiable.at(0));
  REQUIRE_THROWS(sample.at(42));
  REQUIRE_THROWS(verifiable.at(42));

  sample.push_back(1);
  verifiable.push_back(1);
  REQUIRE_THROWS(sample.at(1));
  REQUIRE_THROWS(verifiable.at(1));
  REQUIRE_THROWS(sample.at(42));
  REQUIRE_THROWS(verifiable.at(42));
}
