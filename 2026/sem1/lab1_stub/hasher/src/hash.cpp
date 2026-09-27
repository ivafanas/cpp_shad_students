#include "hash.h"
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
static bool table_create_init = false;
static uint32_t g_crc_table[256];
void crc32_init_table() {
  for (size_t i = 0; i < 256; i++) {
    uint32_t c = i;
    for (int j = 0; j < 8; ++j) {
      c = (c & 1) ? (c >> 1) ^ 0xEDB88320u : c >> 1;
    }
    g_crc_table[i] = c;
  }
}
uint32_t crc32_update(uint32_t crc, const unsigned char *data, size_t len) {
  if (!table_create_init) {
    crc32_init_table();
    table_create_init = true;
  }
  for (size_t i = 0; i < len; i++) {
    crc = g_crc_table[(crc ^ data[i]) & 0xFFu] ^ (crc >> 8);
  }
  return crc;
}
uint32_t compute_crc32(const std::string &filename) {
  std::ifstream ifs(filename, std::ios::binary);
  if (!ifs) {
    std::cerr << "ERROR: cannot open file: " << filename << ";\n";
    print(std::cerr);
    return 1;
  }
  uint32_t crc = 0xFFFFFFFFu;
  const size_t BUFSIZE = 4096;
  std::vector<unsigned char> buffer(BUFSIZE);
  while (true) {
    ifs.read(reinterpret_cast<char *>(buffer.data()), buffer.size());
    std::streamsize n = ifs.gcount();
    if (n <= 0)
      break;
    crc = crc32_update(crc, buffer.data(), static_cast<size_t>(n));
  }
  if (ifs.bad()) {
    std::cerr << "ERROR: read error in file: " << filename << ";\n";
    print(std::cerr);
    return 1;
  }
  crc = crc ^ 0xFFFFFFFFu;
  return crc;
}
uint32_t sum32_update(const unsigned char *buf, size_t len, uint32_t sum) {
  size_t i{};
  for (; i + 4 <= len; i += 4) {
    uint32_t n1 = static_cast<uint32_t>(buf[i]) << 24;
    uint32_t n2 = static_cast<uint32_t>(buf[i + 1]) << 16;
    uint32_t n3 = static_cast<uint32_t>(buf[i + 2]) << 8;
    uint32_t n4 = static_cast<uint32_t>(buf[i + 3]);
    uint32_t n = n1 | n2 | n3 | n4;
    sum += n;
  }
  if (i < len) {
    int shift = 24;
    uint32_t s{};
    for (; i < len; i++) {
      uint32_t k = static_cast<uint32_t>(buf[i]) << shift;
      shift -= 8;
      s += k;
    }
    sum += s;
  }
  return sum;
}
uint32_t compute_sum32(const std::string &filename) {
  std::ifstream ifs(filename, std::ios::binary);
  if (!ifs) {
    std::cerr << "ERROR: cannot open file '" << filename << "'\n";
    print(std::cerr);
    return 1;
  }
  uint32_t sum{};
  const size_t BUFSIZE = 4096;
  std::vector<unsigned char> buffer(BUFSIZE);
  while (true) {
    ifs.read(reinterpret_cast<char *>(buffer.data()), buffer.size());
    std::streamsize n = ifs.gcount();
    if (n <= 0)
      break;
    sum = sum32_update(buffer.data(), n, sum);
  }
  if (ifs.bad()) {
    std::cerr << "ERROR: read error in file '" << filename << "'\n";
    print(std::cerr);
    return 1;
  }
  return sum;
}
void print(std::ostream &os) {
  std::cout << "This is a brief guide on how to use hashing:\n";
  std::cout << "The following options are available to you:\n";
  std::cout << "Brief guide: -h, --help\n";
  std::cout << "Choice of hashing mode: -m\n";
  std::cout << "Available of hashing modes: crc32 or sum32\n";
}