class Solution {
public:
    int sumCounts(vector<int>& nums) {
        unordered_set<int>st;
        int ans = 0;
        int distinct = 0;
        for(int i=0;i<nums.size();i++){
            st.clear();
            for(int j=i;j<nums.size();j++){
                st.insert(nums[j]);
                distinct = st.size();
                ans += (distinct*distinct);
            }
        }
        return ans;
    }
};