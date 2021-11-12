#include <iostream>
using namespace std;

void Merge(long long *a, long long lo, long long mi, long long hi);                           //归并中的合
void MergeSort(long long *a, long long lo, long long hi);                                     //归并中的分
long long BinSearch(long long x[], long long y[], long long q[], long long lo, long long hi); //二分查找
long long max_bin = -1;                                                                       //二分查找的上下界
long long min_bin = -2;
int main()
{
    long long n;
    cin >> n;
    long long *x = new long long[n];
    long long *y = new long long[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    MergeSort(x, 0, n);
    for (long long i = 0; i < n; i++)
    {
        cin >> y[i];
    }
    MergeSort(y, 0, n); //两次归并都变为有序且两组数据的下标相同数据连线
    long long m;
    cin >> m;
    long long q[2];
    for (long long i = 0; i < m; i++) //每次查询输出
    {
        cin >> q[0] >> q[1];
        cout << BinSearch(x, y, q, 0, n) << endl;
    }
    delete[] x;
    delete[] y;
    return 0;
}

void MergeSort(long long a[], long long lo, long long hi) //分而治之，每次二分，递归
{
    if (hi - lo < 2)
        return;
    long long mi = (lo + hi) >> 1;
    MergeSort(a, lo, mi);
    MergeSort(a, mi, hi);
    Merge(a, lo, mi, hi);
};

void Merge(long long a[], long long lo, long long mi, long long hi)
{
    long long *b = new long long[hi - lo];
    long long index = 0;
    long long i = lo;
    long long j = mi;
    while ((i < mi) && (j < hi)) //两边都有剩余，比较后放回原数组
    {
        if (a[i] < a[j])
        {
            b[index++] = a[i++];
        }
        else
        {
            b[index++] = a[j++];
        }
    }
    while (i < mi) //剩余前半部分，全部放回
    {
        b[index++] = a[i++];
    }
    while (j < hi) //剩余后半部分，全部放回
    {
        b[index++] = a[j++];
    }
    for (long long k = lo; k < hi; k++)
    {
        a[k] = b[k - lo];
    }
    delete b;
    return;
};

long long BinSearch(long long x[], long long y[], long long q[], long long lo, long long hi)
{
    long long nn = hi;
    while (lo < hi)
    {
        long long mi = (lo + hi) >> 1;
        long long calc = x[mi] * q[1] - x[mi] * y[mi] + q[0] * y[mi]; //ToLeft测试，向量叉乘，大于0说明在外侧
        if (calc == 0) //特判，即正好压中，直接返回
        {
            max_bin = -1;
            min_bin = -2;
            return mi + 1;
        }
        if (calc > 0) //在外侧，继续向上找
        {
            min_bin = mi;
            lo = mi + 1;
        }
        else //在内测，向里找
        {
            max_bin = mi;
            hi = mi;
        }
    }
    if (min_bin == (nn - 1)) //找到最高位，返回全部
    {
        max_bin = -1;
        min_bin = -2;
        return nn;
    }
    long long nnn = max_bin; //正常返回
    max_bin = -1;
    min_bin = -2;
    return nnn;
}