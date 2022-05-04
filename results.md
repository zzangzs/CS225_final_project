# yuli9-yixiaof2-nankang2-zisuj2
Final project for team: dhrev

## Dijkstra’s Algorithm:

We use Dijkstra’s Algorithm to find the shortest path from one airport to the other. When a user enters the departure and destination airports’ ID, it will return the shortest path in terms of a vector containing airports’ ID, and the total distance will be renewed. If there is no path between, it should return a size one vector with 999999, and the total distance is 0. Consider the case that the straight line between two airports is always the shortest path in real life, we adopt the priority queue built in c++, since we don't need to reset the value stored in each node.

To test Dijkstra’s Algorithm, we used a small dataset. The dataset can be found at tests->Dij_test_Airport1.txt, Dij_test_Route1.txt. Here is the graph representing this dataset:
![image](https://github-dev.cs.illinois.edu/cs225-sp22/yuli9-yixiaof2-nankang2-zisuj2/blob/main/IMG/test_Dijkstra1.jpg)

We also visualize the graph by printing each airport’s adjacent airports.
![image](https://github-dev.cs.illinois.edu/cs225-sp22/yuli9-yixiaof2-nankang2-zisuj2/blob/main/IMG/test_Dijkstra2.png)

We use many test cases to test: 1. no path between; 2. has a path with one edge; 3. no path but has an opposite direction path; 4. has two paths but the one with three edges is shorter than the one with two edges. Here is the result of these test cases, which are all as our expected.
![image](https://github-dev.cs.illinois.edu/cs225-sp22/yuli9-yixiaof2-nankang2-zisuj2/blob/main/IMG/test_Dijkstra3.png)