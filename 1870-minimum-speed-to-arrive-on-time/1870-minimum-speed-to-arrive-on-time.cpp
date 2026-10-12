class Solution {
public:
    double check(vector<int> dis, double m){
        double time=0.0;
        for(int i=0; i<dis.size()-1; i++)
        {
            time += ceil(dis[i]/m);
        }
        time += dis[dis.size()-1]/m;
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        int l=1, r=1e7, res=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(check(dist,m)<=hour)
            {
                res=m;
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
    return res;
    }
};