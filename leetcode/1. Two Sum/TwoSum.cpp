#include <vector>
#include <iostream>
#include <unordered_map>

#include <string>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        m.reserve(100);
        if (nums.size() <= 1) {
            return vector<int>();
        }
        vector<int> rc;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = m.find(target - nums[i]);
            if (iter != m.end()) {
                // find
                rc.push_back(iter->second);
                rc.push_back(i);
            }
            m[nums[i]] = i;
        }
        return rc;
    }
};

int main() {
    vector<int> nums({2,7,1,5});
    Solution s;
    auto rc = s.twoSum(nums, 11);
    for (auto i : rc) {
        cout << i << endl;
    }
    return 0;
}