#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Edges {
    int src;
    int dest;
};

int main() {
    const int nodes = 10;
    vector< vector<int> > adjList;
    adjList.resize(nodes);
    static int visited[nodes];
    int startnode = 0;
    stack<int> stk;
    int current;

    vector<Edges> edges {
        {0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {2, 6}, {2, 7}, {3, 8}, {3, 9}
    };

    for(auto &e : edges) {
        adjList[e.src].push_back(e.dest);
    }

    for(int i = 0; i < nodes; i++){
        cout << "node " << i << "--> ";
        for(int a : adjList[i]){
            cout << " " << a << " ";
        }
        cout << endl;
    }

    stk.push(startnode);
    visited[startnode] = 1;
    while(!stk.empty()){
        current = stk.top();
        stk.pop();
        visited[current] = 2;
        cout << "Processed node : " << current << endl;
        for(int a : adjList[current]){
            if(visited[a] == 0){
                stk.push(a);
                visited[a] = 1;
            }
        }
    }


return 0;
}