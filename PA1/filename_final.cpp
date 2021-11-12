#include <iostream>
#include <cstring>
using namespace std;
int N, M, K;
int mymax(int a, int b) //返回较大数
{
    return a > b ? a : b;
}
int memo[2][400] = {0}; //使用两行循环更新数字
int temp[2010][2010] = {0};
int LCS(char *a, char *b, int alen, int blen, int K)
{
    if ((alen - blen > 100) || (blen - alen > 100))
    {
        return 0;
    }
    if (!(alen > 2000) && !(blen > 2000)) //特判，当a,b长度均小于2000时，直接全部迭代出结果
    {
        for (int i = 1; i < blen; i++)
        {
            for (int j = 1; j < alen; j++)
            {
                if (b[i] == a[j])
                {
                    temp[i][j] = temp[i - 1][j - 1] + 1;
                    continue;
                }
                temp[i][j] = mymax(temp[i - 1][j], temp[i][j - 1]);
            }
        }
        return temp[blen - 1][alen - 1];
    }

    for (int i = 1; i < 103; i++) //先使用temp直接求出前101行，202列的数据，减少特判
    {                             //前101行
        for (int j = 1; j < 207; j++)
        { //前202列
            if (b[i] == a[j])
            {
                temp[i][j] = temp[i - 1][j - 1] + 1;
                continue;
            }
            temp[i][j] = mymax(temp[i - 1][j], temp[i][j - 1]);
        }
    }
    for (int i = 0; i < 205; i++)
    {
        memo[0][i] = temp[102][i];
    }
    int curline = 1; //current line，当前在迭代的这个
    int befline = 0; //before line，上一行是哪个
    int count = 1;
    int finline = 0;                 //最终迭代的哪一行
    for (int i = 103; i < blen; i++) //单重循环，内部为固定长度的循环
    {
        for (int j = i - 101; j < i + 103; j++)
        {
            if (i == blen - 1)
            {
                finline = curline;
            }
            if (b[i] == a[j])
            {
                memo[curline][count] = memo[befline][count] + 1;
                count++;
                continue;
            }
            memo[curline][count] = mymax(memo[curline][count - 1], memo[befline][count + 1]);
            count++;
        }
        if (curline == 1)
        {
            curline = 0;
            befline = 1;
        }
        else
        {
            curline = 1;
            befline = 0;
        }
        count = 1;
    }
    return memo[finline][alen - blen + 102];
};

int main()
{
    cin >> N >> M >> K;
    char fir[N + 110]; //末尾补0，方便之后判断对角线后100位时不必特判，也不会出现数组越界访问
    fir[0] = 0;
    char sec[M + 1];
    sec[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> fir[i];
    }
    for (int i = N + 1; i < N + 110; i++)
    {
        fir[i] = 0;
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> sec[i];
    }
    int tt; //LCS长度
    tt = LCS(fir, sec, N + 1, M + 1, K);
    int fin = M + N - 2 * tt; //最多需要的操作数
    if (fin > K)
    {
        cout << "-1" << endl;
        return 0;
    }
    cout << fin << endl;
    return 0;
}