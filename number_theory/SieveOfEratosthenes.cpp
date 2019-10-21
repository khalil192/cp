/*
Sieve Of Eratosthenes - to find all primes ina a range 1 .. n
on O(n) time and O(n) space complexity
*/


#include<stdio.h>
#include<vector>
#include<math.h>
#include<iostream>
#define lli long long int
#define fo(i,n) for(lli i =0;i<n;i++)
#define FO(i,x,n) for(lli i = x;i<n;i++)
using namespace std; 
vector<lli> v;

void regular_sieve(lli n,vector<lli>& primes){
	vector<bool> is_prime(n+1,true);
	is_prime[0] = is_prime[1] = false;
	for(lli  i =2;i*i <n;i++){
		if(is_prime[i]){
			for(lli j = 2*i;j<n;j+=i){
				is_prime[j] = false;
			}
		}
	}
	FO(i,2,n){
		if(is_prime[i]){
			primes.push_back(i);
		}
	}
}


int main(){ 
	lli n = 1e6+2;
	vector<lli> primes;
	regular_sieve(n,primes); 
    // by the end of that function we have all  the primes stored in primes vector
	
	return 0; 
} 

