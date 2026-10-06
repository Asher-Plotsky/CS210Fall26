//
// Created by asher on 10/6/2026.
//

#pragma once

#include "Queue.h"
#include "List.h"

template <typename T>
class QueueList : public Queue<T> {
    public:
    void enqueue(T* value) override {
        list_.addBack(value);
    }
    void dequeue() override {
        list_.deleteFront();
    }
    T* front() const override {
        return list_.getFront();
    }
    bool isEmpty() const override {
        return list_.isEmpty();
    }
    int size() const override {
        return list_.size();
    }
    void print() const override {
        list_.print();
    }

    private:
    LinkedList<T> list_;
};