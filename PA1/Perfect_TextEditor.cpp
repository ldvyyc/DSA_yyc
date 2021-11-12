#include <iostream>
#include <cstring>
using namespace std;

struct List_Node
{
    int DifCursor;
    char a;
    List_Node * pre;
    List_Node * suc;
    List_Node() {
        DifCursor=0;
        a = 'a';
        pre = NULL;
        suc = NULL;
    }
    List_Node(char e, List_Node * p = NULL, List_Node * s = NULL) : a(e), pre(p), suc(s), DifCursor(0) {}
};

class List 
{
private:
    int Size;//数组现在真实长度多大
    int cnt;//记录开的数组物理上用到了哪一位
    List_Node * Nodes;
public:
    List_Node * head;
    List_Node * tail;
    List_Node * Right_Cursor;
    List_Node * Left_Cursor;
    List();
    List_Node * Insert(char const & e, List_Node * p);
    void Delete(List_Node * p);
    void Reverse(List_Node * a, List_Node * b);
    void Switch(List_Node * p, List_Node * q);
    int OutSize(){
        return Size;
    }
};

List::List(){
    Nodes = new List_Node[7200300];
    head = &Nodes[0];
    tail = &Nodes[1];
    Left_Cursor = &Nodes[2];
    Right_Cursor = &Nodes[3];
    Left_Cursor->DifCursor = 1;
    Left_Cursor->a = '[';
    Right_Cursor->DifCursor = 1;
    Right_Cursor->a = ']';
    head->pre = NULL;
    tail->suc = NULL;
    head->suc = Left_Cursor;
    Left_Cursor->pre = head;
    Left_Cursor->suc = Right_Cursor;
    Right_Cursor->pre = Left_Cursor;
    Right_Cursor->suc = tail;
    tail->pre = Right_Cursor;
    Size = 0;
    cnt = 4;
}

List_Node * List::Insert(char const & e, List_Node * p){//插入，不需要ListNode了，在List里完成
    Size++;
    List_Node * x = &Nodes[cnt];
    p->pre->suc = x;
    x->pre = p->pre;
    x->suc = p;
    p->pre = x;
    cnt++;
    x->a = e;
    x->DifCursor = 0;
    return x;
};

void List::Delete(List_Node * p){
    Size--;
    List_Node * q = p->suc->suc;
    List_Node * r = p->suc;
    r->pre = NULL;
    r->suc = NULL;
    q->pre = p;
    p->suc = q;
    // cout << p << endl << r << endl << q << endl;
    return;
}

void List::Switch(List_Node * p, List_Node * q){
    List_Node * tmp1 = p->pre;
    List_Node * tmp2 = q->suc;
    p->pre->suc = q;
    q->suc->pre = p;
    p->pre = q;
    p->suc = tmp2;
    q->pre = tmp1;
    q->suc = p;
}

void List::Reverse(List_Node * p, List_Node * q){
    int tm = 0;
    List_Node * poi;
    poi = p->suc;
    while (poi != q){
        tm++;
        poi = poi->suc;
    }
    char tmp[tm];
    poi = p->suc;
    int cnn = 0;
    while (poi != q){
        tmp[cnn] = poi->a;
        cnn++;
        poi = poi->suc;
    }
    cnn = 0;
    poi = p->suc;
    while (poi != q){
        poi->a = tmp[tm-cnn-1];
        cnn++;
        poi = poi->suc;
    }
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
                if (point->DifCursor == 1){
                    point = point->suc;
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