#include "matrixlib/matrix.h"

int main(int, char **) {
  if (Matrix<int, 3, 4>::num_values() != 12)
    return 1;
  if (Matrix<float, 5, 6>::num_values() != 30)
    return 1;
  return 0;
}
