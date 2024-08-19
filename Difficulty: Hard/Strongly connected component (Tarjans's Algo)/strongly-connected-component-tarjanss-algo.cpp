//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
	private:
        
    void dfs(int node, vector<int> adj[], vector<bool>& vis, stack<int>& st) {
        vis[node] = true;
        
        for(auto nbr: adj[node]) {
            if(!vis[nbr]) {
                dfs(nbr, adj, vis, st);
            }
        }
        
        st.push(node);
    }
    
    void revDfs(int node, unordered_map<int, list<int>>& adj, vector<bool>& vis, vector<int>& components) {
        vis[node] = true;
        components.push_back(node);
        
        for(auto nbr: adj[node]) {
            if(!vis[nbr]) {
                revDfs(nbr, adj, vis, components);
            }
        }
    }
    
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        /*
            Kosaraju's Alog ->
            1. Find topo sort ordering
            2. Transpose the graph i.e. change the direction of all edges
            3. Call reverse dfs
        */
        
        // 1.) Topo Sort Ordering
        vector<bool> vis(V, false);
        stack<int> st;
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }
        
        // 2.) Transpose the graph
        unordered_map<int, list<int>> transposeAdj;
        for(int i=0; i<V; i++) {
            // change the vis array to false again
            vis[i] = false;
            
            for(auto nbr: adj[i]) {
                transposeAdj[nbr].push_back(i);
            }
        }
        
        vector<vector<int>> ans;
        
        // 3.) Reverse DFS
        int cnt = 0;
        while(!st.empty()) {
            auto node = st.top();
            st.pop();
            
            if(!vis[node]) {
                cnt++;
                vector<int> components;
                revDfs(node, transposeAdj, vis, components);
                ans.push_back(components);
            }
        }
        // cout << "Strongly Connected components: " << cnt << endl;
        for(auto& v: ans) {
            sort(v.begin(), v.end());
        }
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends