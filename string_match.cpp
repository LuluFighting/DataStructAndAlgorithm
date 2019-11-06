#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    Solution() :matched(false) {}
    bool match(string pattern, string text) {
        rmatch(pattern, 0, text, 0);
        return matched;
    }
private:
    void rmatch(string pattern, int pos1, string text, int pos2) {
        if (matched == true) return;
        if (pos1 == pattern.size()) {
            if (pos2 == text.size())
                matched = true;
            return;
        }
        if (pattern[pos1] == '*') {
            for (int k = 0; k <= text.size() - pos2; k++)
                rmatch(pattern, pos1 + 1, text, pos2 + k);
        }else if (pattern[pos1] == '?') {
            rmatch(pattern, pos1 + 1, text, pos2);
            rmatch(pattern, pos1 + 1, text, pos2 + 1);
        }else if (pos2 < text.size() && pattern[pos1] == text[pos2])
            rmatch(pattern, pos1 + 1, text, pos2 + 1);
    }
    bool matched;
};