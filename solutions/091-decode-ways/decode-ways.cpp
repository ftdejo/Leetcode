// A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
//
//
// Given a non-empty string containing only digits, determine the total number of ways to decode it.
//
// Example 1:
//
//
// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
//
//
// Example 2:
//
//
// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
//


class Solution {
public:
    // int numDecodings(string s) {
    //     if(s.empty() || s[0] == '0')
    //         return 0;
    //     int cnt, cnt1, cnt2;
    //     cnt = cnt1 = cnt2 = 1;
    //     for(int i = 1; i < s.size(); ++i){
    //         int num = s[i] - '0';
    //         int num2 = (s[i - 1] - '0') * 10 + num;
    //         if(!num){
    //             if(num2 == 10 || num2 == 20)
    //                 cnt = cnt2;
    //             else
    //                 return 0;
    //         }else{
    //             if(num2 <= 26 && num2 >= 11)
    //                 cnt = cnt1 + cnt2;
    //             else
    //                 cnt = cnt1;
    //         }
    //         cnt2 = cnt1;
    //         cnt1 = cnt;
    //     }
    //     return cnt;
    // }
     int numDecodings(string s) {
        if(s.empty() || s[0] == '0')
            return 0;
        int cnt1(1), cnt2(1);
        for(int i = 1; i < s.size(); ++i){
            if(s[i] == '0')
                cnt1 = 0;
            if(s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6'){
                cnt1 = cnt1 + cnt2;
                cnt2 = cnt1 - cnt2;
            }else
                cnt2 = cnt1;
        }
        return cnt1;
    }
    
    
           
};
