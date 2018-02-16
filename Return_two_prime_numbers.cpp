#include<iostream>
#include<vector>
using namespace std;

#define MAX_PRIME 10000
int prime[MAX_PRIME + 3];

void sieve() {
    prime[1] = 1;
    for(int i = 4; i<MAX_PRIME; i+=2) {
        prime[i] = 1;
    }

    for(int i = 3; i*i <= MAX_PRIME; i++) {
        for (int j = i*i; j <= MAX_PRIME; j += i) {
            prime[j] = 1;
        }
    }
}

int main() {
    sieve();
    int ks;
    cin>>ks;
    while(ks--) {
        int n;
        cin>>n;

        if (!prime[n-2]) {
            cout<<2<<" "<<n-2<<endl;
            continue;
        }

        for(int i = 3; i<=MAX_PRIME/2; i+=2)  {
            if(!prime[i]) {
                int tmp = n - i;
                if(!prime[tmp]) {
                    cout<<i<<" "<<tmp<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
