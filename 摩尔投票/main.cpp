//test
#include"MooreVote.h"

int main()
{
	vector<int>nums;
	int x;
	cout << "输入数据(以-1结束)" << endl;
	while (true)
	{
		cin >> x;
		if (x == -1)break;
		nums.push_back(x);
	}
	for (int x : nums)cout << x << "  ";
	cout << "\n选超过1/n的元素，输入n：";
	cin >> x;
	vector<int>res;
	if (x == 2)
		res = Vote(nums);
	else
		res = Vote(nums, x);
	cout << "结果：";
	for (int x : res)
		cout << x << "  ";
	return 0;
}