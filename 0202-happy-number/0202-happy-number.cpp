class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = nextNumber(n);
        while(fast != 1 && slow != fast){
            slow = nextNumber(slow);
            fast = nextNumber(nextNumber(fast));
        }
        return fast == 1;
    }
    
private:
    int nextNumber(int n){
        int newNumber = 0;
        while(n != 0){
            int num = n%10;
            newNumber += num*num;
            n = n/10;
        }
        
        return newNumber;
    }
    
    
};