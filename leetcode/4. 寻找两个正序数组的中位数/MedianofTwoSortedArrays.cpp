#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() && nums2.empty()) {
            return 0;
        }
        vector<int> num_vec({-1, -1});
        int offset1 = 0;
        int offset2 = 0;
        int total_offset = 0;
        int total_len = nums1.size() + nums2.size();
        int pos = total_len / 2;
        while (offset1 < nums1.size() || offset2 < nums2.size()) {
            int cur;
            // nums1 遍历完成
            if (offset1 >= nums1.size()) {
                cur = nums2[offset2];
                offset2++;
            } else if (offset2 >= nums2.size()) { // nums2 遍历完成
                cur = nums1[offset1];
                offset1++;
            } else {
                if (nums1[offset1] < nums2[offset2]) {
                    cur = nums1[offset1];
                    offset1++;
                } else {
                    cur = nums2[offset2];
                    offset2++;
                }
            }
            cout << cur << endl;
            if (total_offset == 0) {
                num_vec[0] = cur;
            } else {
                num_vec[1] = num_vec[0];
                num_vec[0] = cur;
            }
            if (total_offset == pos) {
                break;
            }
            total_offset++;
        }
        cout << num_vec[0] << " " << num_vec[1] << endl;
        if (total_len % 2 == 0) {
            return (num_vec[0] + num_vec[1]) / 2.0;
        } else {
            return num_vec[0];
        }
    }
};

int main() {
    vector<int> num1({1,2,3});
    vector<int> num2({});
    Solution s;
    double ret = s.findMedianSortedArrays(num1, num2);
    cout << ret << endl;
    return 0;
}