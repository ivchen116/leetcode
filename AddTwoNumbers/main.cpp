#include <iostream>


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *it1 = l1;
		ListNode *it2 = l2;
		ListNode *head = NULL;
		ListNode *prev = NULL;
		ListNode *it = NULL;
		int add = 0;
		int v1,v2;
		int tmp;

        while(it1||it2||add)
        {
			v1 = it1?it1->val:0;
			v2 = it2?it2->val:0;

			it = (ListNode *)malloc(sizeof(ListNode));
			it->next = NULL;

			tmp = v1 + v2 + add;
			add = tmp/10;
			it->val = tmp%10;

			if (prev)
			{
				prev->next = it;
			}
			else
			{
				head = it;
			}
			prev = it;

			if (it1)
			{
				it1 = it1->next;
			}
			
			if (it2)
			{
				it2 = it2->next;
			}
        }

		return head;
    }

	ListNode* makeNumberList(int number)
	{
		ListNode *head = NULL;
		ListNode *prev = NULL;

		while (number)
		{
			ListNode *l = (ListNode*)malloc(sizeof(ListNode*));
			l->val = number%10;
			l->next = NULL;
			number = number/10;

			if (prev)
			{
				prev->next = l;
			}
			else
			{
				head = l;
			}
			prev = l;
		}

		return head;
	}

	int getListNumber(ListNode* l)
	{
		int result = 0;
		int count = 0;

		while(l)
		{
			result += l->val*int(pow(10.0, count));
			l = l->next;
		}
		return result;
	}

	void showListNode(ListNode* l)
	{
		while(l)
		{
			std::cout << l->val;
			l = l->next;
		}
		std::cout <<std::endl;
	}
};

int main(int argc, const char* argv[])
{
	Solution s;

	ListNode *n1 = s.makeNumberList(99999);
	ListNode *n2 = s.makeNumberList(465);

	s.showListNode(n1);
	s.showListNode(n2);

	ListNode *n3 = s.addTwoNumbers(n1, n2);

	s.showListNode(n3);

	std::cout << s.getListNumber(n1) <<"+" << s.getListNumber(n2) << '=' << s.getListNumber(n3) <<std::endl;
}