1: The LinkedList::deleteFront() method calls delete twice.
The first call deletes the data that the pointer points to 
and the second call deletes the pointer itself. The calls that put
them on the heap are when a node is created in LinkedList::addFront().

2: Changing it to be a pointer is what made the destructor necessary.
Pointers are added to the heap while variables are on the stack. The
stack gets automatically cleared while the heap does not. You would 
not get a compiler error for forgetting to make the destructor.

3: Search() and addFront() treat their new pointers differently.
While search adds a temporary one, the one addFront makes is supposed
to be on the list until it is taken off. This allows search to delete its pointer 
while disallowing addFront to do the same.

4: Polymorphism and inheritance let it happen. Polymorphism is when 
writing one thing multiple things can happen in the final code afterward.
Inheritance is what allowed the list header to use arraylist and linkedlist in its place. 

5: Static Const is something I would not have thought to add on my own.
I am familiar of the concept of Final variables from Java, but I have not thought 
about how they may work in other languages. Leaving it out may change some values
that must stay the same as they were when they initialized.