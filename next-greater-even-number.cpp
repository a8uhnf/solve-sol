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

int main() {
    int ks;
    cin>>ks;
    map<int, int>mp;
    while(ks--) {
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
            cout<<"----"<<i<<" "<<mn<<" "<<mx<<" "<<cnt<<endl;
            if(mn == mx && cnt == 1 && cntM == 1)continue;
            cout<<"hello"<<endl;

            // cout<<s[i]<<endl;
            cout<<"----"<<i<<" "<<mn<<" "<<mx<<" "<<cnt<<endl;

            int b1 = false, b2 = false;
            for(int j = v.size()-1; j>=0; j--) {
                    if(mx == mn && mn == v[j]) {
                        if (j-1 >= 0 && mx == v[j-1] && mn == v[j]) {
                            s[i] = v[j]+'0';
                            s[s.size()-1] = v[j]+'0';
                            v[j] = -1;
                            v[j-1] = -1;
                            break;
                        } else if(cnt > 1) {
                            s[i] = v[j]+'0';
                            v[j] = -1;
                            for(int k = v.size()-1; k>=0; k--) {
                                if(v[k]%2 == 0 && mx != v[k]) {
                                    // cout<<"hello"<<endl;
                                    s[s.size()-1] = v[k]+'0';
                                    v[k] = -1;
                                    break;
                                }
                            }
                        } else if(cntM > 1) {
                            if (cnt == 1) {
                                s[s.size()-1] = mx;
                                int p = mp[mx];
                                cout<<mx<<" - "<<v[p]<<endl;
                                v[p] = -1;

                                for(int k = 0; k<v.size(); k++) {
                                    if(v[k] < 0)continue;
                                    if(s[i]-'0' < v[k]) {
                                        // cout<<"hello"<<endl;
                                        s[i] = v[k]+'0';
                                        v[k] = -1;
                                        break;
                                    }
                                }
                            } else if(cntM == 1) {
                                s[i] = mn;
                                int p = mp[mn];
                                v[p] = -1;
                                for(int k = v.size()-1; k>=0; k--) {
                                    if(v[k] < 0)continue;
                                    if(v[k]%2 == 0) {
                                        // cout<<"hello"<<endl;
                                        s[i] = v[k]+'0';
                                        v[k] = -1;
                                        break;
                                    }
                                }
                            }
                        }
                        b1 = true;
                        b2 = true;
                    } else if(v[j]%2 == 0 && mx == v[j] && !b1) {
                        s[s.size()-1] = v[j]+'0';
                        v[j] = -1;
                        b1 = true;
                    } else if (mn == v[j] && !b2) {
                        s[i] = v[j]+'0';
                        v[j] = -1;
                        b2 = true;
                    }

                    if(b1 && b2)break;
            }
            string tmp;

            int id = i+1;
            sort(v.begin(), v.end());
            for(int j = 0; j<v.size(); j++) {

                if(v[j] >= 0) {
                    s[id++] = v[j]+'0';
                }

                if(id == s.size())break;

            }
            break;
        }
        if(tmp == s)cout<<"-1"<<endl;
        else cout<<s<<endl;
    }

    return 0;
}
