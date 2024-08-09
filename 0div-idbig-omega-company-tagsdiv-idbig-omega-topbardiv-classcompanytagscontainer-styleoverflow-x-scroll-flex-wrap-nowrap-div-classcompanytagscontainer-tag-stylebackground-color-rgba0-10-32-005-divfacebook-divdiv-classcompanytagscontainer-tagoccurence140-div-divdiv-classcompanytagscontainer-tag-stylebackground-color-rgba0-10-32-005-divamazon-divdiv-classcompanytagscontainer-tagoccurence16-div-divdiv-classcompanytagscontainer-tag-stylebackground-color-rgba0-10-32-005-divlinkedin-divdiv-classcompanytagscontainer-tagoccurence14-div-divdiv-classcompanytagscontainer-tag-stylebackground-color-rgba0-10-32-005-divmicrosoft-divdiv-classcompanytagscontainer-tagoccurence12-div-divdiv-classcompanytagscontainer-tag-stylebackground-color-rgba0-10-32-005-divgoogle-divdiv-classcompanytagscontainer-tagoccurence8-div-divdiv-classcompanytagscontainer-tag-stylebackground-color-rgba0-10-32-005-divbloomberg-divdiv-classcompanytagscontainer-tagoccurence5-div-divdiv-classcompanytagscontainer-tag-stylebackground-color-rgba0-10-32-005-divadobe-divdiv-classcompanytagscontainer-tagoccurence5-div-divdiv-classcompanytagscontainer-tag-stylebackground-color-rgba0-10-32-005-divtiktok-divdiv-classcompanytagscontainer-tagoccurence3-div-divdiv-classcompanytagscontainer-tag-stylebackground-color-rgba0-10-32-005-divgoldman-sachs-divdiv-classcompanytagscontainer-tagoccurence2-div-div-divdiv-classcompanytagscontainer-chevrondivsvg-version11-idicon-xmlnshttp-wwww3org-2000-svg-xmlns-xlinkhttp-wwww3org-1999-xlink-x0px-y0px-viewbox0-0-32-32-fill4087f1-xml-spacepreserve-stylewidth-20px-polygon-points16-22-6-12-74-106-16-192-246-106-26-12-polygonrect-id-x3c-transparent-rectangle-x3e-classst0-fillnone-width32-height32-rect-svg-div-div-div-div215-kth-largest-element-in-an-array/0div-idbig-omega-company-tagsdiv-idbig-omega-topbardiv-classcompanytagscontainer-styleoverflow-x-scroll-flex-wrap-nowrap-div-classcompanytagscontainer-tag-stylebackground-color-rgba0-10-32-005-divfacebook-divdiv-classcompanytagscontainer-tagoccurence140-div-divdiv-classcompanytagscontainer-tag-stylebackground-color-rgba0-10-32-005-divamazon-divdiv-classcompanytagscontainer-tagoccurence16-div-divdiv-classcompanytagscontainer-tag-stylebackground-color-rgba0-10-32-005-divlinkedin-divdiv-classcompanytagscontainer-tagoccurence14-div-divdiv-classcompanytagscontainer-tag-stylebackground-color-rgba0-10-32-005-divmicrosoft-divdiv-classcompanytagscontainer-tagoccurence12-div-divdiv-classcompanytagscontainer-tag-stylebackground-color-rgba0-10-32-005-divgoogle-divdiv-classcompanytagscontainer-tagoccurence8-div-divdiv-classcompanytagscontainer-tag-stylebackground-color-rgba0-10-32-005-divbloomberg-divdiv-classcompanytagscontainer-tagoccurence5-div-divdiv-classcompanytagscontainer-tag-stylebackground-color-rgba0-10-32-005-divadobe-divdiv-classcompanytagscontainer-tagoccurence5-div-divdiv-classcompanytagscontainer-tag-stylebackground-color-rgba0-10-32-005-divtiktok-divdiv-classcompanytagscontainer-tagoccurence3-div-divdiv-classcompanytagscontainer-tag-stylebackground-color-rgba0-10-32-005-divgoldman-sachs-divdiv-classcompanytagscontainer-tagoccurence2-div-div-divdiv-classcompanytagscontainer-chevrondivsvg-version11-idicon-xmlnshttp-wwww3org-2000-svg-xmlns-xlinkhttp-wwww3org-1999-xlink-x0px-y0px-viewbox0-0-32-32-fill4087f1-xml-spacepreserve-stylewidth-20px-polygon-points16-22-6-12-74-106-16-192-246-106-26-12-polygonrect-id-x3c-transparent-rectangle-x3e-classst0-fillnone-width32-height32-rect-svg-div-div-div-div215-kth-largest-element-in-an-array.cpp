class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq; //it is max_heap    
        for(int i=0; i<nums.size();i++){
            pq.push(nums[i]);
        }
        
        for(int i=1; i<k; i++){
            pq.pop();
        }
        
        //at index i=1 we pop the 1st largest element
        //at index i=2 we pop the 2nd largest element
        //at index k-1 we pop the k-1 largest element 
        //hence we return the kth element
        
        return pq.top();
    }
};
