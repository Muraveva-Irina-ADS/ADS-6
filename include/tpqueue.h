// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T, int size>
class TPQueue {
 private:
    int count, last, first;
    T arr[100];

 public:
    TPQueue(): count(0), first(0), last(0) {}
    bool Empty() const {
        return count == 0;
    }
    bool Full() const {
        return count == size;
    }
    void push(const T& value) {
        if (!Full()) {
            count++;
            int c = first, i = last;
            while (c != last && arr[c].prior >= value.prior)
                c = (c+1) % size;
            while (i != c) {
                arr[i] = arr[(i-1) % size];
                i = (size + i-1) % size;
            }
            last = (last + 1) % size;
            arr[c] = value;
        } else
              throw std::string("FULL!");
    }
    const T & pop() {
        if (!Empty()) {
            count--;
            return arr[first++ % size];
        } else
            throw std::string("Empty!");        
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
