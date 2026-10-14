class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*1ll*num < sum)return "";
        string n="";
        int x=0;
        while(num--){
            if(sum>9){
                n+=to_string(9);
                sum-=9;
            }
            else{
                n+=to_string(sum);
                sum=0;
            }
        }
        return n;
    }
};