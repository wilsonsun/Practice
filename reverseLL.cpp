ListNode* RRLLHelper(ListNode *A, ListNode *B) {
    if (B == NULL)
        return A;
    else {
        ListNode *temp = B->next;
        B->next = A;
        return RRLLHelper(B, temp);
    }
}

ListNode* recursiveReverseLL(ListNode *head) {
    if (head == NULL)
        return NULL;
    
    if (head->next == NULL)
        return head;
    
    ListNode *B = head->next;
    head->next = NULL;
    return RRLLHelper(head, B);
}


void printLL (ListNode *head) {
    ListNode *temp = head;
    if (temp != NULL) {
        cout << temp->val;
        temp = temp->next;
    }
    
    while (temp) {
        cout << '-' << temp->val;
        temp = temp->next;
    }
    cout << endl;
}
