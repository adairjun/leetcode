#include <iostream>
#include <vector>

using namespace std;
class Solution
{
	public:
		vector<int> merge(int A[],int m,int B[],int n)
		{
			// 在进行merge之前需要先加上哨兵牌
			vector<int> a;
			for (auto i=0;i<m;++i)
				a.push_back(A[i]);
			a.push_back(1e9);

			vector<int> b;
			for(auto j=0;j<n;++j)
				b.push_back(B[j]);
			b.push_back(1e9);

			auto i = 0, j = 0,k = 0;
			vector<int> coll;
			while (k < m+n)                                      //保证k有m+n个元素
			{
				if (a[i]<=b[j])
				{
					coll.push_back(a[i]);
					++i;
				}
				else
				{
					coll.push_back(b[j]);
					++j;
				}
				++k;
			}
			return coll;
		}

		double findMedianSortedArrays(int A[], int m, int B[], int n)
		{
			if (m == 0 & n == 0) return 0.0;                          
			if (m == 0) return n%2==1 ? B[n/2] : (B[n/2-1]+B[n/2])/2.0;
			if (n == 0) return m%2==1 ? A[m/2] : (A[m/2-1]+A[m/2])/2.0;

			if(m<n)                                             //保证长的数组一定在最前面,即中位数始终位于A数组里面，至少也是(A[m-1]+B[0])/2,或者是(A[0]+B[n-1])/2
				return findMedianSortedArrays(B,n,A,m);     
					
			// 使用归并排序的merge方法可以让时间复杂度为O(n)
			vector<int> result = merge(A,m,B,n);

			if((m+n)%2==1)
				return result[(m+n)/2];
			else
				return (result[(m+n)/2]+result[(m+n)/2-1])/2.0;
		}
};

int main(int argc,char** argv)
{

	int a[]={1,1,2,2,4,5,5,5,6,6,6,6,7,24,24,32,32,32,54,56,56,56,56,65,67,72,234,3256};
	int b[]={1,1,1,1,1,1,4,5,5,7,23,25,34,43,51,65,123,134,143,245,256,324,354,543};
	Solution solve;
	double result = solve.findMedianSortedArrays(a,sizeof(a)/sizeof(a[0]),b,sizeof(b)/sizeof(b[0]));
	cout<<"the result is ---------------------------------"<<result<<endl;
	return 0;
}
