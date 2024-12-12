#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <cstdlib>
#include "MinHeap.h"
#include <algorithm>

int main() {
    const int size = 10000000; //10 millions
    std::vector<int> data(size);
    MinHeap<int> heap;
    std::vector<int> vec;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    // Generate random data
    srand(time(0));
    for (int i = 0; i < size; i++) {
        data[i] = rand() % size; 
    }

    // Measure heap insertion time
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        heap.insert(data[i]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> heapInsertionTime = end - start;
    std::cout << "Heap Insertion Time: " << heapInsertionTime.count() << " s" << std::endl;
 
    // Measure heap sorting time
   
    start = std::chrono::high_resolution_clock::now();
    while (heap.size() > 0) {
         heap.deleteMin() ;
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::endl;
    std::chrono::duration<double> heapSortingTime = end - start;
    std::cout << "Heap Sorting Time: " << heapSortingTime.count() << " s" << std::endl;


    std::cout << "---------------------------------------------------------------------------------------------\n" << std::endl;


    // Measure vector insertion time
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        vec.push_back(data[i]);
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> vecInsertionTime = end - start;
    std::cout << "Vector Insertion Time: " << vecInsertionTime.count() << " s" << std::endl;
  

    // Measure vector sorting time
    start = std::chrono::high_resolution_clock::now();
    std::sort(vec.begin(), vec.end());
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> vecSortingTime = end - start;
    std::cout << "Vector Sorting Time: " << vecSortingTime.count() << " s" << std::endl;
    

    std::cout << "---------------------------------------------------------------------------------------------\n" << std::endl;


    // Measure priority queue insertion/sorting time
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        pq.push(data[i]);
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> pqInsertionTime = end - start;
    std::cout << "Priority Queue Insertion/Sorting Time: " << pqInsertionTime.count() << " s" << std::endl;

    

    return 0;
}
