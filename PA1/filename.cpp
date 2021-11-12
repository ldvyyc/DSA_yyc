#include <iostream>
#include <cstring>
using namespace std;
int N, M, K;
int mymax(int a, int b)
{
    return a > b ? a : b;
}
int memo[2][400] = {0};
int temp[2010][2010] = {0};
int LCS(char *a, char *b, int alen, int blen, int K)
{
    if ((alen - blen > 100) || (blen - alen > 100))
    {
        return 0;
    }
    if (!(alen > 2000) && !(blen > 2000))
    {
        for (int i = 1; i < blen; i++)
        {
            for (int j = 1; j < alen; j++)
            {
                if (b[i] == a[j])
                {
                    temp[i][j] = temp[i - 1][j - 1] + 1;
                    // cout << i << ' ' << j << ": " << temp[i][j] << endl;
                    continue;
                }
                temp[i][j] = mymax(temp[i - 1][j], temp[i][j - 1]);
                // cout << i << ' ' << j << ": " << temp[i][j] << endl;
            }
        }
        // for (int j=500; j<505; j++){
        //     for (int i=j-101; i<j+103; i++){
        //         cout << temp[j][i] << ' ';
        //     }  
        //     cout << endl;
        // }
        
        return temp[blen-1][alen-1];
    }

    for (int i=1; i<103; i++){//前101行
        for (int j=1; j<207; j++){//前202列
            if (b[i] == a[j])
                {
                    temp[i][j] = temp[i - 1][j - 1] + 1;
                    // cout << i << ' ' << j << ": " << temp[i][j] << endl;
                    continue;
                }
                temp[i][j] = mymax(temp[i - 1][j], temp[i][j - 1]);
                // cout << i << ' ' << j << ": " << temp[i][j] << endl;
        }
    }
    for (int i=0; i<205; i++){
        // cout << temp[102][i] << ' ';
        memo[0][i] = temp[102][i];
    }
    int curline = 1;
    int befline = 0;
    int count = 1;
    int finline = 0;
    for (int i=103; i<blen; i++){
        for (int j=i-101; j<i+103; j++){
            if (i == blen-1){
                finline = curline;
            }
            if (b[i]==a[j]){
                memo[curline][count] = memo[befline][count] + 1;
                count++;
                continue;
            }
            memo[curline][count] = mymax(memo[curline][count-1],memo[befline][count+1]);
            count++;
        }
        // if (i>=500 && i<505){
        //     for (int h=1; h<205; h++){
        //         cout << memo[curline][h] <<' ';
        //     }
        //     cout << endl;
        // }
        // cout << memo[curline][103] << endl;
        // memo[curline][count] = memo[curline][count-1];
        if(curline==1){
            curline = 0;
            befline = 1;
        }
        else{
            curline = 1;
            befline = 0;
        }
        count = 1;
    }
    return memo[finline][alen-blen+102];
};

int main()
{
    cin >> N >> M >> K;
    char fir[N + 110];
    fir[0] = 0;
    char sec[M + 1];
    sec[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> fir[i];
    }
    for (int i=N+1; i<N+110; i++){
        fir[i] = 0;
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> sec[i];
    }
    int tt;
    tt = LCS(fir, sec, N + 1, M + 1, K);
    // cout << tt << endl;
    int fin = M+N-2*tt;
    if (fin > K)
    {
        cout << "-1" << endl;
        return 0;
    }
    cout << fin << endl;
    return 0;
}