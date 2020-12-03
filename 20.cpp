


Node* sort(Node* head){

    if(head -> next == nullptr)
        return head;
    
    int cnt = 0;
    Node* t = head;
    while(t){
        cnt++;
        t = t->next;
    }
    cnt = cnt / 2;
    t = head;
    while(cnt > 1){
        cnt --;
        t = t -> next;
    }

    Node* head1 = sort(t->next);
    t -> next = nullptr;
    Node* head2 = sort(head);

    Node* newHead = new Node();

    while(head1 && head2){

        if(head1->val > head2->val){
            Node* t = head1 -> next;
            head1 -> next = newHead -> next;
            newHead -> next = head1;
            head1 = t;
        }
        else {
            Node * t = head2 -> next;
            head2 -> next = newHead -> next;
            newHead -> next = head2;
            head2 = t;
        }
    }

    if(head1){
        while(head1){
            Node* t = head1 -> next;
            head1 -> next = newHead -> next;
            newHead -> next = head1;
            head1 = t;
        }
    }
    else{
        while(head2){
            Node* t = head2 -> next;
            head2 -> next = newHead -> next;
            newHead -> next = head1;
            head2 = t;
        }
    }
    return newHead -> next;
}