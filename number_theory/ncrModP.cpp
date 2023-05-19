/*
mainly in competitve programming if there is a Combinatorics problem..
we often needed to use Ncr which is N! / (N-r)! * r!
but Ncr may overflow.. hence we will be asked for the ans % large_prime_number
in this code the function ncrMod gives the answer.. for Ncr mod prime_number

ncrModP = (n!/ ((n-r)! (r)!))%p
as it overflows we have to find n! mod p , (n-r)! mod p , (r)! mod p

and then we can't just divide n! modp with r! mod p..
we have to do  ncrModP = (n! mod p)  * modular_inverse_p(((n-r)! mod p))) * modular_inverse_p(((r)! mod p)))

for finding modular inverse i'm using fermat's theorem to solve 
a^prime ≡ a (mod p)
a^-1 ≡ a^p-2 (mod p)
*/


#include<stdio.h>
#include<iostream>
#include<vector>
#define lli long long int
// i'm using long long int because the value often overflows int
using namespace std;
#define MAXI 10001
lli mod = 1e9 +7; //sample prime considered here is 10^9 +7; 


lli fact[100001],n;


void find_facts(lli n){
    fact[0] =1;
    for(lli i=1;i<n;i++){
        fact[i] = ((fact[i-1] * i))%mod; 
    }
}

lli pow_modP(lli x,lli expo,lli prime){
    // returns pow(x,expo) .. x^expo (mod prime)
    lli res =1;
     while (expo > 0) { 
        // If y is odd, multiply x with result 
        if (expo & 1) 
            res = (res * x)%prime; 
        // expo must be even now 
        expo >>= 1; // y = y/2 
        x = (x * x)%prime; // Change x to x^2 
    } 
    return res;
}
lli mod_inverse(lli x,lli prime){
    return pow_modP(x,prime-2,prime);
}
lli ncrModP(lli n,lli r,lli prime){
     if(n < r){return 0;}
    if(r==0){return 1;}
    return (((fact[n] * mod_inverse(fact[r],prime) )% prime ) * 
        mod_inverse(fact[n-r],prime) %prime);
}

int main(){ 
    n = 1000;
    find_facts(n);
    cout<<ncrModP(344,213,mod);
    return 0;
}
