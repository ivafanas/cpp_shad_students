#include "matrixlib/matrix.h"

int main(int, char **) {
  if (Matrix<int, 3, 4>::num_rows() != 3)
    return 1;
  if (Matrix<float, 5, 6>::num_rows() != 5)
    return 1;
  return 0;
}
