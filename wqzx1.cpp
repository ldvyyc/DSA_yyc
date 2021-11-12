#include <iostream>
using namespace std;

int main()
{
    long long M, N;
    cin >> M >> N;
    long long ori[M + 1][N + 1] = {0};
    for (long long i = 1; i <= M; i++)
    {
        for (long long j = 1; j <= N; j++)
        {
            cin >> ori[i][j];
        }
    }
    long long memo[M + 1][N + 1];
    for (long long i = 0; i < M + 1; i++)
    {
        memo[i][0] = 0;
    }
    for (long long i = 0; i < N + 1; i++)
    {
        memo[0][i] = 0;
    }
    // cout << memo[0][0] << ' ' << memo[0][1] << ' ' << memo[1][0] << endl;
    for (long long i = 1; i <= M; i++)
    {
        for (long long j = 1; j <= N; j++)
        {
            memo[i][j] = memo[i - 1][j] + memo[i][j - 1] - memo[i - 1][j - 1] + ori[i][j];
            // cout << "memo[" << i << "][" << j << "] = " << memo[i][j] << endl;
        }
    }
    // return 0;
    long long maxx = ori[1][1];
    long long profit = 0;
    for (long long i = 0; i < M; i++)
    {
        for (long long k = 0; k < N; k++)
        {
            for (long long j = i+1; j < M + 1; j++)
            {
                for (long long l = k+1; l < N + 1; l++)
                {
                    profit = memo[j][l] + memo[i][k] - memo[i][l] - memo[j][k];
                    if (profit > maxx)
                    {
                        maxx = profit;
                    }
                    profit = 0;
                }
            }
        }
    }
    cout << maxx << endl;
    return 0;
}