#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  bool devices_on[21];
  int devices_con[21];
  int n, m, c, dnum, sum, max, seq = 0;
  bool blown;

  while(true) {
    cin >> n >> m >> c;

    if(seq != 0) cout << endl;
    if(n == 0) break;

    fill_n(devices_on, 21, false);
    blown = false;
    sum = 0;
    max = 0;
    seq++;

    for(int i = 1; i <= n; i++) {
      cin >> devices_con[i];
    }

    for(int i = 1; i <= m; i++) {
      cin >> dnum;
      devices_on[dnum] = !devices_on[dnum];
      if(devices_on[dnum]) {
        sum += devices_con[dnum];
        if(sum > max) {
          max = sum;
          if(sum > c) {
            blown = true;
          }
        }
      } else {
        sum -= devices_con[dnum];
      }
    }

    cout << "Sequence " << seq << endl;
    if(blown) {
      cout << "Fuse was blown." << endl;
    } else {
      cout << "Fuse was not blown." << endl;
      cout << "Maximal power consumption was " << max << " amperes." << endl;
    }
  }

  return 0;
}