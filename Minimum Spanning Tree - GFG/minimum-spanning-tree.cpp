//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        int count =0;
        vector<int> vis(V,0);
        //<dist, node, parent>
        q.push({0,{0,-1}});
        while(!q.empty()){
            auto p = q.top();
            q.pop();
            int dis = p.first;
            int node = p.second.first;
            int par = p.second.second;
            if(vis[node] == 1){
                continue;
            }
            count += dis; 
            vis[node] = 1;
            for(auto it:adj[node]){
                int adjnode = it[0];
                int w = it[1];
                if(vis[adjnode] == 0){
                    q.push({w,{adjnode,node}});
                }
            }

        }
        
        
        return count;
        
        
        
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends