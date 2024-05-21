#include <iostream>
#include <fstream>
#define INF 999
#define maxvertices 10

using namespace std;

// number of vertices
int nv;
int graph[maxvertices][maxvertices];

// print table
void printtable(int m[][maxvertices])
{
    for (int i = 0; i < nv; i++)
    {
        for (int j = 0; j < nv; j++)
        {
            cout << m[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
// print recursion
void print(int s[][maxvertices], int u, int v)
{
    if (s[u][v] == u)
    {
        cout << "--> " << v;
        return;
    }
    print(s, u, s[u][v]);
    print(s, s[u][v], v);
}

// print path
void printpath(int m[][maxvertices], int s[][maxvertices])
{
    for (int i = 0; i < nv; i++)
    {
        for (int j = 0; j < nv; j++)
        {
            cout << "path from " << i << " to " << j << " is: ";
            if (i != j)
            {

                print(s, i, j);
                cout << " | cost --> " << m[i][j] << endl;
            }
            else
            {
                cout << "no path!" << endl;
            }
        }
        cout << "|||||||||||||||||||||||||||" << endl;
    }
}

// logic
void floyed()
{
    int m[maxvertices][maxvertices];
    int s[maxvertices][maxvertices];

    for (int i = 0; i < nv; i++)
    {
        for (int j = 0; j < nv; j++)
        {
            if (i == j)
            {
                s[i][j] = -1;
            }
            else if (graph[i][j] != INF)
            {
                s[i][j] = i;
            }
            else
                s[i][j] = INF;

            m[i][j] = graph[i][j];
        }
    }

    // main operation
    for (int k = 0; k < nv; k++)
    {
        for (int i = 0; i < nv; i++)
        {
            for (int j = 0; j < nv; j++)
            {
                if (m[i][k] + m[k][j] < m[i][j])
                {
                    m[i][j] = m[i][k] + m[k][j];
                    s[i][j] = k;
                }
            }
        }
    }
    // print m table
    printtable(m);
    // print path
    printpath(m, s);
}

int main()
{
    fstream infile;
    infile.open("graph.txt", ios::in);
    if (!infile)
    {
        cout << "file opening error!" << endl;
        return 0;
    }
    infile >> nv;
    for (int i = 0; i < nv; i++)
    {
        for (int j = 0; j < nv; j++)
        {
            infile >> graph[i][j];
        }
    }
    infile.close();
    floyed();
    return 0;
}
