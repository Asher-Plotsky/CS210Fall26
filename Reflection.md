1: Concat only needs to work between two lists of the same type because 
only one type is available for makeList at once. To allow concatanation
between both types of arrays, both would need to be able to be created,and
I would have to change their representation to be able to concatenate them.

2:Reverse in the linkedlist needs a current, previous, and next pointers.
Having those allows the method to walk through the entire list. Losing track of
one would make it so the list doesn't truly reverse itself.

3: The range of anywhere for the addAnywhere between 0 and size and deleteAnywhere 
is between 0 and size - 1.
0 is the first term in the array and the head of the linkedlist and size is the space 
after the last term in each of them.

4: for concat you need to walk to the end because you are adding the second list after your first one.
If it still had a tail pointer this could be done with O(1) instead of O(n).

5: For addAnywhere on the arrayList adding it somewhere forces every object to the right of it to be shifted 
over by one. If it moved to the left it would overwrite one piece of data.

6: Reverse is called on line 50 of main. If it was not played, the order of that group would still be the 
original order when it was initialized.