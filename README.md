# Four Sorts of Sorts
Comparing the four sorting algorithms

In this project, an experiment was created to compares the number of comparisons done by these four different sorting algorithms:

The standard C++ STL sort function (not the C qsort function!) is used and is already pre-made. But its number of comparisons is counted. Along with C++ STL sort, the following sorting functions were implemented and compared:

Selection sort, using a priority queue (see below) implemented as an unordered vector.
Insertion sort, using a priority queue (see below) implemented as a sorted vector.
Heapsort, using a priority queue (see below) implemented as a heap.

Code was written to count the number of comparisons done by the 4 different sorts for data sets of n unique integers, where n = 5000, 10000, 15000, …, 100000. When this is done, you will have exactly 4*20 = 80 different counts, one for each sort and value of n.
