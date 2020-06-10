#ifndef _INTEGERARRAY_H_
#define _INTEGERARRAY_H_

#include<iostream>

using namespace std;

class IntegerArray {

private:
    int size;
    int current;
    int* arr;


    void resize(int newSize) {
        int* temp = new int[newSize];
        int minSize;

        if (newSize > size) {
            minSize = size;
        }
        else {
            minSize = newSize;
        }
        for (int i = 0; i < minSize; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        this->size = newSize;
        arr = temp;
    }

public:

    IntegerArray(int *arr, int size) {
        this->current = 0;
        this->size = size;
        this->arr = new int[this->size];
        for (int i = 0; i < this->size; i++) {
            this->arr[i] = arr[i];
        }
    }


    IntegerArray(IntegerArray& o) {			//Constructor Copia 
        this->size = o.size;
        this->arr = new int[this->size];
        for (int i = 0; i < this->size; i++)
            this->arr[i] = o.arr[i];
    }


    void insert(int elem, int pos) {
        resize(size + 1);

        for (int i = size - 1; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = elem;
    }

    void push_back(int elem) {
        resize(size + 1);
        this->arr[size - 1] = elem;
    }

    void remove_back() {
        resize(size - 1);
    }

    void remove(int pos) {
        if (pos >= 0 && pos < size) {
            for (int i = pos; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            resize(size - 1);
        }
    }

    int getSize() const {
        return this->size;
    }

    bool isEmpty() const {
        for (int i = 0; i < this->size; i++) {
            if (this->arr[i]) {
                return false; 
            }
        }
        return true;
    }

    bool isFull() const {
        for (int i = 0; i < this->size; i++) {
            if (!(this->arr[i])) { 
                return false;
            }
        }
        return true;
    }






    void print()const {
        cout << "[ ";
        for (int i = 0; i < this->size; i++)
            cout << arr[i] << " ";
        cout << "]";
    }

    ~IntegerArray() {
        delete[]arr;
    }




};

#endif 