#include "matrixlib/matrix.h"

static bool check() {
  Matrix<int, 2, 2> m = Matrix<int, 2, 2>::zero();
  m.at(0, 0) = 3;
  m.at(1, 1) = 3;
  m.at(0, 1) = 2;
  m.at(1, 0) = 4;
  const int d = det(m);
  if (d != 1)
    return false;

  Matrix<int, 2, 2> inv(0);
  inv.at(0, 0) = 3;
  inv.at(1, 1) = 3;
  inv.at(0, 1) = -2;
  inv.at(1, 0) = -4;

  Matrix<int, 2, 2> mul = m * inv;
  return mul == Matrix<int, 2, 2>::identity();
}

int main(int, char **) {
  if (!check())
    return 1;
  return 0;
}
