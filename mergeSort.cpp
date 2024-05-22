#include <iostream>
#include <fstream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int size = right - left + 1;
    int temp[size];
    int i = left, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    // copy the data in the main array
    k = 0; // re initialize
    for (k = 0; k < size; k++)
    {
        arr[left + k] = temp[k];
    }
}

void mergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    fstream infile;
    infile.open("../sort.txt", ios::in);
    if (!infile)
    {
        cout << "error";
        return 0;
    }
    int n; // size
    infile >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        infile >> arr[i];
    }

    cout << "before sorting: ";
    print(arr, n);
    mergesort(arr, 0, n - 1);
    cout << "after sorting: ";
    print(arr, n);
    return 0;
}