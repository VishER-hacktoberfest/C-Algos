#include<bits/stdc++.h>
using namespace std;

//User function Template for C++

class Solution{
	public:
	/*  Function to implement Bellman-ford
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    int I=100000000;
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> distTo(V,I);
        distTo[S]=0;
        for(int k=0;k<V;k++){
            for(int i=0;i<adj.size();i++){
                int u=adj[i][0];
                int v=adj[i][1];
                int distance=adj[i][2];
                if(distTo[u]!=I && distTo[u]+distance<distTo[v]){
                    distTo[v]=distTo[u]+distance;
                }
            }
        }
        return distTo;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.bellman_ford(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

