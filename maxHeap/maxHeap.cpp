#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class MaxHeap {
private:
    std::vector<T> heap;

    size_t parent(size_t i) const { return (i - 1) / 2; }
    size_t leftChild(size_t i) const { return 2 * i + 1; }
    size_t rightChild(size_t i) const { return 2 * i + 2; }

    void siftUp(size_t i) {
        while (i > 0 && heap[i] > heap[parent(i)]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void siftDown(size_t i) {
        size_t n = heap.size();
        while (true) {
            size_t left = leftChild(i);
            size_t right = rightChild(i);
            size_t largest = i;

            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;

            if (largest != i) {
                std::swap(heap[i], heap[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

public:
    MaxHeap() = default;

    MaxHeap(const std::vector<T>& data) {
        heap = data;
        if (!heap.empty()) {
            for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
                siftDown(i);
            }
        }
    }

    void push(const T& value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) siftDown(0);
    }

    const T& top() {
        if (heap.empty())
            std::cout <<"Heap is empty" << std::endl;
        return heap[0];
    }

    size_t size() const { return heap.size(); }
    bool empty() const { return heap.empty(); }
    void clear() { heap.clear(); }

    static bool isHeap(const std::vector<T>& data) {
        size_t n = data.size();
        for (size_t i = 0; i < n; ++i) {
            size_t left = 2 * i + 1;
            size_t right = 2 * i + 2;
            if (left < n && data[i] < data[left]) return false;
            if (right < n && data[i] < data[right]) return false;
        }
        return true;
    }
};

int main() {
    MaxHeap<int> heap;
    heap.push(10);
    heap.push(30);
    heap.push(20);
    heap.push(5);

    std::cout << "Top: " << heap.top() << "\n"; // 30

    heap.pop();
    std::cout << "Top after pop: " << heap.top() << "\n"; // 20

    std::cout << "Heap size: " << heap.size() << "\n"; // 3

    std::vector<int> arr = {50, 30, 20, 10, 5};
    std::cout << "Is heap? " << MaxHeap<int>::isHeap(arr) << "\n"; // 1 (true)

    return 0;
}
