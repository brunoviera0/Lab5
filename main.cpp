#include "GraphOperations.h"
#include <fstream>
#include <iostream>

using namespace std;
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
int main() {
    //files taken from examples provided
    ifstream file_D_minus_1("D_minus_1.txt");
    ifstream file_D_0("D_0.txt");
    ifstream file_D_1("D_1.txt");

    if (!file_D_minus_1 || !file_D_0 || !file_D_1) {
        cerr << "Error opening one or more files.\n";
        return 1;
    }

    vector<vector<int>> D_minus_1, D_0, D_1;

    GraphOperations::InitAdjacencyMatrices(file_D_minus_1, D_minus_1);
    GraphOperations::InitAdjacencyMatrices(file_D_0, D_0);
    GraphOperations::InitAdjacencyMatrices(file_D_1, D_1);

    file_D_minus_1.close();
    file_D_0.close();
    file_D_1.close();

    GraphOperations::ExpensiveDigraphExactPaths(D_minus_1, D_0, D_1);

    
    cout << "D(-1) Output:\n";
    printMatrix(D_minus_1);

    cout << "D(0) Output:\n";
    printMatrix(D_0);

    cout << "D(1) Output:\n";
    printMatrix(D_1);

    return 0;
}
