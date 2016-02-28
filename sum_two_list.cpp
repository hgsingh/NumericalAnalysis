#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
}list_node;

/*
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a  * single digit. Add the two numbers and return it as a linked list.
 */

class Solution
{
    public:
        list_node* l1_head;
        list_node* l2_head;
        Solution();
        list_node* addTwoNumbers(list_node* l1, list_node* l2);
        int addTwoNumbers(list_node* l1, list_node* l2, list_node* sum, int carry);
        void delete_list(list_node* head);
        void delete_node(list_node** head);
        bool delete_val(list_node* head,int val);
        void generate_list(list_node* &head, int size);
        int print_list(list_node* head);
        void reverse_list(list_node* &head);
        int recurse_generation(list_node*&head, int size);
        ~Solution();
};

Solution::Solution():l1_head(NULL), l2_head(NULL){}

Solution::~Solution()
{
    if(l1_head)
        delete_list(l1_head);
    if(l2_head)
        delete_list(l2_head);
}

void Solution::delete_list(list_node* head)
{
    if(!head)
        return;
    delete_list(head->next);
    head->next = NULL;
    delete head;
}

void Solution::delete_node(list_node** head)
{
    if(*head == NULL)
        return;
    //doesn't work because the pointer needs to be caught
//    list_node* temp = (*head) -> next;
//    //*head =(*head) -> next;
//    //temp->next = NULL;
//    delete *head;
//    *head = temp;
    if(!(*head)->next)
    {
        //delete head because there is nothing next
        delete *head;
        return;
    }
    (*head)->val = (*head)->next->val; //copy value
    list_node*temp = (*head)->next;
    (*head)->next = (*head)->next->next;//update next pointer
    temp->next = NULL;
    delete temp;   
}

bool Solution::delete_val(list_node* head,int val)
{
    if(!head)
        return 0;
    list_node* temp = head;
    while(temp)
    {
        if(temp->val == val)
        {
            delete_node(&temp);
            return 1;
        }
        temp = temp -> next;
    }
    return 0;
}

void Solution::generate_list(list_node* &head, int size)
{
    if(head)
        return;
    int i = 0;
    list_node* p;
    while(i < size)
    {
        p = head;
        int k = rand() % 10; // just need something from 0 to 9
        head = new ListNode(k);
        head->next = p;
        ++i;
    }
}

list_node* Solution::addTwoNumbers(list_node* l1, list_node* l2)
{
    list_node* result = NULL;
    addTwoNumbers(l1_head, l2_head, result, 0);
    reverse_list(result);
    return result;
}

int Solution::addTwoNumbers(list_node *l1, list_node *l2, list_node *sum, int carry)
{
    if(!l1 || !l2)
        return 0;
    int total = l1->val + l2->val + carry;
    sum = new ListNode((total)%10);
    carry = (total- (total % 10))/10;
    return addTwoNumbers(l1->next, l2->next, sum->next, carry);
}

int Solution::print_list(list_node* head)
{
    if(!head){
        cout<<endl;
        return 0;
    }
    cout<<head->val;
    cout<<"-> ";
    return print_list(head->next);
}

int Solution::recurse_generation(list_node *&head, int size)
{
    if(head || size == 0)
        return 0;
    int k = rand() % 10;
    head = new ListNode(k);
    return recurse_generation(head->next, size - 1);
}

void Solution::reverse_list(list_node* &head)
{
    list_node* first;
    list_node* rest;
    if(!head)
        return;
    first = head;
    rest = head->next;
    if(!rest)
        return;
    reverse_list(rest);
    first->next->next = first;
    first->next = NULL;
    head = rest;
}

int main()
{
    srand(time(NULL));
    Solution solution;
    int list_size = 3;
    solution.generate_list(solution.l1_head, list_size);
    solution.generate_list(solution.l2_head, list_size);
    solution.print_list(solution.l1_head);
    solution.print_list(solution.l2_head);
    list_node* test_recurse = NULL;
    solution.generate_list(test_recurse,3);
    solution.print_list(test_recurse);
    solution.delete_val(test_recurse, test_recurse->next->val);
    solution.print_list(test_recurse);
    solution.delete_list(test_recurse);
    return 0;
}
