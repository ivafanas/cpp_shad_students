#include "hash.h"
#include "gtest/gtest.h"

// CRC32TEST
// 1 test
TEST(Crc32Test, EmptyInput) {
  const unsigned char *data = nullptr;
  uint32_t crc = crc32_update(0xFFFFFFFFu, data, 0);
  EXPECT_EQ(crc ^ 0xFFFFFFFFu, 0x00000000u);
}
// 2 test
TEST(Crc32Test, Equality) {
  const unsigned char data1[] = {'N', 'I', 'K'};
  const unsigned char data2[] = {'N', 'I', 'K'};
  uint32_t crc1 = crc32_update(0xFFFFFFFFu, data1, 3);
  uint32_t crc2 = crc32_update(0xFFFFFFFFu, data2, 3);
  EXPECT_EQ(crc1, crc2);
}
// 3 test
TEST(Crc32Test, OneByte) {
  const unsigned char data[] = {'A'};
  uint32_t crc = crc32_update(0xFFFFFFFFu, data, 1);
  EXPECT_EQ(crc ^ 0xFFFFFFFFu, 0xD3D99E8B);
}
// 4 test
TEST(Crc32Test, TwoByte) {
  const unsigned char data[] = {'A', 'B'};
  uint32_t crc = crc32_update(0xFFFFFFFFu, data, 2);
  EXPECT_EQ(crc ^ 0xFFFFFFFFu, 0x30694C07);
}
// 5 test
TEST(Crc32Test, TreeByte) {
  const unsigned char data[] = {'A', 'B', 'C'};
  uint32_t crc = crc32_update(0xFFFFFFFFu, data, 3);
  EXPECT_EQ(crc ^ 0xFFFFFFFFu, 0xA3830348);
}
// 6 test
TEST(Crc32Test, FourByte) {
  const unsigned char data[] = {'A', 'B', 'C', 'D'};
  uint32_t crc = crc32_update(0xFFFFFFFFu, data, 4);
  EXPECT_EQ(crc ^ 0xFFFFFFFFu, 0xDB1720A5);
}
// 7 test
TEST(Crc32Test, FiveByte) {
  const unsigned char data[] = {'A', 'B', 'C', 'D', 'E'};
  uint32_t crc = crc32_update(0xFFFFFFFFu, data, 5);
  EXPECT_EQ(crc ^ 0xFFFFFFFFu, 0x72D31AD5);
}
// 8 test
TEST(Crc32Test, SixByte) {
  const unsigned char data[] = {'A', 'B', 'C', 'D', 'E', 'F'};
  uint32_t crc = crc32_update(0xFFFFFFFFu, data, 6);
  EXPECT_EQ(crc ^ 0xFFFFFFFFu, 0xBB76FE69);
}
// 9 test
TEST(Crc32Test, ManyByte) {
  const unsigned char data[] = {'A', 'B', 'C', 'D', 'E', 'F', 'A', 'B',
                                'C', 'D', 'E', 'F', 'A', 'B', 'C', 'D',
                                'E', 'F', 'A', 'B', 'C', 'D', 'E', 'F',
                                'A', 'B', 'C', 'D', 'E', 'F'};
  uint32_t crc = crc32_update(0xFFFFFFFFu, data, 30);
  EXPECT_EQ(crc ^ 0xFFFFFFFFu, 0xA9355C8A);
}
// 10 test
TEST(Crc32Test, NumberByte) {
  const unsigned char data[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  uint32_t crc = crc32_update(0xFFFFFFFFu, data, 9);
  EXPECT_EQ(crc ^ 0xFFFFFFFFu, 0xCBF43926);
}
// 11 test
TEST(Crc32Test, Register) {
  const unsigned char data1[] = {'A', 'B', 'C'};
  uint32_t crc1 = crc32_update(0xFFFFFFFFu, data1, 3);
  const unsigned char data2[] = {'a', 'b', 'c'};
  uint32_t crc2 = crc32_update(0xFFFFFFFFu, data2, 3);
  EXPECT_NE(crc1, crc2);
}
// 12 test
TEST(Crc32Test, Inverse1) {
  const unsigned char data1[] = {'A', 'B', 'C'};
  uint32_t crc1 = crc32_update(0xFFFFFFFFu, data1, 3);
  const unsigned char data2[] = {'C', 'B', 'A'};
  uint32_t crc2 = crc32_update(0xFFFFFFFFu, data2, 3);
  EXPECT_NE(crc1, crc2);
}
// 13 test
TEST(Crc32Test, Hello) {
  const unsigned char data[] = {'H', 'e', 'l', 'l', 'o'};
  uint32_t crc = crc32_update(0xFFFFFFFFu, data, 5);
  EXPECT_EQ(crc ^ 0xFFFFFFFFu, 0xF7D18982);
}
// 14 тест
TEST(Crc32Test, DifferentInitialCrc) {
  const unsigned char data[] = {'A'};
  uint32_t crc = crc32_update(0x00000000u, data, 1);
  EXPECT_NE(crc ^ 0xFFFFFFFFu, 0xD3D99E8Bu);
}
// 15 тест
TEST(Crc32Test, Same_calls) {
  const unsigned char data1[] = {'A'};
  const unsigned char data2[] = {'B'};
  const unsigned char data3[] = {'C'};
  const unsigned char data4[] = {'A', 'B', 'C'};
  uint32_t crc1 = 0xFFFFFFFFu;
  crc1 = crc32_update(crc1, data1, 1);
  crc1 = crc32_update(crc1, data2, 1);
  crc1 = crc32_update(crc1, data3, 1);
  uint32_t crc2 = crc32_update(0xFFFFFFFFu, data4, 3);
  EXPECT_EQ(crc1, crc2);
}

// SUM32TEST
// 16 тест
TEST(Sum32Test, Empty) {
  const unsigned char *data = nullptr;
  uint32_t sum = sum32_update(data, 0, 0);
  EXPECT_EQ(sum, 0x00000000);
}
// 17 тест
TEST(Sum32Test, OneByte) {
  const unsigned char data[] = {'A'};
  uint32_t sum = sum32_update(data, 1, 0);
  EXPECT_EQ(sum, 0x41000000);
}
// 18 тест
TEST(Sum32Test, TwoByte) {
  const unsigned char data[] = {'A', 'B'};
  uint32_t sum = sum32_update(data, 2, 0);
  EXPECT_EQ(sum, 0x41420000);
}
// 19 тест
TEST(Sum32Test, TreeByte) {
  const unsigned char data[] = {'A', 'B', 'C'};
  uint32_t sum = sum32_update(data, 3, 0);
  EXPECT_EQ(sum, 0x41424300);
}
// 20 тест
TEST(Sum32Test, FourByte) {
  const unsigned char data[] = {'A', 'B', 'C', 'D'};
  uint32_t sum = sum32_update(data, 4, 0);
  EXPECT_EQ(sum, 0x41424344);
}
// 21 тест
TEST(Sum32Test, Byte_8) {
  const unsigned char data[] = {'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D'};
  uint32_t sum = sum32_update(data, 8, 0);
  EXPECT_EQ(sum, 0x82848688);
}
// 22 тест
TEST(Sum32Test, Byte_12) {
  const unsigned char data[] = {'A', 'B', 'C', 'D', 'A', 'B',
                                'C', 'D', 'A', 'B', 'C', 'D'};
  uint32_t sum = sum32_update(data, 12, 0);
  EXPECT_EQ(sum, 0xC3C6C9CC);
}
// 23 тест
TEST(Sum32Test, Hello) {
  const unsigned char data[] = {'H', 'e', 'l', 'l', 'o'};
  uint32_t sum = sum32_update(data, 5, 0);
  EXPECT_EQ(sum, 0xB7656C6C);
}
// 24 тест
TEST(Sum32Test, Number) {
  const unsigned char data[] = {'1', '2', '3', '4', '5',
                                '6', '7', '8', '9', '0'};
  uint32_t sum = sum32_update(data, 10, 0);
  EXPECT_EQ(sum, 0x9F986A6C);
}
// 25 тест
TEST(Sum32Test, ManyByte) {
  const unsigned char data[] = {
      'A', 'B', 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C', 'D', 'E',
      'F', 'G', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C',
      'D', 'E', 'F', 'G', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
  };
  uint32_t sum = sum32_update(data, 35, 0);
  EXPECT_EQ(sum, 0x64666820);
}
// 26 тест
TEST(Sum32Test, Register) {
  const unsigned char data1[] = {'A', 'B', 'C'};
  const unsigned char data2[] = {'a', 'b', 'c'};
  uint32_t sum1 = sum32_update(data1, 3, 0);
  uint32_t sum2 = sum32_update(data2, 3, 0);
  EXPECT_NE(sum1, sum2);
}
// 27 тест
TEST(Sum32Test, Inverse) {
  const unsigned char data1[] = {'A', 'B', 'C'};
  const unsigned char data2[] = {'C', 'B', 'A'};
  uint32_t sum1 = sum32_update(data1, 3, 0);
  uint32_t sum2 = sum32_update(data2, 3, 0);
  EXPECT_NE(sum1, sum2);
}
// 28 тест
TEST(Sum32Test, Same_data) {
  const unsigned char data1[] = {'N', 'I', 'K'};
  uint32_t sum1 = sum32_update(data1, 3, 0);
  const unsigned char data2[] = {'N', 'I', 'K'};
  uint32_t sum2 = sum32_update(data2, 3, 0);
  EXPECT_EQ(sum1, sum2);
}
