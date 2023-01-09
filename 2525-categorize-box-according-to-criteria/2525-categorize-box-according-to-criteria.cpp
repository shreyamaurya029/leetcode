class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        int a=0,b=0;
        long long v = (long long)length*(long long)height*(long long)width;
        if(length>=1e4 || height>=1e4 || width>= 1e4 || v>= 1e9){
            a=1;
        }
        if(mass>=100){
            b=1;
        }
        if(a==1 && b==1){
            return "Both";
        }
        if(a==0 && b==0){
            return "Neither";
        }
        if(a==1 ){
            return "Bulky";
        }
        
        return "Heavy";
       
    }
    
};