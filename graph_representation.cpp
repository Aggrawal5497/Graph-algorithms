#include<iostream>
#include<vector>
using namespace std;

struct edges {
    int src;
    int dest;
};

int main() {
    vector< vector<int> > adjList;
    adjList.resize(4);

    vector<edges> edglist = {
        {0, 1}, {0, 2}, {0, 3}, {1, 3}
    };

    for(auto &e : edglist){
        adjList[e.src].push_back(e.dest);
        adjList[e.dest].push_back(e.src);
    }

    for(int i = 0; i < 4; i++) {
        cout << "Vertex " << i << " --> ";
        for(int v : adjList[i]){
            cout << v << " ";
        }
        cout << endl;
    }
return 0;
}