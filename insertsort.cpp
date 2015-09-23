#include <iostream>
#include <vector>

using namespace std;
void insertsort(vector<int>& A,const int& p,const int& r)
{
	if(p<r)
	{
		for(int j=p; j<=r;++j)
		{
			int key = A[j];
			int i = j-1;
			while(i>=0 && A[i]>key)
			{
				A[i+1]=A[i];
				--i;
			}
			A[i+1] = key;
		} 
	}
}

int main(int argc,char** argv)
{
	vector<int>coll = {2,3,45,3,54,2,46,658,3,51,65684,6,2457,3,5143,6,5,68,67,243,7789,46,7245,4,3,5,7,67,98};
	for(int i=0; i!=coll.size(); ++i)
		cout<<" "<<coll[i];
	cout<<endl;
	insertsort(coll,0,coll.size()-1);
	cout<<"insertsort------------------------------------"<<endl;
	for(int i=0; i!=coll.size(); ++i)
		cout<<" "<<coll[i];
	cout<<endl;
	return 0;
}
