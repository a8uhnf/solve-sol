#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main() {
    vector<int>v;
    int ks;
    cin>>ks;

    while(ks--) {
        int n;
        cin>>n;
        v.clear();

        while(n--) {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        int ans = 0;

        for(int i = 0; i<v.size(); i++) {
            int tmp = 0;
            for(int j = v.size()-1; j>i; j--) {
                if (v[j] >= v[i]) {
                    tmp = j-i;
                    ans = max(ans, tmp);
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
