#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>temp(m+n);
        int i=0;
        int j=0;
        int k=0;
        while(i<m&&j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                temp[k]=nums1[i];
                i++;
                k++;
            }
            else
            {
                   temp[k]=nums2[j];
                j++;
                k++;
            }
        }
        while(i<m)
        {
            temp[k]=nums1[i];
            i++;
            k++;
        }
        while(j<n)
        {
         temp[k]=nums2[j];
          j++;
          k++;
        }
        for(k=0;k<m+n;k++)
        {
            nums1[k]=temp[k];
        }
}
void print(vector<int>v)
{
   
    for(int i : v)
    {
        cout<<i<<" ";
    }
}
int main()
{
    vector<int> nums1={1,3,5,7,9};
    vector<int> nums2={2,4,6,8};
    nums1.resize(nums1.size()+nums2.size());
    

    merge(nums1,5,nums2,4);
    print(nums1);

}