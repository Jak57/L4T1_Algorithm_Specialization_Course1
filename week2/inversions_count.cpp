/**
* @author: Jakir Hasan
* 23-04-2023
* Inversion
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll inversion = 0;

void merge_left_right_halves(int arr[], int low, int mid, int high)
{
    int tmp[high-low+1];
    int i, j, k, length, id;

    i = low;
    j = mid+1;
    length = mid - low + 1;
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
                id = i - low;
                inversion += ll(length - id);
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
    int n = 100000, i, j, arr[100001], low, high;
    freopen("IntegerArray.txt", "r", stdin);
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
    merge_sort(arr, low, high);

    cout<< inversion << "\n";

    return 0;
}


/*
Output
-------
2407905288
*/
