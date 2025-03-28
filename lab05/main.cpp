#include "CosDistance.h"
#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]) {
    std::string filename;
    if (argc < 2) {
        std::cout << "Enter the filename containing vectors: ";
        std::cin >> filename;
    } else {
        filename = argv[1];
    }
    
    try {
        CosDistanceCalculator calculator(filename);
        auto distances = calculator.computePairwiseDistances();
        
        std::cout << "Pairwise cosine distances (ordered by closeness):\n";
        for (const auto& pair : distances) {
            int idx1, idx2;
            double distance;
            std::tie(idx1, idx2, distance) = pair;
            std::cout << "Vector " << idx1 << " and Vector " << idx2 
                      << " => Distance: " << std::fixed << std::setprecision(4) 
                      << distance << "\n";
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
    
    return 0;
}
