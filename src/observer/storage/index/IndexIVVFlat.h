// // IndexIVFFlat.h
// #ifndef INDEX_IVF_FLAT_H
// #define INDEX_IVF_FLAT_H

// #include <vector>
// #include <cmath>
// #include <algorithm>

// enum DistanceType {
//     L2_DISTANCE,
//     COSINE_DISTANCE,
//     INNER_PRODUCT
// };

// class IndexIVFFlat {
// public:
//     IndexIVFFlat(int dim, int lists, DistanceType distance_name);
//     ~IndexIVFFlat();

//     void train(size_t n, const float* vectors);
//     void add(size_t n, const float* vectors);
//     void search(size_t k, const float* query, size_t nprobe, size_t limit,
//                 float* distances, long* indices);

//     void setNprobe(size_t nprobe) { nprobe_ = nprobe; }

// private:
//     int dim_;
//     int lists_;
//     DistanceType distance_name_;
//     size_t nprobe_;
//     std::vector<std::vector<float>> centroids_;
//     std::vector<std::vector<std::vector<float>>> vectors_;

//     float computeDistance(const float* v1, const float* v2);
//     int findNearestCentroid(const float* vector);
// };

// #endif // INDEX_IVF_FLAT_H
