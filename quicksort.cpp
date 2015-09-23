#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
void exchange(T& x,T& y)
{
	T medium=x;
	x=y;
	y=medium;
}

template<typename T>
int partition(vector<T>&A,const int& p,const int& r)
{
	T key =A[r];
	int i=p-1;
	for(auto j=p;j<=r-1;++j)
	{
		if(A[j]<=key)
		{
			++i;
			exchange(A[i],A[j]);
		}
	}
	exchange(A[i+1],A[r]);
	return i+1;
}

template<typename T>
void quicksort(vector<T>&A,const int& p,const int& r)
{
	if(p<r)
	{
		auto q=partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}

int main(int argc,char** argv)
{
	vector<int>coll={2,3,45,3,54,2,46,658,3,51,65684,6,2457,3,5143,6,5,68,67,243,7789,46,7245,4,3,5,7,67,98};
	for(int i=0; i!=coll.size(); ++i)
		cout<<" "<<coll[i];
	cout<<endl;
	quicksort(coll,0,coll.size()-1);
	cout<<"quicksort------------------------------------"<<endl;
	for(int i=0; i!=coll.size(); ++i)
		cout<<" "<<coll[i];
	cout<<endl;
	return 0;
}
