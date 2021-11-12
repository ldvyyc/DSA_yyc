#include <iostream>
using namespace std;

int main()
{
    long long n;
    int j = 0, time = 0;
    cin >> n;
    bool a = false;
    int p[100000];
    int outt[10000];
    int idx = 300000;
    int prime[idx + 1] = {1, 1};
    for (int d = 2; d < idx + 1; d++)
    {
        if (prime[d] == 0)
        {
            for (int k = d + d; k < idx + 1; k += d)
                prime[k] = 1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < idx + 1; i++)
    {
        if (prime[i] == 0)
        {
            p[cnt++] = i;
        }
    }
    int i=0;
    while (n > 1)
    {
        if (n % p[i] == 0)
        {
            outt[j] = p[i];
            j++;
            n /= p[i];
            time++;
            i = 0;
            if (time == 2)
                a = true;
        }
        else
        {
            time = 0;
            i++;
        }
    }
    if (a)
        cout << 'B' << endl;
    else
        cout << 'A' << endl;
    for (int k = 0; k < j; k++)
    {
        cout << outt[k] << endl;
    }
    return 0;
}
