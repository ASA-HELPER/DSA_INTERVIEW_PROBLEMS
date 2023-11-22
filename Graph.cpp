// DFS traversal
// TC => O(V + E) because har node ke liye hum recursive function ko ek hi baar call kar rahe hai and hum har node ke liye uske adjacent nodes par jaate hai
// SC => O(V)
class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &res)
    {
        if (vis[node])
        {
            return;
        }
        vis[node] = true;
        res.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, res);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> res;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, res);
            }
        }
        return res;
    }
};

// BFS traversal
// TC => O(V+E) yahan E is for total degrees as we traverse all adjacent nodes.
// SC => O(V)
class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> res;
        queue<int> q;
        q.push(0);
        vector<bool> vis(V, false);
        vis[0] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        return res;
    }
};

// Problem : Detect Cycle in an Undirected Graph (using DFS)
// TC =>  O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time.
// SC => O(N) + O(N) ~ O(N), Space for recursive stack space and visited array
class Solution
{
private:
    // Hum source node ke saath saath uske parent ko bhi store kar rahe hai recursive stack mein
    bool dfs(int node, int parent, int vis[], vector<int> adj[])
    {
        vis[node] = 1;
        // visit adjacent nodes
        for (auto adjacentNode : adj[node])
        {
            // unvisited adjacent node
            if (!vis[adjacentNode])
            {
                if (dfs(adjacentNode, node, vis, adj) == true)
                    return true;
            }
            // agar koyi node visited hai but parent nahi hai toh iska matlab cycle exist karta hai
            else if (adjacentNode != parent)
                return true;
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        // for graph with connected components
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, vis, adj) == true)
                    return true;
            }
        }
        return false;
    }
};

// Problem : Detect Cycle in an Undirected Graph (using BFS)
// TC => O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time.
// SC => O(N) + O(N) ~ O(N), Space for queue data structure and visited array.
class Solution
{
private:
    bool detect(int src, vector<int> adj[], int vis[])
    {
        vis[src] = 1;
        // store <source node, parent node>
        queue<pair<int, int>> q;
        q.push({src, -1});
        // traverse until queue is not empty
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // go to all adjacent nodes
            for (auto adjacentNode : adj[node])
            {
                // if adjacent node is unvisited
                if (!vis[adjacentNode])
                {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                // if adjacent node is visited and is not it's own parent node
                else if (parent != adjacentNode)
                {
                    // yes it is a cycle
                    return true;
                }
            }
        }
        // there's no cycle
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // initialise them as unvisited
        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, adj, vis))
                    return true;
            }
        }
        return false;
    }
};

// Problem : Detect a Cycle in Directed Graph | Topological Sort | Kahn’s Algorithm
// TC => O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.
// SC => O(N) + O(N) ~ O(2N), O(N) for the in-degree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).
class Solution
{
public:
    bool isCyclic(int V, vector<int> adj[])
    {
        int indegree[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int cnt = 0;
        // o(v + e)
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            // node is in your topo sort
            // so please remove it from the indegree

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        if (cnt == V)
            return false;
        return true;
    }
};

// Problem : Detect a Cycle in Directed Graph using DFS
// TC => O(V+E)
// SC => O(2N) + O(N) for auxillary stack space
class Solution
{
private:
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[])
    {
        // The visited array keeps a track of visited nodes, and the path-visited keeps a track of visited nodes in the current traversal only.
        vis[node] = 1;
        pathVis[node] = 1;

        // traverse for adjacent nodes
        for (auto it : adj[node])
        {
            // when the node is not visited
            if (!vis[it])
            {
                if (dfsCheck(it, adj, vis, pathVis) == true)
                    return true;
            }
            // if the node has been previously visited
            // but it has to be visited on the same path
            // If the adjacent node is visited and also on the same path(i.e marked visited in the pathVis array), we will return true, because it means it has a cycle, thereby the pathVis was true.
            else if (pathVis[it])
            {
                return true;
            }
        }
        // if there are no further nodes to visit, we will unmark the current node in the pathVis array and just return false. Then we will backtrack to the previous node with the returned value.
        // The point to remember is, while we enter we mark both the pathVis and vis as true, but at the end of traversal to all adjacent nodes, we just make sure we unmark the pathVis and still
        // keep the vis marked as true, as it will avoid future extra traversal calls.
        pathVis[node] = 0;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        int pathVis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfsCheck(i, adj, vis, pathVis) == true)
                    return true;
            }
        }
        return false;
    }
};

// Problem : Topological Sort (BFS)
// TC => O(V+E)
// SC => O(2V)
class Solution
{
public:
    vector<int> topo(int N, vector<int> adj[])
    {
        queue<int> q;
        vector<int> indegree(N, 0);
        for (int i = 0; i < N; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return topo;
    }
};

// Problem : Topological Sort Using DFS
// TC => O(N+E) where N = Number of node , E = Number of Edges
// SC => O(N)[Visited Array] + O(N)[Stack data structure] + O(N)[Auxiliary Stack Space Recursion call of DFS]
class Solution
{
public:
    // use check funnction only when you want to check if elements returned by user contains the elements in topological sorted form
    int check(int V, vector<int> &res, vector<int> adj[])
    {
        vector<int> mp(V, -1);
        for (int i = 0; i < V; i++)
        {
            mp[res[i]] = i;
        }
        for (int i = 0; i < V; i++)
        {
            for (int v : adj[i])
            {
                if (mp[i] > mp[v])
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                findTopoSort(it, vis, st, adj);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                findTopoSort(i, vis, st, adj);
            }
        }
        vector<int> topo;
        while (!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};

// Problem : Number of Distinct Islands
// TC => O(N x M x log(N x M)) + O(NxMx4) ~ O(N x M), For the worst case, assuming all the pieces as land, the DFS function will be called for (N x M) nodes,
// and for every node, we are traversing for 4 neighbors, it will take O(N x M x 4) time. Set at max will store the complete grid, so it takes log(N x M) time.
// SC => O(N x M), O(N x M) for the visited array and set takes up N x M locations at max.
class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int row0, int col0)
    {
        vis[row][col] = 1;
        // island ke shape ko indexes ki form mein store kar rahe hai shape ke first(base) cordinate se har adjacent coordinate ko subtract karke
        vec.push_back({row - row0,
                       col - col0});
        int n = grid.size();
        int m = grid[0].size();
        //   all four directions mein traverse karne ke liye
        vector<int> delrow = {-1, 0, +1, 0};
        vector<int> delcol = {0, -1, 0, +1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            // checking base conditions
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, vis, grid, vec, row0, col0);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        // grid ke through traverse karenge and har univisited node ke liye visited matrix mein hume DFS ko call karna hoga
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, vis, grid, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

// Problem : Bipartite Graph | BFS Implementation
// TC =>  O(V + 2E), Where V = Vertices, 2E is for total degrees as we traverse all adjacent nodes.
// SC => O(3V) ~ O(V), Space for queue data structure, colour array and an adjacency list.
class Solution
{
    // colors a component
private:
    bool check(int start, int V, vector<int> adj[], int color[])
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                // if the adjacent node is yet not colored  you will give the opposite color of the node
                if (color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                // is the adjacent guy having the same color someone did color it on some other path
                else if (color[it] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        int color[V];
        for (int i = 0; i < V; i++)
            color[i] = -1;

        for (int i = 0; i < V; i++)
        {
            // if not coloured
            if (color[i] == -1)
            {
                if (check(i, V, adj, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// Problem : Kosaraju's Algorithm for strongly connected component
// A component is called a Strongly Connected Component(SCC) only if for every possible pair of vertices (u, v) inside that component, u is reachable from v and v is reachable from u.
// A component containing a single vertex is always a strongly connected component.
// Steps :
// A) Sort all the nodes according to their finishing time : After the DFS gets completed for all the nodes, the stack will be storing all the nodes in the sorted order of their finishing time.
// B) Reverse all the edges of the entire graph : we will create another adjacency list and store the information of the graph in a reversed manner.
// C) Perform the DFS and count the no. of different DFS calls to get the no. of SCC.
// TC => O(V+E) + O(V+E) + O(V+E) ~ O(V+E) , where V = no. of vertices, E = no. of edges. The first step is a simple DFS, so the first term is O(V+E). The second step of reversing the graph and
//  the third step, containing DFS again, will take O(V+E) each.
// SC =>  O(V)+O(V)+O(V+E), where V = no. of vertices, E = no. of edges. Two O(V) for the visited array and the stack we have used. O(V+E) space for the reversed adjacent list.
class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[],
             stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }

private:
    void dfs3(int node, vector<int> &vis, vector<int> adjT[])
    {
        vis[node] = 1;
        for (auto it : adjT[node])
        {
            if (!vis[it])
            {
                dfs3(it, vis, adjT);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> adjT[V];
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }
};

// Problem : Articulation Point in a graph GFG : Woh nodes jinhe remove karne par graph ko different components mein divide kar sakte hai unhe articulation point kehte hai
// TC => O(V+2E), where V = no. of vertices, E = no. of edges. It is because the algorithm is just a simple DFS traversal.
// SC => O(3V), where V = no. of vertices. O(3V) is for the three arrays i.e. tin, low, and vis, each of size V.
class Solution
{
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[], vector<int> &mark, vector<int> adj[])
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                // extra condition in dfs code
                if (low[it] >= tin[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }
    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<int> mark(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (mark[i] == 1)
            {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};

// Problem : Dijkstra Algorithm for Shortest Path
// TC => O( E log(V) ) { for Dijkstra’s Algorithm } + O(V) { for backtracking in order to find the parent for each node } Where E = Number of edges and V = Number of Nodes.
// SC => O( |E| + |V| ) { for priority queue and dist array } + O( |V| ) { for storing the final path } Where E = Number of edges and V = Number of Nodes.
class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Create an adjacency list of pairs of the form node1 -> {node2, edge weight} where the edge weight is the weight of the edge from node1 to node2.
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        // Create a priority queue for storing the nodes along with distances in the form of a pair { dist, node }.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Create a dist array for storing the updated distances and a parent array for storing the nodes from where the current nodes represented by indices of
        // the parent array came from.
        vector<int> dist(n + 1, 1e9), parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        dist[1] = 0;

        // Push the source node to the queue.
        pq.push({0, 1});
        while (!pq.empty())
        {
            // Topmost element of the priority queue is with minimum distance value.
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;

            // Iterate through the adjacent nodes of the current popped node.
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                // Check if the previously stored distance value is greater than the current computed value or not, if yes then update the distance value.
                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});

                    // Update the parent of the adjNode to the recent node where it came from.
                    parent[adjNode] = node;
                }
            }
        }

        // If distance to a node could not be found, return an array containing -1.
        if (dist[n] == 1e9)
            return {-1};

        // Store the final path in the ‘path’ array.
        vector<int> path;
        int node = n;

        // Iterate backwards from destination to source through the parent array.
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);

        // Since the path stored is in a reverse order, we reverse the array to get the final answer and then return the array.
        reverse(path.begin(), path.end());
        return path;
    }
};

// Problem : BellMan Ford Algorithm
// TC => O(V*E), where V = no. of vertices and E = no. of Edges.
// SC => O(V) for the distance array which stores the minimized distances.
class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // Nth relaxation to check negative cycle
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                return {-1};
            }
        }
        return dist;
    }
};

// Problem : Floyd Warshall Algorithm
// TC => O(V^3), as we have three nested loops each running for V times, where V = no. of vertices.
// SC => O(V^2), where V = no. of vertices. This space complexity is due to storing the adjacency matrix of the given graph.
class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 1e9;
                }
                if (i == j)
                    matrix[i][j] = 0;
            }
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j],
                                       matrix[i][k] + matrix[k][j]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1e9)
                {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};

// Problem : Prim’s Algorithm – Minimum Spanning Tree
// TC => O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
// The maximum size of the priority queue can be E so after at most E iterations the priority queue will be empty and the loop will end. Inside the loop, there is a pop operation that will take logE time. This will result in the first O(E*logE) time complexity. Now, inside that loop,
// for every node, we need to traverse all its adjacent nodes where the number of nodes can be at most E. If we find any node unvisited, we will perform a push operation and for that, we need a logE time complexity. So this will result in the second O(E*logE).
// SC => O(E) + O(V), where E = no. of edges and V = no. of vertices. O(E) occurs due to the size of the priority queue and O(V) due to the visited array. If we wish to get the mst, we need an extra O(V-1) space to store the edges of the most.
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> vis(V, 0);
        // {wt, node}
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            if (vis[node] == 1)
                continue;
            // add it to the mst
            vis[node] = 1;
            sum += wt;
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edW = it[1];
                if (!vis[adjNode])
                {
                    pq.push({edW, adjNode});
                }
            }
        }
        return sum;
    }
};

// Problem : Kruskal’s Algorithm – Minimum Spanning Tree
// TC => O(N+E) + O(E logE) + O(E*4α*2)   where N = no. of nodes and E = no. of edges. O(N+E) for extracting edge information from the adjacency list.
// O(E logE) for sorting the array consists of the edge tuples. Finally, we are using the disjoint set operations inside a loop. The loop will continue to E times.
// Inside that loop, there are two disjoint set operations like findUPar() and UnionBySize() each taking 4 and so it will result in 4*2. That is why the last term O(E*4*2) is added.
// SC => O(N) + O(N) + O(E) where E = no. of edges and N = no. of nodes. O(E) space is taken by the array that we are using to store the edge information.
// And in the disjoint set data structure, we are using two N-sized arrays i.e. a parent and a size array (as we are using unionBySize() function otherwise,
// a rank array of the same size if unionByRank() is used) which result in the first two terms O(N).
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // 1 - 2 wt = 5
        /// 1 - > (2, 5)
        // 2 -> (1, 5)

        // 5, 1, 2
        // 5, 2, 1
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v))
            {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }
};
