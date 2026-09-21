class DynamicArray {
public:
    int* _arr;
    size_t _size;
    size_t _capacity;
    DynamicArray(int capacity) {
        this->_capacity = capacity;
        _size = 0;
        _arr = new int[_capacity];
    }

    int get(int i) {
        return _arr[i];
    }

    void set(int i, int n) {
        _arr[i] = n;
    }

    void pushback(int n) {
        if(_size == _capacity){
            resize();
        }
        _arr[_size] = n;
        _size++;
    }

    int popback() {
    if(_size != 0) --_size;
    return _arr[_size];
}

    void resize() {
        int new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
        int* new_arr = new int[new_capacity];

        for(int i=0; i < _size;i++){
            new_arr[i] = _arr[i];
        }

        delete[] _arr;
        _arr = new_arr;
        _capacity = new_capacity;
    }

    int getSize() {
        return _size;
    }

    int getCapacity() {
        return _capacity;
    }
};
