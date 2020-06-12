#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int getSizeOfLL(SinglyLinkedListNode *head) {
  int count=0;
  if(!head)
    return count;
  SinglyLinkedListNode *trav = head;
  while(trav) {
    count++;
    trav = trav->next;
  }
  return count;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
  int size1 = getSizeOfLL(head1);
  int size2 = getSizeOfLL(head2);
  int d=0; 
  
  SinglyLinkedListNode  *trav1 = head1;
  SinglyLinkedListNode  *trav2 = head2;

  if(size1 > size2) {
    d = size1 - size2;
    for(int i=0; i<d; i++) 
      trav1 = trav1->next;
  }
  else {
    d = size2 - size1;
    for(int i=0; i<d; i++)
      trav2 = trav2->next;
  }
  while(trav1 && trav2) {
    if(trav1 == trav2)
      return trav1->data;
    trav1 = trav1->next;
    trav2 = trav2->next;
  }
  return -1;

#if 0
/**************** 2nd Logic *********************/
Condition here: They must intersect at some point, otherwise this wont work.


  SinglyLinkedListNode  *currentA = head1;
  SinglyLinkedListNode  *currentB = head2;
  
  while(currentA != currentB) {
    //If you reached the end of one list start at the beginning of the other one
    //currentA
    currentA = (currentA->next ? currentA->next : head2);
    currentB = (currentB->next ? currentB->next : head1);
  }
  return currentA->data;
/*************************************************/  
#endif
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        int index;
        cin >> index;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }
      
      	SinglyLinkedListNode* ptr1 = llist1->head;
      	SinglyLinkedListNode* ptr2 = llist2->head;
      
      	for (int i = 0; i < llist1_count; i++) {
            if (i < index) {
          		ptr1 = ptr1->next;
            }
        }
      
      	for (int i = 0; i < llist2_count; i++) {
          	if (i != llist2_count-1) {
          		ptr2 = ptr2->next;
            }
        }
      
      	ptr2->next = ptr1;

        int result = findMergeNode(llist1->head, llist2->head);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

