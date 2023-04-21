/**
* @author: Jakir Hasan
* 21-04-2023
* Large Integer Multiplication
*/

#include<bits/stdc++.h>
using namespace std;

string grad_school_multiplication(string a, string b)
{
    int n, m, i, j, prod, carry, len;
    n = a.size();
    m = b.size();

    // Convert string to vector of int in reverse order
    vector<int> x;
    vector<int> y;

    for (i = n-1; i >= 0; i--)
        x.push_back(a[i] - '0');

    for (i = m-1; i >= 0; i--)
        y.push_back(b[i] - '0');


    vector<int> result(n + m, 0);
    for (i = 0; i < m; i++)
    {
        carry = 0;
        for (j = 0; j < n; j++)
        {
            prod = y[i] * x[j] + carry + result[i+j];
            carry = prod / 10;
            result[i + j] = prod % 10;
        }
        result[i + n] = carry;
    }

    // Removing leading zeros
    while (result.size() > 1 && result.back() == 0)
        result.pop_back();

    len = result.size();
    string product = "";
    for (i = len - 1; i >= 0; i--) {
        product += (result[i] + '0');
    }

    return product;
}

int main()
{
    string x, y, product;
    x = "3141592653589793238462643383279502884197169399375105820974944592";
    y = "2718281828459045235360287471352662497757247093699959574966967627";

    product = grad_school_multiplication(x, y);
    cout<< "Product is:" << "\n";
    cout<< product << "\n";

    return 0;
}
