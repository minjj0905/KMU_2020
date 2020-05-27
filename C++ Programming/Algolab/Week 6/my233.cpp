#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, m, n, ans, cnt;
bool visit[110][110];
string arr[110];
vector<int> v; 
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void init();
void dfs();
void start();

int main() {
    cin >> t;
    while(t--) {
        init();
        start();
        cout << ans << endl;
        sort(v.begin(), v.end());
        for(auto it = v.rbegin(); it!=v.rend(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
}

void init() {
    cin >> n >> m;
    ans = 0;
    cnt = 0;
    v.clear();
    for(int i=0; i<m; i++) cin >> arr[i];
    for(int y=0; y<m; y++) {
        for(int x=0; x<n; x++) {
            visit[y][x] = true;
        }
    }
}

void dfs(int y, int x) {
    cnt++;
    visit[y][x] = false;
    for(int d=0; d<4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(0>ny || 0>nx || ny>=m || nx>=n) continue;
        if(arr[ny][nx] == '.' && visit[ny][nx]) dfs(ny, nx);
    }
}

void start() {
    for(int y=0; y<m; y++) {
        for(int x=0; x<n; x++) {
            if(arr[y][x] == '.' && visit[y][x]) {
                cnt = 0;
                ans ++;
                dfs(y,x);
                v.push_back(cnt);
            }
        }
    }
}