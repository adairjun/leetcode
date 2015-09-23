#include <iostream>
#include <string>

using namespace std;
class Solution
{
	public:
		string init(string s) 
		{
			string ret = "^";
			for (int i = 0; i < s.length(); i++) {
				ret += "#";                               //在字符串的中间加上#号，如果回文串是奇数，那么对称轴就是字符，如果是偶数，那么对称轴就是#号，总之不为空
				ret += s[i];
			}
			ret += "#$";
			return ret;
		}

		string longestPalindrome(string s)
		{
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			//manacher algorithm
			if (s.length() == 0) {
				return "";
			}
			string t = init(s);

			int tlen = t.length();
			int *p = new int[tlen];                                        //p[i]存储的是回文串的长度除以2
			int id = 0, rightMost = 0;
			for (int i = 1; i < tlen - 1; i++) {
				if (rightMost > i) {
					p[i] = min(rightMost - i, p[2 * id - i]);
				} else {
					p[i] = 0;
				}
				while (t[ i + p[i] + 1 ] == t[i - p[i] - 1]) {
					p[i]++;                                       //当执行到两个q之间的#时，p[i]变为6
				}
				if (i + p[i] > rightMost) {
					rightMost = i + p[i];
					id = i;
				}
			}
			int maxLen = 0;
			for (int i = 1; i < tlen - 1; i++) {
				if (maxLen < p[i]) {
					maxLen = p[i];
					id = i;
				}
			}
			delete []p;
			return s.substr((id - maxLen - 1) / 2, maxLen);                          //因为maxLen有奇数偶数，但是id-maxLen一定在#号上，除以2的作用是去掉#,-1的作用是去掉开头的^
		}
};

int main(int argc,char** argv)
{
	string s = "abcdefghijklmnopqqporst";                                              //最长回文串是opqpo
	Solution solve;
	string result = solve.longestPalindrome(s);
	cout<<"the result is -----------------"<<result<<endl;
	return 0;
}
