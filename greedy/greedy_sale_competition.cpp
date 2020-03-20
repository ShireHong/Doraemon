/*
这个题目有点难理解，首先这是一个物品的买卖，而且这个物品的价格表在一开始是已知的，
问题就转化为在一些已知的数组里通过加减操作获得最大值。

*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int prices[100];

int main()
{
	ios::sync_with_stdio(false);
	int i, n, res = 0,buy, sell;
	priority_queue<int, vector<int>, greater<int>> q;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>prices[i];
	}
	res -= prices[0];
	res += prices[n-1];
	
	for(i=1;i<n-1;i += 2)
	{
		buy  = min(prices[i], prices[i+1]);
		sell = max(prices[i], prices[i+1]);
		if(!q.empty())
		{
			if(buy>q.top())
			{
				/*
				这是这道题的难点，其他状态是低买进，高卖出，这个是当买的价格高于之前卖的价格，就需要
				把之前卖的在买回来，在这一次通通卖掉。
				举个栗子：
				如果价格表是这样  7 6 5 8 9 10
				去掉 7 10
				第一次的buy=5，sell=6，到第二次的时候buy=8，sell=9，就是8比上一次的sell还要大，所以上一次都要变成买，这一次两次都变成卖。
				*/
				res = res - 2*q.top() + buy + sell;
				q.pop();
				q.push(buy);
				q.push(sell);
			}
			else{
				res = res - buy + sell;
				q.push(sell);
			}
		}
		else{
			res = res - buy + sell;
			q.push(sell);
		}
	}
	cout<<res<<endl;
}
