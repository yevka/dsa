#include <vector>
#include <iostream>
#include "catch.hpp"
#include "vector.h"


TEST_CASE("at", "vector") {
  std::vector<int> etalon;
  dsa::vector<int> verifiable;
  REQUIRE_THROWS(etalon.at(0));
  REQUIRE_THROWS(verifiable.at(0));
  REQUIRE_THROWS(etalon.at(42));
  REQUIRE_THROWS(verifiable.at(42));

  etalon.push_back(1);
  verifiable.push_back(1);
  REQUIRE_THROWS(etalon.at(1));
  REQUIRE_THROWS(verifiable.at(1));
  REQUIRE_THROWS(etalon.at(42));
  REQUIRE_THROWS(verifiable.at(42));
}
