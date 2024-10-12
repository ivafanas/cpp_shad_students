#include "matrixlib/matrix.h"

int main(int, char **) {
  Matrix<float, 3, 2> m;
  float d = det(m);
  return 0;
}
