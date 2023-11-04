/* https://leetcode.com/problems/add-two-numbers/submissions/1091391987
Runtime Details 11ms
Beats 97.68%of users with C++
Memory Details 71.66MB
Beats 70.96%of users with C++
*/

#include <tuple>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// for debuging
// void printList(ListNode *head)
// {
//     std::ostringstream ss;
//     ss << "{";
//     while (head != NULL) {
//         ss << head->val;
//         if (head->next) {
//             ss << ", ";
//         }
//         head = head->next;
//     }
//     ss << "}" << std::endl;
//     std::cout << ss.str();
// }

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr;
        ListNode *current = nullptr;
        int current_carry = 0;

        while (l1 || l2)
        {
            auto [new_node, new_carry] = addNodes(l1, l2, current_carry);

            if (!head)
                head = new_node;
            else
                current->next = new_node;

            current = new_node;
            current_carry = new_carry;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        if (current_carry)
        {
            current->next = new ListNode(current_carry);
        }

        return head;
    }

private:
    std::pair<int, int> getCarry(int x)
    {
        if (x > 19)
            throw std::runtime_error("Sum cannot be greater than 19");

        int carry = x > 9 ? x / 10 : 0;
        x %= 10;

        return {x, carry};
    }

    std::pair<ListNode *, int> addNodes(ListNode *l1, ListNode *l2, int carry)
    {
        int sum = carry;

        if (l1)
            sum += l1->val;
        if (l2)
            sum += l2->val;

        auto [new_val, new_carry] = getCarry(sum);
        return {new ListNode(new_val), new_carry};
    }
};