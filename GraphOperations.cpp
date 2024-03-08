#include "GraphOperations.h"

using namespace std;
void GraphOperations::InitAdjacencyMatrices(istream& input, vector<vector<int>>& matrix) {
    int value;
    vector<int> row;
    while (input >> value) {
        row.push_back(value);
        if (row.size() == 6) { //all examples have 6 rows
            matrix.push_back(row);
            row.clear();
        }
    }
}

void GraphOperations::ExpensiveDigraphExactPaths(std::vector<std::vector<int>>& D_minus_1, vector<vector<int>>& D_0, vector<vector<int>>& D_1) {
    int n = D_0.size();

    //for D_0, every node can reach every other node at zero cost.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) D_0[i][j] = 0;
        }
    }

    //for D_1, every node can reach every other node at a cost of 1.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            D_1[i][j] = 1; 
        }
    }

    //for D_minus_1, every node can reach every other node at a cost of -1.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            D_minus_1[i][j] = -1; 
        }
    }
}
