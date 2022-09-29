//时间: 2022.9.29
//题目： 6. Z 字形变换

/*
对于z字形变换，首先找到下标的变换规则
规则如下：
规定step = 2*numRow-2
0.起始下标都是行号
1.第0层和第numRows-1层的下标间距总是step 。
2.中间层的下标间距总是step-2*行数，2*行数交替。
3.下标不能超过len(s)-1

其他方法：
构造二维矩阵
按照z字形将s每个字符放到适应的行，然后再将每一行连接
*/

#include <iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        int step = 2*numRows - 2; //间距
        int index = 0;
        int len = s.length();
        int add = 0; //真实间距
        string new_s;
        for(int i = 0;i<numRows;i++){
            index = i;
            add = i*2; //2*行数
            while (index < len) //确定每行的字母，当index>len,进入下一行
            {
                new_s+=s[index];
                add = step - add; //第一次间距是step -2*i，第二次是2*i
                //针对最后一行和第一行进行处理
                if(i==0||i==numRows-1){ 
                    index += step;
                }
                else{
                    index += add;
                }
            }
            
        }
        return new_s;
    }
};