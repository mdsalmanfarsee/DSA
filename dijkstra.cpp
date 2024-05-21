#include <iostream>
#include <fstream>
#define maxval 10
#define INF 999
using namespace std;

int v; // number of vertices
int graph[maxval][maxval];

int minIndex(int key[maxval], bool vis[maxval])
{
    int minval = INF;
    int index;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i] && key[i] < minval)
        {
            minval = key[i];
            index = i;
        }
    }
    return index;
}

void path(int parent[maxval], int ind)
{
    if (parent[ind] == -1)
    {
        cout << ind;
        return;
    }
    path(parent, parent[ind]);
    cout << "-->" << ind;
}

void dijkstra(int src)
{
    int key[maxval];
    int parent[maxval];
    bool vis[maxval];
    for (int i = 0; i < v; i++)
    {
        key[i] = INF;
        parent[i] = INF;
        vis[i] = false;
    }
    key[src] = 0;
    parent[src] = -1;

    // logic

    for (int i = 0; i < v - 1; i++)
    {
        int m = minIndex(key, vis);
        vis[m] = true;
        for (int n = 0; n < v; n++)
        {
            if (!vis[n] && graph[m][n] && key[m] != INF && key[m] + graph[m][n] < key[n])
            {
                key[n] = key[m] + graph[m][n];
                parent[n] = m;
            }
        }
    }

    // print
    for (int i = 0; i < v; i++)
    {
        cout << "path from " << src << " to " << i << ":";
        int temp = i;
        if (parent[temp] == INF)
        {
            cout << "no path" << endl;
        }
        else
        {
            path(parent, i);
            cout << "| cost --> " << key[i] << endl;
        }
    }
}

int main()
{
    fstream infile;
    infile.open("../graph.txt", ios::in);
    if (!infile)
    {
        cout << "error" << endl;
        return 0;
    }
    infile >> v;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            infile >> graph[i][j];
        }
    }

    // source
    int src = 0;
    dijkstra(src);
    return 0;
}