#include <iostream>
#include <string>

using namespace std;
class Solution
{
	public:
		string convert(string s,int nRows)
		{

		}
};

int main(int argc,char** argv)
{
	string s = "PAYPALISHIRING";
	int nRows = 3;
	cout<<"the s is --------------------"<<s<<"----------"<<nRows<<endl;
	Solution solve;
	string result = solve.convert(s,nRows);
	cout<<"the result is --------------------------"<<result<<endl;
	return 0;
}
