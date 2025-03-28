# Lab Week 5: Cos-distance

**Name:** Phillip G. Bradford  
**Lab Name:** Cos-distance

## Overview
This project computes pairwise cosine distances for vectors of doubles in ℝ^k (with k ≥ 2).  
Each vector, assumed to start at the origin (0,0,…,0), is read from a file where each line represents one vector.  
The geometric dot product is used to calculate cosine similarity:
  - **Dot Product:** For vectors x and y, dot(x, y) = x₁y₁ + x₂y₂ + ... + xₖyₖ.
  - **Magnitude:** |x| = √(x₁² + x₂² + ... + xₖ²).
  - **Cosine Similarity:** (x · y) / (|x| * |y|).
  - **Cosine Distance:** 1 - cosine similarity.

The program computes all pairwise cosine distances and outputs the pairs in order from the closest (smallest distance) to the furthest.

## Application Architecture
- **Input Handling:** Reads vectors from a file; each line contains k space-separated double values.
- **Computation:**
  - A `CosDistanceCalculator` class encapsulates methods for calculating the dot product, magnitude, cosine similarity, and cosine distance.
  - **Strategy Pattern:** The cosine distance calculation is isolated in its own function, making the design extensible.
- **Output:** The application outputs sorted pairs of vectors with their computed cosine distances.
- **Testing:** Unit tests are implemented using the `doctest` framework.

## User Flow Diagram


## Files Included
- **Header File:** `CosDistance.h`
- **Source Files:** `CosDistance.cpp`, `main.cpp`
- **Unit Testing:** `test_cosdistance.cpp` (using `doctest`)
- **Doctest Library:** `doctest.h`

## Compilation & Execution
Compile the project with:
```sh
g++ -std=c++17 -o cos_distance main.cpp CosDistance.cpp && ./cos_distance <input_file>
