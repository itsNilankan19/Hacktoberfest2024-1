Leetcode POTD problem

Q. You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

 

Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.
 

Constraints:

0 <= num <= 10^8



Soln:-

class Solution {
public:
    int maximumSwap(int num) {
        // Convert the number to a string for easier digit manipulation
        string numStr = to_string(num);
        int n = numStr.size();
        
        // Store the last occurrence of each digit (0-9)
        vector<int> last(10, -1);
        for (int i = 0; i < n; ++i) {
            last[numStr[i] - '0'] = i;
        }
        
        // Traverse each digit from left to right
        for (int i = 0; i < n; ++i) {
            // Check if there's a larger digit appearing later
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (last[d] > i) {
                    // Swap the current digit with the larger one
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr); // Convert back to integer and return
                }
            }
        }
        
        // If no swap was made, return the original number
        return num;
    }
};
