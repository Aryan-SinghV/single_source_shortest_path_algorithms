Dijkstra's Shortest Path Algorithm (C++)
Overview

This project implements Dijkstra's Shortest Path Algorithm in C++ using an adjacency list, a priority queue, and a visited array.

Dijkstra's algorithm is a greedy graph algorithm that calculates the shortest distance from a given source vertex to every other vertex in a weighted graph with non-negative edge weights.

This implementation uses a max-heap priority queue with negative distances to simulate a min-heap, ensuring that the vertex with the smallest tentative distance is processed first.

It follows the lazy priority queue approach, where distances are updated during edge relaxation and outdated priority queue entries are skipped using a visited array.

Algorithm Approach

The implementation follows these steps:

Represent the graph using an adjacency list.
Initialize the distance of every vertex to infinity (INF).
Initialize all vertices as unvisited.
Set the source vertex distance to 0.
Insert the source vertex into the priority queue.
Extract the vertex with the smallest tentative distance.
If the vertex has already been visited, skip it.
Otherwise, mark it as visited, finalizing its shortest distance.
Explore all its neighbouring vertices.
If a neighbour is unvisited and a shorter distance is found, update its distance and insert it into the priority queue.
Continue until the priority queue becomes empty.
Key Concepts Used
1. Adjacency List

The graph is represented using:

cpp
vector<vector<pair<int,int>>> g;


Each adjacency list entry stores:

first: Neighbouring vertex.
second: Weight of the connecting edge.

The implementation creates an undirected weighted graph.

2. Priority Queue
cpp
priority_queue<pair<int,int>> q;


The default C++ priority queue is a max-heap.

To simulate a min-heap, negative distances are inserted:

cpp
q.push(make_pair(-d, neigh.first));


This ensures that the vertex with the smallest actual distance is extracted first.

3. Visited Array
cpp
vector<bool> visited;


The visited array keeps track of vertices whose shortest distances have been finalized.

Once a vertex is visited, it is not processed again.

cpp
if(visited[curr.second]) continue;
visited[curr.second] = 1;


This also helps skip outdated entries in the priority queue.

4. Distance Array
cpp
vector<int> dist;


The distance array stores the shortest known distance from the source vertex to every other vertex.

Initially, all distances are set to infinity:

cpp
dist.resize(v, INF);


The source vertex is initialized with distance zero:

cpp
dist[src] = 0;


Distances are updated during edge relaxation:

cpp
if(d < dist[neigh.first]){
    dist[neigh.first] = d;
    q.push(make_pair(-d, neigh.first));
}


The distance is not updated again when extracting a vertex from the priority queue.

Input Format
text
V
E
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
6
9
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
Printing the distances
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
Operation	Time Complexity
Graph construction	O(V + E)
Priority queue operations	O((V + E) log V)
Visiting vertices	O(V)

Overall Time Complexity:

O((V + E) log V)

Overall Space Complexity:

O(V + E)

The adjacency list requires O(V + E) space, while the distance array, visited array, and priority queue require additional space.

Important Conditions and Limitations
All edge weights must be non-negative.
This implementation supports undirected weighted graphs.
The graph can be disconnected.
Unreachable vertices retain a distance of INF (1e18).
The algorithm does not support negative edge weights reliably, even if there are no negative cycles.
Negative cycles are not supported by Dijkstra's algorithm.
Distances are stored using 64-bit integers.

For graphs containing negative edge weights, consider using the Bellman-Ford algorithm.

Compilation and Execution

Compile using G++:

bash
g++ -std=c++17 main.cpp -o dijkstra


Run on Linux/macOS:

bash
./dijkstra


Run on Windows:

bash
dijkstra.exe

Applications

Dijkstra's algorithm is commonly used in:

GPS navigation and route planning.
Network routing.
Transportation and logistics.
Shortest path problems in weighted graphs.
Competitive programming.
Graph-based optimization problems.
Implementation Summary
Property	Details
Algorithm	Dijkstra's Shortest Path
Language	C++
Graph Representation	Adjacency List
Graph Type	Undirected Weighted Graph
Data Structure	Priority Queue (Max-Heap)
Distance Handling	Negative distances
Optimization	Visited Array
Implementation	Lazy Priority Queue
Edge Weights	Non-negative

Purpose: Implementation and practice of graph algorithms and shortest path techniques in C++.
