/**
* @author: Jakir Hasan
* 23-04-2023
* Merge Sort
*/

#include<bits/stdc++.h>
using namespace std;

void merge_left_right_halves(int arr[], int low, int mid, int high)
{
    int tmp[high-low+1];
    int i, j, k;

    i = low;
    j = mid+1;
    for (k = 0; k <= high-low; k++)
    {
        if (i <= mid && j <= high) {
            if (arr[i] < arr[j])
            {
                tmp[k] = arr[i];
                i++;
            }
            else
            {
                tmp[k] = arr[j];
                j++;
            }
        }
        else
            break;
    }

    while (i <= mid)
    {
        tmp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        tmp[k] = arr[j];
        j++;
        k++;
    }

    k = 0;
    for (i = low; i <= high; i++)
    {
        arr[i] = tmp[k];
        k++;
    }
}

void merge_sort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        // sort left half
        merge_sort(arr, low, mid);
        // sort right half
        merge_sort(arr, mid+1, high);
        // merge
        merge_left_right_halves(arr, low, mid, high);
    }
}

int main()
{
    int n, i, j, arr[10000], low, high;
    cin>> n;

    for (i = 0; i < n; i++)
        cin>> arr[i];

    low = 0;
    high = n-1;
    merge_sort(arr, low, high);

    for (i = 0; i < n; i++)
        cout<< arr[i] << " ";
    cout<< "\n";

    return 0;
}


/*
Input
------
6
2 4 5 6 1 3

Output:
-------
1 2 3 4 5 6
*/
