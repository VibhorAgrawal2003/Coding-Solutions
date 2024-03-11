#include <iostream>
#include <string>
#include <vector>

using namespace std;

void computePiTable(const string &pattern, vector<int> &pi) {
  int m = pattern.length();
  pi.resize(m);
  pi[0] = 0;
  int k = 0;
  for (int q = 1; q < m; ++q) {
    while (k > 0 && pattern[k] != pattern[q]) {
      k = pi[k - 1];
    }
    if (pattern[k] == pattern[q]) {
      k++;
    }
    pi[q] = k;
  }
}

int KMPSearch(const string &text, const string &pattern) {
  vector<int> pi;
  computePiTable(pattern, pi);
  int n = text.length();
  int m = pattern.length();
  int s = 0; // shift value
  int q = 0;
  for (int i = 0; i < n; ++i) {
    while (q > 0 && pattern[q] != text[i]) {
      q = pi[q - 1];
    }
    if (pattern[q] == text[i]) {
      q++;
    }
    if (q == m) {
      // Pattern found at index i - m + 1
      cout << "Pattern found at index " << i - m + 1 << endl;
      s = i - m + 1;
      // Reset q to continue searching for the next occurrence
      q = pi[q - 1];
    }
  }
  return s;
}

void printPiTable(const string &pattern, const vector<int> &pi) {
  cout << "Pi Table" << endl;
  cout << "q ";
  for (int i = 0; i < pattern.length(); ++i) {
    cout << i + 1 << " ";
  }
  cout << endl << "p ";
  for (char c : pattern) {
    cout << c << " ";
  }
  cout << endl << "pi";
  for (int val : pi) {
    cout << " " << val;
  }
  cout << endl;
}

int main() {
  string text = "bacbabababacaca";
  string pattern = "ababaca";

  vector<int> pi;
  int s = KMPSearch(text, pattern);
  computePiTable(pattern, pi);
  printPiTable(pattern, pi);
  cout << "Given pattern \"" << pattern << "\" is found in T with s = " << s
       << "." << endl;

  cout << "\n";

  string text2 = "abcdabcabcdf";
  string pattern2 = "abcab";

  vector<int> pi2;
  int s2 = KMPSearch(text2, pattern2);
  computePiTable(pattern2, pi2);
  printPiTable(pattern2, pi2);
  cout << "Given pattern \"" << pattern2 << "\" is found in T with s = " << s2
       << "." << endl;

  return 0;
}
