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

template<int N = 10>
class Graph11 {
public:
    Graph11() : id(N,0) {
        for(int i = 0; i < N ; ++i)
            id[i] = i;
    }

    bool find(int p, int q) {
        // 0 1 2 3 4 5 6 7 8 9 - id
        // 0 1 2 3 4 5 6 7 8 9 - 1
        // 0 1 2 4 4 5 6 7 8 9 - 2
        return id[p] == id[q];
    }

    void union_(int p, int q) {
        const int t = id[p];
        for (int i = 0; i < N; i++) {
            if (t == id[i]) {
                id[i] = id[q];
            }
        }
    }

    bool insert(int p, int q) {
        if (!find(p, q)) { // 1 * N
            union_(p, q);
            return false;
        }
        return true;
    }
private:
    std::vector<int> id;
};

TEST_CASE("connectivity problem", "alg") {
    std::vector<std::pair<int, int>> pairs = {
            {3, 4},
            {4, 9},
            {8, 0},
            {2, 3},
            {5, 6},
            {2, 9},
            {5, 9},
            {7, 3},
            {4, 8},
            {5, 6},
            {0, 2},
            {6, 1},
            {0, 8},
            {10,1}
    };

    const std::vector<int> sample = {
             false // 3 4
            ,false // 4 9
            ,false // 8 0
            ,false // 2 3
            ,false // 5 6
            ,true  // 2 9
            ,false // 5 9
            ,false // 7 3
            ,false // 4 8
            ,true  // 5 6
            ,true  // 0 2
            ,false // 6 1
            ,true  // 0 8
            ,false // 10 1
    };

    Graph11<11> g;
    for(int i = 0; i < pairs.size() ; ++i) {
        int p = pairs.at(i).first;
        int q = pairs.at(i).second;
        std::cout << p << " " << q << std::endl;
        REQUIRE(sample.at(i) == g.insert(p, q));
    }
}