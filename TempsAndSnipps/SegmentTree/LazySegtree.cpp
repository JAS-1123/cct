ll const N = 2e5 + 5;
vll seg(4*N, 0);
vll lazy(4*N);
vll a(N);
//ALL ARE 1 BASED INDEX
void build(ll ind, ll low, ll high){
    if(low == high){
        seg[ind] = [low];
        return;
    }
    ll mid = (low + high)/2;
    build(2*ind, low, mid);
    build(2*ind + 1, mid + 1, high);
 
    seg[ind] = seg[2*ind] + seg[2*ind + 1];
}
 
void updateRange(ll node, ll start, ll end, ll l, ll r, ll val){
    if(lazy[node] != 0){ 
        seg[node] += (end - start + 1)*lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end or start > r or end < l){
        return;
    }
    if(start >= l and end <= r){
        seg[node] += (end - start + 1)*val;
        if(start != end){
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    ll mid = (start + end)/2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end, l, r, val);
    seg[node] = seg[node*2] + seg[node*2+1];
}
 
ll queryRange(ll node, ll start, ll end, ll l, ll r){
    if(start > end or start > r or end < l) return 0;
    if(lazy[node] != 0){
        seg[node] += (end - start + 1)*lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l and end <= r){
        return seg[node];
    }
    ll mid = (start + end)/2;
    ll p1 = queryRange(node*2, start, mid, l, r);
    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r);
    return (p1 + p2);
}
