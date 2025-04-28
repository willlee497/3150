#include <iostream>
#include <stdexcept>  //for std::out_of_range

template <typename T>
class RawVector {
private:
    T* data;           //pointer to allocated memory
    size_t sz;         //curr num of elements in the vector
    size_t cap;        //curr capacity

    //helper function to dynamically increase memory
    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];  //new memory
        for (size_t i = 0; i < sz; ++i) {
            new_data[i] = data[i];  //copy old data to the new memory
        }
        delete[] data;  //free old mem.
        data = new_data;  //point to the new memory
        cap = new_capacity;  //update bit capacity
    }

public:
    //constructor #1
    RawVector() : data(nullptr), sz(0), cap(0) {}

    //destructor #2
    ~RawVector() {
        delete[] data;
    }

    //copy constructor #3
    RawVector(const RawVector& other) : sz(other.sz), cap(other.cap) {
        data = new T[cap];
        for (size_t i = 0; i < sz; ++i) {
            data[i] = other.data[i];
        }
    }

    //copy assignment operator #4
    RawVector& operator=(const RawVector& other) {
        if (this != &other) {  //check for self assignment
            delete[] data;     //free existing memory

            //allocate new memory and copy data
            sz = other.sz;
            cap = other.cap;
            data = new T[cap];

            for (size_t i = 0; i < sz; ++i) {
                data[i] = other.data[i];  //coping all elements
            }
        }
        return *this;  //return the current object
    }

    //move constructor (instead of copying twice and allocating more memory, efficient this way) #5
    RawVector(RawVector&& other) noexcept
        : data(other.data), sz(other.sz), cap(other.cap) {
        other.data = nullptr;
        other.sz = 0;
        other.cap = 0;
    }
 
    //move assignment operator (moving resources efficiently) #6
    RawVector& operator=(RawVector&& other) noexcept {
        if (this != &other) {  
            delete[] data;     

            //taking the resources
            data = other.data;
            sz = other.sz;
            cap = other.cap;

            //leave the other object in a valid state
            other.data = nullptr;
            other.sz = 0;
            other.cap = 0;
        }
        return *this;
    }

    //adds an element to end #7
    void push_back(const T& value) {
        if (sz == cap) {  //if false increase bit size
            resize(cap == 0 ? 1 : cap * 2);
        }
        data[sz++] = value;  //add the new element and increment size
    }

    //indexed access to elements #8
    T& operator[](size_t index) {
        if (index >= sz) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    //const indexed access to elements (reading access) 
    const T& operator[](size_t index) const {
        if (index >= sz) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    //returns the current num of elements #9
    size_t size() const {
        return sz;
    }

    //returns the current capacity #10
    size_t capacity() const {
        return cap;
    }
};

int main() {
    RawVector<int> vec;
    int num_elements;

    //testing code
    std::cout << "Enter the number of elements you want to add to the vector: ";
    std::cin >> num_elements;

    std::cout << "Enter " << num_elements << " integers:\n";
    for (int i = 0; i < num_elements; ++i) {
        int value;
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> value;
        vec.push_back(value);
    }

    //show curr vector elements
    std::cout << "\nInitial vector contents:\n";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "Element " << i << ": " << vec[i] << std::endl;
    }
    
    //add more?
    char add_more;
    std::cout << "\nWould you like to add more elements to the vector? (y/n): ";
    std::cin >> add_more;

    while (add_more == 'y' || add_more == 'Y') {
        int new_value;
        std::cout << "Enter the next value to add: ";
        std::cin >> new_value;
        vec.push_back(new_value);

        //update
        std::cout << "\nUpdated vector contents:\n";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << "Element " << i << ": " << vec[i] << std::endl;
        }

        std::cout << "\nWould you like to add more elements to the vector? (y/n): ";
        std::cin >> add_more;
    }

    //final
    std::cout << "\nFinal vector size: " << vec.size() << std::endl;
    std::cout << "Final vector capacity: " << vec.capacity() << std::endl;

    return 0;
}
