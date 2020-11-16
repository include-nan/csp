#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 * 使用multimap的方法
 */
/**
int main() {
    int n, X, Y;
    cin >> n >> X >> Y;
    multimap<int, int> ans;
    multimap<int, int>::iterator imap;
    for (int i = 0; i < n; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        int tmp;
        tmp = (tmp1 - X) * (tmp1 - X) +
              (tmp2 - Y) * (tmp2 - Y);
        ans.insert(pair<int, int>(tmp, i));
    }

    imap = ans.begin();
    for (int i = 0; i < 3; i++, imap++) {
        cout << (*imap).second + 1 << endl;
    }

    return 0;
}
*/

/**
 * 使用数组遍历的方法
 */

struct Node {
    int length;
    int order;
};

int main() {
    int n, X, Y;
    cin >> n >> X >> Y;
    Node node[n];
    int tmp1, tmp2;
    for (int i = 0; i < n; i++) {
        cin >> tmp1 >> tmp2;
        int tmp;
        tmp = (tmp1 - X) * (tmp1 - X) + (tmp2 - Y) * (tmp2 - Y);
        node[i].length = tmp;
        node[i].order = i + 1;
    }

    Node change;

    for (int j = 0; j < 3; j++) {
        for (int k = j + 1; k < n; k++) {
            if (node[j].length > node[k].length) {
                change.length = node[j].length;
                change.order = node[j].order;
                node[j].length = node[k].length;
                node[j].order = node[k].order;
                node[k].length = change.length;
                node[k].order = change.order;
            } else if (node[j].length == node[k].length &&
                       node[j].order > node[k].order) {
                change.length = node[j].length;
                change.order = node[j].order;
                node[j].length = node[k].length;
                node[j].order = node[k].order;
                node[k].length = change.length;
                node[k].order = change.order;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << node[i].order << endl;
    }
    return 0;
}
