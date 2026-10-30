#include<iostream>
#include<vector>
#include<queue>


using namespace std;

#define int long long
#define endl '\n'

int v,e,src;
vector<vector<pair<int, int>>> g;
vector<int> dist;
priority_queue<pair<int,int>> q; //{-distance, node}

void sssp(int src){
    q.push(make_pair(0,src));
    dist[src]=0;

    while(!q.empty()){
        auto curr = q.top();
        q.pop();
        if(dist[curr.second]< -curr.first) continue;
        dist[curr.second]= -curr.first;

        for(auto neigh:g[curr.second]){
            if(dist[neigh.first]>dist[curr.second]+neigh.second){//update the distance using priority queue
                int d = dist[curr.second]+neigh.second;
                q.push(make_pair(-d,neigh.first));
            }
        }
    }


}


void solve(){
    cout<<"Enter the number of vertices and edges ";
    cin>>v>>e;

    g.resize(v);
    dist.assign(v,1e18);

    cout<<"Enter the nodes and the weights between them "<<endl;
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back(make_pair(y,w));
        g[y].push_back(make_pair(x,w));
    }

    cout<<"Enter the source node ";
    cin>>src;

    sssp(src);
    cout<<"Printing the smallest distances "<<endl;

    for(int i=0;i<v;i++){
        cout<<"node "<<i<<" "<<dist[i];
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    solve();
}
