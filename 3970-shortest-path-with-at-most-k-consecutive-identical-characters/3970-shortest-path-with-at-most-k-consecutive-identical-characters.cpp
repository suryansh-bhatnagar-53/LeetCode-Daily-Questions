class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        using T = tuple<int,int,int,char>;
        vector<vector<pair<int,int>>>adj(n);
        for(auto &i : edges){
            adj[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<T,vector<T>,greater<T>>pq;
        vector<vector<int>>dist(n,vector<int>(k + 1,INT_MAX));
        pq.push({0,0,1,labels[0]});
        dist[0][1] = 0;
        while(!pq.empty()){
            auto [dis,node,p_streak,p_char] = pq.top();
            pq.pop();
            if(node == n - 1){
                return dis;
            }
            for(auto &i : adj[node]){
                int n_dist = dis + i.second;
                int n_streak = p_streak,n_char = labels[i.first];
                if(p_char == n_char){
                    n_streak++;
                }
                else{
                    n_streak = 1;
                }
                if(n_streak > k){
                    continue;
                }
                if(dist[i.first][n_streak] > n_dist){
                    dist[i.first][n_streak] = n_dist;
                    pq.push({n_dist,i.first,n_streak,n_char});
                }
            }
        }
        return -1;
    }
};