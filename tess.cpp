#include <iostream>
#include <string>

using namespace std;

string a;

void play(int rank, char color) {
    int left = rank;
    int right = rank;
    a.insert(a.cbegin() + rank, color);

    while (left >= 0 && a[left] == color) --left;
    left += 1;
    while (right < a.size() && a[right] == color) ++right;

    int size = right - left;
    if (size >= 3) a.erase(left, size);
}

int main() {
    getline(cin, a);
    int m = 0;
    cin >> m;

    int rank; char color;
    for (int i = 0; i < m; ++i) {
        cin >> rank >> color;
        play(rank, color);
    }
    
    cout << a << endl;

    return 0;
}