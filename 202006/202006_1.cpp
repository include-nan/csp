#include <iostream>
using namespace std;

struct Node {
    int x;
    int y;
    char type;
};

struct Line {
    int seite0;
    int seite1;
    int seite2;
};

int sum(int n, int m) {
    if (n < 0) {
        n = -n;
    }
    if (m < 0) {
        m = -m;
    }
    return n + m;
}

int main() {
    int n, m;
    cin >> n >> m;
    Node node[n];
    Line line[m];
    for (int i = 0; i < n; i++) {
        cin >> node[i].x >> node[i].y >> node[i].type;
    }

    for (int i = 0; i < m; i++) {
        cin >> line[i].seite0 >> line[i].seite1 >> line[i].seite2;
    }

    for (int i = 0; i < m; i++) {
        int tmp1 = 0;
        int tmp2 = 0;
        for (int j = 0; j < n; j++) {
            if (node[j].type == 'A') {
                if (line[i].seite0 + line[i].seite1 * node[j].x +
                        line[i].seite2 * node[j].y >
                    0) {
                    tmp1++;
                } else {
                    tmp1--;
                }
            }
            if (node[j].type == 'B') {
                if (line[i].seite0 + line[i].seite1 * node[j].x +
                        line[i].seite2 * node[j].y >
                    0) {
                    tmp2++;
                } else {
                    tmp2--;
                }
            }
        }
        if (sum(tmp1, tmp2) == n) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}