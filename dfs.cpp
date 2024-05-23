#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *adjlist[10] = {NULL};

void insert(int i, int j)
{
    Node *curr = new Node();
    curr->data = j;
    curr->next = NULL;

    if (adjlist[i] == NULL)
    {
        adjlist[i] = curr;
        return;
    }
    Node *temp = adjlist[i];
    while (temp->next)
        temp = temp->next;
    temp->next = curr;
}

void dfs(int node, bool visited[])
{
    visited[node] = true;
    cout << node << "  ";

    Node *temp = adjlist[node];
    while (temp)
    {
        if (!visited[temp->data])
        {
            dfs(temp->data, visited);
        }
        temp = temp->next;
    }
}

int main()
{
    fstream infile;
    infile.open("dfs.txt", ios::in);
    if (!infile)
        return 0;
    int n; // number of vertex
    infile >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int data;
            infile >> data;
            if (data)
                insert(i, j);
        }
    }
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    cout << "dfs traversal is: ";
    dfs(0, visited);

    return 0;
}