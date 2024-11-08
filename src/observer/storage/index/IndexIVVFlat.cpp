// // IndexIVFFlat.cpp
// #include "storage/index/IndexIVVFlat.h"
// #include <iostream>

// IndexIVFFlat::IndexIVFFlat(int dim, int lists, DistanceType distance_name)
//     : dim_(dim), lists_(lists), distance_name_(distance_name), nprobe_(1) {}

// IndexIVFFlat::~IndexIVFFlat() {}

// void IndexIVFFlat::train(size_t n, const float* vectors) {
//     // 简化版的训练过程，这里直接将前lists_个向量作为质心
//     centroids_.resize(lists_);
//     for (int i = 0; i < lists_; ++i) {
//         centroids_[i].resize(dim_);
//         std::copy(vectors + i * dim_, vectors + (i + 1) * dim_, centroids_[i].begin());
//     }
// }

// void IndexIVFFlat::add(size_t n, const float* vectors) {
//     vectors_.resize(lists_);
//     for (size_t i = 0; i < n; ++i) {
//         int centroid_index = findNearestCentroid(vectors + i * dim_);
//         vectors_[centroid_index].push_back(std::vector<float>(vectors + i * dim_, vectors + (i + 1) * dim_));
//     }
// }

// void IndexIVFFlat::search(size_t k, const float* query, size_t nprobe, size_t limit,
//                           float* distances, long* indices) {
//     std::vector<std::pair<float, long>> results;
//     for (int i = 0; i < std::min(nprobe_, centroids_.size()); ++i) {
//         for (const auto& vector : vectors_[i]) {
//             float distance = computeDistance(query, vector.data());
//             results.emplace_back(distance, i);
//             if (results.size() > limit) {
//                 std::sort(results.begin(), results.end());
//                 results.pop_back();
//             }
//         }
//     }

//     std::sort(results.begin(), results.end());
//     for (size_t i = 0; i < k && i < results.size(); ++i) {
//         distances[i] = results[i].first;
//         indices[i] = results[i].second;
//     }
// }

// float IndexIVFFlat::computeDistance(const float* v1, const float* v2) {
//     float distance = 0.0f;
//     switch (distance_name_) {
//         case L2_DISTANCE:
//             for (int i = 0; i < dim_; ++i) {
//                 distance += (v1[i] - v2[i]) * (v1[i] - v2[i]);
//             }
//             return distance;
//         case COSINE_DISTANCE:
//             float dot_product = 0.0f;
//             float norm_v1 = 0.0f;
//             float norm_v2 = 0.0f;
//             for (int i = 0; i < dim_; ++i) {
//                 dot_product += v1[i] * v2[i];
//                 norm_v1 += v1[i] * v1[i];
//                 norm_v2 += v2[i] * v2[i];
//             }
//             return 1.0f - dot_product / (std::sqrt(norm_v1) * std::sqrt(norm_v2));
//         case INNER_PRODUCT:
//             for (int i = 0; i < dim_; ++i) {
//                 distance += v1[i] * v2[i];
//             }
//             return distance;
//         default:
//             std::cerr << "Unknown distance type" << std::endl;
//             return -1.0f;
//     }
// }

// int IndexIVFFlat::findNearestCentroid(const float* vector) {
//     int nearest_index = -1;
//     float min_distance = std::numeric_limits<float>::max();
//     for (size_t i = 0; i < centroids_.size(); ++i) {
//         float distance = computeDistance(vector, centroids_[i].data());
//         if (distance < min_distance) {
//             min_distance = distance;
//             nearest_index = i;
//         }
//     }
//     return nearest_index;
// }