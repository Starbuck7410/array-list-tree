# array-list-tree
Array List Tree (Name pending change) is a data structure that came to me in a shower thought. Have fun reading the theory and hopefully implementation in the near future.


# Structure

The array list tree is a dynamic memory structure used to store dynamic data with O(log n) reads, O(1) adds, and the advantage of being non-continous like a linked list, and also being very fast in small scales.

The structure goes as follows: 

Each element is an array of N items, and stores a pointer to the parent, and 2 children, labeled "0" and "1" children.







### This is just thoughts here dont mind this:

1011 -> 1, 1, 0, 1 = 11 

[1, 10, 11, 100, 101, 110, 111]
read msb, choose path, follow path repeat until path is 0

if N = 4, index is 25, 25 / 4 = 6 + remainder 1
6 in binary is 110, add 1 to get 111, remove the leading 1 and the route we follow to get there is 1, 1

in there it's the 2nd element (element 1)

so far checks out, will have to improve on this concept

if N is a power of 2 an easy trick can be used:
25 in binary is 11001, you can remove the LSBs until you get to the path of the entry, add 1, remove the leading MSB 1 and go to town
