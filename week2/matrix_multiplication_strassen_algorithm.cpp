/**
* @author: Jakir Hasan
* 28-04-2023
* Strassen Matrix Multiplication Algorithm
*/

#include<bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vv;

void sub(vv &X, vv &Y, vv &Z, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            Z[i][j] = X[i][j] - Y[i][j];
        }
    }
}

void add(vv &X, vv &Y, vv &Z, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            Z[i][j] = X[i][j] + Y[i][j];
        }
    }
}

void strassen_algorithm(vv &X, vv &Y, vv &Z, int n)
{
    int m, i, j;
    if (n == 1)
    {
        Z[0][0] = X[0][0] * Y[0][0];
        return;
    }
    else
    {
        m = n / 2;
        vector<int> zeros(m, 0);

        // Dividing X into 4 sub-matrices of size m x m
        vv A(m, zeros);
        vv B(m, zeros);
        vv C(m, zeros);
        vv D(m, zeros);

        // Dividing Y into 4 sub-matrices of size m x m
        vv E(m, zeros);
        vv F(m, zeros);
        vv G(m, zeros);
        vv H(m, zeros);

        // Dividing Z into 4 sub-matrices of size m x m
        vv I(m, zeros);
        vv J(m, zeros);
        vv K(m, zeros);
        vv L(m, zeros);

        // 10 matrices
        vv s1(m, zeros);
        vv s2(m, zeros);
        vv s3(m, zeros);
        vv s4(m, zeros);
        vv s5(m, zeros);

        vv s6(m, zeros);
        vv s7(m, zeros);
        vv s8(m, zeros);
        vv s9(m, zeros);
        vv s10(m, zeros);

        // 7 matrices
        vv p1(m, zeros);
        vv p2(m, zeros);
        vv p3(m, zeros);
        vv p4(m, zeros);
        vv p5(m, zeros);

        vv p6(m, zeros);
        vv p7(m, zeros);

        // 2 temporary matrices
        vv temp1(m, zeros);
        vv temp2(m, zeros);

        // Creating sub-matrices of size m x m
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < m; j++)
            {
                A[i][j] = X[i][j];
                B[i][j] = X[i][j+m];
                C[i][j] = X[i+m][j];
                D[i][j] = X[i+m][j+m];
            }
        }

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < m; j++)
            {
                E[i][j] = Y[i][j];
                F[i][j] = Y[i][j+m];
                G[i][j] = Y[i+m][j];
                H[i][j] = Y[i+m][j+m];
            }
        }

        // 10 matrices

        // s1 = F - H
        sub(F, H, s1, m);

        // s2 = A + B
        add(A, B, s2, m);

        // s3 = C + D
        add(C, D, s3, m);

        // s4 = G - E
        sub(G, E, s4, m);

        // s5 = A + D
        add(A, D, s5, m);

        // s6 = E + H
        add(E, H, s6, m);

        // s7 = B - D
        sub(B, D, s7, m);

        // s8 = G + H
        add(G, H, s8, m);

        // s9 = A - C
        sub(A, C, s9, m);

        // s10 = E + F
        add(E, F, s10, m);


        // Calculating 7 products
        // p1 = A . s1
        strassen_algorithm(A, s1, p1, m);

        // p2 = s2 . H
        strassen_algorithm(s2, H, p2, m);

        // p3 = s3 . E
        strassen_algorithm(s3, E, p3, m);

        // p4 = D .s4
        strassen_algorithm(D, s4, p4, m);

        // p5 = s5. s6
        strassen_algorithm(s5, s6, p5, m);

        // p6 = s7 . s8
        strassen_algorithm(s7, s8, p6, m);

        // p7 = s9 . s10
        strassen_algorithm(s9, s10, p7, m);


        // Calculating output sub-matrices

        // I = p5 + p4 - p2 + p6
        add(p5, p4, temp1, m);
        add(temp1, p6, temp2, m);
        sub(temp2, p2, I, m);

        // J = p1 + p2
        add(p1, p2, J, m);

        // K = p3 + p4
        add(p3, p4, K, m);

        // L = p1 + p5 - p3 - p7
        add(p1, p5, temp1, m);
        sub(temp1, p3, temp2, m);
        sub(temp2, p7, L, m);


        // Combining output sub-matrices
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < m; j++)
            {
                Z[i][j] = I[i][j];
                Z[i][j+m] = J[i][j];
                Z[i+m][j] = K[i][j];
                Z[i+m][j+m] = L[i][j];
            }
        }
    }
}

int main()
{
    int n, i, j, k, num;
    cin>> n; // size of matrix is n x n

    vector<int> zeros(n, 0);
    vv X;
    vv Y;
    vv Z(n, zeros);

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
    strassen_algorithm(X, Y, Z, n);

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

