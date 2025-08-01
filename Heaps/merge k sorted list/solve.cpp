#include<bits/stdc++.h>
using namespace std;

class ListNode{
 public:
 int val;
 ListNode* next;
   ListNode(int data){
    val = data;
    next = NULL;
   }
};

class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Step 1: Push the head of each list into the min heap
        for (ListNode* list : lists) {
            if (list) pq.push(list);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        // Step 2: Extract-min and add to result
        while (!pq.empty()) {
            ListNode* curr = pq.top(); pq.pop();
            tail->next = curr;
            tail = curr;

            if (curr->next) {
                pq.push(curr->next);
            }
        }

        return dummy->next;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
ListNode* createList(vector<int> vals) {
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    for (int val : vals) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    return dummy->next;
}

// Utility function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create k sorted linked lists
    vector<ListNode*> lists;
    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));

    Solution sol;
    ListNode* result = sol.mergeKLists(lists);

    cout << "Merged Linked List: ";
    printList(result);

    return 0;
}