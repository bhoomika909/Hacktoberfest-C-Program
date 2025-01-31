// For q queries, check whether a number is prime or not
// T C : N/2 + N/3 + N/5 + N/7 = N (1/2 + 1/3 + 1/5 + ...) = N * log (log (N))

#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);  // initially marking all these nos as prime


int main() {
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < N; i++) { // or i * i < N
        if(isPrime[i] == true) {
            for(int j = 2 * i; j < N; j += i) {  // i * i  in place of 2 * i would also work as nos before i * i would be marked false before itself
               // marking all the multiples of i as false
                isPrime[j] = false;
            }
        }
    }
    
    int q;
    cin >> q;
    while(q--) {
        int num;
        cin >> num;
        if(isPrime[num]) {
            cout << "Prime\n";
        }
        else 
        cout << "Not Prime\n";
    }
}
