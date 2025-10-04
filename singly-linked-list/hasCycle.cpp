#include <iostream>

struct ListNode {
    int data;
    ListNode* next;

    explicit ListNode(int val) : data(val), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
   if(!head) {
       return false;
   } 
   
   ListNode* slow = head;
   ListNode* fast = head;
   
   while(fast != nullptr && fast->next != nullptr) {
       slow = slow->next;
       fast = fast->next->next;
       
       if(slow == fast) {
           return true;
       }
   }
   
   return false;
}

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    
    std::cout << std::boolalpha << hasCycle(head) << std::endl; 
    
    head->next->next->next->next = head->next;
    
    std::cout << std::boolalpha << hasCycle(head) << std::endl; 
}