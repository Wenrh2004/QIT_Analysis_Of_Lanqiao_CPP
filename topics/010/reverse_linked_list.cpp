/*
 * @topics 010 反转链表
 * @file reverse_linked_list.cpp
 * @brief Reverse linked list
 *
 * In a chain table every three nodes for a group of nodes on both sides of each group will be exchanged, less than a group of nodes is not exchanged
 *
 */
#include <iostream>
#include <vector>

using namespace std;

/*
 * @brief Define linked list nodes
 * @param val The linked list node value
 * @param *next The next node in the linked list
 */
struct ListNode {
    int val;
    ListNode *next;

    /*
     * @brief The constructor for the linked list node
     * @param x The val for the linked list node
     */
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

/*
 * @brief Convert linked list to vector
 *
 * Traverse the linked list and store the value in current node into the container
 * @param head The head node in the linked list
 */
vector<ListNode *> listToVector(ListNode *head) {
    vector<ListNode *> result;
    while (head) {
        result.push_back(head);
        head = head->next;
    }
    return result;
}

/*
 * @brief Convert vector to linked list
 *
 * Store the value in the container into a linked list
 * @param nodes The vector which store the value for the linked list
 */
ListNode *vectorToList(const vector<ListNode *> &nodes) {
    if (nodes.empty()) return nullptr;
    ListNode *head = nodes[0];
    ListNode *current = head;
    for (int i = 1; i < nodes.size(); i++) {
        current->next = nodes[i];
        current = current->next;
    }
    current->next = nullptr;
    return head;
}

/*
 * @brief Swap node location
 *
 * Vectorize the nodes, exchange node values and re-node the vectors
 * @param head The head node in the linked list
 */
ListNode *swapNodesInPairs(ListNode *head) {
    if (!head || !head->next) return head;

    vector<ListNode *> nodes = listToVector(head);

    for (int i = 0; i + 2 < nodes.size(); i += 3) {
        swap(nodes[i], nodes[i + 2]);
    }

    return vectorToList(nodes);
}

/*
 * @brief Release linked list memory
 *
 * Traverse the linked list and point the head node to empty
 * @param head The head node in the linked list
 */
void deleteList(ListNode *head) {
    while (head) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Initial linked list
    ListNode *head = nullptr;
    ListNode *current = nullptr;
    int val;
    // Read input and store in linked list
    while (cin >> val && val != -1) {
        auto *newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    // Switching node
    head = swapNodesInPairs(head);

    // Output results
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    // Release linked list memory
    deleteList(head);

    return 0;
}
