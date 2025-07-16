/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> data1, data2;
        while (l1 != nullptr) {
            data1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            data2.push_back(l2->val);
            l2 = l2->next;
        }

        int carryOver = 0;
        if (data1.size() < data2.size()) {
            vector<int> temp = data1;
            data1 = data2;
            data2 = temp;
        }

        vector<int> holder;
        for (int i = 0; i < data2.size(); i++) {
            int add = data1[i] + data2[i] + carryOver;
            carryOver = 0;
            if (add >= 10) {
                add = add - 10;
                carryOver = 1;
            }
            holder.push_back(add);
        }

        for (int i = data2.size(); i < data1.size(); i++) {
            int add = data1[i] + carryOver;
            carryOver = 0;
            if (add >= 10) {
                add = add - 10;
                carryOver = 1;
            }
            holder.push_back(add);
        }

        if (carryOver != 0) {
            holder.push_back(carryOver);
        }

        ListNode* out = new ListNode(holder[holder.size() - 1]);

        for (int i = holder.size() - 2; i >= 0; i--) {
            out = new ListNode(holder[i], out);
        }
        return out;
    }
};