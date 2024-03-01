#include <cmath>
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

void diamondPattern(int &n) {
  int m{1};
  for (int i = 0; i >= 0; i += m) {
    if (m == 1 && i >= n / 2) {
      m = -1;
      if (n % 2 == 0) {
        continue;
      }
    }
    for (int j = 1; j < (n - i); j++) {
      cout << "  ";
    }
    for (int j = 0; j < 2 * i + 1; j++) {
      cout << "* ";
    }
    cout << "\n";
  }
}

void leftTrianglePattern(int &n) {
  int m{1};
  for (int i = 0; i >= 0; i += m) {

    if (m == 1 && i >= n / 2) {
      m = -1;
      if (n % 2 == 0) {
        continue;
      }
    }

    for (int j = 0; j <= i; j++) {
      cout << "* ";
    }
    cout << "\n";
  }
}

void downLeftAlternativePattern(int &n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if ((i + j) % 2 == 0) {
        cout << "1 ";
      } else {
        cout << "0 ";
      }
    }
    cout << "\n";
  }
}

void numberValleyPattern(int &n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << j << " ";
    }

    for (int j = 0; j < 2 * (n - i); j++) {
      cout << "  ";
    }

    for (int j = i; j >= 1; j--) {
      cout << j << " ";
    }

    cout << "\n";
  }
}

void numberNaturalPattern(int &n) {
  int x = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= i + 1; j++) {
      cout << x++ << " ";
    }
    cout << "\n";
  }
}

void downLeftAlphaPattern(int &n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << (char)(j % 26 + 65) << " ";
    }
    cout << "\n";
  }
}

void upLeftAlphaPattern(int &n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      cout << (char)(j % 26 + 65) << " ";
    }
    cout << "\n";
  }
}

void downLeftAlphaPattern2(int &n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << (char)(i % 26 + 65) << " ";
    }
    cout << "\n";
  }
}

void upwardAlphaPyramidPattern(int &n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (n - i - 1); j++) {
      cout << "  ";
    }
    for (int j = 0; j <= i; j++) {
      cout << (char)(j % 26 + 65) << " ";
    }
    for (int j = i - 1; j >= 0; j--) {
      cout << (char)(j % 26 + 65) << " ";
    }
    cout << "\n";
  }
}

void downLeftAlphaPattern3(int &n) {
  for (int i = 0; i < n; i++) {
    for (int j = n - i - 1; j < n; j++) {
      cout << (char)(j % 26 + 65) << " ";
    }
    cout << "\n";
  }
}

void hollowDiamondPattern(int &n) {
  int m = 1;
  for (int i = 0; i >= 0; i += m) {
    if (m == 1 && i >= n / 2) {
      m = -1;
      if (n % 2 == 0) {
        continue;
      }
    }

    for (int j = 0; j <= (n / 2 - i); j++) {
      cout << "* ";
    }

    for (int j = 0; j < 2 * i; j++) {
      cout << "  ";
    }

    for (int j = 0; j <= (n / 2 - i); j++) {
      cout << "* ";
    }

    cout << "\n";
  }
}

void butterflyPattern(int &n) {}

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

  cout << "Left triangle pattern\n\n";
  leftTrianglePattern(n);
  cout << "\n";

  cout << "Down left alternative pattern\n\n";
  downLeftAlternativePattern(n);
  cout << "\n";

  cout << "Number valley pattern\n\n";
  numberValleyPattern(n);
  cout << "\n";

  cout << "Natural number pattern\n\n";
  numberNaturalPattern(n);
  cout << "\n";

  cout << "Down left alpha pattern\n\n";
  downLeftAlphaPattern(n);
  cout << "\n";

  cout << "Up left alpha pattern\n\n";
  upLeftAlphaPattern(n);
  cout << "\n";

  cout << "Down left alpha pattern 2\n\n";
  downLeftAlphaPattern2(n);
  cout << "\n";

  cout << "Upward alpha pyramid pattern\n\n";
  upwardAlphaPyramidPattern(n);
  cout << "\n";

  cout << "Down left alpha pattern 3\n\n";
  downLeftAlphaPattern3(n);
  cout << "\n";

  cout << "Hollow diamond pattern\n\n";
  hollowDiamondPattern(n);
  cout << "\n";

  cout << "Butterfly pattern\n\n";
  butterflyPattern(n);
  cout << "\n";

  return 0;
}