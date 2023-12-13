//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    
    {
        vector<int> dist(V,INT_MAX);
        dist[S] = 0;
        set<pair<int,int>> s;
        s.insert({0,S});
        
        while(!s.empty()){
            auto p = *(s.begin());
            s.erase(p);
            int node = p.second;
            int d = p.first;
            
            for(auto it:adj[node]){
                int w = it[1];
                int v = it[0];
                if(d+w < dist[v]){
                    if(dist[v] != INT_MAX){
                        s.erase({dist[v],v});
                    }
                    dist[v] = d+w;
                    s.insert({dist[v],v});
                }
            }
        }
        return dist;
        // Code here
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends