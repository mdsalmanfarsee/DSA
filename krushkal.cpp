#include <iostream>
#include <fstream>
using namespace std;

struct edge
{
    int src;
    int dest;
    int weight;
};

void sort(edge arr[], int n)
{
    // bubble sort
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j].weight > arr[j + 1].weight)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void makeset(int parent[], int rank[], int v)
{
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find_par(int parent[], int index)
{
    if (parent[index] == index)
    {
        return index;
    }
    return parent[index] = find_par(parent, parent[index]); // path compression
}

void unionset(int parent[], int rank[], int u, int v)
{
    int par_u = find_par(parent, u);
    int par_v = find_par(parent, v);

    if (rank[par_u] > rank[par_v])
    {
        parent[v] = par_u;
    }
    else if (rank[par_v] > rank[par_u])
    {
        parent[u] = par_v;
    }
    else
    {
        parent[v] = par_u;
        rank[par_u]++;
    }
}

int main()
{
    fstream infile;
    infile.open("../krushkal.txt", ios::in);
    if (!infile)
    {
        cout << "error" << endl;
        return 0;
    }

    int n; // number of edges
    infile >> n;
    edge arr[n];
    int v; // number of vertices
    infile >> v;

    for (int i = 0; i < n; i++)
    {
        infile >> arr[i].src;
        infile >> arr[i].dest;
        infile >> arr[i].weight;
    }

    int parent[v];
    int rank[v];
    makeset(parent, rank, v);
    sort(arr, n); // sort according to edge weight

    // union operation
    string path = "";
    int sum = 0;

    for (int i = 0; i < n; i++) // traverse for all the edges
    {
        int u = arr[i].src;
        int v = arr[i].dest;
        int w = arr[i].weight;

        int par_u = find_par(parent, u);
        int par_v = find_par(parent, v);

        if (par_u != par_v) // if parent are same then it will form a cycle
        {
            sum += w;
            path += "(" + to_string(u) + "," + to_string(v) + ")";
            unionset(parent, rank, u, v); // add the edges into the disjoint set
        }
    }

    cout << "total cost is: " << sum << "and path is : " << path << endl;

    return 0;
}