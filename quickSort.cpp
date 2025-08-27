#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    int pos = start;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] <= arr[end])
            swap(arr[i], arr[pos++]);
    }

    // return the index of pivot element
    return pos - 1;
}

void quickSort(vector<int> &arr, int start, int end)
{

    if (start >= end)
        return;

    int pivot = partition(arr, start, end);

    // Left Side
    quickSort(arr, start, pivot - 1);
    // Right Side
    quickSort(arr, pivot + 1, end);
}

int main()
{
    vector<int> arr = {6, 4, 2, 8, 13, 7, 11, 9, 3, 6};
    int n = arr.size();

    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

// TC => n^2 (Worst Case)
// TC => nlogn (Average Case)
// SC => logn (Average Case)
// SC => n (Worst Case)