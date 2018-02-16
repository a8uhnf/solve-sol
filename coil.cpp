#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;


int mat[100][100];
int visit[100][100];
int total, avg;

vector<int>steps;
int w, h;
int x[] = {0, 0, -1, +1};
int y[] = {-1, +1, 0, 0};


void traverseCoil(int i, int j, int dir, int step, vector<int>&v) {
    if (i<0 || j<0 || i==w || j==h) return;
    if(visit[i][j] && steps[step] == 0)return;
    if (visit[i][j])return;

    if (total == 0)return;
    if (step >= steps.size())return;
    if (!visit[i][j]) {
        total--;
        visit[i][j] = 1;
        steps[step]--;
        v.push_back(mat[i][j]);
    }

    // cout<<mat[i][j]<<endl;
    // visit[i][j] = 1;

    if (steps[step] == 0) {
        if (dir) {
            for(int k = 2; k<4; k++) {
                int tmpX = i + x[k], tmpY = j;
                // traverseCoil(tmpX, tmpY, 1-dir, step+1, v);
                if (abs(avg-tmpX) < abs(avg-i)) {
                    traverseCoil(tmpX, tmpY, 1-dir, step+1, v);
                }
            }
        } else {
            for(int k = 0; k<2; k++) {
                int tmpX = i + x[k], tmpY = j + y[k];
                // traverseCoil(tmpX, tmpY, 1-dir, step+1, v);
                if(abs(avg-tmpY) < abs(avg-j)) {
                    traverseCoil(tmpX, tmpY, 1-dir, step+1, v);
                }
            }
        }
        return;
    }

    if(dir) {
        traverseCoil(i, j+1, dir, step, v);
        traverseCoil(i, j-1, dir, step, v);
    } else {
        traverseCoil(i+1, j, dir, step, v);
        traverseCoil(i-1, j, dir, step, v);
    }
    return;
}


int main() {

    int ks;
    cin>>ks;

    while(ks--) {
        memset(visit, 0, sizeof(visit));
        int n;
        cin>>n;
        h = 4*n, w = 4*n;
        int cnt = 1;
        for (int i = 0; i< w; i++) {
            for(int j = 0; j< h; j++) {
                mat[j][i] = cnt++;
            }
        }
        avg = h/2;
        steps.clear();

        steps.push_back(w);
        int tmpW = w - 2;
        total = w;
        while(tmpW) {
            steps.push_back(tmpW);
            steps.push_back(tmpW);
            total += 2*tmpW;
            tmpW = tmpW - 2;
        }
        vector<int>coil1, coil2;
        int tmp = total;
        traverseCoil(w-1, h-1, 1, 0, coil1);
        reverse(coil1.begin(), coil1.end());
        for(int i = 0; i<coil1.size(); i++) {
            if (i != 0)cout<<" ";
            cout<<coil1[i];
        }
        cout<<endl;
        memset(visit, 0, sizeof(visit));
        steps.clear();

        steps.push_back(w);
        tmpW = w - 2;
        total = w;
        while(tmpW) {
            steps.push_back(tmpW);
            steps.push_back(tmpW);
            total += 2*tmpW;
            tmpW = tmpW - 2;
        }

        traverseCoil(0, 0, 1, 0, coil2);

        // cout<<"-------------------"<<endl;

        reverse(coil2.begin(), coil2.end());
        for(int i = 0; i<coil2.size(); i++) {
            if (i != 0)cout<<" ";
            cout<<coil2[i];
        }
        cout<<endl;
        // int
    }
    return 0;
}
