#include<bits/stdc++.h>

#define CUSTOM 10000

using namespace std;

using pp = pair<int, int>;

bool flag[CUSTOM];
vector<int> adj[CUSTOM];

void make_graph() {
    for (int i = 0; i < CUSTOM; i++) {
        if (flag[i])
            continue;
        for (int j = 0; j < 4; j++) {
            int tt = pow(10, j);
            int prev, dig, next;
            prev = i / tt;
            dig = prev % 10;
            prev /= 10;
            next = i % tt;
            for (int k = 0; k <= 9; k++) {
                if (k == dig) {
                    continue;
                }
                int num = prev * tt * 10 + tt * k + next;
                if (!flag[num]) {
                    adj[i].push_back(num);
                }
            }
        }
    }
}

void compute() {
    for (int i = 2; i <= 100; i++) {
        if (!flag[i]) {
            for (int j = i + i; j < CUSTOM; j += i) {
                flag[j] = true;
            }
        }
    }
    make_graph();
}

int bfs(int x, int y) {
    if (x == y) return 0;
    queue<pp> q;
    bool check[CUSTOM];
    for (bool &i : check) i = false;
    check[x] = true;
    q.push(make_pair(x, 0));
    while (!q.empty()) {
        pp tt = q.front();
        q.pop();
        for (auto j = adj[tt.first].begin(); j != adj[tt.first].end(); j++) {
            if (!check[*j]) {
                check[*j] = true;
                if (*j == y) {
                    return tt.second + 1;
                }
                q.push(make_pair(*j, tt.second + 1));
            }
        }
    }
    return -1;
}

int main() {
    compute();
    int x, y;
    cin >> x >> y;
    int val = bfs(x, y);
    if (val == -1) {
        cout << -1 << "\n";
    } else {
        cout << val << "\n";
    }
    return 0;
}