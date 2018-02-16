#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

int visit[10][10];
char boggle[10][10];
int w, h;
int x[] = {0, 0, +1, +1, +1, -1, -1, -1};
int y[] = {-1, +1, -1, 0, +1, -1, 0, +1};

bool traverseDictionary(int i, int j, string str, int pos) {
    // cout<<"---------------------"<<endl;;
    // cout<<boggle[i][j]<<endl;
    // cout<<"---------------------"<<endl;
    if (i == w || j == h) return false;
    if (str[pos] != boggle[i][j]) return false;
    if (str.size() == pos) return false;
    if (visit[i][j])return false;
    if (pos == (str.size() - 1) && boggle[i][j] == str[pos]) return true;

    visit[i][j] = 1;
    bool ret = false;
    for(int m = 0;  m<8; m++) {
        int tmpX = x[m]+i;
        int tmpY = y[m]+j;
        ret = traverseDictionary(tmpX, tmpY, str, pos+1);
        if (ret) return ret;
    }
    return ret;
}

int main() {
    int ks;
    cin>>ks;

	while(ks--) {
	    int n;
	    cin>>n;
	    vector<string>v;
	    map<string, bool>mp;
	    memset(visit, 0, sizeof(visit));
	    while(n--) {
	        string str;
	        cin>>str;
	        v.push_back(str);
	        mp[str] = 1;
	    }

        map<string, bool>::iterator it;
        cin>>w>>h;

        for(int i = 0; i<w; i++) {
            for(int j = 0; j<h; j++) {
                char ch;
                cin>>ch;
                boggle[i][j] = ch;
            }
        }
        vector<string>ans;
        for(it = mp.begin(); it != mp.end(); it++) {
            bool dic = false;
            for(int j = 0; j<w && !dic; j++) {
                for(int k = 0; k<h && !dic; k++) {
                    memset(visit, 0, sizeof(visit));
                    bool ret = traverseDictionary(j, k, it->first, 0);
                    if (ret) {
                        dic = true;
                        ans.push_back(it->first);
                    }
                }
            }
        }

        if (ans.size() == 0) {
            cout<<"-1"<<endl;
            continue;
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i< ans.size(); i++) {
            if (i != 0) cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;
	}
	return 0;
}
