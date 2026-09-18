//
// Created by asher on 9/17/2026.
//

#pragma once
#include "Node.h"

template <typename T>
class LinkedList {
    public:
    Node<T>* head;
    int size;
    LinkedList(T *value) {
        Node<T>* temp = new Node<T>(value);
        head = temp;
        size = 1;
    }
    LinkedList() {
        head = nullptr;
        size = 0;
    }
    void addFront(T *value) {
        if (head == nullptr) {
            head = new Node<T>(value);
            size++;
            return;
        }
        Node<T>* temp = new Node<T>(value);
        temp->next = head;
        head = temp;
        size++;
    }
    void addBack(T *value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        size++;
    }
    void deleteFront() {
        if (head == nullptr) {
            return;
        }
        head = head->next;
        size--;
    }
    void deleteBack() {
        if (head == nullptr) {
            return;
        }
        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nullptr;
        size--;
    }
    void print() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->print() << std::endl;
            temp = temp->next;
        }
    }
};
