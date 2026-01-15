vll ncr(40, vll(40, 0));
void NCR(){
    for(ll i = 0; i < 40; i++){
        ncr[i][0] = 1;
        for(ll j = 1; j <= i; j++){
            ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
        }
    }
}

vll npr(40, vll(40, 0));
void NPR(){
    for(ll i = 0; i < 40; i++){
        npr[i][0] = 1;
        for(ll j = 1; j <= i; j++){
            npr[i][j] = i*npr[i - 1][j - 1];
        }
    }
}
