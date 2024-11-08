#include "storage/index/IndexIVVFlat.h"
IndexIVFFlat::IndexIVFFlat(int dim, int nlist, FuncOp metric)
    : dim_(dim), nlist_(nlist), nprobe_(1), metric_(metric) {
    centroids_.resize(nlist_, std::vector<float>(dim, 0.0f));
    invertedLists_.resize(nlist_);
}
IndexIVFFlat::~IndexIVFFlat() {}
void IndexIVFFlat::train(int n, const float* x) {
    // Simple k-means clustering to initialize centroids
    // This is a very naive implementation for demonstration purposes
    std::vector<std::vector<float>> data(n, std::vector<float>(dim_));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < dim_; ++j) {
            data[i][j] = x[i * dim_ + j];
        }
    }
    // Randomly initialize centroids
    for (int i = 0; i < nlist_; ++i) {
        centroids_[i] = data[rand() % n];
    }
    // Perform k-means clustering (simplified)
    for (int iter = 0; iter < 10; ++iter) {
        std::vector<std::vector<float>> new_centroids(nlist_, std::vector<float>(dim_, 0.0f));
        std::vector<int> counts(nlist_, 0);
        for (int i = 0; i < n; ++i) {
            int best_centroid = 0;
            float best_dist = std::numeric_limits<float>::max();
            for (int j = 0; j < nlist_; ++j) {
                float dist = distance(data[i], centroids_[j]);
                if (dist < best_dist) {
                    best_dist = dist;
                    best_centroid = j;
                }
            }
            for (int d = 0; d < dim_; ++d) {
                new_centroids[best_centroid][d] += data[i][d];
            }
            counts[best_centroid]++;
        }
        for (int j = 0; j < nlist_; ++j) {
            if (counts[j] > 0) {
                for (int d = 0; d < dim_; ++d) {
                    centroids_[j][d] /= counts[j];
                }
            }
        }
    }
}
void IndexIVFFlat::add(int n, const float* x) {
    std::vector<int> assignments(n);
    assign(n, x, assignments);
    for (int i = 0; i < n; ++i) {
        int list_id = assignments[i];
        std::vector<float> vec(dim_);
        for (int d = 0; d < dim_; ++d) {
            vec[d] = x[i * dim_ + d];
        }
        invertedLists_[list_id].push_back({i, vec});
    }
}
void IndexIVFFlat::search(int n, const float* x, int k, float* distances, int64_t* indices) {
    for (int i = 0; i < n; ++i) {
        std::vector<float> query(dim_);
        for (int d = 0; d < dim_; ++d) {
            query[d] = x[i * dim_ + d];
        }
        std::vector<std::pair<float, int64_t>> results;
        std::vector<int> nearest_lists(nprobe_);
        for (int j = 0; j < nprobe_; ++j) {
            nearest_lists[j] = j; // Simplified: should be the nearest clusters
        }
        for (int list_id : nearest_lists) {
            for (const auto& entry : invertedLists_[list_id]) {
                float dist = distance(query, entry.second);
                results.push_back({dist, entry.first});
            }
        }
        std::sort(results.begin(), results.end());
        for (int j = 0; j < k; ++j) {
            distances[i * k + j] = results[j].first;
            indices[i * k + j] = results[j].second;
        }
    }
}
float IndexIVFFlat::distance(const std::vector<float>& a, const std::vector<float>& b) const {
    if (metric_ == I2_DISTANCE) {
        float dist = 0.0f;
        for (size_t i = 0; i < a.size(); ++i) {
            dist += (a[i] - b[i]) * (a[i] - b[i]);
        }
        return dist;
    } else if (metric_ == COSINE_DISTANCE || metric_ == INNER_PRODUCT) {
        float dot_product = 0.0f;
        float norm_a = 0.0f;
        float norm_b = 0.0f;
        for (size_t i = 0; i < a.size(); ++i) {
            dot_product += a[i] * b[i];
            norm_a += a[i] * a[i];
            norm_b += b[i] * b[i];
        }
        if (metric_ == COSINE_DISTANCE) {
            return 1.0f - (dot_product / (std::sqrt(norm_a) * std::sqrt(norm_b)));
        } else {
            return -dot_product; // For inner product, smaller is better
        }
    }
    return 0.0f;
}
void IndexIVFFlat::assign(int n, const float* x, std::vector<int>& assignments) const {
    for (int i = 0; i < n; ++i) {
        std::vector<float> vec(dim_);
        for (int d = 0; d < dim_; ++d) {
            vec[d] = x[i * dim_ + d];
        }
        int best_centroid = 0;
        float best_dist = std::numeric_limits<float>::max();
        for (int j = 0; j < nlist_; ++j) {
            float dist = distance(vec, centroids_[j]);
            if (dist < best_dist) {
                best_dist = dist;
                best_centroid = j;
            }
        }
        assignments[i] = best_centroid;
    }
}