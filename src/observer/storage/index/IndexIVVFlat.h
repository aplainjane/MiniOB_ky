#ifndef INDEX_IVF_FLAT_H
#define INDEX_IVF_FLAT_H
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include "storage/index/index.h"

class IndexIVFFlat {
public:
    IndexIVFFlat(int dim, int nlist, FuncOp metric);
    ~IndexIVFFlat();
    void train(int n, const float* x);
    void add(int n, const float* x);
    void search(int n, const float* x, int k, float* distances, int64_t* indices);
    void setNProbe(int nprobe) {
        nprobe_ = nprobe;
    }
private:
    int dim_;
    int nlist_;
    int nprobe_;
    FuncOp metric_;
    std::vector<std::vector<float>> centroids_;
    std::vector<std::vector<std::pair<int64_t, std::vector<float>>>> invertedLists_;
    float distance(const std::vector<float>& a, const std::vector<float>& b) const;
    void assign(int n, const float* x, std::vector<int>& assignements) const;
};
#endif // INDEX_IVF_FLAT_H