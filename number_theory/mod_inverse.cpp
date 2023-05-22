
// To compute x^y under modulo m
lli power(lli x,  lli y, lli m){
     if (y == 0){
        return 1;
    }
    lli p = power(x, y / 2, m) % m;
    p = (p * p) % m;

    return (y % 2 == 0) ? p : (x * p) % m;
}
lli modInverse(lli A, lli M){
     return power(A, M - 2, M);
}
 
lli multiply(lli a, lli b,lli mod){
    return ((a % mod) * (b % mod)) % mod;
}

lli divide(lli a, lli b,lli mod){
    return multiply(a, modInverse(b,mod),mod);
}
