class Solution {
public:
    ListNode *intersect_Node(ListNode *headA,ListNode *headB,int n,int m){
        if(n<m) return intersect_Node(headB,headA,m,n);
        int diff = n-m;
        ListNode *temp1 = headA, *temp2 = headB;
        while(diff){
            temp1 = temp1->next;
            diff--;
        }
        while(temp1){
            if(temp1==temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = 0,m = 0;
        ListNode *temp1 = headA, *temp2 = headB;
        while(temp1){
            n++;
            temp1 = temp1->next;
        }
        while(temp2){
            m++;
            temp2 = temp2->next;
        }
        return intersect_Node(headA,headB,n,m);
        
    }