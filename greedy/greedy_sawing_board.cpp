/*
利用霍夫曼树思想来求解。

霍夫曼树的思想就是把最小的和次小的值拿出来合并，一直合并到出现root的值。

目前到此为止，我自己还没找到贪心算法的统一解法，可能是贪心算法的题目的差异很大，解法也比较多，拿到这种题目很烧脑。但是还是可以找出一些思路，就是每一次去找最值的问题，根据实际需求，最好是可以自己举个例子，比如锯木板锯 3 4 6这三个，那么耗费3+4+6这个值就行了，以这个为基础去类比。
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int i, n, res = 0, tmp;
	priority_queue<int, vector<int>, less<int>> q;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>tmp;
		q.push(tmp);
	}
	
	while(q.size() > 1)
	{
		res = q.top();
		q.pop();
		res += q.top();
		q.pop();
		q.push(res);
	}
	res = q.top();
	cout<<res<<endl;
}