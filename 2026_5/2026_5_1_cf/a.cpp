#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n * 2);
    for (int i = 0; i < n * 2; i++) {
        cin >> a[i];
    }
    int pl = -1, pr = -1;
    for (int i = 0; i < 2 * n; i++) {
        if (a[i] == 0 && pl != -1) {
            pr = i;
            break;
        }
        if (a[i] == 0 && pl == -1) {
            pl = i;
        } 
    }
    vector<int> ans1, ans2;
    ans1.push_back(0);
    ans2.push_back(0);
    for (int i = 1; pl - i >= 0 && pl + i < 2 * n; i++) {
        if (a[pl - i] != a[pl + i]) {
            break;
        }
        ans1.push_back(a[pl - i]);
    }
    int mx = 0;

    sort(ans1.begin(), ans1.end());
    if (ans1.back() == ans1.size() - 1) {
        mx = ans1.size();
    } else {
        for (int i = 1; i < ans1.size(); i++) {
            if (ans1[i] != ans1[i - 1] + 1) {
                mx = ans1[i - 1] + 1;
                break;
            }
        }
    }

    for (int i = 1; pr - i >= 0 && pr + i < 2 * n; i++) {
        if (a[pr - i] != a[pr + i]) {
            break;
        }
        ans2.push_back(a[pr - i]);
    }
    sort(ans2.begin(), ans2.end());
    if (ans2.back() == ans2.size() - 1) {
        mx = max(mx, (int)ans2.size());
    } else {
        for (int i = 1; i < ans2.size(); i++) {
            if (ans2[i] != ans2[i - 1] + 1) {
                mx = max(mx, ans2[i - 1] + 1);
                break;
            }
        }
    }

    vector<int> ans;
    ans.push_back(0);
    for (int i = 1; pl + i <= pr - i; i++) {
        if (a[pl + i] != a[pr - i]) {
            cout << max(mx, 1) << endl;
            return;
        }
        ans.push_back(a[pl + i]);
    }
    for (int i = 1; pl - i >= 0 && pr + i < n * 2; i++) {
        if (a[pl - i] != a[pr + i]) {
            break;
        }
        ans.push_back(a[pl - i]);
    }
    sort(ans.begin(), ans.end());
    for (int i = 1; i < ans.size(); i++) {
        if (ans[i] != ans[i - 1] + 1) {
            cout << max(mx, ans[i - 1] + 1) << endl;
            return;
        }
    }
    cout << max(mx, (int)ans.size()) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}