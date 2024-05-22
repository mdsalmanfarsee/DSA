#include <iostream>
#include <fstream>
using namespace std;

struct job
{
    int id;
    int deadline;
    int profit;
};

void sort(job arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j].profit < arr[j + 1].profit)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void jobSequencing(job arr[], int n)
{
    int result[n];
    bool slot[n];
    for (int i = 0; i < n; i++)
    {
        result[i] = -1;
        slot[i] = false;
    }

    // sort according to profit
    sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].deadline); j >= 0; j--)
        {
            if (!slot[j])
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    // calculate profit
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (result[i] != -1)
        {
            cout << "JOB Id : " << arr[result[i]].id << " with profit: " << arr[result[i]].profit << endl;
            total += arr[result[i]].profit;
        }
    }

    cout << "total profit: " << total << endl;
}

int main()
{
    fstream infile;
    infile.open("job.txt", ios::in);

    int n; // size
    infile >> n;
    job arr[n];
    for (int i = 0; i < n; i++)
    {
        infile >> arr[i].id;
        infile >> arr[i].deadline;
        infile >> arr[i].profit;
    }

    jobSequencing(arr, n);

    return 0;
}