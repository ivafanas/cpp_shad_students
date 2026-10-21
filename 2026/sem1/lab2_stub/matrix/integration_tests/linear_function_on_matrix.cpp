#include "matrixlib/matrix.h"

static bool check() {
  // 1 3
  // 4 2
  Matrix<int, 2, 2> m1 = Matrix<int, 2, 2>::zero();
  m1.at(0, 0) = 1;
  m1.at(1, 1) = 2;
  m1.at(0, 1) = 3;
  m1.at(1, 0) = 4;

  // 2 6
  // 8 4
  m1 *= 2;

  // 2
  // -1
  Matrix<int, 2, 1> m2;
  m2.at(0, 0) = 2;
  m2.at(1, 0) = -1;

  // -2
  // 12
  Matrix<int, 2, 1> m3 = m1 * m2;

  // 4
  // 18
  m3 += Matrix<int, 2, 1>(6);

  const Matrix<int, 2, 1> expected = [](){
    Matrix<int, 2, 1> rv(4);
    rv.at(1, 0) = 18;
    return rv;
  }();

  return m3 == expected;
}

int main(int, char **) {
  if (!check())
    return 1;
  return 0;
}
