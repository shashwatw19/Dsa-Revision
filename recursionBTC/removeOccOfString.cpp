//leetcode 1910

// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

 

// Example 1:

// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
// Explanation: The following operations are done:
// - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
// - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
// - s = "dababc", remove "abc" starting at index 3, so s = "dab".
// Now s has no occurrences of "abc".


// Find & remove part	O(n)
// Number of calls	O(n/m)
// Total	O(n²/m)
//since m is constant t.c is O(n^2)
 void removeOccrences_helper(string &str , string&part ,int size){
        int found = str.find(part);

        if(found == string::npos)
            return;
        
        string leftPart = str.substr(0,found);
        string rightPart = str.substr(found + size , str.size());

        str = leftPart+rightPart;

        removeOccrences_helper(str , part , size);
}
string removeOccurrences(string s, string part) {
        string temp = s;
        int size = part.size();
        removeOccrences_helper(temp , part , size );
         return temp;
}