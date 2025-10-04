#include <iostream>

struct ListNode {
    int data;
    ListNode* next;

    explicit ListNode(int val) : data(val), next(nullptr) {}
};

ListNode* findMiddle(ListNode* head){
    if(!head){
        return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while(curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if(!head || !head->next) return true;
    ListNode* middle = findMiddle(head);
    ListNode* secondHalf = reverseList(middle);
    
    ListNode* lst1 = head;
    ListNode* lst2 = secondHalf;
    
    while(lst2) {
        if(lst1->data != lst2->data) {
            return false;
        }
        lst1 = lst1->next;
        lst2 = lst2->next;
    }
    return true;
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
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(2);
    head1->next->next->next = new ListNode(1);

    printList(head1, "Список: ");
    bool result = isPalindrome(head1);
    std::cout << std::boolalpha << "Результат: " << result;
    std::cout << (result ? " (палиндром)\n\n" : " (не палиндром)\n\n");
    
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    
    printList(head2, "Список: ");
    bool result1 = isPalindrome(head2);
    std::cout << std::boolalpha << "Результат: " << result1;
    std::cout << (result1 ? " (палиндром)\n\n" : " (не палиндром)\n\n");
}