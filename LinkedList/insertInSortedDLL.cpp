#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
  public:
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;

    DoublyLinkedListNode(int node_data) {
      this->data = node_data;
      this->next = nullptr;
      this->prev = nullptr;
    }
};

class DoublyLinkedList {
  public:
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;

    DoublyLinkedList() {
      this->head = nullptr;
      this->tail = nullptr;
    }

    void insert_node(int node_data) {
      DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

      if (!this->head) {
        this->head = node;
      } else {
        this->tail->next = node;
        node->prev = this->tail;
      }

      this->tail = node;
    }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
  while (node) {
    fout << node->data;

    node = node->next;

    if (node) {
      fout << sep;
    }
  }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
  while (node) {
    DoublyLinkedListNode* temp = node;
    node = node->next;

    free(temp);
  }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
  DoublyLinkedListNode *cur = head;
  DoublyLinkedListNode *nptr = new DoublyLinkedListNode(data);
  // Empty DLL.
  if(!head)
    return (head = nptr);

  if(cur->data >= data) { // Need to insert at starting.
    nptr->next = cur;
    cur->prev = nptr;
    head = nptr;
    return head;
  }
  while(cur->next) {
    if(cur->data < data && cur->next->data >= data) {
      nptr->next = cur->next;
      cur->next->prev = nptr;
      nptr->prev = cur;
      cur->next = nptr;
      return head;
    }
    cur = cur->next;
  }
  // insert at last.
  if(cur->data < data) {
    nptr->prev = cur;
    cur->next = nptr;
  }
  return head;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    DoublyLinkedList* llist = new DoublyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
      int llist_item;
      cin >> llist_item;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      llist->insert_node(llist_item);
    }

    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

    print_doubly_linked_list(llist1, " ", fout);
    fout << "\n";

    free_doubly_linked_list(llist1);
  }

  fout.close();

  return 0;
}

