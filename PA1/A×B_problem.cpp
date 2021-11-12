#include <iostream>
#include <cstring>
using namespace std;
string x, y, ou, temm;
int main()
{
    ios::sync_with_stdio(false); //提升输入输出速度
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        cin >> y;
        int lenx = x.length();    //x长度
        int leny = y.length();    //y长度
        if (lenx < 9 && leny < 9) //特判，若x，y均小于9位，直接相乘
        {
            long long a, b;
            a = stoi(x);
            b = stoi(y);
            long long c = a * b;
            cout << c << endl;
            continue;
        }
        int lenszx = lenx / 8 + 1; //所开的数组大小
        int lenszy = leny / 8 + 1;
        long long szx[lenszx] = {0}; //初始化数组
        long long szy[lenszy] = {0};

        int j = 1, k = 1;
        for (int i = lenx % 8; i <= lenx - 8; i += 8) //从lenx%8开始每8位一赋值给数组
        {
            ou = x.substr(i, 8);
            szx[j] = stoi(ou);
            j++;
        }
        ou = x.substr(0, lenx % 8); //复制最开始的几位，特判长度为8的倍数情况
        if (ou.length() > 0)
            szx[0] = stoi(ou);
        else
        {
            szx[0] = {0};
        };
        for (int i = leny % 8; i <= leny - 8; i += 8) //y数组同理
        {
            ou = y.substr(i, 8);
            szy[k] = stoi(ou);
            k++;
        }
        ou = y.substr(0, leny % 8);
        if (ou.length() > 0)
            szy[0] = stoi(ou);
        else
        {
            szy[0] = {0};
        };

        long long fin[lenszx + lenszy] = {0}; //final数组
        int finint[lenszx + lenszy] = {0};    //转化为int存储
        for (int i = lenszx - 1; i >= 0; i--)
        {
            for (int j = lenszy - 1; j >= 0; j--)
            {
                fin[i + j + 1] += szx[i] * szy[j];
            }
        }
        for (int i = lenszx + lenszy - 1; i >= 0; i--)
        {
            if (fin[i] >= 100000000) //若超过8位，则进位
            {
                int xx;
                xx = fin[i] % 100000000;
                fin[i - 1] += fin[i] / 100000000;
                finint[i] = xx;
            }
            else //直接赋值
            {
                finint[i] = fin[i];
            }
        }

        int temint;
        temm = "";
        ou = "";
        for (int i = 0; i <= lenszx + lenszy - 1; i++)
        {
            if (ou.length() == 0) //初始为0时，直接跳过
            {
                if (finint[i] == 0)
                {
                    continue;
                }
                ou += to_string(finint[i]);
                continue;
            }
            temm = to_string(finint[i]); //8位前补齐0
            temint = 8 - temm.length();
            for (j = 0; j < temint; j++)
            {
                ou += "0";
            }
            ou += temm;
        }
        if (ou.length() == 0) //若整体为0，即x，y中有一个为0，则输出0
        {
            ou += "0";
        }
        cout << ou << endl;
    }
    return 0;
}