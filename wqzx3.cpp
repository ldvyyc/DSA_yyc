#include <iostream>
#include <string.h>
using namespace std;

int main()
{
  long long n = 1, i = 2, j = 0, time = 0;
  cin >> n;
  bool a = false;
  long long p[10000];
  while (n > 1)
  {
    if (n % i == 0)
    {
      p[j] = i;
      j++;
      n /= i;
      time++;
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
  for (long long k = 0; k < j; k++)
  {
    cout << p[k] << endl;
  }
  return 0;
}
