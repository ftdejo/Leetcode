// Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
//
// Note that the row index starts from 0.
//
//
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
// Example:
//
//
// Input: 3
// Output: [1,3,3,1]
//
//
// Follow up:
//
// Could you optimize your algorithm to use only O(k) extra space?
//


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp;
        for(int i = 0; i <= rowIndex ; ++i){
            for(int j = i - 1; j > 0; --j){
                temp[j] += temp[j - 1];
            }
            temp.push_back(1);
        }
        return temp;
    }
};