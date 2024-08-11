class Solution {
public:
    int minBitFlips(int start, int goal) {
        //bascially use XOR operation to know which bits are different
        //then count those bits
        int count=0;
        while(start>0 or goal>0){
            if(goal%2 != start%2){
                count++;
            }
            goal = goal/2;
            start = start/2;
        }
        return count;
    }
};