#include "catch.hpp"
#include "binary_tree.h"

#include <string>


TEST_CASE("first add", "binary tree") {
  const int key = 1;
  const std::string key_value = "fuck u";

  binary_tree<int, std::string> bt;
  REQUIRE( bt.empty() );
  REQUIRE( bt.count() == 0 );

  bt.insert(key, key_value);
  REQUIRE( ! bt.empty() );
  REQUIRE( bt.count() == 1u );

  std::string* n = bt.find(key);
  REQUIRE(n != nullptr);
  REQUIRE(*n == key_value);

  bt.erase(key);
  REQUIRE( bt.empty() );
  REQUIRE( bt.count() == 0 );
}
