#include <iostream>

struct ListNode{
    int data;
    ListNode* next;

    explicit ListNode(int val) : data(val), next(nullptr) {}
};

int getDecimalValue(ListNode* head){
    int result = 0;
    while(head){
    result = result * 2 + head->data;
        head = head->next;
    }
    return result;
}

void printBinary(ListNode* head){
    while(head){
        std::cout << head->data;
        head = head->next;
    }
}

void printList(ListNode* head){
    std::cout  << "Список: " << head -> data;
    head = head -> next;
    while(head != nullptr){
        std::cout << " -> " << head -> data;
        head = head->next;
    }
    std::cout << " -> " << "nullptr\n";
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(1);
    printList(head);
    std::cout << "Бинарное число: ";
    printBinary(head);
    std::cout << "₂" << std::endl;
    std::cout << "Десятичное число: " << getDecimalValue(head) << "₁₀" << std::endl;
}