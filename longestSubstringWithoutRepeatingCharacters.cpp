#include <iostream>
#include <string>

using namespace std;
class Solution
{
	public:
		int lengthOfLongestSubstring(string s)
		{
			if(s.length() == 0)
				return 0;
			int hash[256];                            //ascii字符只有256个，a是97，如果s[i]=a,那么hash[s[i]]即为hash[97]  
			for(auto i=0;i<256;++i)
				hash[i] = -1;
			int start = 0, ans = 0;
			int i;
			for (i = 0; i < s.size(); ++i)
			{
				if(hash[s[i]] != -1)                   //说明有相同的元素出现
				{
					if(ans < i - start)                //取之前长度与现在取得长度的最大值
						ans = i - start;
					for(int j = start; j < hash[s[i]]; ++j)          //把以前hash表里面的清为-1
						hash[j] = -1;
					if(hash[s[i]]+1 > start)                         //重新划分start
						start = hash[s[i]] + 1;
				}
				hash[s[i]] = i;
			}		
			if(ans < i - start)
				ans = i - start;
			return ans;
		}
};

int main(int argc,char** argv)
{
	string s ="aabcabcbb";
	cout<<s<<endl;
	Solution solve;
	int result = solve.lengthOfLongestSubstring(s);
	cout<<"the result is -------------------------------"<<result<<endl;
	return 0;
}
