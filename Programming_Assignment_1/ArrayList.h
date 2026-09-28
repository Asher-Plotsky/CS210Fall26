//
// Created by asher on 9/15/2026.
//

#pragma once

#include <iostream>


template <typename T>
class ArrayList : public List<T> {
    public:
    void addFront(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList is full." << std::endl;
            return;
        }
        for (int i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }
        data_[0] = value;
        ++size_;
    }
    void addAnywhere(int position, T* value) override {
        if (position > size_ || position < 0) {
            std::cout << "Position out of bounds." << std::endl;
        }
        else {
            for (int i = size_; i > position; --i) {
                data_[i] = data_[i - 1];
            }
            data_[position] = value;
            ++size_;
        }
    }
    void deleteFront() override{
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
        }
        else {
            delete data_[0];
            for (int i = 0; i < size_ - 1; ++i) {
                data_[i] = data_[i + 1];
            }
            --size_;
        }
    }
    void deleteAnywhere(int position) override {
        if (size_ == 0) {
            std::cout << "ArrayList is empty." << std::endl;
        }
        if (position >= size_ || position < 0) {
            std::cout << "Position out of bounds" << std::endl;
        }
        else {
            delete data_[position];
            for (int i = position; i < size_ - 1; ++i) {
                data_[i] = data_[i + 1];
            }
            --size_;
        }
    }
    void reverse() override{
        for (int i = 0; i < size_ / 2; i++) {
            T* temp = data_[i];
            data_[i] = data_[size_ - i - 1];
            data_[size_ - i - 1] = temp;
        }
    }
    bool search(T* value) const override {
        for (int i = 0; i < size_; ++i) {
            if (*data_[i] == *value) return true;
        }
        return false;
    }
    void print() const override {
        for (int i = 0; i < size_; ++i) {
            std::cout << *data_[i] << ",";
        }
        std::cout << std::endl;
    }
    void concat(List<T>* other) override{
        ArrayList* newList = dynamic_cast<ArrayList*>(other);
        if (newList == nullptr){
            std::cout << "Not a list." << std::endl;
        }
        else {
            if (size_ + newList->size_ >= CAPACITY) {
                std::cout << "ArrayList would be full." << std::endl;
            }
            else {
                for (int i = size_, j = 0; i < size_ + newList->size_; ++i, j++)
                {
                    data_[i] = newList->data_[j];
                    newList->data_[j] = nullptr;
                }
                size_ += newList->size_;

            }
        }
    }
    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete data_[i];
        }
    }
private:
    static const int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_;
};
