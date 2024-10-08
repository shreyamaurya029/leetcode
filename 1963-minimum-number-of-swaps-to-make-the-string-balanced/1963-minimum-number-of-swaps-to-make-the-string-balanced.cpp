class Solution {
public:
    int minSwaps(string s) {
        int balance=0, unbalance = 0;
        for(auto it: s){
            if(it == '['){
                balance++;
            }
            else{
                balance--;
            }
            
            if(balance<0){
                unbalance++;
                balance = 0;
            }
        }
        
        return (unbalance+1)/2;
        
        
    }
};