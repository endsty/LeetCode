//时间: 2022.10.4
//题目： 11. 盛最多水的容器

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
根据题目矩形的面积与底和两条垂线的短一段有关
为求最大面积
要求：两条垂直线的距离越远越好，两条垂直线的最短长度也要越长越好
采用双指针法
若向内 移动短板 ，水槽的短板 min(h[i], h[j])min(h[i],h[j]) 可能变大，因此下个水槽的面积 可能增大 。
若向内 移动长板 ，水槽的短板 min(h[i], h[j])min(h[i],h[j])​ 不变或变小，因此下个水槽的面积 一定变小 。

*/
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1; //左右两条垂线
        int res = 0;
        while (l < r) //循环遍历条件
        {
            res = max(min(height[l], height[r]) * (r - l), res); //求当前最大面积
            //确定哪边向内移动
            if (height[l] < height[r])
            {
                l++;
            }
            else
                r--;
        }
        return res;
    }
};