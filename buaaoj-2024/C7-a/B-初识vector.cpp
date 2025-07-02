#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(const vector<int> &v)
{
	cout << "v: ";
	// for (auto it = v.begin(); it != v.end(); ++it)
	for (int element : v)
	{
		cout << element << " ";
	}
	cout << endl;
}
int main()
{
	int n, e;
	cin >> n >> e; // 读入n, e
	vector<int> v(n, e); // 初始化v为n个值为e的元素
	print(v); // 输出v
	string s;
	while(cin >> s) // 
	{
		int i, x, flag = 1;
		if(s == "push_back")
		{
			// 读入x
            cin >> x;
			// push_back
            v.push_back(x);
		}
		else if(s == "pop_back")
		{
			// 若v为空，则flag=0
            if(v.empty())flag = 0;
			// 否则，pop_back
            else(v.pop_back());
		}
		else if(s == "insert")
		{
			// 读入i, x
            cin >> i >> x;
			// 若i合法，insert，提示：v.begin() + i
            if(0<=i && i <= v.size())v.insert(v.begin()+i,x);
            else flag = 0;
			// 否则，非法，flag=0;
		}
		else if(s == "erase")
		{
			// 读入i
			// 若i合法，erase
			// 否则，非法，flag=0;
            cin >> i;
            if(0<=i && i < v.size())v.erase(v.begin()+i);
            else flag = 0;
		}
		else if(s == "clear")
		{
			// clear
            v.clear();
		}
		else if(s == "sort")
		{
			// sort
            sort(v.begin(),v.end());
		}
		if(flag) // 操作合法，输出v中每个元素
			print(v);
		else     // 操作非法，输出You can't do that!
			cout << "You can't do that!" << endl;
	}
	return 0;
}