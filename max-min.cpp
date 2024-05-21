#include <iostream>
#include <fstream>
#define INF 9999
using namespace std;

struct item
{
    int max;
    int min;
};

item maxMin(int arr[], int i, int j)
{
    item ans;
    if (i == j)
    {
        ans.max = ans.min = arr[i];
        return ans;
    }
    else if (i + 1 == j)
    {
        if (arr[i] <= arr[j])
        {
            ans.max = arr[j];
            ans.min = arr[i];
        }
        else
        {
            ans.max = arr[i];
            ans.min = arr[j];
        }
        return ans;
    }
    int mid = (i + j) / 2;
    item left = maxMin(arr, i, mid);
    item right = maxMin(arr, mid + 1, j);
    ans.max = (left.max > right.max) ? left.max : right.max;
    ans.min = (left.min < right.min) ? left.min : right.min;
    return ans;
}

int main()
{
    fstream infile;
    infile.open("../max-min.txt", ios::in);
    if (!infile)
    {
        cout << "error" << endl;
        return 0;
    }
    int n; // size
    infile >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        infile >> arr[i];
    }

    // get the ans
    item ans = maxMin(arr, 0, n - 1);

    cout << "smallest element is: " << ans.min << endl;
    cout << "heighest element is : " << ans.max << endl;

    return 0;
}