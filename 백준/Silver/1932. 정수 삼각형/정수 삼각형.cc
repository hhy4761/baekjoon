#include <bits/stdc++.h>
using namespace std;

int n;
int nums[501][501];
int d[501][501];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> nums[i][j];
        }
    }
    d[1][1] = nums[1][1];
    d[2][1] = d[1][1] + nums[2][1];
    d[2][2] = d[1][1] + nums[2][2];
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
                d[i][j] = d[i - 1][j] + nums[i][j];

            else if (j == i)
                d[i][j] = d[i - 1][j - 1] + nums[i][j];

            else
                d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + nums[i][j];
        }
    }
    int *max = max_element(d[n],d[n]+n+1);
    cout << *max;
}