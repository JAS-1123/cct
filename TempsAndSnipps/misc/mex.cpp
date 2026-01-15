ll mex(vll &a, ll n){
    as(a);
    ll mx = 0;
    for(ll i = 0; i < n; i++){
        if(a[i] == mx) mx++;
    }
    return mx;
}
