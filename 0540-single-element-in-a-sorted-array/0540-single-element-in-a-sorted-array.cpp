class Solution {
public:
    int singleNonDuplicate(vector<int>& n) {
        int low=0, high=n.size()-2;
        while(low<=high){
            int mid = (low+high)/2;
            if(n[mid]==n[mid^1])
                low = mid+1;
            else
                high = mid-1;
        }
        return n[low];
    }
};