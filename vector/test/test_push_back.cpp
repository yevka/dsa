#include <vector>
#include <iostream>
#include "catch.hpp"
#include "vector.h"


TEST_CASE("push_back", "vector") {
  std::vector<int> sample;
  dsa::vector<int> verifiable;

  for(int i = 0; i < 5 ; ++i) {
    sample.push_back(i);
    verifiable.push_back(i);
  }

  const int* sample_data = sample.data();
  const int* verifiable_data = verifiable.data();

  REQUIRE(sample_data);
  REQUIRE(verifiable_data);
  for(int i = 0; i < 5 ; ++i) {
    REQUIRE(sample_data[i] == verifiable_data[i]);
    REQUIRE_NOTHROW(sample.at(i) == verifiable.at(i));
  }
}
