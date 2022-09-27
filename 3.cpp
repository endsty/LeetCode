//时间: 2022.9.27
//题目： 3. 无重复字符的最长子串

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//滑动窗口解决
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> m(128, 0); // m储存s中字母的的位置，每出现重复更新位置
                               //利用字母在ASCALL表中表示的大小，所以128
        int ans = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            i = max(i, m[s[j]]); /* i左边界，每次出现重复更新到上一个重复字符
                                    的下一位
                                  */  
            m[s[j]] = j + 1;     // j表示子串的最后一个字母，子串长度计算为j-i+1
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};