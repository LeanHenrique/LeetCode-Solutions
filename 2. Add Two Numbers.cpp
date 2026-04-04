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
        ListNode* init = new ListNode();
        ListNode* current = init;
        int aux = 0;

        while(l1 != nullptr || l2 != nullptr || aux != 0){
            
            int sum = aux;

            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2 -> next;
            }

            if(sum >= 10) {
                aux = 1;
                sum = sum - 10;
            }else{
                aux = 0;
            }

            current->next = new ListNode(sum);
            current = current->next;

        }
        return init->next;
    }
};
