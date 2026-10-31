class Solution {
public:
    bool check(int k, vector<int>& inventory, int orders) {
        long long int count = 0;

        int c =0;
        for (int i : inventory) {
            if (i > k) {
                count += i - k;
            }

            if(i>=k){
                c++;
            }

            if (count+c >= orders) {
                return true;
            }
        }

        return count+c >= orders;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        const int mod = 1e9 + 7;
        int n = inventory.size();
        sort(inventory.rbegin(), inventory.rend());

        int low = 0;

        int high = inventory[0];

        int k = -1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (check(mid, inventory, orders)) {
                k = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        long long int sum = 0;
       
        for (int i = 0; i < n; i++) {

            int balls = inventory[i];
            if (balls > k) {
                orders -= (balls - k);
                inventory[i]=k;

                // k+1 k+2 ..... inventory[i]

                long long int s =
                    (balls * 1LL * (balls + 1)) / 2 - (k * 1LL * (k + 1)) / 2;

               
                sum = (sum + s) % mod;
            }

            if(orders ==0){
                break;
            }
        }

        sum = (sum+k*1LL*orders)%mod;

        return sum;
    }
};