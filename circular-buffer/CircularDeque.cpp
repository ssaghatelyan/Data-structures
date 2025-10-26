#include <iostream>

template<typename T>
class CircularDeque {
    T *_data{};
    int _size = 0;
    int _capacity = 0;
    int head = 0;
    int rear = 0;

public:

    explicit CircularDeque(int n) : _capacity(n) {
        _data = static_cast<T *>(::operator new(n * sizeof(T)));
    }
    
    ~CircularDeque() {
        for (int i = 0; i < _size; ++i) {
            (*this)[i].~T();
        }
        ::operator delete(_data);
    }
    
    int size() const { return _size; }
    bool empty() const { return _size == 0; }
    bool full() const { return _size == _capacity; }
    
    void swap(CircularDeque& other) {
    std::swap(_data, other._data);
    std::swap(_size, other._size);
    std::swap(_capacity, other._capacity);
    std::swap(head, other.head);
    std::swap(rear, other.rear);
    }

    void push_back(const T &var) {
        if (_size + 1 > _capacity) {
            CircularDeque temp(2 * _size);
            for (int i = 0; i < _size; ++i) {
                temp.push_back(_data[i]);
            }
            this->swap(temp);
        }

        new(_data + rear) T(var);
        _size++;
        rear++;
        if(rear == _capacity) rear = 0;
    }

    void pop_back() {
        if(_size == 0) throw std::out_of_range("Deque is empty!");
        rear--;
        if (rear < 0) rear = _capacity - 1;
        _data[rear].~T();
        _size--;
    }

    void push_front(const T &var) {
        if (_size + 1 > _capacity) {
            CircularDeque temp(2 * _size);
            for (int i = 0; i < _size; ++i) {
                temp.push_back(_data[i]);
            }
            this->swap(temp);
        }

        head--;
        if(head < 0) head = _capacity -1;
        new(_data + head) T(var);
        _size++;
    }

    void pop_front() {
        if (_size == 0) throw std::out_of_range("Deque is empty!");
        _data[head].~T();
        head++;
        if (head == _capacity) head = 0;
        _size--;
    }

    T &operator[](size_t i) {
        if (i >= static_cast<size_t>(_size)) throw std::out_of_range("Index out of range");
        int index = head + static_cast<int>(i);
        if (index >= _capacity) index -= _capacity;
        return _data[index];    
    }
    
    const T &operator[](size_t i) const{
        if (i >= static_cast<size_t>(_size)) throw std::out_of_range("Index out of range");
        int index = head + static_cast<int>(i);
        if (index >= _capacity) index -= _capacity;
        return _data[index];    
    }
    
     T &front() {
        if (_size == 0) throw std::out_of_range("Deque is empty");
        return _data[head];
    }

    T &back() {
        if (_size == 0) throw std::out_of_range("Deque is empty");
        int index = rear - 1;
        if (index < 0) index = _capacity - 1;
        return _data[index];
    }
};

int main() {
    CircularDeque<int> dq(2);

    dq.push_back(1); // 1
    dq.push_back(2); // 1 2
    dq.push_front(0); // 0 1 2

    dq.pop_front(); // 1 2
    dq.pop_back(); // 1
    
    dq.push_back(3); // 1 3
    dq.push_back(4); // 1 3 4
    dq.push_back(5); // 1 3 4 5
    
    for (int i = 0; i < dq.size(); ++i)
        std::cout << dq[i] << ' ';
    std::cout << "\n";

    std::cout << "Front: " << dq.front() << "\n"; // 1
    std::cout << "Back: " << dq.back() << "\n"; // 5
}