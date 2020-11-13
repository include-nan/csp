#include <iostream>
using namespace std;
struct Svector {
    int x1;
    int x2;
};

int main() {
    long long n;
    int a, b;
    cin >> n >> a >> b;
    Svector s1[a];
    Svector s2[b];

    for (long long i = 0; i < a; i++) {
        cin >> s1[i].x1 >> s1[i].x2;
    }
    for (long long i = 0; i < b; i++) {
        cin >> s2[i].x1 >> s2[i].x2;
    }

    long long ans = 0;
    for (long long i = 0, j = 0; i < a && j < b;) {
        if (s1[i].x1 == s2[j].x1) {
            ans += s1[i].x2 * s2[j].x2;
            i++;
            j++;
        } else if (s1[i].x1 > s2[j].x1) {
            j++;
        } else {
            i++;
        }
    }

    cout << ans << endl;
    return 0;
}
