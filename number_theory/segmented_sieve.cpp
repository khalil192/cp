/*
this is just an updated version of sieve of Eratosthenes
the main optimisation is space complexity which is reduced to O(sqrt(n)) from O(n)
the time complexity remains same though
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
void SieveOfEratosthenes(int n){ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          v.push_back(p);
} 
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

void segmented_sieve(lli n,vector<lli>& primes){
	lli limit = sqrt(n) +1;
	regular_sieve(limit,primes);
	lli size = primes.size();
	lli low = limit,high = 2*limit;
	bool is_prime[limit+5];
	while(low<n){
		if(high > n)	high = n;
		fo(i,limit) is_prime[i] = true;
		for(int i=0;i<size;i++){
			lli curr = floor(low/primes[i]) * primes[i];
			if(curr < low) curr+=primes[i];
			
			for(;curr < high;curr += primes[i]){
				is_prime[curr - low] = false;
			}
		}
		for(lli i = low;i<high;i++){
			if(is_prime[i-low]) primes.push_back(i);
		}
		low = high, high+= limit;
	}
}

int main(){ 
	lli n = 1e6+2;
	vector<lli> primes;
	segmented_sieve(n,primes); 
	lli c =0;
	// fo(i,primes.size()){
		// cout<<primes[i]<<" = "<<v[i]<<endl; c++;
	// }
	cout<<primes.size()<<"  = "<< v.size()<<endl;
	return 0; 
} 

