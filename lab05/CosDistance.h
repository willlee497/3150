#pragma once

#include <vector>
#include <tuple>
#include <string>

// CosDistanceCalculator encapsulates the functionality to compute cosine distances
// between vectors of doubles in ℝ^k (with k ≥ 2). All vectors are assumed to start
// at the origin (0,0,…,0). The cosine similarity is defined as:
//     cosine_similarity = (a · b) / (|a| * |b|)
// and the cosine distance is given by:
//     cosine_distance = 1 - cosine_similarity
class CosDistanceCalculator {
public:
    // Constructs the calculator by reading vectors from a file.
    // Each line in the file should contain k space-separated double values.
    CosDistanceCalculator(const std::string& filename);

    // Alternative constructor that accepts vectors directly.
    CosDistanceCalculator(const std::vector<std::vector<double>>& vectors);

    // Computes cosine distance between two vectors.
    // Throws an exception if a zero vector is encountered.
    double computeCosineDistance(const std::vector<double>& a, const std::vector<double>& b) const;

    // Computes all pairwise cosine distances.
    // Returns a vector of tuples: (index1, index2, cosine_distance)
    std::vector<std::tuple<int, int, double>> computePairwiseDistances() const;

    // Returns the stored vectors.
    const std::vector<std::vector<double>>& getVectors() const;

private:
    std::vector<std::vector<double>> vectors_;
};

