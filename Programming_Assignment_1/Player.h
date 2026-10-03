#pragma once
#include <ostream>
#include <string>
#include "Card.h"
#include "Stack.h"

class Player {
public:
    Player(int id, const std::string& name)
        : id_(id), name_(name){
        stack_ = new Stack<Card>();
    }

    bool operator==(const Player& other) const {
        return id_ == other.id_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& p) {
        return out << p.id_ << " " << p.name_;
    }

    void draw(){
        stack_->push(new Card(rand() % 10, rand() % 4));
    }

    void play() {
        std::cout << name_ << " played ";
        stack_->pop()->print();

    }

private:
    int id_;
    std::string name_;
    Stack<Card>* stack_;
};
