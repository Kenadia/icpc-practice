#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool f(const int x) {               // def f(x):
  return x == 0;                    //     return x != 0
}

int main() {
  vector<int> v;                    // v = []
  int x = 0;                        // x = 0
  v.push_back(x);                   // v.append(x)
  cout << (int)(v.size()) << endl;  // print len(v)
  v.erase(                          // v = filter(f, v)
    remove_if(v.begin(), v.end(), f),
    v.end()
  );
  cout << (int)(v.size()) << endl;  // print len(v)
  return 0;
}
