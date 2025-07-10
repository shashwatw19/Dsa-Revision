#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// time complexit O( 2N + 4logN)
//space complxity O(N) where N is the size of List which is being stored in the mapp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode* , int>mpp;
    ListNode* temp = headA;
    // o(n * 2logn)
    while(temp){
        mpp[temp] = 1;
        temp = temp->next;
    }
    temp = headB;
    //o(n * 2logn)
    while(temp){
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        temp = temp->next;
    }
        return nullptr;
}

//so the total over t.c will be O(n1) + O(n2) + O(n2-n1) + O(n1) which will be equals O( n1 + 2n2)
//space complexity O(1)
ListNode* collisionPoint(ListNode* smaller ,  ListNode* greater , int steps){
    ListNode* g = greater;
    //O(n2-n1)
    while(steps--){
        g = g->next;
    }
    ListNode* s = smaller;
    //O(n1)
    while(s != g){
        s = s->next;
        g = g->next;
    }
    return s;
}
ListNode *method2(ListNode *headA, ListNode *headB){
    ListNode* temp1 = headA;
    int cnt1 = 0;
    //O(N1)
    while(temp1){
        cnt1++;
        temp1 = temp1->next;
    }
    int cnt2 = 0;
    ListNode* temp2 = headB;
    //O(N2)
    while(temp2){
        cnt2++;
        temp2 = temp2->next;
    }

    if(cnt1 < cnt2){
        return collisionPoint(headA , headB , cnt2-cnt1);
    }else{
        return collisionPoint(headB , headA , cnt1-cnt2 );
    }
}

ListNode* optimised(ListNode *headA, ListNode *headB){
    ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(t1!=t2){
            t1 = t1->next;
            t2 = t2->next;
            if(t1==t2){
                return t1;
            }
            if(!t1){
                t1 = headB;
            }
            if(!t2){
                t2 = headA;
            }
        }
        return t1;
}
