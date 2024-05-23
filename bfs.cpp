#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *adjlist[10] = {NULL};

class queue
{
    Node *front;
    Node *rear;

public:
    queue()
    {
        front = rear = NULL;
    }

    void push(int v)
    {
        Node *curr = new Node();
        curr->data = v;
        curr->next = NULL;
        if (rear == NULL)
        {
            front = rear = curr;
            return;
        }

        rear->next = curr;
        rear = rear->next;
    }
    bool empty()
    {
        return front == NULL;
    }
    int pop()
    {
        if (empty())
            exit(0);
        Node *temp = front;
        front = front->next;
        int val = temp->data;
        if (front == NULL)
            rear = NULL;
        delete temp;
        return val;
    }
};

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
    queue q;
    for (int i = 0; i < n; i++)
        visited[i] = false;
    cout << "bfs traversal is: ";
    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
        int node = q.pop();
        cout << node << "  ";
        Node *temp = adjlist[node];
        while (temp)
        {
            if (!visited[temp->data])
            {
                visited[temp->data] = true;
                q.push(temp->data);
            }
            temp = temp->next;
        }
    }

    return 0;
}