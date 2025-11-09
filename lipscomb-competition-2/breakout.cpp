#include <bits/stdc++.h>
#include <algorithm>

#define lint long long int

using namespace std;

class FenwickTree {
    public:
        vector<lint> tree;

        FenwickTree(int m) {
            tree.assign(m + 1, 0);
        }

        lint query(int j) {
            lint sum = 0;
            
            for (; j != 0; j -= (j & -j))
                sum += tree[j];

            return sum;
            
        }

        long query(int i, int j) {
            return query(j) - query(i - 1);
        }

        void update(int i, lint v) {
            if (i == 0) return;

            for(; i < (int) tree.size(); i += (i & -i)) {
                tree[i] += v;
            }
        }
};

class ReverseFenwickTree {
public:
    FenwickTree fen;

    ReverseFenwickTree(int m) : fen(FenwickTree(m + 1)) {}

    lint query(int i) {
        return fen.query(i);
    }

    void update(int i, int j, lint v) {
        fen.update(i, v);
        fen.update(j + 1, -v);
    }

    void update(int i, lint v) {
        update(i, i, v);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int b, w, h;
    cin >> b >> w >> h;

    // ReverseFenwickTree fen(w);
    // fen.update(0, 3, 10);
    vector<int> wall;
    wall.assign(w, h);

    // for (int i = 0; i < w; i++) {
    //     cout << fen.query(i) << "\n";
    // }

    for (int i = 0; i < b; i++) {
        int t, p, d;
        cin >> t >> p >> d;

        int bounces = 0;

        while (t < w && t >= 0) {
            // if (fen.query(t) <= 0) break;
            if (wall[t] <= 0) break;

            // fen.update(max(0ll, t - p), min(w, t + p), -1);
            int start = max(0, t - p);
            int end = min(w - 1, t + p);

            for (int i = start; i <= end; i++) {
                wall[i]--;
            }

            bounces += 1;
            t += d;

            if (d == 0) break;
        }

        cout << bounces << "\n";
    }

    return 0;
}