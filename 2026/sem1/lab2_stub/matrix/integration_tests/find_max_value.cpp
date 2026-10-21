#include "matrixlib/matrix.h"

#include <algorithm>

template <typename T> bool check() {
  Matrix<T, 3, 3> m = Matrix<T, 3, 3>::diagonal(static_cast<T>(100));
  m.at(0, 1) = static_cast<T>(50);
  m.at(1, 0) = static_cast<T>(-128);
  m.at(0, 2) = static_cast<T>(150);
  m.at(2, 1) = static_cast<T>(-200);
  return *std::max_element(m.crbegin(), m.crend()) == static_cast<T>(150);
}

int main(int, char **) {
  if (!check<int>())
    return 1;
  if (!check<float>())
    return 1;
  if (!check<double>())
    return 1;
  return 0;
}
