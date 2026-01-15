const ll N = 1e6 + 5; 
vll spf(N);
void buildSPF(){
    for(ll i = 2; i < N; i++) spf[i] = i;
    for(ll i = 2; i*i < N; i++){
        if(spf[i] == i){
            for(ll j = i*i; j < N; j += i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}
int count(ll n){
    if(n <= 1) return 0;
    ll ct = 0;
    while(n > 1){
        n /= spf[n];
        ct++;
    }
    return ct;
}
