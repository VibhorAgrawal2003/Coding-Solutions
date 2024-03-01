#include <iostream>

using namespace std;

void rectanglePattern(int &n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << "* ";
    }
    cout << "\n";
  }
}

void downLeftTrianglePattern(int &n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << "* ";
    }
    cout << "\n";
  }
}

void downLeftNumberPattern(int &n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << j << " ";
    }
    cout << "\n";
  }
}

void downLeftNumberPattern2(int &n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << i << " ";
    }
    cout << "\n";
  }
}

void upLeftTrianglePattern(int &n) {
  for (int i = 0; i < n; i++) {
    for (int j = n; j > i; j--) {
      cout << "* ";
    }
    cout << "\n";
  }
}

void upLeftNumberPattern(int &n) {
  for (int i = 0; i < n; i++) {
    for (int j = n; j > i; j--) {
      cout << (n + 1 - j) << " ";
    }
    cout << "\n";
  }
}

void upwardPyramidPattern(int &n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n - i; j++) {
      cout << "  ";
    }
    for (int j = 0; j < 2 * i - 1; j++) {
      cout << "* ";
    }
    cout << "\n";
  }
}

void downwardPyramidPattern(int &n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      cout << "  ";
    }
    for (int j = 0; j < 2 * (n - i) + 1; j++) {
      cout << "* ";
    }
    cout << "\n";
  }
}

void diamondPattern(int &n) {}

int main() {

  int n{};
  cout << "Enter size of pattern (n): ";
  cin >> n;

  cout << "Rectangle pattern\n\n";
  rectanglePattern(n);
  cout << "\n";

  cout << "Down left triangle pattern\n\n";
  downLeftTrianglePattern(n);
  cout << "\n";

  cout << "Down left number pattern\n\n";
  downLeftNumberPattern(n);
  cout << "\n";

  cout << "Down left number pattern 2\n\n";
  downLeftNumberPattern2(n);
  cout << "\n";

  cout << "Up left triangle pattern\n\n";
  upLeftTrianglePattern(n);
  cout << "\n";

  cout << "Up left number pattern\n\n";
  upLeftNumberPattern(n);
  cout << "\n";

  cout << "Upward pyramid pattern\n\n";
  upwardPyramidPattern(n);
  cout << "\n";

  cout << "Downward pyramid pattern\n\n";
  downwardPyramidPattern(n);
  cout << "\n";

  cout << "Diamond pattern\n\n";
  diamondPattern(n);
  cout << "\n";

  return 0;
}