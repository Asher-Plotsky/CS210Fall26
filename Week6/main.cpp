//
// Created by asher on 10/6/2026.
//
#include <iostream>
#include "List.h"
#include "Data.h"

// STEP 3 and STEP 5 of the lab guide: uncomment these two includes
// once the files exist.
#include "StackList.h"
#include "QueueList.h"

int main() {
    // ---- Part 0: the List you already know, plus the new methods. ----
    // This part runs right now. Build and run it before you write anything.
    std::cout << "== List<int> ==" << std::endl;
    std::unique_ptr<List<int>> list = makeList<int>();
    list->addFront(new int(20));
    list->addFront(new int(10));
    list->addBack(new int(30));
    list->print();                                           // 10,20,30,
    std::cout << "getFront: " << *list->getFront() << std::endl;   // 10
    std::cout << "size: " << list->size() << std::endl;            // 3
    list->deleteFront();
    list->print();                                           // 20,30,

    // ---- Part 1: StackList. Uncomment after STEP 3. ----

    std::cout << std::endl << "== Stack<int> ==" << std::endl;
    StackList<int> stack;
    stack.push(new int(1));
    stack.push(new int(2));
    stack.push(new int(3));
    stack.print();                                           // 3,2,1,
    std::cout << "peek: " << *stack.peek() << std::endl;     // 3
    stack.pop();
    stack.print();                                           // 2,1,
    std::cout << "size: " << stack.size() << std::endl;      // 2

    std::cout << std::endl << "== Stack<Data> ==" << std::endl;
    StackList<Data> dataStack;
    dataStack.push(new Data(1, "Alice"));
    dataStack.push(new Data(2, "Bilal"));
    dataStack.push(new Data(3, "Chen"));
    dataStack.print();                                       // 3 Chen,2 Bilal,1 Alice,
    dataStack.pop();
    std::cout << "peek: " << *dataStack.peek() << std::endl; // 2 Bilal

    std::cout << std::endl << "== Empty stack ==" << std::endl;
    StackList<int> emptyStack;
    emptyStack.pop();                                        // LinkedList is empty.
    std::cout << "isEmpty: " << emptyStack.isEmpty() << std::endl; // 1


    // ---- Part 2: QueueList. Uncomment after STEP 5. ----

    std::cout << std::endl << "== Queue<int> ==" << std::endl;
    QueueList<int> queue;
    queue.enqueue(new int(1));
    queue.enqueue(new int(2));
    queue.enqueue(new int(3));
    queue.print();                                           // 1,2,3,
    std::cout << "front: " << *queue.front() << std::endl;   // 1
    queue.dequeue();
    queue.print();                                           // 2,3,
    std::cout << "size: " << queue.size() << std::endl;      // 2

    std::cout << std::endl << "== Queue<Data> ==" << std::endl;
    QueueList<Data> dataQueue;
    dataQueue.enqueue(new Data(1, "Alice"));
    dataQueue.enqueue(new Data(2, "Bilal"));
    dataQueue.enqueue(new Data(3, "Chen"));
    dataQueue.print();                                       // 1 Alice,2 Bilal,3 Chen,
    dataQueue.dequeue();
    std::cout << "front: " << *dataQueue.front() << std::endl; // 2 Bilal

    // Empty the queue, then reuse it. Checks that tail_ resets correctly.
    std::cout << std::endl << "== Drain and reuse ==" << std::endl;
    queue.dequeue();
    queue.dequeue();
    std::cout << "isEmpty: " << queue.isEmpty() << std::endl; // 1
    queue.enqueue(new int(99));
    queue.print();                                           // 99,


    return 0;
}
