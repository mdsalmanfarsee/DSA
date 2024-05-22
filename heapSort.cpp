#include <iostream>
#include <fstream>
using namespace std;

void heapify(int arr[], int ind, int n)
{
    int largest = ind;
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != ind)
    {
        swap(arr[largest], arr[ind]);
        ind = largest;
        heapify(arr, ind, n);
    }
}

void heapSort(int arr[], int n)
{
    // make heap
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
    // sort
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
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
    heapSort(arr, n);
    cout << "after sorting: ";
    print(arr, n);
    return 0;
}