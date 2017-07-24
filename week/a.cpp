#include <cstdio>
#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>

struct Graph
{
    int *adj[];
};

struct Edge
{
    int v;
    int w;
    int weight;
};

struct Node
{
    int v;
};

struct Edge newEdge(int v, int w, int weight){
    Edge e;
    e.v = v;
    e.w = w;
    e.weight = weight;
    return e;
}

int main(){
    std::priority_queue<int> q;
    // get value for number of nodes and edges
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph g;

    // load all the graph
    int from, to, weight;
    while (scanf("%d %d %d", &from, &to, &weight) == 3){
        Edge e = newEdge(from, to, weight);
        g
    }



    return 0;
}
