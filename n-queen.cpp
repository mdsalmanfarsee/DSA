#include <iostream>
using namespace std;

#define size 10
int n; // number of queen

// print table
void printTable(int board[size][size])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j])
                cout << "Q  ";
            else
                cout << "X  ";
        }
        cout << endl;
    }
    cout << endl;
}

bool safe(int board[size][size], int row, int col)
{
    int i = row, j = col;
    // check left
    for (j = col; j >= 0; j--)
    {
        if (board[i][j])
            return false;
    }

    // check left up corner
    j = col;
    i = row;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j])
            return false;
        i--;
        j--;
    }

    // check left down corner
    j = col;
    i = row;
    while (i < n && j >= 0)
    {
        if (board[i][j])
            return false;
        i++;
        j--;
    }

    return true;
}

void nqueen(int board[size][size], int col)
{
    if (col == n)
    {
        printTable(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (safe(board, row, col))
        {
            board[row][col] = 1;
            nqueen(board, col + 1);
            // back track
            board[row][col] = 0;
        }
    }
}

int main()
{
    cout << "enter number of queen: ";
    cin >> n;
    int board[size][size];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    nqueen(board, 0);

    return 0;
}