#include<bits/stdc++.h>
using namespace std;

string large_int_sub(string x, string y)
{
    /**
    Subtracts two large integers of equal length.
    */
    int n, m, i, j, borrow, diff, digit1, digit2;
    n = x.size();
    string ans = "";
    char ch;

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    borrow = 0;
    for (i = 0; i < n; i++) {
        digit1 = x[i] - '0';
        digit2 = y[i] - '0';

        diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else
            borrow = 0;

        ch = diff + '0';
        ans += ch;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string x = "654321";
    string y = "123456";
    string sub;

    sub = large_int_sub(x, y);
    cout<< sub << "\n";

    return 0;
}

/*
Output:
------

530865
*/
