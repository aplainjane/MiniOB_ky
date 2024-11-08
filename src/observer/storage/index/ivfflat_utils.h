#ifndef INDEX_IVFFLAT_H
#define INDEX_IVFFLAT_H

#include <vector>
#include <iostream>
#include <cmath>
#include <limits>

class IndexFlatL2 {
public:
    IndexFlatL2(int dim) : dim_(dim) {}
    void add(int n, const float* x);
    void search(int n, const float* x, int k, float* distances, long* labels);
    
private:
    int dim_;
    std::vector<float> data_;
};

class IndexIVFFlat {
public:
    IndexIVFFlat(IndexFlatL2* quantizer, int dim, int nlist, int metric);
    void train(int n, const float* x);
    void add(int n, const float* x);
    void search(int n, const float* x, int k, float* distances, long* labels);
    
    int nprobe; // Number of clusters to probe during search

private:
    IndexFlatL2* quantizer_;
    int dim_;
    int nlist_;
    int metric_;
    std::vector<std::vector<float>> centroids_;
    std::vector<std::vector<int>> inverted_lists_;
};

#endif // INDEX_IVFFLAT_H