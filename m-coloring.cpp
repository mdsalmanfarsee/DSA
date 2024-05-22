#include <iostream>
#include <fstream>
#define maxsize 10
using namespace std;

int graph[maxsize][maxsize];

int n; // number of vertices

bool safe(int v, int color[], int c)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

bool operation(int v, int color[], int m)
{
    if (v == n)
        return true;
    for (int c = 1; c <= m; c++)
    {
        if (safe(v, color, c))
        {
            color[v] = c;
            if (operation(v + 1, color, m))
            {
                return true;
            }
            // back track
            color[v] = 0;
        }
    }
}

void graphcoloring(int v, int m)
{
    int color[n];
    for (int i = 0; i < n; i++)
        color[i] = 0;

    if (!operation(v, color, m))
    {
        cout << "graph coloring not possible" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "vertex " << i << " is colored with: " << color[i] << endl;
    }
}

int main()
{
    fstream infile;
    infile.open("./m-coloring.txt", ios::in);
    if (!infile)
    {
        cout << "error" << endl;
        return 0;
    }
    infile >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            infile >> graph[i][j];
        }
    }
    int m; // number of colors
    cout << "enter number of colors: ";
    cin >> m;
    graphcoloring(0, m);
    return 0;
}