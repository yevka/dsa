#include <vector>
#include <iostream>
#include "catch.hpp"
#include "vector.h"


TEST_CASE("clear", "vector") {
  std::vector<int> sample;
  dsa::vector<int> verifiable;

  sample.push_back(1);
  verifiable.push_back(1);

  sample.clear();
  verifiable.clear();

  REQUIRE(sample.capacity() == verifiable.capacity());
  REQUIRE(sample.size() == verifiable.size());

  REQUIRE(sample.data());
  REQUIRE(verifiable.data());
}
