#include <iostream>

using namespace std;

struct Result {
  int day;
  bool success;
};

Result simulate(float h, float u, float d, float fat) {
  float position = 0, climb = 0;
  int day = 0;
  Result r;
  while(position >= 0) {
    day += 1;
    if(climb >= 0) {
      climb = u-fat*(day-1);
      if(climb > 0) position += climb;
      if(position > h) break;
    } 
    position -= d;
  }
  r.day = day;
  r.success = position > 0;
  return r;
}

int main() {
  int h, u, d, f;
  Result r;
  while(true) {
    cin >> h >> u >> d >> f;
    if(h == 0) break;
    r = simulate((float)h, (float)u, (float)d, f*u/100.0);
    if(r.success) {
      cout << "success on day " << r.day << endl;
    } else {
      cout << "failure on day " << r.day << endl;
    }
  }
  return 0;
}