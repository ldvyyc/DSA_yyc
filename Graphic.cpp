#include <iostream>
using namespace std;

void Merge(int a[], int lo, int mi, int hi);
void MergeSort(int a[], int lo, int hi);
int BinSearch(int x[], int y[], int q[], int lo, int hi);
int max_bin = -1;
int min_bin = -2;
int main()
{
    int n;
    cin >> n;
    int x[n];
    int y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    MergeSort(x, 0, n);
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }
    MergeSort(y, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << y[i] << ' ';
    }
    // int m;
    // cin >> m;
    // int q[2];
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> q[0] >> q[1];
    //     cout << BinSearch(x,y,q,0,n) << endl;
    // }
    return 0;
}

void MergeSort(int a[], int lo, int hi)
{
    if (hi - lo < 2)
        return;
    int mi = (lo + hi) >> 1;
    MergeSort(a, lo, mi);
    MergeSort(a, mi, hi);
    Merge(a, lo, mi, hi);
};

void Merge(int a[], int lo, int mi, int hi)
{
    // cout << "aa" << endl;
    cout << "Merge: " << lo << ' ' << hi << endl;
    int b[hi - lo];
    int index = lo;
    int i = lo;
    int j = mi;
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
    for (int k = lo; k < hi; k++)
    {
        a[k] = b[k];
    }
};

int BinSearch(int x[], int y[], int q[], int lo, int hi){
    int nn = hi;
    while(lo<hi){
        cout << lo << ' ' << hi << endl;
        int mi = (lo+hi) >> 1;
        if (x[mi]*q[1]-x[mi]*y[mi]+q[0]*y[mi] < 0){
            min_bin = mi;
            lo = mi + 1;
        }
        else{
            max_bin = mi;
            hi = mi;
        }
    }
    if (max_bin==-1){
        min_bin = -2;
        return 0;
    }
    if (min_bin==-2){
        cout << "min_bin" << endl;
        max_bin = -1;
        return nn;
    }
    cout << max_bin << endl;

    int nnn = max_bin + 1;
    max_bin = -1;
    min_bin = -2;
    return nnn;
}