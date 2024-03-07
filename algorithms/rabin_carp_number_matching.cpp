#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define d 10
#define ll long long int

ll get_length(ll number) {
  int len{};
  while (number > 0) {
    number /= 10;
    len++;
  }
  return len;
}

vector<int> vectorize(ll number) {
  vector<int> res{};
  while (number > 0) {
    res.insert(res.begin(), number % 10);
    number /= 10;
  }
  return res;
}

void rabin_carp_search(ll text, ll pattern, int q) {

  int n = get_length(text);
  int m = get_length(pattern);
  int p = 0;
  int t = 0;
  int h = 1;
  int i{}, j{};

  vector<int> valid{};
  vector<int> spurious{};

  // Vectorize long integers
  vector<int> textV = vectorize(text);
  vector<int> patV = vectorize(pattern);

  // Perform hashing
  for (i = 0; i < m - 1; i++) {
    h = (h * d) % q;
  }

  for (i = 0; i < m; i++) {
    t = (d * t + textV[i]) % q;
    p = (d * p + patV[i]) % q;
  }

  // Pattern matching
  for (i = 0; i <= n - m; i++) {

    if (p == t) {
      for (j = 0; j < m; j++) {
        if (textV[i + j] != patV[j]) {
          break;
        }
      }

      if (j == m) {
        valid.push_back(i + 1);
      } else {
        spurious.push_back(i + 1);
      }
    }

    if (i < n - m) {
      t = (d * (t - textV[i] * h) + textV[i + m]) % q;
      if (t < 0) {
        t += q;
      }
    }
  }

  // Display results
  cout << "Valid hit(s) - index: ";
  for (auto x : valid) {
    cout << x << " ";
  }
  cout << "\n";

  cout << "Spurious hit(s) - index: ";
  for (auto x : spurious) {
    cout << x << " ";
  }
  cout << "\n";
}

int main() {

  vector<tuple<ll, ll, int>> testcases{};
  testcases.push_back((tuple<ll, ll, int>){2359023141526739921, 31415, 13});
  testcases.push_back((tuple<ll, ll, int>){3141592653589793, 26, 11});

  for (int i = 0; i < (int)testcases.size(); i++) {
    cout << "\n~ ~ ~ Testcase " << i + 1 << " ~ ~ ~ \n";
    tuple<ll, ll, int> x = testcases[i];
    rabin_carp_search(get<0>(x), get<1>(x), get<2>(x));
    cout << "\n";
  }

  return 0;
}