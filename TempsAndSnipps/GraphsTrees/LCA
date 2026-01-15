const ll N = 1e5;
vector<vector<ll>> g;
vector<vector<ll>> up; //up[i][j] = 2^jth ancestor of i
vector<ll> depth;
//replace 31/32 with any other bit depending on the question constraints
 
void dfs(ll a, ll p, ll d){
    depth[a] = d;
    up[a][0] = p;
 
    for (ll j = 1; j < 32; j++){
        up[a][j] = up[up[a][j - 1]][j - 1];
    }
 
    for (auto ch : g[a]){
        if(ch != p){
            dfs(ch, a, d + 1); 
        }
    }
}
 
ll get_lca(ll a, ll b){
    if(depth[a] < depth[b]){
        swap(a, b);
    }
    ll k = depth[a] - depth[b];
    for(ll j = 31; j >= 0; j--){
        if(k & (1LL << j)){
            a = up[a][j];
        }
    }
    
    if(a == b) return a;
 
    for(ll j = 31; j >= 0; j--){
        if(up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
 
    return up[a][0];
}
