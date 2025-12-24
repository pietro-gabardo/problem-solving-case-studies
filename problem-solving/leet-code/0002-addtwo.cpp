# include <iostream>

struct ListNode { // By leet code.
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

/*
* Problem: 2. Add Two Numbers
* Difficulty: Easy
* Time Complexity: O(n)
* Space Complexity: O(n)
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int d1 = (l1 != nullptr) ? l1->val : 0;
            int d2 = (l2 != nullptr) ? l2->val : 0;

            int sum = d1 + d2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            tail->next = new ListNode(digit);
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};

/* Short explanation
* Create a null first element that will be used to define when stop the while loop.
* In the loop rach element is added to its equivalent in the other list, this process only end when both list are empty and there is no carry.
*/


/*
* Test case with some utilities functions:
*/
void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}


void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;


    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    cout << "List 1: "; printList(l1);
    cout << "List 2: "; printList(l2);

    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: "; printList(result);

    deleteList(l1);
    deleteList(l2);
    deleteList(result);

    return 0;
}
