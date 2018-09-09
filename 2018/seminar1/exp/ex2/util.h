#pragma once

#include <iosfwd>


unsigned read_n(std::istream& is);

void write_result(double res, std::ostream& os);

double calc_exp(unsigned n);

