#include<bits/stdc++.h>
using namespace std;
vector<int> reversed(vector<int> v)
{
    int s=0;
	int e=v.size()-1;
    while(s<=e)
    {
        swap(v[s],v[e]);
        s++;
        e--;

    }
     return v;
}
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
	vector<int> ans;
	int i=n-1;
	int j=m-1;
	int carry=0;
	while(i>=0 && j>=0)
	{
		int val1=a[i];
		int val2=b[j];
		int sum=val1+val2+carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
		i--;
		j--;
	}
	while(i>=0)
	{
		int sum=a[i]+carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
		i--;
	}
	while(j>=0)
	{
		int sum=b[j]+carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
		j--;
	}
	while(carry!=0)
	{
		int sum=carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
	}
	
  return reversed(ans);
}

int main()
{
    vector<int> arr={1,2,3,4};
    vector<int> arr2={4,2,3,1};
    vector<int> result=findArraySum(arr,4,arr2,4);

     for (int num : result) {
        cout << num << " ";
    }
    
}