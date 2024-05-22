#include <iostream>
#include <fstream>
using namespace std;

struct item
{
    int val;
    int weight;
};

void sort(item arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            float ratio1 = (arr[j].val) / float(arr[j].weight);
            float ratio2 = (arr[j + 1].val) / float(arr[j + 1].weight);
            if (ratio1 < ratio2) // if ratio is greater apears at beginning
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

float knapsack(item arr[], float take[], int n, float capacity)
{
    // sort according to val/weight ratio
    sort(arr, n);

    float ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= capacity)
        {
            ans += arr[i].val;
            take[i] = 1.0;
            capacity -= arr[i].weight;
        }
        else
        {
            float fraction = arr[i].val / float(arr[i].weight);
            take[i] = capacity / float(arr[i].weight);
            ans += fraction * capacity;
            break;
        }
    }
    return ans;
}

int main()
{
    fstream infile;
    infile.open("./knapsack.txt", ios::in);
    int n; // size
    infile >> n;
    item arr[n];
    float take[n]; // store which item take in how much fraction
    for (int i = 0; i < n; i++)
    {
        infile >> arr[i].val;
        infile >> arr[i].weight;
        take[i] = 0.0;
    }
    float capacity;
    cout << "enter capacity:";
    cin >> capacity;

    float val = knapsack(arr, take, n, capacity);

    cout << "total profit: " << val << endl;
    cout << "item taken: ";
    for (int i = 0; i < n; i++)
    {
        cout << take[i] << "  ";
    }
    cout << endl;

    return 0;
}