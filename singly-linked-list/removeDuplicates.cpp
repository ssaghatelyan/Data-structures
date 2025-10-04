#include <iostream>

struct ListNode {
    int data;
    ListNode* next;

    explicit ListNode(int val) : data(val), next(nullptr) {}
};

void removeDuplicates(ListNode* head) {
    ListNode* curr = head;
    
    while(curr && curr->next) {
        if(curr->data == curr->next->data) {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else {
            curr = curr->next;
        }
    }
}


void printList(ListNode* head, const std::string& text){
    std::cout  << text << head -> data;
    head = head -> next;
    while(head != nullptr){
        std::cout << " -> " << head -> data;
        head = head->next;
    }
    std::cout << " -> " << "nullptr\n";
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(1);
    head1->next->next = new ListNode(2);
    
    printList(head1, "Список: ");
    removeDuplicates(head1);
    printList(head1, "Список после удаления: ");
    
    std::cout << "\n";
    
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(2);
    head2->next->next->next = new ListNode(3);
    head2->next->next->next->next = new ListNode(3);
    
    printList(head2, "Список: ");
    removeDuplicates(head2);
    printList(head2, "Список после удаления: ");
}