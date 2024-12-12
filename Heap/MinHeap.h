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
    // Check if the heap is empty, throw an exception if true
    if (heap.empty()) throw std::underflow_error("Heap is empty");
    
    // Store the minimum element (the root of the heap) to return later
    T minElement = heap[0];
    
    // Replace the root (min element) with the last element in the heap
    heap[0] = heap.back();
    
    // Remove the last element from the heap (since it's now at the root)
    heap.pop_back();
    
    // Restore the Min-Heap property by adjusting the heap starting from the root
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
    // Get the size of the heap
    int size = heap.size();
    
    // Calculate the indices of the left and right children
    int leftChild = 2 * currentIndex + 1;
    int rightChild = 2 * currentIndex + 2;
    
    // Initialize 'min' as the current index (assuming the current node is the smallest)
    int min = currentIndex;
    
    // If the left child exists and is smaller than the current node, update 'min'
    if (leftChild < size && heap[leftChild] < heap[min]) 
        min = leftChild;
    
    // If the right child exists and is smaller than the current 'min', update 'min'
    if (rightChild < size && heap[rightChild] < heap[min]) 
        min = rightChild;
    
    // If the smallest element is not the current node, swap and recursively adjust the heap
    if (min != currentIndex) {
        swap(&heap[currentIndex], &heap[min]); // Swap current node with the smallest child
        adjustHeap(min);  // Recursively adjust the subtree rooted at 'min'
    }
}

