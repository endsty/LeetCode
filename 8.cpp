//时间: 2022.10.3
//题目： 8. 字符串转换整数 (atoi)

#include <iostream>
#include <algorithm>

using namespace std;
/*
建立自动机
每次从s中获取一个字符，根据该字符判断下一步
*/
class Solution
{
    long long int_min = -2147483648;
    long long int_max = 2147483647; //范围2^31-1 ~~ -2^31
    long long ans = 0;
    int sign = 1;     //正负
    char state = '1'; //初始状态
public:
    void push_c(char c)
    {
        if (state == '1') //状态1：处于接受空格状态下
        {
            if (c == ' ')
                return;
            else if (c == '+' || c == '-')
            {
                state = '2'; //进入下一个状态
                sign = c == '+' ? 1 : -1;
                return;
            }
            else if (isdigit(c))
            {                // c为数字
                state = '3'; //进入3状态
                ans = ans * 10 + c - '0';
                return;
            }
            else
            {
                state = '4';
                return;
            }
        }
        if (state == '2') //状态2：处于接受+/-状态下
        {
            if (isdigit(c))
            {                // c为数字
                state = '3'; //进入3状态
                ans = ans * 10 + c - '0';
                return;
            }
            else
            {
                state = '4';
                return;
            }
        }
        if (state == '3') //状态3：处于接受数字字符状态下
        {
            if (isdigit(c))
            { // c为数字
                ans = ans * 10 + c - '0';
                ans = sign == 1 ? min(ans, (long long)int_max) : min(ans, -(long long)int_min); //解决溢出的问题
                return;
            }
            else
            {
                state = '4';
                return;
            }
        }
        if (state == '4') //状态4：结束
        {
            return;
        }
    }
    int myAtoi(string s)
    {
        for (char c : s)
        {
            push_c(c);
        }
        ans *= sign;
        return ans;
    }
};