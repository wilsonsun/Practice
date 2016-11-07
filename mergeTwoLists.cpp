ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL && l2 == NULL)
        return NULL;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;
    
    ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    ListNode *temp = head;
    
    if (temp1->val <= temp2->val) {
        temp->val = temp1->val;
        temp1 = temp1->next;
    } else {
        temp->val = temp2->val;
        temp2 = temp2->next;
    }
    
    while (temp1 || temp2) {
        if (temp1 == NULL) {
            temp->next = temp2;
            return head;
        }
        
        if (temp2 == NULL) {
            temp->next = temp1;
            return head;
        }
        
        ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (temp1->val <= temp2->val) {
            node->val = temp1->val;
            temp1 = temp1->next;
        } else {
            node->val = temp2->val;
            temp2 = temp2->next;
        }
        
        temp->next = node;
        temp = temp->next;
    }
    
    return head;
}
