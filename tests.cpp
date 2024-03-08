#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "GraphOperations.h"
#include <sstream>
#include <vector>

using namespace std;
TEST_CASE("Test Matrix Initialization and Algorithm Functionality") {
    istringstream issD0(
        "0 2 2 2 2 2\n"
        "2 0 2 2 2 2\n"
        "2 2 0 2 2 2\n"
        "2 2 2 0 2 2\n"
        "2 2 2 2 0 2\n"
        "2 2 2 2 2 0\n"
    );

    istringstream issD1(
        "2 1 2 2 2 2\n"
        "2 2 1 2 2 2\n"
        "2 2 2 1 2 2\n"
        "2 2 2 2 1 2\n"
        "2 2 2 2 2 1\n"
        "1 2 2 2 2 2\n"
    );

    istringstream issDMinus1(
        "-1 2 2 2 2 2\n"
        "2 -1 2 2 2 2\n"
        "2 2 -1 2 2 2\n"
        "2 2 2 -1 2 2\n"
        "2 2 2 2 -1 2\n"
        "2 2 2 2 2 -1\n"
    );

    vector<vector<int>> D0, D1, DMinus1;
    
    GraphOperations::InitAdjacencyMatrices(issD0, D0);
    GraphOperations::InitAdjacencyMatrices(issD1, D1);
    GraphOperations::InitAdjacencyMatrices(issDMinus1, DMinus1);

    GraphOperations::ExpensiveDigraphExactPaths(DMinus1, D0, D1);

    for (const auto& row : D0) {
        for (const auto& element : row) { //check that each element is 0
            CHECK(element == 0);
        }
    }

    for (const auto& row : D1) {
        for (const auto& element : row) { //check that each element is 1
            CHECK(element == 1);
        }
    }

    for (const auto& row : DMinus1) {
        for (const auto& element : row) { //check that each element is -1
            CHECK(element == -1);
        }
    }
}
