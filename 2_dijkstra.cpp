//dijkstra's algorithm: explore the shortest weighted edge first, doesn't work on graphs with negative cycles

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define int long long
#define endl '\n'
#define INF 1e18

int v,e;

vector<vector<pair<int,int>>> g;//adjacency list to represent the graph (node, weight)
vector<int> dist;//contains the distance to every node
vector<bool> visited;
priority_queue<pair<int,int>> q;//contains (distance, node)

void dijkstra(int src){

    while(!q.empty()){
        pair<int,int> curr = q.top();//extract the top element
        q.pop();
        if(visited[curr.second]) continue;
        visited[curr.second]=1;

        for(auto neigh:g[curr.second]){//make changes to the priority queue
            if(!visited[neigh.first]){
                int d = dist[curr.second]+neigh.second;
                if(d<dist[neigh.first]){
                    dist[neigh.first]=d;
                    q.push(make_pair(-d,neigh.first));
                }
            }
        }
    }
}



void solve(){
    cout<<"Enter the number of vertices ";
    cin>>v;
    cout<<"Enter the number of edges ";
    cin>>e;

    g.resize(v);
    dist.resize(v,INF);
    visited.resize(v,0);

    cout<<"Enter the graph details ";
    for(int i=0;i<e;i++){
        cout<<"Enter the two nodes and then the weight between the nodes ";
        int x, y,w;
        cin>>x>>y>>w;
        g[x].push_back(make_pair(y,w));
        g[y].push_back(make_pair(x,w));
    }

    cout<<"Enter the source node ";
    int src;
    cin>>src;
    dist[src]=0;
    q.push(make_pair(0,src));//initialise the source node with 0 distance and push it into the priority queue

    dijkstra(src);

    cout<<"Printing the distances "<<endl;
    for(int i=0;i<v;i++){
        cout<<"node "<<i<<" "<<dist[i]<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
