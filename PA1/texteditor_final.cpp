#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

struct List_Node //节点
{
    char a;
    int Rank;
    List_Node *suc;
};
//使用数组存储两个单向链表
List_Node Nodes[7200010];
List_Node Nodes2[7200010];
//约定Nodes为正向，Nodes2为反向，数组第一位为head，第二位为tail，初始化左右指针，以及反向链表的左右指针
List_Node *Left_Cursor = &Nodes[0];
List_Node *Right_Cursor = &Nodes[1];
List_Node *Left_Cursor2 = &Nodes2[1];
List_Node *Right_Cursor2 = &Nodes2[0];
//构造List
class List
{
public:
    int cnt; //记录开的数组物理上用到了哪一位
    List_Node *head;
    List_Node *tail;
    List_Node *head2;
    List_Node *tail2;

    List();
    void Insert(char const &e, char LorR); //插入
    void Delete(char LorR);                //删除
    void Reverse();                        //翻转
    void LeftCursorMoveLeft();             //左游标左移
    void LeftCursorMoveRight();            //左游标右移
    void RightCursorMoveLeft();            //右游标左移
    void RightCursorMoveRight();           //右游标右移
    void ShowCursor();                     //Debug用，显示当前数组使用情况以及指针指向
    ~List(){};
};

List::List()
{
    head = &Nodes[0];
    tail = &Nodes[1];
    tail->suc = NULL;
    head->suc = tail;
    tail->Rank = 1;
    head->Rank = 0;

    cnt = 2;

    head2 = &Nodes2[0];
    tail2 = &Nodes2[1];
    tail2->suc = head2;
    head2->suc = NULL;
    head2->Rank = 0;
    tail2->Rank = 1;
}

void List::ShowCursor()
{
    cout << Left_Cursor->Rank << ' ' << Right_Cursor->Rank << ' ' << Left_Cursor2->Rank << ' ' << Right_Cursor2->Rank << endl;
    for (int i = 2; i < cnt; i++)
    {
        cout << i << ": " << Nodes[i].a << endl;
    }
}

void List::Insert(char const &e, char LorR)
{
    int TempRank;
    if (LorR == 'L')
    {
        List_Node *Left_Cursor_Pre;
        Nodes[cnt].a = e;
        Nodes[cnt].Rank = cnt;
        TempRank = Right_Cursor2->suc->Rank;
        if (&Nodes2[TempRank] == Right_Cursor2->suc)
        {
            Left_Cursor_Pre = &Nodes[TempRank];
        }
        else
        {
            Left_Cursor_Pre = &Nodes2[TempRank];
        }
        Left_Cursor_Pre->suc = &Nodes[cnt];
        Nodes[cnt].suc = Left_Cursor;

        Nodes2[cnt].a = e;
        Nodes2[cnt].Rank = cnt;
        List_Node *Right_Cursor2_Suc = Right_Cursor2->suc;
        Right_Cursor2->suc = &Nodes2[cnt];
        Nodes2[cnt].suc = Right_Cursor2_Suc;
    }
    else
    {
        List_Node *Right_Cursor_Pre;
        Nodes[cnt].a = e;
        Nodes[cnt].Rank = cnt;
        TempRank = Left_Cursor2->suc->Rank;
        if (&Nodes2[TempRank] == Left_Cursor2->suc)
        {
            Right_Cursor_Pre = &Nodes[TempRank];
        }
        else
        {
            Right_Cursor_Pre = &Nodes2[TempRank];
        }
        Right_Cursor_Pre->suc = &Nodes[cnt];
        Nodes[cnt].suc = Right_Cursor;

        Nodes2[cnt].a = e;
        Nodes2[cnt].Rank = cnt;
        List_Node *Left_Cursor2_Suc = Left_Cursor2->suc;
        Left_Cursor2->suc = &Nodes2[cnt];
        Nodes2[cnt].suc = Left_Cursor2_Suc;
    }
    cnt++;
    return;
};

void List::Delete(char LorR)
{
    int TempRank1, TempRank2;
    if (LorR == 'L')
    {
        List_Node *Left_Cursor_Pre;
        TempRank1 = Right_Cursor2->suc->Rank;
        if (&Nodes2[TempRank1] == Right_Cursor2->suc)
        {
            Left_Cursor_Pre = &Nodes[TempRank1];
        }
        else
        {
            Left_Cursor_Pre = &Nodes2[TempRank1];
        }
        List_Node *Right_Cursor2_Pre;
        TempRank2 = Left_Cursor->suc->Rank;
        if (&Nodes[TempRank2] == Left_Cursor->suc)
        {
            Right_Cursor2_Pre = &Nodes2[TempRank2];
        }
        else
        {
            Right_Cursor2_Pre = &Nodes[TempRank2];
        }
        Left_Cursor = Left_Cursor->suc;
        Left_Cursor_Pre->suc->suc = NULL;
        Left_Cursor_Pre->suc = Left_Cursor;

        Right_Cursor2_Pre->suc = Right_Cursor2->suc;
        Right_Cursor2->suc = NULL;
        Right_Cursor2 = Right_Cursor2_Pre;
    }
    else
    {
        List_Node *Right_Cursor_Pre;
        TempRank1 = Left_Cursor2->suc->Rank;
        if (&Nodes2[TempRank1] == Left_Cursor2->suc)
        {
            Right_Cursor_Pre = &Nodes[TempRank1];
        }
        else
        {
            Right_Cursor_Pre = &Nodes2[TempRank1];
        }
        List_Node *Left_Cursor2_Pre;
        TempRank2 = Right_Cursor->suc->Rank;
        if (&Nodes[TempRank2] == Right_Cursor->suc)
        {
            Left_Cursor2_Pre = &Nodes2[TempRank2];
        }
        else
        {
            Left_Cursor2_Pre = &Nodes[TempRank2];
        }
        Right_Cursor = Right_Cursor->suc;
        Right_Cursor_Pre->suc->suc = NULL;
        Right_Cursor_Pre->suc = Right_Cursor;

        Left_Cursor2_Pre->suc = Left_Cursor2->suc;
        Left_Cursor2->suc = NULL;
        Left_Cursor2 = Left_Cursor2_Pre;
    }
    return;
}

void List::Reverse()
{
    int TempRank1, TempRank2;
    List_Node *Left_Cursor_Pre;
    List_Node *Right_Cursor_Pre;
    List_Node *Right_Cursor2_Suc;
    List_Node *Left_Cursor2_Suc;

    TempRank1 = Right_Cursor2->suc->Rank;
    if (&Nodes2[TempRank1] == Right_Cursor2->suc)
    {
        Left_Cursor_Pre = &Nodes[TempRank1];
    }
    else
    {
        Left_Cursor_Pre = &Nodes2[TempRank1];
    }
    TempRank2 = Left_Cursor2->suc->Rank;
    if (&Nodes2[TempRank2] == Left_Cursor2->suc)
    {
        Right_Cursor_Pre = &Nodes[TempRank2];
    }
    else
    {
        Right_Cursor_Pre = &Nodes2[TempRank2];
    }
    Left_Cursor2_Suc = Left_Cursor2->suc;
    Right_Cursor2_Suc = Right_Cursor2->suc;

    Left_Cursor_Pre->suc = Left_Cursor2_Suc;
    Right_Cursor_Pre->suc = Right_Cursor2_Suc;
    Left_Cursor2->suc = Left_Cursor;
    Right_Cursor2->suc = Right_Cursor;

    Left_Cursor = Left_Cursor2_Suc;
    Right_Cursor2 = Right_Cursor_Pre;
    return;
}

void List::LeftCursorMoveLeft()
{
    if (Left_Cursor == &Nodes[0])
    {
        return;
    }
    int TempRank;
    TempRank = Right_Cursor2->suc->Rank;
    if (&Nodes2[TempRank] == Right_Cursor2->suc)
    {
        Left_Cursor = &Nodes[TempRank];
    }
    else
    {
        Left_Cursor = &Nodes2[TempRank];
    }
    Right_Cursor2 = Right_Cursor2->suc;
    return;
}

void List::LeftCursorMoveRight()
{
    if (Left_Cursor == &Nodes[1])
    {
        return;
    }
    int TempRank;
    TempRank = Left_Cursor->suc->Rank;
    if (&Nodes2[TempRank] == Left_Cursor->suc)
    {
        Right_Cursor2 = &Nodes[TempRank];
    }
    else
    {
        Right_Cursor2 = &Nodes2[TempRank];
    }
    Left_Cursor = Left_Cursor->suc;
    return;
}

void List::RightCursorMoveLeft()
{
    if (Right_Cursor == &Nodes[0])
    {
        return;
    }
    int TempRank;
    TempRank = Left_Cursor2->suc->Rank;
    if (&Nodes2[TempRank] == Left_Cursor2->suc)
    {
        Right_Cursor = &Nodes[TempRank];
    }
    else
    {
        Right_Cursor = &Nodes2[TempRank];
    }
    Left_Cursor2 = Left_Cursor2->suc;
    return;
}

void List::RightCursorMoveRight()
{
    if (Right_Cursor == &Nodes[1])
    {
        return;
    }
    int TempRank;
    TempRank = Right_Cursor->suc->Rank;
    if (&Nodes2[TempRank] == Right_Cursor->suc)
    {
        Left_Cursor2 = &Nodes[TempRank];
    }
    else
    {
        Left_Cursor2 = &Nodes2[TempRank];
    }
    Right_Cursor = Right_Cursor->suc;
    return;
}

int main()
{
    //程序默认游标在指向位置的左手边，反向链表则在右边，因此游标不能指向head
    ios::sync_with_stdio(false);
    List TextEditor;
    string x;
    getline(cin, x);
    int len = x.length();
    char *a = new char[len];
    strcpy(a, x.c_str());
    for (int i = 0; i < len; i++)
    {
        TextEditor.Insert(a[i], 'R');
    }
    TextEditor.LeftCursorMoveRight(); //左游标初始为0
    int m;
    cin >> m;
    char inn, m1, m2;
    int LefCount = 0; //记录游标左边有几个元素
    int RigCount = len;
    List_Node *point = TextEditor.head;
    for (int i = 0; i < m; i++)
    {
        cin >> inn;
        switch (inn)
        {
        case 'C': //调试用
            TextEditor.ShowCursor();
            break;
        case '<':
            cin >> m1;
            if (m1 == 'L')
            {
                if (Right_Cursor2->suc->Rank == 0)
                {
                    putchar('F');
                    putchar('\n');
                    break;
                }
                LefCount--;
                TextEditor.LeftCursorMoveLeft();
                putchar('T');
                putchar('\n');
                break;
            }
            else
            {
                if (Left_Cursor2->suc->Rank == 0)
                {
                    putchar('F');
                    putchar('\n');
                    break;
                }
                RigCount--;
                TextEditor.RightCursorMoveLeft();
                putchar('T');
                putchar('\n');
                break;
            }
            break;
        case '>':
            cin >> m1;
            if (m1 == 'L')
            {
                if (Left_Cursor == TextEditor.tail)
                {
                    putchar('F');
                    putchar('\n');
                    break;
                }
                LefCount++;
                TextEditor.LeftCursorMoveRight();
                putchar('T');
                putchar('\n');
                break;
            }
            else
            {
                if (Right_Cursor == TextEditor.tail)
                {
                    putchar('F');
                    putchar('\n');
                    break;
                }
                RigCount++;
                TextEditor.RightCursorMoveRight();
                putchar('T');
                putchar('\n');
                break;
            }
            break;
        case 'I':
            cin >> m1 >> m2;
            if (m1 == 'L')
            {
                if (LefCount <= RigCount)
                {
                    LefCount++;
                    RigCount++;
                }
                else
                {
                    LefCount++;
                }
                TextEditor.Insert(m2, 'L');
                putchar('T');
                putchar('\n');
                break;
            }
            else
            {
                if (RigCount <= LefCount)
                {
                    LefCount++;
                    RigCount++;
                }
                else
                {
                    RigCount++;
                }
                TextEditor.Insert(m2, 'R');
                putchar('T');
                putchar('\n');
                break;
            }
        case 'D': //需要保证相邻时L总在R左侧
            cin >> m1;
            if (m1 == 'L')
            {
                if (Left_Cursor == TextEditor.tail)
                {
                    putchar('F');
                    putchar('\n');
                    break;
                }
                TextEditor.Delete('L');
                if (RigCount == LefCount)
                {
                    Right_Cursor = Left_Cursor;
                    Left_Cursor2 = Right_Cursor2;
                }
                if (RigCount > LefCount)
                {
                    RigCount--;
                }
                putchar('T');
                putchar('\n');
                break;
            }
            else
            {
                if (Right_Cursor == TextEditor.tail)
                {
                    putchar('F');
                    putchar('\n');
                    break;
                }
                TextEditor.Delete('R');
                if (RigCount == LefCount)
                {
                    Left_Cursor = Right_Cursor;
                    Right_Cursor2 = Left_Cursor2;
                }
                if (LefCount > RigCount)
                {
                    LefCount--;
                }
                putchar('T');
                putchar('\n');
                break;
            }
        case 'R':
            if (LefCount < RigCount)
            {
                TextEditor.Reverse();
                putchar('T');
                putchar('\n');
                break;
            }
            putchar('F');
            putchar('\n');
            break;
        case 'S':
            while (point->suc->Rank != 1)
            {
                point = point->suc;
                putchar(point->a);
            }
            point = TextEditor.head;
            putchar('\n');
            break;
        default:
            break;
        }
    }
    return 0;
}