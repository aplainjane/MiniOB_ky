#include "ivfflat_utils.h"

// IndexFlatL2 Implementation
void IndexFlatL2::add(int n, const float* x) {
    data_.insert(data_.end(), x, x + n * dim_);
}

void IndexFlatL2::search(int n, const float* x, int k, float* distances, long* labels) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            distances[i * k + j] = std::numeric_limits<float>::max();
            labels[i * k + j] = -1;
        }
    }
    // A simple brute-force search (placeholder)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < data_.size() / dim_; ++j) {
            float dist = 0;
            for (int d = 0; d < dim_; ++d) {
                float diff = x[i * dim_ + d] - data_[j * dim_ + d];
                dist += diff * diff;
            }
            for (int j_k = 0; j_k < k; ++j_k) {
                if (dist < distances[i * k + j_k]) {
                    for (int m = k - 1; m > j_k; --m) {
                        distances[i * k + m] = distances[i * k + m - 1];
                        labels[i * k + m] = labels[i * k + m - 1];
                    }
                    distances[i * k + j_k] = dist;
                    labels[i * k + j_k] = j;
                    break;
                }
            }
        }
    }
}

// IndexIVFFlat Implementation
IndexIVFFlat::IndexIVFFlat(IndexFlatL2* quantizer, int dim, int nlist, int metric)
    : quantizer_(quantizer), dim_(dim), nlist_(nlist), metric_(metric), nprobe(1) {
    centroids_.resize(nlist_);
    inverted_lists_.resize(nlist_);
}

void IndexIVFFlat::train(int n, const float* x) {
    // Placeholder: Randomly select centroids for training
    for (int i = 0; i < nlist_; ++i) {
        centroids_[i].resize(dim_);
        for (int d = 0; d < dim_; ++d) {
            centroids_[i][d] = x[(i % n) * dim_ + d]; // Simple assignment
        }
    }
}

void IndexIVFFlat::add(int n, const float* x) {
    // Placeholder: Assign vectors to their nearest centroid
    for (int i = 0; i < n; ++i) {
        int nearest_centroid = 0;
        float min_dist = std::numeric_limits<float>::max();
        for (int j = 0; j < nlist_; ++j) {
            float dist = 0;
            for (int d = 0; d < dim_; ++d) {
                float diff = x[i * dim_ + d] - centroids_[j][d];
                dist += diff * diff;
            }
            if (dist < min_dist) {
                min_dist = dist;
                nearest_centroid = j;
            }
        }
        inverted_lists_[nearest_centroid].push_back(i);
        quantizer_->add(1, x + i * dim_); // Add to the quantizer
    }
}

void IndexIVFFlat::search(int n, const float* x, int k, float* distances, long* labels) {
    // Simplified search over the inverted lists
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < nlist_; ++j) {
            if (inverted_lists_[j].empty()) continue;
            float dist = 0;
            for (int d = 0; d < dim_; ++d) {
                float diff = x[i * dim_ + d] - centroids_[j][d];
                dist += diff * diff;
            }
            if (dist < distances[i * k]) {
                // Update search results
                distances[i * k] = dist;
                labels[i * k] = j; // This is a simple example
            }
        }
    }
}