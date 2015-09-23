#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
	public:
		vector<int> twoSum(vector<int>&numbers,int target)
		{
			map<int,int>coll;
			vector<int>result;
			for(auto i= 0;i <numbers.size();++i)
			{
				auto pt = coll.find(target-numbers[i]);
				if(pt != coll.end())
				{
					result.push_back(pt->second);                       //pt->second必然小于i+1，因为pt->second已经在map中了
					result.push_back(i+1);
					return result;
				}
				pt=coll.find(numbers[i]);
				if(pt == coll.end())
				{
					coll[numbers[i]]=i+1;
				}
			}
			return result;	
		}
};

int main(int argc,char** argv)
{
//	vector<int>hello={2,7,11,15};
	vector<int>hello={0,4,3,0};
	Solution solve;
	vector<int>result=solve.twoSum(hello,atoi(argv[1]));
	for(auto i=result.begin();i!=result.end();++i)
	{
		cout<<*i<<endl;
	}
	return 0;
}
