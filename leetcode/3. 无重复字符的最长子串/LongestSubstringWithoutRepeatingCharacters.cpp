#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) {
            return s.size();
        }
        int head = 0;
        int max_len = 0;
        for (int i = 1; i < s.size(); i++) {
            for (int pos = head; pos < i; pos++) {
                if (s[pos] == s[i]) {
                    head = pos + 1;
                    break;
                }
            }
            max_len = max(max_len, i - head + 1);
        }
        return max_len;
    }
};

int main() {
    string s("ppppwwkew");
    Solution ss;
    int len = ss.lengthOfLongestSubstring(s);
    cout << len << endl;
    return 0;
}