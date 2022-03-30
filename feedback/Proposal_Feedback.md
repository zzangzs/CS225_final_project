### Grade
~~Competent (90%)~~ Sophisticated (100%)

I have changed my grade here as the issues seem very minor and the group has a clear idea of how to move forward.

### Comments
A well-written proposal overall, with a few minor issues I have pointed out below.

**Leading Question**
The leading question of finding the optimal path between two airports is good, but you mentioned the number of stops as being a factor. It appears that you are trying to solve this by using Dijkstra's algorithm, but Dijkstra's only looks at edge weights (and not number of airports visited). Therefore, you would likely need to modify Dijkstra's slightly if you wanted to include number of stops as a factor. 

Given that your other proposed algorithm is PageRank, you could add this as another component of your leading question (i.e. to determine the most central airports).

**Dataset**
You have given a thorough and clear description of the dataset. In terms of data correction, I believe OpenFlights has airports with missing fields in their entries, so this is another issue you may have to deal with when reading in the dataset. 

Regarding your data storage section, there are two things I wanted to point out: 
1. I don't exactly see why you are converting the latitude and longitude to a 3D point. Possibly to make the distance computations easier? Even so, I also don't see what scheme you would be using for the 3D point system (what would the origin be?).
2. You mention that you are going to use a KD-Tree to store the airports, presumably to find the nearest neighboring airports to a given point? This could work, but it would end up being less optimal than Dijkstra's algorithm and you would also need to factor in which airports are actually connected by an edge.

As such, I would recommend not using a KD-Tree for this, and also to stick with latitude and longitude instead of a 3D point representation. If you use 3D points for distance, you may also find that they are inaccurate because the Earth is a spheroid (so to be precise, you want to find distance traveled on the surface). I would recommend checking out Haversine distance to do this.

**Algorithm**
There is a minor flaw in your runtime for DFS, as the expected runtime should be O(V + E). Also, note that your Dijkstra's runtime is assuming the array implementation. You could also try implementing the priority queue implementation of Dijkstra's, which has a runtime of O((E+V)log(V)).
