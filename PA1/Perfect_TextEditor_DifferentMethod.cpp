#include <iostream>
#include <cstring>
using namespace std;

struct List_Node
{
    int DifCursor;
    char a;
    List_Node * suc;
    List_Node * pre;
    List_Node() { 
        DifCursor=0;
        a = 'a';
        suc = NULL;
    }
};

List_Node Nodes[7300000];
List_Node Nodes2[7300000];
    
class List
{
public:
    int Size;//数组现在真实长度多大
    int cnt;//记录开的数组物理上用到了哪一位
    List_Node * head;
    List_Node * tail;
    List_Node * head2;
    List_Node * tail2;

    List_Node * Right_Cursor;
    List_Node * Left_Cursor;
    List_Node * Right_Cursor2;
    List_Node * Left_Cursor2;
    List();
    void Insert(char const & e, List_Node * p);
    void Delete(List_Node * p);
    void Reverse(List_Node * a, List_Node * b);
    void Switch(List_Node * p, List_Node * q);
    int OutSize(){
        return Size;
    }
};

List::List(){

    head = &Nodes[0];
    tail = &Nodes[1];
    Left_Cursor = &Nodes[2];
    Right_Cursor = &Nodes[3];
    Left_Cursor->DifCursor = 3;
    Left_Cursor->a = '[';
    Right_Cursor->DifCursor = 4;
    Right_Cursor->a = ']';
    head->DifCursor = 2;
    tail->DifCursor = 2;
    tail->suc = NULL;
    tail->pre = Right_Cursor;
    head->suc = Left_Cursor;
    head->pre = NULL;
    Left_Cursor->suc = Right_Cursor;
    Left_Cursor->pre = head;
    Right_Cursor->suc = tail;
    Right_Cursor->pre = Left_Cursor;
    Size = 0;
    cnt = 4;

    head2 = &Nodes2[0];
    tail2 = &Nodes2[1];
    Left_Cursor2 = &Nodes2[2];
    Right_Cursor2 = &Nodes2[3];
    Left_Cursor2->DifCursor = 3;
    Left_Cursor2->a = '[';
    Right_Cursor2->DifCursor = 4;
    Right_Cursor2->a = ']';
    head2->DifCursor = 2;
    tail2->DifCursor = 2;
    tail2->suc = Right_Cursor2;
    tail2->pre = NULL;
    head2->suc = NULL;
    head2->pre = Left_Cursor2;
    Left_Cursor2->suc = head2;
    Left_Cursor2->pre = Right_Cursor2;
    Right_Cursor2->suc = Left_Cursor2;
    Right_Cursor2->pre = tail2;
}

void List::Insert(char const & e, List_Node * p){//插入，不需要ListNode了，在List里完成
    Size++;
    List_Node * x = &Nodes[cnt];
    List_Node * y = &Nodes2[cnt];
    x->DifCursor = 0;
    x->a = e;
    y->DifCursor = 0;
    y->a = e;

    List_Node * tmp1 = p->pre;
    tmp1->suc = x;
    x->pre = tmp1;
    x->suc = p;
    p->pre = x;

    if(p->DifCursor == 3){
        List_Node * tmp2 = Left_Cursor2->suc;
        tmp2->pre = y;
        y->suc = tmp2;
        y->pre = Left_Cursor2;
        Left_Cursor2->suc = y;
    }
    else{
        List_Node * tmp2 = Right_Cursor2->suc;
        tmp2->pre = y;
        y->suc = tmp2;
        y->pre = Right_Cursor2;
        Right_Cursor2->suc = y;
    }
    cnt++;
};

void List::Delete(List_Node * p){
    Size--;

    List_Node * tmp2 = p->suc;//正链表
    p->suc = tmp2->suc;
    tmp2->suc = NULL;
    tmp2->pre = NULL;

    if (p->DifCursor == 3){
        List_Node * tmp3 = Left_Cursor2->pre;
        Left_Cursor2->pre = tmp3->pre;
        tmp3->pre = NULL;
        tmp3->suc = NULL;
    }
    else{
        List_Node * tmp3 = Right_Cursor2->pre;
        Right_Cursor2->pre = tmp3->pre;
        tmp3->pre = NULL;
        tmp3->suc = NULL;
    }
    
    return;
}

void List::Switch(List_Node * p, List_Node * q){
    List_Node * tmp1 = p->pre;
    List_Node * tmp2 = q->suc;
    tmp1->suc = q;
    q->pre = tmp1;
    tmp2->pre = p;
    p->suc = tmp2;
    q->suc = p;
    p->pre = q;
    if (p->DifCursor == 3){
        List_Node * tmp3 = Left_Cursor2->suc;
        List_Node * tmp4 = Left_Cursor2->pre->pre;
        List_Node * tmp5 = Left_Cursor2->pre;
        tmp4->suc = Left_Cursor2;
        Left_Cursor2->pre = tmp4;
        tmp3->pre = tmp5;
        tmp5->suc = tmp3;
        Left_Cursor2->suc = tmp5;
        tmp5->pre = Left_Cursor2;
        return;
    }
    if (p->DifCursor == 4){
        List_Node * tmp3 = Right_Cursor2->suc;
        List_Node * tmp4 = Right_Cursor2->pre->pre;
        List_Node * tmp5 = Right_Cursor2->pre;
        tmp4->suc = Right_Cursor2;
        Right_Cursor2->pre = tmp4;
        tmp3->pre = tmp5;
        tmp5->suc = tmp3;
        Right_Cursor2->suc = tmp5;
        tmp5->pre = Right_Cursor2;
        return;
    }
    if (q->DifCursor == 3){
        List_Node * tmp3 = Left_Cursor2->suc;
        List_Node * tmp4 = Left_Cursor2->suc->suc;
        List_Node * tmp5 = Left_Cursor2->pre;
        tmp4->pre = Left_Cursor2;
        Left_Cursor2->suc = tmp4;
        tmp5->suc = tmp3;
        tmp3->pre = tmp5;
        Left_Cursor2->pre = tmp3;
        tmp3->suc = Left_Cursor2;
        return;
    }
    if (q->DifCursor == 4){
        List_Node * tmp3 = Right_Cursor2->suc;
        List_Node * tmp4 = Right_Cursor2->suc->suc;
        List_Node * tmp5 = Right_Cursor2->pre;
        tmp4->pre = Right_Cursor2;
        Right_Cursor2->suc = tmp4;
        tmp5->suc = tmp3;
        tmp3->pre = tmp5;
        Right_Cursor2->pre = tmp3;
        tmp3->suc = Right_Cursor2;
        return;
    }
}

void List::Reverse(List_Node * p, List_Node * q){
    List_Node * tmp1 = Left_Cursor->suc;
    List_Node * tmp2 = Right_Cursor->pre;
    List_Node * tmp3 = Left_Cursor2->pre;
    List_Node * tmp4 = Right_Cursor2->suc;

    Left_Cursor->suc = tmp4;
    tmp4->pre = Left_Cursor;
    Right_Cursor->pre = tmp3;
    tmp3->suc = Right_Cursor;
    Left_Cursor2->pre = tmp2;
    tmp2->suc = Left_Cursor2;
    Right_Cursor2->suc = tmp1;
    tmp1->pre = Right_Cursor2;

    return;    
}

int main()
{
    List TextEditor;
    string x;
    getline(cin, x);
    int len = x.length();
    char a[len];
    strcpy(a,x.c_str());
    for (int i=0; i<len; i++){
        TextEditor.Insert(a[i],TextEditor.Right_Cursor);
    }
    int m;
    cin >> m;
    char inn,m1,m2;
    string ou;//cout
    int LefCount = 0;
    int RigCount = len;
    List_Node * point = TextEditor.head;
    for (int i=0; i<m; i++){
        cin >> inn;
        switch (inn)
        {
        case '<':
            cin >> m1;
            if (m1=='L'){
                if (LefCount==0){
                    cout << 'F' << endl;
                    break;
                }
                LefCount--;
                TextEditor.Switch(TextEditor.Left_Cursor->pre, TextEditor.Left_Cursor);
                if (TextEditor.Left_Cursor->pre == TextEditor.Right_Cursor){
                    TextEditor.Switch(TextEditor.Right_Cursor,TextEditor.Left_Cursor);
                }
                cout << 'T' << endl;
                break;
            }
            else{
                if (RigCount==0){
                    cout << "intocount" << endl;
                    cout << 'F' << endl;
                    break;
                }
                RigCount--;
                if (TextEditor.Right_Cursor->pre == TextEditor.Left_Cursor){
                    TextEditor.Switch(TextEditor.Left_Cursor,TextEditor.Right_Cursor);
                }
                TextEditor.Switch(TextEditor.Right_Cursor->pre, TextEditor.Right_Cursor);
                cout << 'T' << endl;
                break;
            }
            break;
        case '>':
            cin >> m1;
            if (m1=='L'){
                if (LefCount == TextEditor.OutSize()){
                    cout << 'F' << endl;
                    break;
                }
                LefCount++;
                if (TextEditor.Left_Cursor->suc == TextEditor.Right_Cursor){
                    TextEditor.Switch(TextEditor.Left_Cursor, TextEditor.Right_Cursor);
                }
                TextEditor.Switch(TextEditor.Left_Cursor, TextEditor.Left_Cursor->suc);
                cout << 'T' << endl;
                break;
            }
            else{
                if (RigCount == TextEditor.OutSize()){
                    cout << 'F' << endl;
                    break;
                }
                RigCount++;
                TextEditor.Switch(TextEditor.Right_Cursor, TextEditor.Right_Cursor->suc);
                if (TextEditor.Right_Cursor->suc == TextEditor.Left_Cursor){
                    TextEditor.Switch(TextEditor.Right_Cursor, TextEditor.Left_Cursor);
                }
                cout << 'T' << endl;
                break;
            }
            break;
        case 'I':
            cin >> m1 >> m2;
            if (m1=='L'){
                if (LefCount <= RigCount){
                    LefCount++;
                    RigCount++;
                }
                if (LefCount > RigCount){
                    LefCount++;
                }
                TextEditor.Insert(m2,TextEditor.Left_Cursor);
                cout << 'T' << endl;
                break;
            }
            if (RigCount <= LefCount){
                    LefCount++;
                    RigCount++;
                }
                if (LefCount < RigCount){
                    RigCount++;
                }
            if (TextEditor.Right_Cursor->pre == TextEditor.Left_Cursor){
                TextEditor.Insert(m2,TextEditor.Left_Cursor);
                cout << 'T' << endl;
                break;
            }
            TextEditor.Insert(m2,TextEditor.Right_Cursor);
            cout << 'T' << endl;
            break;
        case 'D'://需要保证相邻时L总在R左侧
            cin >> m1;
            if (m1=='L'){
                if (TextEditor.Left_Cursor->suc == TextEditor.tail){
                    cout << 'F' << endl;
                    break;
                }
                if (TextEditor.Left_Cursor->suc == TextEditor.Right_Cursor){
                    if (TextEditor.Right_Cursor->suc != TextEditor.tail){
                        TextEditor.Delete(TextEditor.Right_Cursor);
                        cout << 'T' << endl;
                        break;
                    }
                    cout << 'F' << endl;
                    break;
                }
                TextEditor.Delete(TextEditor.Left_Cursor);
                cout << 'T' << endl;
                break;
            }
            else{
                if (TextEditor.Right_Cursor->suc == TextEditor.tail){
                    cout << 'F' << endl;
                    break;
                }
                TextEditor.Delete(TextEditor.Right_Cursor);
                if(TextEditor.Right_Cursor->suc = TextEditor.Left_Cursor){
                    TextEditor.Switch(TextEditor.Right_Cursor,TextEditor.Left_Cursor);
                }
                cout << 'T' << endl;
                break;
                }
        case 'R':
            if (LefCount < RigCount){
                TextEditor.Reverse(TextEditor.Left_Cursor, TextEditor.Right_Cursor);
                cout << 'T' << endl;
                break;
            }
            cout << 'F' << endl;
            break;
        case 'S':
            while(point->suc != TextEditor.tail){
                point = point->suc;
                if (point->DifCursor == 3 || point->DifCursor == 4){
                    point = point->suc;
                    continue;
                }
                else{
                    ou+=point->a;
                } 
            }
            point = TextEditor.head;
            cout << ou << endl;
            ou = "";
            break;
        default:
            break;
        }
    }
    return 0;
}