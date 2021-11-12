#include <iostream>
#include <cstring>
using namespace std;

struct List_Node
{
    int myself;
    int pre;
    int suc;
    char AorH;
    char _preAorH;
    char _sucAorH;
    char a;
};

List_Node actualone[7200010];
List_Node helper[7200010];
List_Node * Left_Cursor = &actualone[0];
List_Node * Right_Cursor = &actualone[1];
List_Node * Left_Cursor_Helper = &helper[0];
List_Node * Right_Cursor_Helper = &helper[1];

class List 
{
public:
    int Size;//数组现在真实长度多大
    int cnt;//记录开的数组物理上用到了哪一位
    List_Node head;
    List_Node tail;
    List_Node headh;
    List_Node tailh;
    List();
    void Insert(char const & e, int prerank, int currank, int preAorH, int curAorH);
    void Delete(int currank, int sucrank);
    void Reverse(List_Node a, List_Node b);
    int OutSize(){
        return Size;
    }
};

List::List(){
    head = actualone[0];
    tail = actualone[1];
    head.AorH = 'A';
    tail.AorH = 'A';
    head.pre = -100;
    head.myself = 0;//-2代表head
    head.suc = 1;
    tail.pre = 0;
    tail.myself = 1;//-1代表tail
    tail.suc = -100;
    
    Size = 0;
    cnt = 2;

    headh.AorH = 'H';
    tailh.AorH = 'H';
    headh = helper[0];
    tailh = helper[1];
    headh.pre = -100;
    headh.myself = 0;
    headh.suc = 1;
    tailh.pre = 0;
    tailh.myself = 1;
    tailh.suc = -100;
}

void List::Insert(char const & e, int prerank, int currank, int preAorH, int curAorH){//插入，不需要ListNode了，在List里完成
    Size++;
    actualone[cnt].pre = prerank;
    actualone[cnt].myself = cnt;
    actualone[cnt].suc = currank;
    actualone[cnt].a = e;
    actualone[prerank].suc = cnt;
    actualone[currank].pre = cnt;
    cnt++;
    return;
};

void List::Delete(int currank, int sucrank){
    Size--;
    actualone[sucrank].pre = -100;
    actualone[currank].suc = actualone[sucrank].suc;
    actualone[sucrank].suc = -100;
    actualone[actualone[currank].suc].pre = currank;
    return;
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
        TextEditor.Insert(a[i],Right_Cursor->pre,Right_Cursor->myself);
    }
    int m;
    cin >> m;
    char inn,m1,m2;
    string ou;//cout
    int LefCount = 0;
    int RigCount = len;
    int point = 0;
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
                cout << 'T' << endl;
                break;
            }
            else{
                if (RigCount == TextEditor.OutSize()){
                    cout << 'F' << endl;
                    break;
                }
                RigCount++;
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
            while(actualone[point].suc != 1){
                point = actualone[point].suc;
                ou+=actualone[point].a;
            }
            point = 0;
            cout << ou << endl;
            ou = "";
            break;
        default:
            break;
        }
    }
    return 0;
}