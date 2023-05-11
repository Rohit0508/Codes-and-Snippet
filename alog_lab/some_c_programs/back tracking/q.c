#include <stdio.h>
#include <string.h>
#define maxsize 100
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int main()
{
    int n, m;
    char s1[maxsize];
    char s2[maxsize];
    scanf("%s", s1);
    scanf("%s", s2);
    n = strlen(s1);
    m = strlen(s2);
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int size = dp[n][m];
    char lcs[size];
    int i = n, j = m;
    while (i >= 0 && j >= 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs[size - 1] = s1[i - 1];
            size--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
            j--;
    }
    printf("%s", lcs);

    return 0;
}