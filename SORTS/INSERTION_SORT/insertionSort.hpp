#pragma once
#include <iostream>
#include <cassert>

template <class T>
class sort {
private:
    T* a;
    int N;
public:
    sort(int N) {
        assert(N > 0);
        a = new T[N];
        this->N = N;
    }

    ~sort() {
        delete[] a;
    }

    T& operator[](int index) {
        assert(index >= 0 && index < N);
        return *(a + index);
    }

    void insertion_sort() {
        int j = 1;
        int i;
        T tmp;
        while (j < N) {
            tmp = a[j];
            i = j - 1;
            while (i >= 0 && tmp < a[i]) {
                a[i + 1] = a[i];
                i--;
            }
            a[i + 1] = tmp;
            j++;
        }
    }

    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const sort<U>& arr);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const sort<T>& arr) {
    for (int i = 0; i < arr.N; ++i)
        os << arr.a[i] << " ";
    os << std::endl;
    return os;
}
