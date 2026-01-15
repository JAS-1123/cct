ll const N = 2e5 + 5;
vll seg(4*N, 0);
vll a(N);
// ALL ARE 1 BASED INDEX
void build(ll ind, ll low, ll high){
    if(low == high){
        seg[ind] = a[low];
        return;
    }
    ll mid = (low + high)/2;
    build(2*ind, low, mid);
    build(2*ind + 1, mid + 1, high);

    seg[ind] = seg[2*ind] + seg[2*ind + 1];
}

void update(ll node, ll start, ll end, ll idx, ll val){
    if(start == end){
        seg[node] = val;
        a[idx] = val;
        return;
    }
    ll mid = (start + end)/2;
    if(idx <= mid){
        update(2*node, start, mid, idx, val);
    }
    else{
        update(2*node + 1, mid + 1, end, idx, val);
    }
    seg[node] = seg[2*node] + seg[2*node + 1];
}
 
ll queryRange(ll node, ll start, ll end, ll l, ll r){
    if(start > end or start > r or end < l) return 0;    
    if(start >= l and end <= r){
        return seg[node];
    }    
    ll mid = (start + end)/2;
    ll p1 = queryRange(node*2, start, mid, l, r);
    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r);
    return (p1 + p2);
}
