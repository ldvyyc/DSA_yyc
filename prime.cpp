#include <stdio.h>
#include <stdlib.h> //两个必须的文件
#include <time.h>   //两个必须的文件
// #include <iostream>
// #include <fstream>
// using namespace std;

const __int64 MAX = 2000000000;
const int MAXP = 700000000;
bool p[MAXP] = {false};
__int64 x[2] = {2, 3};
int c = 2;
int cal(int n) //计算n这个数字在数组中的位置,即小于等于n的前面有多少个不能被2和3整除
{
    return n - n / 2 - n / 3 + n / 6;
}
int main()
{
    printf("%d\n", cal(MAX));
    __int64 i, cnt = 0;
    int j, k;
    int s = time(0), e;
    p[1] = true; //第一个是1
    p[0] = true; //第0个是0,这两个都不是素数
    // ofstream fout("prime.txt");
    for (i = 2; i < MAX; i++)
    {
        if ((i & 1) && i % 3 != 0 && !p[cal(i)])
        {
            printf("%I64d\n", i);
            // fout << i << ',';
            k = 0;
            for (j = i * i; j < MAX; j += i)
            {
                if (0 == (j & 1) || j % 3 == 0)
                    continue;
                //printf("%d\n",j);
                k = j - j / 2 - j / 3 + j / 6; //查找j这个数字在数组是第几位
                p[k] = true;
            }
            e = time(0);
            //getchar();
        }
    }
    k = MAX - MAX / 2 - MAX / 3 + MAX / 6;
    j = 0;
    for (i = 2; i <= k; i++)
        j += (p[i] == false);
    // printf("共发现%d个素数\n", j + 2); //再加上2和3两个
    e = time(0);
    // printf("此次运行耗时%d秒\n", e - s);
    // fout.close();
    return 0;
}