#include "matrixlib/matrix.h"

int main(int, char **) {
  if (Matrix<int, 3, 4>::num_cols() != 4)
    return 1;
  if (Matrix<float, 5, 6>::num_cols() != 6)
    return 1;
  return 0;
}
