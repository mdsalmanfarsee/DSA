#include <iostream>
#include <fstream>
#define maxval 100
using namespace std;

int dp[maxval][maxval];

struct item
{
    int val;
    int weight;
};

int knapsack(item arr[], int capacity, int ind, int taken[])
{
    if (ind < 0 || capacity == 0)
        return 0;
    if (dp[ind][capacity] != -1)
        return dp[ind][capacity];

    int take = 0, notake = 0;
    if (arr[ind].weight <= capacity)
    {
        take = arr[ind].val + knapsack(arr, capacity - arr[ind].weight, ind - 1, taken);
    }
    notake = knapsack(arr, capacity, ind - 1, taken);

    taken[ind] = (take > notake) ? 1 : 0;
    return dp[ind][capacity] = max(take, notake);
}

int main()
{
    fstream infile;
    infile.open("./knapsack.txt", ios::in);
    int n; // size
    infile >> n;
    item arr[n];
    int taken[n]; // store which item take in how much fraction
    for (int i = 0; i < n; i++)
    {
        infile >> arr[i].val;
        infile >> arr[i].weight;
        taken[i] = 0;
    }
    int capacity;
    cout << "enter capacity:";
    cin >> capacity;

    // fill dp
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            dp[i][j] = -1;
        }
    }

    int val = knapsack(arr, capacity, n - 1, taken);

    cout << "total profit: " << val << endl;
    cout << "item taken: ";
    for (int i = 0; i < n; i++)
    {
        cout << taken[i] << "  ";
    }
    cout << endl;

    return 0;
}