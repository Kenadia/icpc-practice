#include <iostream>
#include <vector>
using namespace std;

struct Pt {
  int r;
  int c;
};

vector<Pt> get_neighbors(int i, int j, int n, int m) {
  vector<Pt> v;
  for (int r = i - 1; r <= i + 1; r++) {
    for (int c = j - 1; c <= j + 1; c++) {
      if (r != i || c != j) {
        if (r >= 0 && r < n && c >= 0 && c < m) {
          Pt p = {r, c};
          v.push_back(p);
        }
      }
    }
  }
  return v;
}

char **grid;

bool is_empty(const Pt p) {
  return grid[p.r][p.c] == '.';
}


int main() {
  int case_num = 1;
  int n, m;
  string line;
  cin >> n >> m;
  while (n & m) {
    // Read the input
    grid = new char*[n];
    for (int i = 0; i < n; i++) {
      grid[i] = new char[m];
      cin >> line;
      for (int j = 0; j < m; j++) {
        grid[i][j] = line[j];
      }
    }
    // Print the output
    printf("Field #%i:\n", case_num);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '*') {
          cout << '*';
        } else {
          vector<Pt> neighbors = get_neighbors(i, j, n, m);
          neighbors.erase(
            remove_if(neighbors.begin(), neighbors.end(), is_empty),
            neighbors.end()
          );
          cout << (int)(neighbors.size());
        }
      }
      cout << endl;
    }
    // Get next case
    cin >> n >> m;
    case_num++;
    if (n & m) cout << endl;
  }
  return 0;
}
