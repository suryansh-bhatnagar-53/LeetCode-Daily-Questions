class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<tuple<int, int, int>> v;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            v.push_back({sum, nums[i], i});
        }

        sort(v.begin(), v.end());

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || get<2>(v[i]) == i) continue;

            int j = i;
            int cycle = 0;

            while (!vis[j]) {
                vis[j] = 1;
                j = get<2>(v[j]);
                cycle++;
            }

            ans += cycle - 1;
        }

        return ans;
    }
};