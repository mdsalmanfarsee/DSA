#include <iostream>
#include <fstream>
#define INF 999
using namespace std;

struct edge
{
    int src;
    int dest;
    int weight;
};

void path(int parent[], int u)
{
    if (parent[u] == -1)
    {
        cout << u;
        return;
    }
    path(parent, parent[u]);
    cout << "--> " << u;
}

void belmann(edge arr[], int n, int src, int v)
{
    int dist[v];
    int parent[v];
    for (int i = 0; i < v; i++)
    {
        dist[i] = INF;
        parent[i] = INF;
    }
    dist[src] = 0;
    parent[src] = -1;

    for (int i = 0; i < v - 1; i++) // v-1 times iteration
    {
        for (int k = 0; k < n; k++) // traverse all the edges
        {
            if (dist[arr[k].src] != INF && dist[arr[k].src] + arr[k].weight < dist[arr[k].dest])
            {
                dist[arr[k].dest] = dist[arr[k].src] + arr[k].weight;
                parent[arr[k].dest] = arr[k].src;
            }
        }
    }
    // check 1 more time for negative edge
    for (int k = 0; k < n; k++) // traverse all the edges
    {
        if (dist[arr[k].src] != INF && dist[arr[k].src] + arr[k].weight < dist[arr[k].dest])
        {
            cout << "graph contains negative weight" << endl;
            return;
        }
    }

    // print path & cost
    for (int i = 0; i < v; i++)
    {
        cout << "path from " << src << " to " << i << ":";
        if (parent[i] == INF)
        {
            cout << "no path" << endl;
        }
        else
        {
            path(parent, i);
            cout << "  | cost --> " << dist[i] << endl;
        }
    }
}

int main()
{
    fstream infile;
    infile.open("belmann.txt", ios::in);
    if (!infile)
    {
        cout << "eror" << endl;
        return 0;
    }
    int n; // number of edges
    infile >> n;
    int v; // number of vertices
    infile >> v;
    edge arr[n];
    for (int i = 0; i < n; i++)
    {
        infile >> arr[i].src;
        infile >> arr[i].dest;
        infile >> arr[i].weight;
    }
    belmann(arr, n, 0, v);

    return 0;
}
