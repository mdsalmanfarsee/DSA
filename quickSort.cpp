#include <iostream>
#include <fstream>
using namespace std;

int partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int i = left, j = right;
    while (i < j)
    {
        while (i <= right && arr[i] <= pivot)
        {
            i++;
        }
        while (j > left && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    // swap with pivot element
    swap(arr[left], arr[j]);
    return j;
}

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
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
    quickSort(arr, 0, n - 1);
    cout << "after sorting: ";
    print(arr, n);
    return 0;
}