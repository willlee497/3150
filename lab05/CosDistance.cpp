#include "CosDistance.h"
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <algorithm>

// Helper function: computes the dot product of two vectors.
// Geometric intuition: The dot product measures the "projection" of one vector onto another.
static double dotProduct(const std::vector<double>& a, const std::vector<double>& b) {
    double dot = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        dot += a[i] * b[i];
    }
    return dot;
}

// Helper function: computes the magnitude (norm) of a vector.
// Geometric intuition: The magnitude of vector x = (x₁, x₂, ..., xₖ) is computed as:
//     |x| = sqrt(x₁² + x₂² + ... + xₖ²)
static double norm(const std::vector<double>& a) {
    return std::sqrt(dotProduct(a, a));
}

// Constructor: Reads vectors from a file. Each line should represent a vector.
CosDistanceCalculator::CosDistanceCalculator(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines.
        std::istringstream iss(line);
        std::vector<double> vec;
        double value;
        while (iss >> value) {
            vec.push_back(value);
        }
        if (!vec.empty()) {
            vectors_.push_back(vec);
        }
    }
    file.close();

    // Ensure all vectors have the same dimension.
    if (!vectors_.empty()) {
        size_t expectedSize = vectors_[0].size();
        for (const auto& vec : vectors_) {
            if (vec.size() != expectedSize) {
                throw std::runtime_error("Vectors have inconsistent dimensions.");
            }
        }
    }
}

// Constructor that accepts vectors directly.
CosDistanceCalculator::CosDistanceCalculator(const std::vector<std::vector<double>>& vectors)
    : vectors_(vectors)
{
    if (!vectors_.empty()) {
        size_t expectedSize = vectors_[0].size();
        for (const auto& vec : vectors_) {
            if (vec.size() != expectedSize) {
                throw std::runtime_error("Vectors have inconsistent dimensions.");
            }
        }
    }
}

double CosDistanceCalculator::computeCosineDistance(const std::vector<double>& a, const std::vector<double>& b) const {
    double dot = dotProduct(a, b);
    double normA = norm(a);
    double normB = norm(b);
    if (normA == 0 || normB == 0) {
        throw std::runtime_error("Zero vector encountered.");
    }
    // Cosine similarity: (a · b) / (|a| * |b|)
    double cosineSimilarity = dot / (normA * normB);
    // Cosine distance is defined as 1 - cosine similarity.
    return 1.0 - cosineSimilarity;
}

std::vector<std::tuple<int, int, double>> CosDistanceCalculator::computePairwiseDistances() const {
    std::vector<std::tuple<int, int, double>> distances;
    int n = vectors_.size();
    // Compute distances for every unique pair (i, j) with i < j.
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double distance = computeCosineDistance(vectors_[i], vectors_[j]);
            distances.push_back(std::make_tuple(i, j, distance));
        }
    }
    // Sort by cosine distance (ascending order: closest vectors first).
    std::sort(distances.begin(), distances.end(), [](const auto& a, const auto& b) {
        return std::get<2>(a) < std::get<2>(b);
    });
    return distances;
}

const std::vector<std::vector<double>>& CosDistanceCalculator::getVectors() const {
    return vectors_;
}
