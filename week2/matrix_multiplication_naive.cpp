/**
* @author: Jakir Hasan
* 27-04-2023
* Matrix Multiplication Naive Approach
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, k, num;
    cin>> n; // size of matrix is n x n

    vector<int> zeros(n, 0);
    vector< vector<int> > X;
    vector< vector<int> > Y;
    vector< vector<int> > Z(n, zeros);

    // matrix X
    for (i = 0; i < n; i++)
    {
        vector<int> tmp;
        for (j = 0; j < n; j++)
        {
            cin>> num;
            tmp.push_back(num);
        }
        X.push_back(tmp);
    }

    // matrix Y
    for (i = 0; i < n; i++)
    {
        vector<int> tmp;
        for (j = 0; j < n; j++)
        {
            cin>> num;
            tmp.push_back(num);
        }
        Y.push_back(tmp);
    }

    // Z = X . Y
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                Z[i][j] += (X[i][k] * Y[k][j]);
            }
        }
    }

    cout<< "\nOutput matrix is: " << "\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout<< Z[i][j] << " ";
        cout<< "\n";
    }

    return 0;
}


/*
Input:
--------

4

1         1         1         1
2         2         2         2
3         3         3         3
2         2         2         2

1         1         1         1
2         2         2         2
3         3         3         3
2         2         2         2

Output:
---------

8         8         8         8
16        16        16        16
24        24        24        24
16        16        16        16

*/

