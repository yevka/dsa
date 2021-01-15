#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector>
#include <utility>


template<int N = 10>
class Graph1 {
public:
    Graph1() : id(N, 0) {
        for(int i = 0; i < N ; ++i)
            id[i] = i;
    }

    bool insert(int p, int q) {
        // quick find
        if (!find(p, q)) {
            union_(p, q);
            return false;
        }
        return true;
    }

private:
    std::vector<int> id;

private:
    bool find(int p, int q) {
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
};


template<int N = 10>
class Graph2 {
public:
    Graph2() : id(N, 0) {
        for(int i = 0; i < N ; ++i)
            id[i] = i;
    }

    bool insert(int p, int q) {
        // quick union
        int i = 0, j = 0;
        for(i = p; i != id.at(i) ; i = id[i]);
        for(j = q; j != id.at(j) ; j = id[j]);
        bool is_found = (i == j);
        if (!is_found)
            id[i] = j;
        return is_found;
    }

private:
    std::vector<int> id;
};




TEST_CASE("connectivity problem", "sedgewick") {
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

    const std::vector<int> is_connect = {
              false // 3 4
            , false // 4 9
            , false // 8 0
            , false // 2 3
            , false // 5 6
            , true  // 2 9
            , false // 5 9
            , false // 7 3
            , false // 4 8
            , true  // 5 6
            , true  // 0 2
            , false // 6 1
            , true  // 0 8
            , false // 10 1
    };

    SECTION( "quick_find" ) {
        Graph1<11> g;
        for(int i = 0; i < pairs.size() ; ++i) {
            const int p = pairs.at(i).first;
            const int q = pairs.at(i).second;
            std::cout << p << " " << q << std::endl;
            REQUIRE(is_connect.at(i) == g.insert(p, q));
        }
    }

    std::cout << std::endl;

    SECTION( "quick_union" ) {
        Graph2<11> g;
        for(int i = 0; i < pairs.size() ; ++i) {
            const int p = pairs.at(i).first;
            const int q = pairs.at(i).second;
            std::cout << p << " " << q << std::endl;
            REQUIRE(is_connect.at(i) == g.insert(p, q));
        }
    }

}