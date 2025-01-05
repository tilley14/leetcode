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
        // Iterate the nodes.
        // Sum the values of the nodes. Store the ones place in a new node (by moding by 10)
        // store the carry over to add to the next next sum (divide by 10)
        // Stop once there are no more nodes to visit
        ListNode* head = new ListNode();
        auto node = head;

        auto w1 = l1;
        auto w2 = l2;

        int sum = 0;
        while (w1 || w2 || sum != 0) {
            if (w1) {
                sum += w1->val;
                w1 = w1->next;
            }
            if (w2) {
                sum += w2->val;
                w2 = w2->next;
            }

            node->val = sum % 10;
            sum /= 10;

            if (w1 || w2) {
                node->next = new ListNode();
                node = node->next;
            }
        }

        // // Add any outstanding carry over values
        // while (sum != 0) {
        //     node->next = new ListNode();
        //     node = node->next;

        //     node->val = sum % 10;
        //     sum /= 10;
        // }

        return head;
    }
};