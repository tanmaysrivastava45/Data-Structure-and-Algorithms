// class Solution {
// public:
//     int trailingZeroes(int n) {
        
//         for(long long int i=n-1;i>0;i--)
//         {
//             n=1ll*n*i;
//         }
//         int count=0;
//         int q=0;
//         while(n!=0)
//         {
//             q=n%10;
//             if(q!=0)
//             {
//                 break;
//             }
//             else{
//                 count++;
//             }
//             n=n/10;
//         }
//         return count;
//     }
// };
class Solution {
public:
    int trailingZeroes(int n) {
        int count =0;
        while (n >= 5) {
            n /= 5;
            count += n; // Add the count of multiples of 5
        }
        return count;
    }
};
