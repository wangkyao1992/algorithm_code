#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int x = 0;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                x = l2->val;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                x = l1->val;
                l1 = l1->next;
            } else {
                x = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            x += carry;
            ListNode* n = new ListNode(x%10);
            carry = x/10;
            if (head == nullptr) {
                head = n;
            } else {
                tail->next = n;
            }
            tail = n;
        }
        if (carry > 0) {
            ListNode* n = new ListNode(carry);
            tail->next = n;
        }
        return head;
    }
};

ListNode* ToList(int num) {
    if (num == 0) {
        return new ListNode(0);
    }
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    while (num > 0) {
        int x = num % 10;
        num = num / 10;
        ListNode* n = new ListNode(x);
        if (head == nullptr) {
            head = n;
        } else {
            tail->next = n;
        }
        tail = n;
    }
    return head;
}

void ForEachList(ListNode* head) {
    for (auto n = head; n != nullptr; n = n->next) {
        cout << "val:" << n->val << endl;
    }
}

int main() {
    ListNode* l1 = ToList(99999999);
    ListNode* l2 = ToList(10001);
    Solution s;
    ListNode* ret = s.addTwoNumbers(l1, l2);
    ForEachList(ret);
    return 0;
}