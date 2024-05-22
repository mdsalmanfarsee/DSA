#include <iostream>
#include <fstream>
using namespace std;

struct item
{
    int src;
    int cost;
};

class pqueue
{

    item arr[50];
    int size = 0;
    int index = -1;

public:
    int parent(int ind)
    {
        return (ind - 1) / 2;
    }
    void push(int s, int val)
    {
        index++;
        size++;
        arr[index].src = s;
        arr[index].cost = val;

        // heapify up
        int i = index;
        while (i != 0 && arr[i].cost < arr[parent(i)].cost)
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    bool empty()
    {
        return index == -1;
    }
    void heapify(int ind)
    {
        int largest = ind;
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;

        if (left < size && arr[left].cost < arr[largest].cost)
            largest = left;
        if (right < size && arr[right].cost < arr[largest].cost)
            largest = right;

        if (largest != ind)
        {
            swap(arr[largest], arr[ind]);
            ind = largest;
            heapify(ind);
        }
    }

    item pop()
    {
        if (empty())
            exit(0);
        item ans = arr[0];
        swap(arr[0], arr[index]);
        index--;
        size--;
        if (index > 0)
            heapify(0); // heapify up
        return ans;
    }
};

int main()
{

    fstream infile;
    infile.open("./prims.txt", ios::in);
    if (!infile)
    {
        cout << "error";
        return 0;
    }
    int n; // number of edges;
    infile >> n;
    int v; // number of vertex
    infile >> v;
    int graph[v][v];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            infile >> graph[i][j];
        }
    }

    int s = 0; // start from source 0
    bool visited[v];
    int dist[v];
    int parent[v];
    item mstEdge[v - 1]; // v-1 number of edges in mst
    int ind = 0;         // initial index
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        dist[i] = 9999;
        parent[i] = -1;
    }
    dist[s] = 0;
    pqueue pq;
    pq.push(s, 0);
    int sum = 0;
    // string path = "";
    while (!pq.empty())
    {
        item a = pq.pop();
        int u = a.src;

        if (visited[u])
            continue;
        visited[u] = true;
        sum += dist[a.src];
        if (parent[u] != -1)
        {
            mstEdge[ind].src = parent[u];
            mstEdge[ind].cost = u;
            ind++;
        }
        // find all adjacent
        for (int i = 0; i < v; i++)
        {
            if (!visited[i] && graph[u][i] && graph[u][i] < dist[i])
            {
                dist[i] = graph[u][i];
                pq.push(i, dist[i]);
                parent[i] = u;
            }
        }
    }
    cout << "total cost is: " << sum << endl;
    cout << " path is : " << endl;
    for (int i = 0; i < v - 1; i++)
    {
        cout << mstEdge[i].src << "  " << mstEdge[i].cost << endl;
    }

    return 0;
}