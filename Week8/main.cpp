// Simple array-based min heap in C++
// Index math for a 0-based array:
//   parent(i) = (i - 1) / 2
//   left(i)   = 2 * i + 1
//   right(i)  = 2 * i + 2

#include <iostream>
#include <stdexcept>
using namespace std;

class MinHeap {
private:
    int* data;      // the array that stores the heap
    int capacity;   // max number of elements
    int size;       // current number of elements

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    // Move element at index i UP until the heap property holds
    void heapifyUp(int i) {
        while (i > 0 && data[i] < data[parent(i)]) {
            swap(data[i], data[parent(i)]);
            i = parent(i);
        }
    }

    // Move element at index i DOWN until the heap property holds
    void heapifyDown(int i) {
        while (true) {
            int smallest = i;
            int l = left(i);
            int r = right(i);

            if (l < size && data[l] < data[smallest]) smallest = l;
            if (r < size && data[r] < data[smallest]) smallest = r;

            if (smallest == i) break;   // already in the right spot

            swap(data[i], data[smallest]);
            i = smallest;
        }
    }

public:
    MinHeap(int cap) : capacity(cap), size(0) {
        data = new int[capacity];
    }

    ~MinHeap() {
        delete[] data;
    }

    bool isEmpty() const { return size == 0; }
    bool isFull()  const { return size == capacity; }
    int  getSize() const { return size; }

    // Add a value: place it at the end, then bubble it up. O(log n)
    void insert(int value) {
        if (isFull()) throw overflow_error("Heap is full");
        data[size] = value;
        size++;
        heapifyUp(size - 1);
    }

    // Look at the smallest value without removing it. O(1)
    int peek() const {
        if (isEmpty()) throw underflow_error("Heap is empty");
        return data[0];
    }

    // Remove and return the smallest value. O(log n)
    int extractMin() {
        if (isEmpty()) throw underflow_error("Heap is empty");
        int minVal = data[0];
        data[0] = data[size - 1];   // move last element to the root
        size--;
        heapifyDown(0);             // sink it to its correct position
        return minVal;
    }

    // Print the raw array (level order)
    void print() const {
        cout << "[ ";
        for (int i = 0; i < size; i++) cout << data[i] << " ";
        cout << "]" << endl;
    }
};

int main() {
    MinHeap heap(10);

    int values[] = {42, 17, 8, 23, 5, 31, 12};
    for (int v : values) {
        heap.insert(v);
        cout << "Inserted " << v << " -> ";
        heap.print();
    }

    cout << "\nMin (peek): " << heap.peek() << endl;

    cout << "\nExtracting in order: ";
    while (!heap.isEmpty()) {
        cout << heap.extractMin() << " ";
    }
    cout << endl;

    return 0;
}