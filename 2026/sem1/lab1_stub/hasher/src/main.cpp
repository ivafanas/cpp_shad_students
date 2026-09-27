#include "hash.h"
#include <iomanip>
#include <iostream>
#include <string>
int main(int argc, char **argv) {
  if (argc == 1) {
    std::cerr << "ERROR: missing arguments" << "\n";
    print(std::cerr);
    return 1;
  }
  std::string filename;
  std::string mode;
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "-h" || arg == "--help") {
      print(std::cout);
      return 0;
    }
    if (arg == "-m") {
      if (i + 1 >= argc) {
        std::cerr << "ERROR: option '-m' requires a value" << "\n";
        print(std::cerr);
        return 1;
      }
      mode = argv[i + 1];
      i++;
      continue;
    }
    filename = arg;
  }
  if (mode.empty()) {
    std::cerr << "ERROR: missing mode" << "\n";
    print(std::cerr);
    return 1;
  }
  if (filename.empty()) {
    std::cerr << "ERROR: missing filename" << "\n";
    print(std::cerr);
    return 1;
  }
  uint32_t result = 0;
  if (mode == "crc32") {
    result = compute_crc32(filename);
  } else {
    if (mode == "sum32") {
      result = compute_sum32(filename);
    } else {
      std::cerr << "ERROR: unknown mode '" << mode
                << "'. Expected: crc32, sum32" << "\n";
      print(std::cerr);
      return 1;
    }
  }
  std::cout << std::hex << std::setw(8) << std::setfill('0') << result << "\n";
  return 0;
}
