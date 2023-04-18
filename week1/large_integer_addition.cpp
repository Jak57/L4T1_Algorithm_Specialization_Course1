#include<bits/stdc++.h>
using namespace std;

string large_int_add(string x, string y)
{
    /**
    Adds large integers of equal length.
    */

    int n, m, i, j, carry = 0, rem, digit1, digit2, total, mx;
    vector<int> v;
    string sum = "";
    char ch;

    n = x.size();
    m = y.size();
    mx = max(n, m);

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    while (x.size() != mx)
        x += '0';

    while (y.size() != mx)
        y += '0';

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    cout<< x << " " << y << "\n";

    for (i = mx-1; i >= 0; i--) {

        digit1 = x[i] - '0';
        digit2 = y[i] - '0';
        total = digit1 + digit2 + carry;

        rem = total % 10;
        carry = total / 10;
        ch = rem + '0';
        sum += ch;
    }

    reverse(sum.begin(), sum.end());
    return sum;
}

int main()
{
    string x = "456";
    string y = "123456";
    string sum;

    sum = large_int_add(x, y);
    cout<< sum << "\n";


    return 0;
}

/*
Output:
------

23912
*/
