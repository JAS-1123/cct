vll div(ll n){
    vll d;
    for(ll i = 1; i*i <= n; i++){
        if(n%i == 0){         
            if(n/i == i){
                d.pb(i);
            }
            else{
                d.pb(i);
                d.pb(n/i);
            }
        }
    }
    return d;
}
