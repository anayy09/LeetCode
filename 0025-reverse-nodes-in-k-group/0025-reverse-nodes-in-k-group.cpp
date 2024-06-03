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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }

        ListNode* current = head;
        int cnt = 0;
        while (current != nullptr) {
            cnt++;
            current = current->next;
        }

        ListNode temp(0);
        temp.next = head;
        ListNode* prevGroupEnd = &temp;

        while (cnt >= k) {
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* groupEnd = groupStart;
            for (int i = 1; i < k; i++) {
                groupEnd = groupEnd->next;
            }
            ListNode* nextGroupStart = groupEnd->next;
            reverse(groupStart, groupEnd);

            prevGroupEnd->next = groupEnd;
            groupStart->next = nextGroupStart;

            prevGroupEnd = groupStart;
            cnt -= k;
        }

        return temp.next;
    }

private:
    void reverse(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        ListNode* next = nullptr;

        while (prev != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
};
