/*
Given a string s, return true if s is a good string, or false otherwise.

A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

 

Example 1:

Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
Example 2:

Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/

//----------------------------------------------------------SOLUTION---------------------------------------------------

class Solution {
public:
     bool areOccurrencesEqual(const string &s) 
    {
        map<char, int> freq;

        // Count the frequency of each character in the string
        for (const char c : s) {
            ++freq[c];
        }
        
        // Insert the frequency of each character into the set
        set<int> size;
        for (const auto& elem : freq) {
            size.insert(elem.second);
        }

        // If the size of the set is 1, all characters have the same frequency
        return size.size() == 1 ? true : false;
    }
};