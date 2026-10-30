Dijkstra's Shortest Path Algorithm (C++)
Overview

This project implements Dijkstra's Shortest Path Algorithm in C++ using an adjacency list and a priority queue.

Dijkstra's algorithm is a greedy graph algorithm used to find the shortest distances from a given source vertex to all other vertices in a weighted graph with non-negative edge weights.

Algorithm

The implementation uses:

Adjacency List to represent the graph.
Priority Queue to efficiently select the vertex with the minimum tentative distance.
Lazy Deletion to skip outdated entries in the priority queue.
Edge Relaxation to update shortest distances.
How It Works
Initialize the distance of every vertex to infinity.
Set the source vertex distance to 0.
Insert the source vertex into the priority queue.
Extract the vertex with the smallest distance.
Visit all its adjacent vertices.
Update the distance if a shorter path is found.
Push the updated distance and vertex into the priority queue.
Repeat until the priority queue becomes empty.
Implementation Details
Graph Representation

The graph is represented using an adjacency list:

cpp
vector<vector<pair<int, int>>> g;


Each adjacency list entry contains:

first: Neighbouring vertex.
second: Weight of the edge.

The graph is implemented as an undirected weighted graph.

Priority Queue
cpp
priority_queue<pair<int,int>> q;


C++ priority queues are max-heaps by default.

To simulate a min-heap, the implementation stores negative distances:

cpp
q.push(make_pair(-d, neigh.first));


This ensures that the vertex with the smallest actual distance is processed first.

Lazy Deletion
cpp
if(dist[curr.second] < -curr.first) continue;


This condition skips outdated entries in the priority queue, avoiding unnecessary processing.

Input Format
text
V E
u1 v1 w1
u2 v2 w2
...
uE vE wE
source


Where:

V = Number of vertices.
E = Number of edges.
u, v = Endpoints of an edge.
w = Weight of the edge.
source = Starting vertex.

Note: Vertices are numbered from 0 to V-1.

Sample Input
text
6 9
0 1 4
0 2 2
1 2 1
1 3 5
2 3 8
2 4 10
3 4 2
3 5 6
4 5 3
0

Sample Output
text
Printing the smallest distances
node 0 0
node 1 3
node 2 2
node 3 8
node 4 10
node 5 13

Complexity Analysis

Let:

V = Number of vertices.
E = Number of edges.
Operation	Complexity
Graph construction	O(V + E)
Priority queue operations	O((V + E) log V)
Space complexity	O(V + E)

Overall Time Complexity:

O((V + E) log V)

Overall Space Complexity:

O(V + E)

Important Conditions
All edge weights must be non-negative.
The graph can be disconnected.
Unreachable vertices retain a distance of infinity (1e18).
The implementation currently supports undirected graphs.
Compilation and Execution

Compile using g++:

bash
g++ -std=c++17 main.cpp -o dijkstra


Run:

bash
./dijkstra


On Windows:

bash
dijkstra.exe

Applications

Dijkstra's algorithm is commonly used in:

GPS navigation and shortest-route finding.
Network routing protocols.
Transportation and logistics.
Finding shortest paths in weighted graphs.
Competitive programming and graph theory problems.
Limitations

Dijkstra's algorithm does not guarantee correct results when negative edge weights are present.

For graphs containing negative edge weights, consider using the Bellman-Ford algorithm.

Algorithm: Dijkstra's Shortest Path

Language: C++

Graph Representation: Adjacency List

Data Structure: Priority Queue (Max-Heap with Negative Distances)
