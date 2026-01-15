vll primes;
void sieve(ll limit){
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2; i <= limit; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(ll j = i*i; j <= limit; j += i){
                isPrime[j] = false;
            }
        }
    }
}

ll count(ll n){
    ll cnt = 0;
    for(ll prime : primes){
        if(prime*prime > n) break;
        while(n%prime == 0){
            n /= prime;
            cnt++;
        }
    }
    if(n > 1) cnt++;
    return cnt;
}
