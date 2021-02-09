#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector>
#include <utility>


// quick find
class Graph1 {
public:
    explicit Graph1(int N)  : N_(N), id(N_, 0) {
        for(int i = 0; i < N_ ; ++i)
            id[i] = i;
    }

    bool insert(int p, int q) {
        if (!find(p, q)) {
            union_(p, q);
            return false;
        }
        return true;
    }

private:
    const int N_;
    std::vector<int> id;

private:
    bool find(int p, int q) {
        return id[p] == id[q];
    }

    void union_(int p, int q) {
        const int t = id[p];
        for (int i = 0; i < N_; ++i) {
            if (t == id[i]) {
                id[i] = id[q];
            }
        }
    }
};


// quick union
class Graph2 {
public:
    explicit Graph2(int N) : N_(N), id(N, 0) {
        for(int i = 0; i < N_ ; ++i)
            id[i] = i;
    }

    bool insert(int p, int q) {
        // quick union
        int root_p = root(p);
        int root_q = root(q);
        bool is_connected = (root_p == root_q);
        if (!is_connected) {
            id[root_p] = root_q;
            return false;
        }
        return true;
    }

private:
    const int N_;
    std::vector<int> id;

private:
    int root(int i) {
        while(i != id[i]) i = id[i];
        return i;
    }

    bool connected(int p, int q) {
        return root(p) == root(q);
    }

    void union_(int p, int q) {
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }
};


// weighted quick-union
class Graph3 {
public:
    explicit Graph3(int N) : N_(N), id(N, 0), sz(N, 0) {
        for(int i = 0; i < N_ ; ++i)
            id[i] = i;
    }

    bool insert(int p, int q) {
        // weighted quick-union
        if (!connected(p, q)) {
            union_(p, q);
            return false;
        }
        return true;
    }

private:
    const int N_;
    std::vector<int> id;
    std::vector<int> sz;

private:
    int root(int i) {
        while(i != id[i]) {
            i = id[i];
        }
        return i;
    }

    bool connected(int p, int q) {
        return root(p) == root(q);
    }

    void union_(int p, int q) {
        int i = root(p);
        int j = root(q);
        if (i == j) return;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
    }
};

// weighted quick-union + path compression
class Graph4 {
public:
    explicit Graph4(int N) : N_(N), id(N, 0), sz(N, 0) {
        for(int i = 0; i < N_ ; ++i)
            id[i] = i;
    }

    bool insert(int p, int q) {
        // weighted quick-union
        if (!connected(p, q)) {
            union_(p, q);
            return false;
        }
        return true;
    }

private:
    const int N_;
    std::vector<int> id;
    std::vector<int> sz;

private:
    int root(int i) {
        while(i != id[i]) {
            id[i] = id[id[i]]; // path compression
            i = id[i];
        }
        return i;
    }

    bool connected(int p, int q) {
        return root(p) == root(q);
    }

    void union_(int p, int q) {
        int i = root(p);
        int j = root(q);
        if (i == j) return;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
    }
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

    SECTION( "quick find" ) {
        Graph1 g(11);
        for(int i = 0; i < pairs.size() ; ++i) {
            const int p = pairs.at(i).first;
            const int q = pairs.at(i).second;
            REQUIRE(is_connect.at(i) == g.insert(p, q));
        }
    }

    SECTION( "quick union" ) {
        Graph2 g(11);
        for(int i = 0; i < pairs.size() ; ++i) {
            const int p = pairs.at(i).first;
            const int q = pairs.at(i).second;
            REQUIRE(is_connect.at(i) == g.insert(p, q));
        }
    }

    SECTION( "weighted quick-union" ) {
        Graph3 g(11);
        for(int i = 0; i < pairs.size() ; ++i) {
            const int p = pairs.at(i).first;
            const int q = pairs.at(i).second;
            REQUIRE(is_connect.at(i) == g.insert(p, q));
        }
    }


}





struct Friendship {
    int p;
    int q;
    int timestamp;
};


class SocialNetwork {
public:
    SocialNetwork() {}


    int is_complete(int p, int q) {

        return 0;
    }


private:
    /*
        log_file.txt: sort by time
        Vlad Oleg 12/19/2020
        John Tom 1/21/2021
    */
    std::vector<int> members_; // N members
    std::vector<Friendship> timestamps_; // M union
};



TEST_CASE("Interview Question: Union-Find", "sedgewick") {

    SECTION( "1. Social network connectivity" ) {
        /*
         * Social network connectivity. Given a social network
         * containing nn members and a log file containing n timestamps
         * at which times pairs of members formed friendships, design an
         * algorithm to determine the earliest time at which all members
         * are connected (i.e., every member is a friend of a friend of a
         * friend ... of a friend). Assume that the log file is sorted by
         * timestamp and that friendship is an equivalence relation.
         * The running time of your algorithm should be m log n or better
         * and use extra space proportional to n.
         * Note: these interview questions are ungraded and purely for
         * your own enrichment. To get a hint, submit a solution.
        */


    }

}
