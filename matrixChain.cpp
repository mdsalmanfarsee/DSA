#include <iostream>
#include <fstream>
#define INF 999
using namespace std;

int m[10][10];
int s[10][10];

void printtable(int table[10][10], int n)
{
    for (int i = 1; i <= n; i++) // 1 base indexing
    {
        for (int j = 1; j <= n; j++)
        {
            cout << table[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

// display
void display(int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
        return;
    }
    cout << "(";
    display(i, s[i][j]);
    display(s[i][j] + 1, j);
    cout << ")";
}

int matrixchain(int p[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0; // diagonal elements are zero
    }

    for (int size = 2; size <= n; size++)
    {
        for (int i = 1; i <= n - size + 1; i++)
        {
            int j = i + size - 1;
            m[i][j] = INF;
            for (int k = i; k < j; k++)
            {
                int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (temp < m[i][j])
                {
                    m[i][j] = temp;
                    s[i][j] = k;
                }
            }
        }
    }
    // print table
    printtable(m, n);

    return m[1][n];
}

int main()
{
    fstream infile;
    infile.open("../matrixChain.txt", ios::in);
    if (!infile)
    {
        cout << "error" << endl;
        return 0;
    }
    int n; // number  of matrix
    infile >> n;
    int p[n + 1]; // size of p-table will be n+1
    for (int i = 0; i <= n; i++)
    {
        infile >> p[i];
    }

    int val = matrixchain(p, n);

    display(1, n);
    cout << "\ntotal cost is: " << val;

    return 0;
}