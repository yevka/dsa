#define CATCH_CONFIG_MAIN

#include <vector>
#include <algorithm>
#include <cstdint>
#include <random>
#include <ctime>

#include "catch.hpp"
#include "counting_sort.h"


TEST_CASE("counting_sort", "alg") {
  std::mt19937_64 gen(static_cast<size_t>(time(nullptr)));
  std::uniform_int_distribution<int> uid(0, 255);

  const size_t kN = 5;
  std::vector<int> v;
  v.reserve(kN);
  for(size_t i = 0; i < kN ; ++i) {
    int val = uid(gen);
    v.push_back(val);
  }

  auto etalon = v;
  std::sort(etalon.begin(), etalon.end());

  dsa::counting_sort(v.begin(), v.end());
  REQUIRE(etalon == v);
}
