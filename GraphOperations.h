#ifndef GRAPHOPERATIONS_H
#define GRAPHOPERATIONS_H

#include <vector>
#include <istream>

class GraphOperations {
public:
    static void InitAdjacencyMatrices(std::istream& input, std::vector<std::vector<int>>& matrix);
    static void ExpensiveDigraphExactPaths(std::vector<std::vector<int>>& D_minus_1,
                                           std::vector<std::vector<int>>& D_0,
                                           std::vector<std::vector<int>>& D_1);
};

#endif
