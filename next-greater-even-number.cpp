#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<map>
#include<limits>
#include<algorithm>
using namespace std;

string xchng(int i, int j, string s) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
    return s;
}

long long convert(string s) {
    int l = 0;
    long long ret = 0;
    while(l < s.size()) {
        ret = (ret*10);
        ret += (s[l]-'0');
        l++;
    }
    return ret;
}

string str;

string generateString(vector<int>v, int i, int mn, int mx) {
    int b1 = false, b2 = false;
    for(int j = v.size()-1; j>=0; j--) {
            if (v[j]%2 == 0 && mx == v[j]) {
                str[str.size()-1] = v[j]+'0';
                v[j] = -1;
                b1 = true;
            }
            if(b1)break;
    }
    for(int j = 0; j < v.size(); j++) {
        if(v[j] < 0)continue;

        if (mn <= v[j]) {
            str[i] = v[j]+'0';
            v[j] = -1;
            b2 = true;
        }
        if(b2)break;
    }

    int id = i+1;
    for(int j = 0; j<v.size(); j++) {
        if(v[j] >= 0) {
            str[id++] = v[j]+'0';
        }

        if(id == str.size())break;

    }
    return str;
}

bool validataionString(string s1, string s2) {
    if(convert(s1) < convert(s2)) return false;
    map<int, int>mp;
    for(int i = 0; i<s2.size(); i++) {
        mp[s2[i]-'0']++;
    }
    for(int i = 0; i<s1.size(); i++) {
        mp[s1[i]-'0']--;
    }

    map<int, int>::iterator it;

    for(it = mp.begin(); it != mp.end(); it++) {
        if(it->second != 0)return false;
    }
    return true;
}

int main() {
    int ks;
    cin>>ks;
    map<int, int>mp;
    while(ks--) {
        string ans;
        bool dicision = false;
        mp.clear();
        string tmp;
        string s;
        cin>>s;
        tmp = s;
        int idx = s.size()-2;
        for(int i = idx; i >= 0; i--) {
            s = tmp;
            int cnt = 0;
            int cntM = 0;
            int mx = numeric_limits<int>::min(), mn = numeric_limits<int>::max();
            vector<int>v;
            for(int j = i; j< s.size(); j++) {
                if ((s[i]-'0') < (s[j]-'0')) {
                    // cout<<(s[i]-'0')<<" "<<(s[j]-'0')<<endl;
                    cntM++;
                    mn = min(mn, s[j]-'0');
                }
                if((s[j]-'0')%2 == 0) {
                    mx = max(mx, s[j]-'0');
                    cnt++;
                }

                v.push_back(s[j]-'0');
                if(mp.find(s[j]-'0') == mp.end()) {
                    mp[s[j]-'0'] = v.size()-1;
                }
            }

            if(cnt == 0 || cntM == 0)continue;
            // cout<<"----"<<i<<" "<<mn<<" "<<mx<<" "<<cnt<<endl;
            if(mn == mx && cnt == 1 && cntM == 1)continue;
            // cout<<"hello"<<endl;

            // cout<<s[i]<<endl;
            // cout<<"----"<<i<<" "<<mn<<" "<<mx<<" "<<cnt<<endl;
            sort(v.begin(), v.end());
            for(int j = v.size()-1; j>=0; j--) {
                if(v[j]%2 == 0) {
                    str = s;
                    for(int k = v.size()-1; k >= 0; k--) {
                        if(j == k) continue;
                        if(mn > v[k])continue;

                        string tmp1 = generateString(v, i, v[k], v[j]);
                        // cout<<"-------------"<<endl;
                        // cout<<"-------------"<<endl;
                        // cout<<tmp1<<endl;
                        if(validataionString(tmp1, s)) {
                            //cout<<tmp1<<endl;
                            dicision = true;
                            //break;
                            if(ans == "") {
                                ans = tmp1;
                            } else if(ans[i]-'0' > tmp1[i]-'0') {
                                ans = tmp1;
                            }
                        }
                    }
                    // if(dicision)break;
                }
            }
            if(dicision)break;
        }
        if(!dicision)cout<<"-1"<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}


// 2 3810 866851995210
