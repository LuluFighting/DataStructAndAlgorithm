#include <iostream>
using namespace std;
class Solution {
public:
    Solution() : cnt(0) {}
    void eight_queen(int *rows, int row) {
        if (row == 8) {
            cout << "one solution is " << endl;
            print(rows);
            cout << "------------------------" << endl;
            cnt++;
        }
        for (int i = 0; i < 8; i++) {
            if (isOk(rows, row, i)) {
                rows[row] = i;
                eight_queen(rows, row + 1);
            }
        }
    }
    int get_cnt() {
      return this->cnt;
    }
private:
    bool isOk(int *rows, int row, int col) {
        int leftup = col - 1, rightup = col + 1;
        for (int i = row - 1; i >= 0; i--) {
            if (rows[i] == col) return false;
            if (leftup >= 0 && rows[i] == leftup) return false;
            if (rightup < 8 && rows[i] == rightup) return false;
            leftup--;
            rightup++;
        }
        return true;
    }
    void print(int *rows) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (rows[i] == j) {
                    cout << "Q "; 
                }else cout << "* ";
            }
            cout << endl;
        }
    }
    int cnt;
};
int main() {
    int rows[8] = {-1};
    Solution a;
    a.eight_queen(rows, 0);
    cout << a.get_cnt() << endl;
}