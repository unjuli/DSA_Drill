#include <iostream>
using namespace std;


struct node {
  int data;
  node* next;

  node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

node* insert(int data, node* head = NULL) {
  if(head == NULL) {
    head = new node(data);
    return head;
  }
  node* tmp = head;
  while(tmp->next) {
    tmp = tmp->next;
  }
  tmp->next = new node(data);
  return head;
}

void print(node* head) {
  while(head->next) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << head->data << endl;
}

node* reverse_iter(node* head) {
  // if(!head || head->next == NULL) return head;
  node* current = head;
  node* prev = NULL;
  node* next_ptr = NULL;

  while(current) {
    next_ptr = current->next;
    current->next = prev;
    prev = current;
    current = next_ptr;
  }
  return prev;
}

node* reverse_recur(node* current, node* prev) {
  if(!current) return prev;
  node* next = current->next;
  current->next = prev;
  return reverse_recur(next, current);
}

node* reverse_recur2(node* head) {
  // empty LL or last node detected
  if(!head || !(head->next)) return head;
  node* reverse_ptr = reverse_recur2(head->next);
  node* tmp = reverse_ptr;
  while(tmp->next) tmp = tmp->next;
  tmp->next = head;
  // important assignment of NULL; I missed it at first
  head->next = NULL;
  return reverse_ptr;
}

int main() {
  node* head = insert(2);
  insert(3, head);
  insert(4, head);
  insert(5, head);      
  cout << "LL: ";
  print(head);
  head = reverse_iter(head);
  cout << "Iterative reverse: ";
  print(head);
  cout << "Recursive reverse I: ";
  head = reverse_recur(head, NULL);
  print(head);
  cout << "Recursive reverse II: ";
  head = reverse_recur2(head);
  print(head);
}