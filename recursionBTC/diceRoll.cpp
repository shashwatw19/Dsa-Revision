    // you have given n dice and each dice has a k faces numbered from 1 to k , 
    // given three integers n , k and target return the no. of possible ways (out of the kth total ways) so the sum of face-up 
    // numbers equals target 
    // test cases : 1.n = 2 k = 6 target = 7 total ways = 6 2. n= 3 k = 2 target = 6 total ways = 1

// Recursive Idea
// Each dice can take values from 1 to k.
// At each step, we "pick" a face and reduce the target.

// Base cases:
// If n == 0 and target == 0 → 1 valid way.
// If n == 0 and target != 0 → 0 ways.
// If target < 0 → 0 ways.


//time complexity -> k^n
//space complexity -> O(n)

#include<iostream>
using namespace std;

int numsRollsToTarget(int n , int k , int target){
    // bases cases
    if(target < 0)
        return 0;
    if(n == 0 && target == 0)
        return 1;
    if( n == 0 && target != 0)
        return 0;
    
    int ans = 0;
    for(int i = 1 ; i <= k ; i++){
        ans+= numsRollsToTarget(n-1 , k , target - i);
    }
    return ans;
}
int main(){
    cout<<numsRollsToTarget(2, 2, 6);
}