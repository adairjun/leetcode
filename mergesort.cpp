#include <iostream>
#include <vector>

using namespace std;
template<typename T>
void merge(vector<T>& A,const int& p,const int& k,const int& r)
{
	vector<T>lvec(A.begin()+p, A.begin()+k+1);
	vector<T>rvec(A.begin()+k+1, A.begin()+r+1);
	lvec.push_back(1E9);                             //哨兵牌,最大的整数，但是只能用于数字的排序
	rvec.push_back(1E9);
	for(int i=0,j=0,h=p;h<=r;++h)
	{
		if(lvec[i]<rvec[j])
			{
				A[h]=lvec[i];
				++i;
			}
		else
			{
				A[h]=rvec[j];
				++j;
			}
	}
}

template<typename T>
void mergesort(vector<T>& A,const int& p,const int& r)
{
	if(p<r)
	{
		int k = (p+r)/2;
		mergesort(A,p,k);
		mergesort(A,k+1,r);
		merge(A,p,k,r);
	}
}


int main(int argc,char** argv)
{
	vector<double>coll={2,3,45,3,54,2,46,658,3,51,65684,6,2457,3,5143,6,5,68,67,243,7789,46,7245,4,3,5,7,67,98,100.001};
	for(int i=0; i!=coll.size(); ++i)
		cout<<" "<<coll[i];
	cout<<endl;
	mergesort(coll,0,coll.size()-1);
	cout<<"mergesort------------------------------------"<<endl;
	for(int i=0; i!=coll.size(); ++i)
		cout<<" "<<coll[i];
	cout<<endl;
	return 0;
}
