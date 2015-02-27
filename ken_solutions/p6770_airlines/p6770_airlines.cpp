#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void process(int n, int *froms);
void simulate(int n, int *froms);
void print_solution(int n, int *froms);

int main() {
  string line;
  while (!cin.eof()) {
    int n;
    cin >> n;
    printf("%d\n", n);
    int * froms = new int[n];
    process(n, froms);
    simulate(n, froms);
    // print_solution(n, froms);
    printf("\n");
  }
  return 0;
}

void process(int n, int * froms) {
  bool even = n & 1 == 0;
  int from = n + 2;
  for (int i = 0; i < n; i++) {
    froms[i] = from;
    from -= n - 1;
    if (from < 0) from += 2 * n + 2;
  }
}

void printline(int len, char *line) {
  for (int i = 0; i < len; i++) {
    cout << line[i];
  }
  cout << endl;
}

void simulate(int n, int *froms) {
  int linelen = n * 2 + 2;
  char *line = new char[linelen];
  line[0] = ' ';
  line[1] = ' ';
  for (int i = 2; i < linelen; i++) {
    line[i] = i & 1 ? 'A' : 'B';
  }
  printline(linelen, line);
  int to = -1;
  for (int i = 0; i < n; i++) {
    // printf("%d to %d\n", froms[i], to);
    int from = froms[i];
    line[to + 2] = line[from + 2];
    line[to + 1] = line[from + 1];
    line[from + 2] = ' ';
    line[from + 1] = ' ';
    printline(linelen, line);
    to = from;
  }
  delete [] line;
}

void print_solution(int n, int *froms) {
  int to = -1;
  for (int i = 0; i < n; i++) {
    printf("%d to %d\n", froms[i], to);
    to = froms[i];
  }
}
