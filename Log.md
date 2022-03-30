### 2022/3/26 Week 0

1. complete and test Point struture
2. Point(Latitude: Deg, negative is South, positive is North; Longitude: Deg, negative is West, positive is East):
3. Axis: x- axis: for Earth's center to (latitute 0, longitude 90E); y- axis: for Earth's center to (latitute 90N, longitude 0); z- axis: for Earth's center to (latitute 0, longitude 0) 
4. use "g++ testPoint.cpp -std=c++11" to complie, use "./a.out" to see the output

### 2022/4/1 Week 1
author: ZJ

**Changed our leading question**
1. Changed the user input from two arbitrary coordinates to two cities and countries, which better simulates the real situations.
2. Disregarded stops in the routes since waiting time during stops varies from route to route and specific information is not provided.
3. Added another question of finding the most popular airport based on the number of incoming routes using the PageRank algorithm, which can be visulized by the node size each airport takes on the final image.

**Finished basic interfaces of Graph**
1. A vector of bool to mark whether the nodes in the graph is visited during traversals.
2. A 2d vector of double, alse the adjacency list to store distances between any two airports, i.e., the weights of edges.
3. A map that helps to parse the vector of routes into ordered ad
