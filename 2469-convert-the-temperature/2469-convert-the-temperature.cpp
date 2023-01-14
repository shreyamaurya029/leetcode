class Solution {
public:
    vector<double> convertTemperature(double c) {
        double k,f;
        k = double(c+ 273.15);
        f = double (c*1.80 + 32.00);
        return{k,f};
    }
};