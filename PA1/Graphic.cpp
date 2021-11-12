#include <iostream>
using namespace std;

void Merge(long long *a, long long lo, long long mi, long long hi);
void MergeSort(long long *a, long long lo, long long hi);
long long BinSearch(long long x[], long long y[], long long q[], long long lo, long long hi);
long long max_bin = -1;
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
    MergeSort(y, 0, n);
    long long m;
    cin >> m;
    long long q[2];
    for (long long  i = 0; i < m; i++)
    {
        cin >> q[0] >> q[1];
        cout << BinSearch(x, y, q, 0, n) << endl;
    }
    delete[] x;
    delete[] y;
    return 0;
}

void MergeSort(long long a[], long long lo, long long hi)
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
    while ((i < mi) && (j < hi))
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
    while (i < mi)
    {
        b[index++] = a[i++];
    }
    while (j < hi)
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
        long long calc = x[mi] * q[1] - x[mi] * y[mi] + q[0] * y[mi]; //大于0说明在外侧
        if (calc == 0)
        {
            max_bin = -1;
            min_bin = -2;
            return mi + 1;
        }
        if (calc > 0)
        {
            min_bin = mi;
            lo = mi + 1;
        }
        else
        {
            max_bin = mi;
            hi = mi;
        }
    }
    if (min_bin == (nn - 1))
    {
        max_bin = -1;
        min_bin = -2;
        return nn;
    }
    long long nnn = max_bin;
    max_bin = -1;
    min_bin = -2;
    return nnn;
}