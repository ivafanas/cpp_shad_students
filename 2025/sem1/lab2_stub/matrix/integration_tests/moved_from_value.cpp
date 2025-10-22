#include "matrixlib/matrix.h"

#include <utility>

int main(int, char **) {
  auto m1 = Matrix<int, 10, 10>::diagonal(35);
  auto m2 = std::move(m1);
  m1.at(5, 5) = 42;
  m2.at(5, 5) = 7;
  if (m1.at(5, 5) != 42)
    return 1;
  return 0;
}
