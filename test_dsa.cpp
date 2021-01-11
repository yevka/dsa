#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "swap.h"

#include <vector>
#include <utility>


TEST_CASE("swap", "alg") {
  int a = 1;
  int b = 2;
  dsa::swap(a, b);
  REQUIRE(a == 2);
  REQUIRE(b == 1);
}


class Graph {
public:
    Graph() = default;

    std::vector<int> set(int p, int q) {
        std::vector<int> ret;
        if (find(p, q)) {

        } else {
            union_(p, q);
        }
        return ret;
    }

private:
    std::vector<std::vector<int>> pairs;

private:
    bool find(int p, int q) {
        return false;
    }

    void union_(int p, int q) {}
};


TEST_CASE("connectivity problem", "alg") {
    std::vector<std::pair<int, int>> pairs = {
            {3, 4},
            {4, 9},
            {8, 0},
            {8, 0},
            {2, 3},
            {5, 6},
            {2, 9},
            {5, 9},
            {7, 3},
            {4, 8},
            {5, 6},
            {0, 2},
            {6, 1}
    };

    const std::vector<std::vector<int>> sample = {
            {3, 4},
            {4, 9},
            {8, 0},
            {8, 0},
            {2, 3},
            {5, 6},
            {2, 3, 4, 9},
            {5, 9},
            {7, 3},
            {4, 8},
            {5, 6},
            {0, 8, 4, 3, 2},
            {6, 1}
    };

    Graph graph;
    for(int i = 0; i < pairs.size() ; ++i) {
        auto result = graph.set(pairs.at(i).first, pairs.at(i).second);
        REQUIRE(result == sample.at(i));
    }
}