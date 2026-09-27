#pragma once
#include <cstddef>
#include <cstdint>
#include <string>
void crc32_init_table();
uint32_t crc32_update(uint32_t crc, const unsigned char *data, size_t len);
uint32_t compute_crc32(const std::string &filename);
uint32_t sum32_update(const unsigned char *buf, size_t len, uint32_t sum);
uint32_t compute_sum32(const std::string &filename);
void print(std::ostream &os);
