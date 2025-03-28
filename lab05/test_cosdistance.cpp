#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "CosDistance.h"
#include <vector>
#include <tuple>
#include <cmath>

TEST_CASE("Test cosine distance computation") {
    // Define two simple vectors.
    std::vector<double> v1 = {1.0, 0.0};
    std::vector<double> v2 = {0.0, 1.0};
    std::vector<double> v3 = {1.0, 1.0};

    // Create a calculator instance with these vectors.
    std::vector<std::vector<double>> vectors = {v1, v2, v3};
    CosDistanceCalculator calculator(vectors);

    // For orthogonal vectors (v1 and v2), cosine similarity = 0, hence distance = 1.
    double d1 = calculator.computeCosineDistance(v1, v2);
    CHECK(std::abs(d1 - 1.0) < 1e-6);

    // For v1 and v3: cosine similarity = (1*1 + 0*1) / (1 * sqrt(2)) = 1/sqrt(2),
    // so the distance = 1 - 1/sqrt(2).
    double expected = 1.0 - 1.0/std::sqrt(2.0);
    double d2 = calculator.computeCosineDistance(v1, v3);
    CHECK(std::abs(d2 - expected) < 1e-6);
}

TEST_CASE("Test pairwise distance ordering") {
    // Create three vectors.
    std::vector<double> v1 = {1.0, 0.0, 0.0};
    std::vector<double> v2 = {0.0, 1.0, 0.0};
    std::vector<double> v3 = {1.0, 1.0, 0.0};
    std::vector<std::vector<double>> vectors = {v1, v2, v3};

    CosDistanceCalculator calculator(vectors);
    auto distances = calculator.computePairwiseDistances();

    // There should be 3 pairs: (0,1), (0,2), (1,2)
    CHECK(distances.size() == 3);

    // Verify that the distances are sorted in ascending order.
    for (size_t i = 1; i < distances.size(); ++i) {
        CHECK(std::get<2>(distances[i]) >= std::get<2>(distances[i-1]));
    }
}
