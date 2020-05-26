#include <vector>
#include <climits>
#include "catch.hpp"
#include "vector.h"


TEST_CASE("reserve: exception length_error", "vector") {
  std::vector<int> sample;
  dsa::vector<int> verifiable;
  const size_t kN = std::numeric_limits<size_t>::max();
  REQUIRE_THROWS(sample.reserve(kN));
  REQUIRE_THROWS(verifiable.reserve(kN));
}

TEST_CASE("reserve: new_cap > capacity_", "vector") {
  std::vector<int> sample;
  dsa::vector<int> verifiable;

  REQUIRE(sample.size() == 0);
  REQUIRE(sample.capacity() == 0);
  REQUIRE(sample.empty());

  REQUIRE(verifiable.size() == 0);
  REQUIRE(verifiable.capacity() == 0);
  REQUIRE(verifiable.empty());

  const size_t kN = 1000;
  sample.reserve(kN);
  verifiable.reserve(kN);

  REQUIRE(sample.size() == 0);
  REQUIRE(sample.capacity() == kN);
  REQUIRE(sample.empty());

  REQUIRE(verifiable.size() == 0);
  REQUIRE(verifiable.capacity() == kN);
  REQUIRE(verifiable.empty());
}
