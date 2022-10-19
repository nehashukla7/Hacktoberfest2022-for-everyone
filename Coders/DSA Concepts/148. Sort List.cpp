class Solution {
public:
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode *fh=NULL;
        ListNode *ft=NULL;
        if(!list1)
        {
            return list2;
        }
        if(!list2)
        {
            return list1;
        }
        while(list1 && list2)
        {
            if(ft==NULL && fh==NULL)
            {
                if(list1->val>list2->val)
                {
                    fh=list2;
                    ft=list2;
                    list2=list2->next;
                }
                else
                {
                    fh=list1;
                    ft=list1;
                    list1=list1->next;
                }
            }else{
     
       
            if(list1->val<list2->val)
            {
                ft->next=list1;
                ft=ft->next;
                list1=list1->next;
            }
            else
            {
                ft->next=list2;
                ft=ft->next;
                list2=list2->next;
            }
          
            }
        }
            
        if(list1)
        {
            ft->next=list1;
        }
        if(list2)
        {
            ft->next=list2;
        }
        return fh;
    }
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *temp=NULL;
        while(fast && fast->next)
        {
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        ListNode *l1=sortList(head);
        ListNode *l2=sortList(slow);
        ListNode *answer=mergeTwoLists(l1,l2);
        return answer;
    }
};
