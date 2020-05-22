#include <vector>
#include <iostream>
#include "catch.hpp"
#include "vector.h"


static
dsa::vector<int> magic(dsa::vector<int> v) {
  dsa::vector<int> vv;
  return vv;
}

static
dsa::vector<int> magic() {
  dsa::vector<int> vv;
  return vv;
}


TEST_CASE("rule3", "vector") {
  dsa::vector<int> sample1;
  dsa::vector<int> sample2 = sample1;
  dsa::vector<int> sample3;
  sample3 = sample2;
  auto sample4 = magic(sample3);
  const auto sample5 = sample4;

  const auto& sample6 = magic();
  //auto& sample7 = magic();

  const auto sample8 = magic(sample3);
  auto sample9 = sample8;
}
