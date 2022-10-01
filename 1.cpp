#include <iostream.h>
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector <pair<int, int>> &adj, int x, int y) {
    adj.push_back(make_pair(y, u));
}

vector<unordered_set<int> > make_graph(int n, vector<pair<int, int> >& adj) {
    vector<unordered_set<int> > graph(n);
    for (auto pre : adj)
        graph[pre.second].insert(pre.first);
    return graph;
}

void printGraph(vector<pair<int, int> >&adj, int V) {
    vector<unordered_set<int> > graph = make_graph(V, adj);
    int user = 0;
    for (auto i: graph) {
        cout << user << ":";
        for (auto j : i) 
            cout << j << " ";
        cout << endl;
        user++;
    }
    cout << endl;
}

void printDeadUsers(unordered_map <int, bool> &isFollowed, int users) {
    cout << "Dead users are: ";
    for (int i = 0; i < users; i++) {
        if (isFollowed.find(i) == isFollowed.end()) 
            cout << i << " ";
    }
    cout << endl;
}

bool dfs(vector<unordered_set<int> >& graph, int node, vector<bool>& onpath, vector<bool>& visited, vector<int>& toposort) {
    if (visited[node])
        return false;
    onpath[node] = visited[node] = true;
    for (int neigh : graph[node])
        if (onpath[neigh] || dfs(graph, neigh, onpath, visited, toposort))
            return true;
    toposort.push_back(node);
    return onpath[node] = false;
}

vector<int> findOrder(int V, vector<pair<int, int> >& adj) {
    vector<unordered_set<int> > graph = make_graph(V, adj);
    vector<int> toposort;
    vector<bool> onpath(V, false), visited(V, false);
    for (int i = 0; i < V; i++)
        if (!visited[i] && dfs(graph, i, onpath, visited, toposort))
            return {};
    reverse(toposort.begin(), toposort.end());
    return toposort;
}

void printSequence(vector <pair<int, int>> following, int users) {
    vector <int> v = findOrder(users, following);
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " ";
}

int main() {
    int edges, users;
    cin >> edges >> users;
    vector <pair<int, int>> adj;
    unordered_map <int, bool> isFollowed;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
        isFollowed[v] = true;
    }

    printGraph(adj, users);
    printDeadUsers(isFollowed, users);

    cout << "\nCorrect sequence is: ";
    printSequence(adj, users);
    return 0;
}
