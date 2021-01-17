/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *divide(ListNode *L) {
        //divide original linked-list into 2 equally
        
        ListNode *R = L , *pre = L; 
        //pre = the last node of Left linked-list
        
        /*
        Because sortList will return if(L == nullptr && L->next == nullptr),
        original R->next(= original L->next) must not be nullptr.
        => In the begining of divide, pre=L, 
        so we can remove pre and add the first if of divide function, 
        and make some slight adjustments.
        But it's not worth, cause it running slower and memory usage is similar, 
        */
        /*
        //make L=pre functionaly
        if(R != nullptr && R->next != nullptr){
            R = R->next->next;
        }
        */
        
        while(R != nullptr && R->next != nullptr){
            //divide original linked-list into 2 equally
            //R grow twice faster than L
            pre = L;
            L = L->next;
            R = R->next->next;
        }
        pre->next = nullptr;
        return L;
    }
    
    ListNode *merge(ListNode *L, ListNode *R) {
        //merge 2 linked-list
        
        ListNode *head = new ListNode, *ori = head;//ori = original "head"
        
        while(L != nullptr && R != nullptr){
            if(L->val <= R->val){
                head->next = L;
                L = L->next;
            }else{
                head->next = R;
                R = R->next;
            }
            head = head->next;
        }
        
        //dealing with the last element
        if(L != nullptr){
            head->next = L;
        }else{
            head->next = R;
        }
        
        return ori->next;
    }
    
    
    ListNode *sortList(ListNode *L) {
        //use merge sort
        if(L == nullptr || L->next == nullptr){
            return L;
        }
        
        ListNode *R;
        
        //divide it until there is one element in the linked-list
        R = divide(L);
        R = sortList(R);
        L = sortList(L);
        return merge(L, R);
    }
};