#pragma once
#ifndef MOOREVOTE_H_
#define MOOREVOTE_H_

/**
摩尔投票法
2021.10.23
*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//选超过半数的元素
vector<int> Vote(vector<int>nums)
{
	int c = 0, fc = 0;
	for (int x : nums)
	{
		if (fc > 0 && c == x)//相同元素，+1
			fc++;
		else if (fc == 0)//少于半数，除去，重新开始
		{
			c = x;
			fc++;
		}
		else//不同，-1
			fc--;
	}
	fc = 0;
	for (int x : nums)
		if (x == c)
			fc++;//重新计数
	vector<int>res;
	if (fc > nums.size() / 2)
		res.push_back(c);//多余半数得到结果
	return res;
}

//选超过1/n的元素(找众数)
vector<int> Vote(vector<int>nums, int n)
{
	vector<int>c , fc;
	if (n <= 0)return c;
	c.assign(n - 1, 0);
	fc.assign(n - 1, 0);
	for (int x : nums)
	{
		bool flag = false;//模拟单元素时else if条件
		for (int i = 0; i < c.size(); i++)
		{
			if (fc[i] > 0 && c[i] == x)
			{
				fc[i]++;
				flag = true;
				break;
			}
		}
		if (flag)continue;
		for (int i = 0; i < c.size(); i++)
		{
			if (fc[i] == 0)
			{
				c[i] = x;
				fc[i]++;
				flag = true;
				break;
			}
		}
		if (flag)continue;
		for (int i = 0; i < c.size(); i++)
			if (c[i] != x)
				fc[i]--;
	}
	fc.assign(n - 1, 0);
	for (int x : nums)
		for (int i = 0; i < c.size(); i++)
			if (c[i] == x)
				fc[i]++;
	unordered_set<int>res;//过滤掉相同的元素
	int s = nums.size() / n;
	for (int i = 0; i < c.size(); i++)
		if (fc[i] > s)
			res.emplace(c[i]);
	return vector<int>(res.begin(), res.end());
}

#endif // !MOOREVOTE_H_

