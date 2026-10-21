#include "matrixlib/matrix.h"

int main(int, char **) {
  Matrix<int, 2, 2> m1;
  Matrix<int, 3, 3> m2;
  auto m3 = m1 * m2;
  return 0;
}
