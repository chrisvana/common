// Copyright 2014
// Author: Christopher Van Arsdale

#ifndef _COMMON_STRINGS_BITS_H__
#define _COMMON_STRINGS_BITS_H__

#include <string>
#include <vector>
#include "common/base/types.h"
#include "common/strings/stringpiece.h"

#include <iostream>

namespace strings {

inline void EncodeUInt32(uint32 value, std::string* output) {
  int current_size = output->size();
  output->resize(current_size + 4);
  (*output)[current_size + 0] = ((value >> 24) & 0xFF);
  (*output)[current_size + 1] = (value >> 16) & 0xFF;
  (*output)[current_size + 2] = (value >> 8) & 0xFF;
  (*output)[current_size + 3] = (value >> 0) & 0xFF;
}

inline uint32 DecodeUInt32(const char* input) {
  return ((static_cast<uint32>(static_cast<uint8>(input[0])) << 24) |
          (static_cast<uint32>(static_cast<uint8>(input[1])) << 16) |
          (static_cast<uint32>(static_cast<uint8>(input[2])) << 8) |
          (static_cast<uint32>(static_cast<uint8>(input[3])) << 0));
}

class BitEncoder {
 public:
  BitEncoder(std::string* output) : output_(output), pos_(0) {}
  ~BitEncoder() {}

  void EncodeBit(bool bit);
  void EncodeBits(const std::vector<bool>& bits);
  int byte_size() const { return (pos_ + 7) / 8; }
  int bit_size() const { return pos_; }

 private:
  std::string* output_;
  int pos_;
};

class BitDecoder {
 public:
  BitDecoder(const StringPiece& input) : input_(input), pos_(0) {}
  ~BitDecoder() {}

  bool Next() { pos_++; return !Done(); }
  bool Done() const { return (pos_ / 8 >= input_.size()); }
  bool Value() const {
    return (input_.data()[pos_ / 8] >> (7 - (pos_ % 8))) & 1;
  }
  int bytes_read() const {
    return (pos_ + 7) / 8;
  }
  int bits_read() const {
    return input_.size() == 0 ? 0 : pos_ + 1;
  }

 private:
  StringPiece input_;
  int pos_;
};


inline void BitEncoder::EncodeBit(bool bit) {
  int within = pos_ % 8;
  if (within == 0) {
    output_->resize(output_->size() + 1, 0);
  }
  output_->back() |= (bit << (7 - within));
  ++pos_;
}

inline void BitEncoder::EncodeBits(const std::vector<bool>& bits) {
  for (int i = 0; i < bits.size(); ++i) {
    EncodeBit(bits[i]);
  }
}

}  // namespace strings

#endif  // _COMMON_STRINGS_BITS_H__
