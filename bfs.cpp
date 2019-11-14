#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Edges {
    int src;
    int dest;
};

void bfs(vector < vector<int> > const &, int[], int);

int main() {
    const int nodes = 10;
    vector < vector<int> > adjList;
    static int visited[nodes];
    int current;
    int startnode = 0;
    adjList.resize(10);

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

    bfs(adjList, visited, startnode);
return 0;
}


void bfs(vector < vector<int> > const &mylist, int visit[], int startnode){
    int current = startnode;
    queue<int> que;
    que.push(startnode);
    visit[startnode] = 1;
    while(!que.empty()){
        current = que.front();
        que.pop();
        cout << "Processed node : " << current << endl;
        visit[current] = 2;
        for(int a : mylist[current]){
            if(visit[a] == 0){
                que.push(a);
                visit[a] = 1;
            }
        }
    }
}