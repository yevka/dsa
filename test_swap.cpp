#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "swap.h"

TEST_CASE("swap", "alg") {
  int a = 1;
  int b = 2;
  dsa::swap(a, b);
  REQUIRE(a == 2);
  REQUIRE(b == 1);
}
