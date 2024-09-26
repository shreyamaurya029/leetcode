class Solution {
public:
    int mySqrt(int x) {
        long long low=0, high=x+(1LL*1);
        while(low <= high){
            long long mid = low+(high-low)/2;
            if(mid*mid > x){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low-1;
    }
};