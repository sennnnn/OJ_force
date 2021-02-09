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
        int carry = 0;
        int value = 0;
        while(l1||l2){
            int l1_val = l1 ? l1->val : 0;
            int l2_val = l2 ? l2->val : 0;
            value = l1_val + l2_val + carry;
            carry = value / 10;
            value = value % 10;
            if(!head){
                head = tail = new ListNode(value);
            }else{
                tail->next = new ListNode(value);
                tail = tail->next;
            }
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        if(carry > 0){
            tail->next = new ListNode(carry);
            tail = tail->next;
        }
        return head;
    }
};