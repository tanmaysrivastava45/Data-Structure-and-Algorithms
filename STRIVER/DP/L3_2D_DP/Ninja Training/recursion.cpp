#include<bits/stdc++.h>
using namespace std;

int recursion(int ind,int last,vector<vector<int>>&points){
    if(ind==0){
        int maxi =0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi = max(maxi,points[ind][i]);
            }
        }
        return maxi;
    }
    int maxi =0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int point = points[ind][i]+recursion(ind-1,i,points);
            maxi = max(maxi,point);
        }
    }
    return maxi;
}

int ninjaTraining(int n,vector<vector<int>>&points){
  return recursion(n-1,3,points);
}

int main() {
  // Define the points matrix
  vector<vector<int>> points = {{10, 40, 70},
                                 {20, 50, 80},
                                 {30, 60, 90}};

  int n = points.size();  // Get the number of days
  // Call the ninjaTraining function to find the maximum points and print the result
  cout << ninjaTraining(n, points);
}
