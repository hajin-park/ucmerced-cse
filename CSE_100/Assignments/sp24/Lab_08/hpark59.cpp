#include <iostream>

using namespace std;


int MemoizedCutRodAux(int* p, int n, int* r) {
  if (r[n] >= 0) {
    return r[n];
  }
  int q;
  if (n == 0) {
    q = 0;
  } else {
    q = -1;
    for (int i = 1; i <= n; i++) {
      q = max(q, p[i] + MemoizedCutRodAux(p, n - i, r));
    }
  }
  r[n] = q;
  return q;
}

int MemoizedCutRod(int* p, int n) {
  int* r = new int[n + 1];
  for (int i = 0; i <= n; i++) {
    r[i] = -1;
  }
  return MemoizedCutRodAux(p, n, r);
}

int ExtendedBottomUpCutRod(int* p, int n) {
  int* r = new int[n + 1];
  int* s = new int[n + 1];
  r[0] = 0;
  for (int j = 1; j <= n; j++) {
    int q = -1;
    for (int i = 1; i <= j; i++) {
      if (q < p[i] + r[j - i]) {
        q = p[i] + r[j - i];
        s[j] = i;
      }
    }
    r[j] = q;
  }
  int result = r[n];
  delete[] r;
  delete[] s;
  return result;
}

void PrintCutRodSolution(int* p, int n) {
  int* r = new int[n + 1];
  int* s = new int[n + 1];
  r[0] = 0;
  
  for (int j = 1; j <= n; j++) {
    int q = -1;
    for (int i = 1; i <= j; i++) {
      if (q < p[i] + r[j - i]) {
        q = p[i] + r[j - i];
        s[j] = i;
      }
    }
    r[j] = q;
  }

  while (n > 0) {
    cout << s[n] << " ";
    n = n - s[n];
  }
  cout << "-1" << endl;

  delete[] r;
  delete[] s;
}

int main(int argc, char** argv) {
    int n;
    cin >> n;
    int* p = new int[n + 1];
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
    }

    cout << MemoizedCutRod(p, n) << endl;
    PrintCutRodSolution(p, n);

    return 1;
}