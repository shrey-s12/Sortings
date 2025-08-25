#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    int n = end - start + 1;
    vector<int> temp(n);

    int i = start, j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // left array is not empty
    while (i <= mid)
        temp[k++] = arr[i++];

    // right array is not empty
    while (j <= end)
        temp[k++] = arr[j++];

    // Copy temp into array
    k = 0;
    while (start <= end)
        arr[start++] = temp[k++];
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if (start == end)
        return;

    int mid = start + (end - start) / 2;

    // Left Side
    mergeSort(arr, start, mid);
    // Right Side
    mergeSort(arr, mid + 1, end);

    // Merge left + Right
    merge(arr, start, mid, end);
}

int main()
{
    // vector<int> arr = {7, 5, 6, 9, 3};
    vector<int> arr = {8, 2, 4, 1, 5, 7, 5, 6, 9, 3};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}