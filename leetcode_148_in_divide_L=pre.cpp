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
        ListNode *R = L; 
        //pre = the last node of Left linked-list
        
        
        //make L=pre functionaly
        if(R != nullptr && R->next != nullptr){
            R = R->next->next;
        }
        
        
        while(R != nullptr && R->next != nullptr){
            //divide original linked-list into 2 equally
            //pre = L; //this line sould be commanded if making L=pre functionally
            L = L->next;
            R = R->next->next;
        }
        /*
        Because sortList will return if(L == nullptr && L->next == nullptr),
        original R->next(= original L->next) must not be nullptr.
        => In the begining of divide, pre=L, 
        so we can remove pre and add the first if of divide function.
        It's not worth, cause it running slower and memory usage is similar, 
        */
        
        R = L->next; //make L=pre functionaly
        L->next = nullptr;
        //pre->next = nullptr;
        return R;
    }
    
    ListNode *merge(ListNode *L, ListNode *R) {
        ListNode *head = new ListNode, *ori = head;//ori = original head
        
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
        
        //the last element
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
        R = divide(L);
        
        R = sortList(R);
        L = sortList(L);
        return merge(R, L);
    }
};