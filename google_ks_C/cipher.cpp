#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  for (int t = 1; t <= n; t++) {
    string s;
    cin >> s;
    cout << "Case #" << t << ": ";
    if (s.size() != 1 && s.size() & 1) {
      cout << "AMBIGUOUS\n";
      continue;
    }
    int m = s.size();
    if (m == 1) {
      cout << s << endl;
    } else if (s.size() == 2) {
      cout << s[1] << s[0] << endl;
    } else {
      // a is the decrypted string (in form of number)
      int a[m] = {0};

      a[1] = s[0] - 'A';
      a[m - 2] = s[m - 1] - 'A';

      // iterative solutions
      //1 + 2 = 3
      for (int i = 3; i < m; i += 2) {
        a[i] = (s[i - 1] - 'A' - a[i - 2] + 26) % 26;
      }

      for (int i = m - 4; i >= 0; i -= 2) {
        a[i] = (s[i + 1] - 'A' - a[i + 2] + 26) % 26;
      }

      // output each letter
      for (int i = 0; i < m; i++) {
        cout << (char)(a[i] + 'A');
      }
      cout << endl;
    }
  }
}

//________________________________

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(0);
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
  solve();
}
