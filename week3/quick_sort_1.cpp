/**
* @author: Jakir Hasan
* 04-05-2023
* Total Comparisons in QuickSort considering first element as pivot
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int total_comparison = 0;

int partition_array(int arr[], int low, int high)
{
    int pivot, i, j, tmp;
    pivot = arr[low];

    i = low + 1;
    for (j = low+1; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
            i++;
        }
    }

    tmp = arr[low];
    arr[low] = arr[i-1];
    arr[i-1] = tmp;

    return i-1;
}

void quick_sort(int arr[], int low, int high)
{
    int pivot_index, length;
    if (low >= high)
        return;

    length = high - low + 1;
    total_comparison += (length - 1);

    pivot_index = partition_array(arr, low, high);
    quick_sort(arr, low, pivot_index-1);
    quick_sort(arr, pivot_index+1, high);
}

int main()
{
    int n = 10000, i, j, arr[10001], low, high;
    freopen("QuickSort.txt", "r", stdin);
    int num, cnt = 0;

    i = 0;
    while (cin>> num)
    {
        arr[i] = num;
        cnt++;
        i++;
    }

    low = 0;
    high = n-1;
    quick_sort(arr, low, high);

    cout<< total_comparison << "\n";

    return 0;
}

/*
Output
-------
162085
*/
