#pragma once
// MinHeap.h

#include <vector>
#include <iostream>

template <typename T>
class MinHeap {
public:
    void insert(T data);
    T deleteMin();
    size_t size() const;
    void display() const;

private:
    std::vector<T> heap;

    void swap(T* a, T* b);
    void adjustHeap(int currentIndex);
};

template <typename T>
void MinHeap<T>::insert(T data) {
    heap.push_back(data);
    int i = heap.size() - 1;
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

template <typename T>
T MinHeap<T>::deleteMin() {
    if (heap.empty()) throw std::underflow_error("Heap is empty");
    T minElement = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    adjustHeap(0);
    return minElement;
}

template <typename T>
size_t MinHeap<T>::size() const {
    return heap.size();
}

template <typename T>
void MinHeap<T>::display() const {
    for (const auto& elem : heap) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void MinHeap<T>::swap(T* a, T* b) {
    T aux = *a;
    *a = *b;
    *b = aux;
}

template <typename T>
void MinHeap<T>::adjustHeap(int currentIndex) {
    int size = heap.size();
    int leftChild = 2 * currentIndex + 1;
    int rightChild = 2 * currentIndex + 2;
    int smallest = currentIndex;
    if (leftChild < size && heap[leftChild] < heap[smallest]) smallest = leftChild;
    if (rightChild < size && heap[rightChild] < heap[smallest]) smallest = rightChild;
    if (smallest != currentIndex) {
        swap(&heap[currentIndex], &heap[smallest]);
        adjustHeap(smallest);
    }
}