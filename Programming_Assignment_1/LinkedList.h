//
// Created by asher on 9/17/2026.
//

#pragma once
#include "Node.h"



template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr) {}
    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
        size_++;
    }
    void addAnywhere(int position, T* value) override {
        if (position > size_ || position < 0){
            std::cout << "Position out of bounds." << std::endl;
        }
        else
        {
            Node<T>* fresh = new Node<T>(value);
            Node<T>* current = head_;
            if (position == 0) {
                fresh->next = head_;
                head_ = fresh;
            }
            else if (position == size_) {
                while (current->next != nullptr){
                    current = current->next;
                }
                current->next = fresh;
            }
            else{
                int currentPosition = 0;
                while (currentPosition < position - 1){
                    currentPosition++;
                    current = current->next;
                }
                fresh->next = current->next;
                current->next = fresh;
            }
            size_++;
        }
    }
    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        size_--;
        Node<T>* doomed = head_;
        head_ = head_->next;
        delete doomed->data;
        delete doomed;
    }
    void deleteAnywhere(int position) override{
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
        }
        else if (position >= size_ || position < 0) {
            std::cout << "Position out of bounds." << std::endl;
        }
        else {
            Node<T>* doomed = head_;
            if (position == 0){
                head_ = head_->next;
                delete doomed->data;
                delete doomed;
            }
            else{
                Node<T>* current = head_;
                int currentPosition = 0;
                while (currentPosition < position - 1)
                {
                    currentPosition++;
                    current = current->next;
                }
                doomed = current->next;
                current->next = current->next->next;
                delete doomed->data;
                delete doomed;
            }
            size_--;
        }
    }
    void reverse() override {
        Node<T>* current = head_;
        Node<T>* previous = nullptr;
        while (current != nullptr) {
            Node<T>* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head_ = previous;
    }
    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) return true;
            current = current->next;
        }
        return false;
    }
    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }
    void concat(List<T>* other) override{
        LinkedList* newList = dynamic_cast<LinkedList*>(other);
        if (head_ == nullptr) {
            head_ = newList->head_;
        }
        if (newList == nullptr){
            std::cout << "Not a List." << std::endl;
        }
        else{
            Node<T>* current = head_;
            while (current->next != nullptr){
                current = current->next;
            }
            current->next = newList->head_;
            size_ += newList->size_;
            newList->size_ = 0;
            newList->head_ = nullptr;
        }
    }
    void drawRound() override{
        Node<T>* current = head_;
        while (current != nullptr) {
            if constexpr (std::is_same_v<T,Player>) {
                current->data->draw();
            }
            else {
                return;
            }
            current = current->next;
        }
    }
    void playRound() override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if constexpr (std::is_same_v<T,Player>) {
                current->data->play();
            }
            else {
                return;
            }
            current = current->next;
        }
    }
    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }
private:
    Node<T>* head_;
    int size_;
};