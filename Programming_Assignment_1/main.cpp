#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();
    // ---- Part 2: your Uno scene goes below ----
    std::cout << std::endl << "== UNO Scene ==" << std::endl;
    std::unique_ptr<List<Player>> players = makeList<Player>();
    std::cout << std::endl << "Table is formed" << std::endl;
    players->addFront(new Player(1, "John"));
    players->addFront(new Player(2, "Jane"));
    players->addFront(new Player(3, "Steve"));
    players->print();
    std::cout << std::endl << "Player joins mid round" << std::endl;
    players->addAnywhere(2, new Player(4, "Jesse"));
    players->print();
    std::cout << std::endl << "Reverse card played" << std::endl;
    players->reverse();
    players->print();
    std::cout << std::endl << "One player leaves" << std::endl;
    players->deleteAnywhere(2);
    players->print();
    std::cout << std::endl << "Second table merges" << std::endl;
    std::unique_ptr<List<Player>> table2 = makeList<Player>();
    table2->addFront(new Player(5, "Bob"));
    table2->addFront(new Player(6, "Dylan"));
    table2->addFront(new Player(7, "Alex"));
    players->print();
    table2->print();
    players->concat(table2.get());
    players->print();
    table2->print();
    return 0;
}
