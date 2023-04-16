// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include<string>

template<typename T, int size>
class TPQueue {
     private:
        T* arr;
        int first, last, count;

     public:
        TPQueue() :first(0), last(0), count(0) {
            arr = new T[size];
        }
        ~TPQueue() {
            delete[]arr;
        }
        bool isEmpty()const {
            return 0 == count;
        }
        bool isFull()const {
            return 0 == size;
        }
        void push(const T& value) {
        if (isFull()) {
            throw std::string("Full!");
            } else {
            int n = last;
                T temp = arr[n % size];
                while (n > first && \
                arr[(n - 1) % size].prior < arr[n % size].prior) {
                temp = arr[n % size];
                    arr[n % size] = arr[(n - 1) % size];
                    arr[(n - 1) % size] = temp;
                    n--;
                    }
                ++count;
                ++last;
                }
            }
        const T& pop() {
            if (isEmpty()) {
                throw std::string("Empty!");
            } else {
                --count;
            return arr[first++ % size];
            }
        }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
