// Copyright 2013
// Author: Christopher Van Arsdale
//
// TODO(cvanarsdale): This is a garbage library that should be updated with
// something faster/correct. It exists solely for bootstrapping this codebase.
//
// These functions are in no way efficient.

#include <cstdio>
#include <string>
#include <vector>
#include "common/strings/stringpiece.h"
#include "common/strings/strutil.h"
#include "common/third_party/stringencoders/src/modp_b64.h"
#include "common/third_party/stringencoders/src/modp_b64w.h"

namespace strings {

std::vector<StringPiece> Split(const StringPiece& base,
                               const StringPiece& delim,
                               bool allow_empty) {
  std::vector<StringPiece> out;
  if (delim.empty()) {
    out.resize(base.size());
    for (int i = 0; i < base.size(); ++i) {
      out[i] = StringPiece(base.substr(i, 1));
    }
  } else {
    StringPiece next = base;
    size_t pos = next.find(delim);
    for (; pos != StringPiece::npos; pos = next.find(delim)) {
      if (allow_empty || pos > 0) {
        out.push_back(next.substr(0, pos));
      }
      next = next.substr(pos + delim.size());
    }
    if (allow_empty || !next.empty()) {
      out.push_back(next);
    }
  }
  return out;
}

std::vector<std::string> SplitString(const StringPiece& base,
                                     const StringPiece& delim,
                                     bool allow_empty) {
  std::vector<StringPiece> pieces = Split(base, delim, allow_empty);
  std::vector<std::string> out(pieces.size());
  for (size_t i = 0; i < pieces.size(); ++i) {
    pieces[i].CopyToString(&out[i]);
  }
  return out;
}

std::string Repeat(const StringPiece& input, int n_times) {
  std::string out;
  out.reserve(input.size() * n_times);
  for (int i = 0; i < n_times; ++i) {
    out.append(input.as_string());
  }
  return out;
}

std::string Replace(const StringPiece& input,
                    const StringPiece& original,
                    const StringPiece& replace) {
  if (original.empty()) {
    return input.as_string();
  }

  int pos = input.find(original);
  if (pos == StringPiece::npos) {
    return input.as_string();
  }
  return (input.substr(0, pos).as_string() +
          replace.as_string() +
          input.substr(pos + original.size()).as_string());
}

std::string ReplaceAll(const StringPiece& input,
                       const StringPiece& original,
                       const StringPiece& replace) {
  if (original.empty()) {
    return input.as_string();
  }

  std::string out;
  for (StringPiece current = input; !current.empty(); ) {
    int pos = current.find(original);
    if (pos == StringPiece::npos) {
      out += current.as_string();
      break;
    }
    out.append(current.substr(0, pos).as_string());
    out.append(replace.as_string());
    current = current.substr(pos + original.size());
  }
  return out;
}

std::string Base64Encode(const StringPiece& input) {
  return modp::b64_encode(input.data(), input.size());
}
std::string Base64Decode(const StringPiece& input) {
  return modp::b64_decode(input.data(), input.size());
}

std::string WebSafeBase64Encode(const StringPiece& input) {
  return modp::b64w_encode(input.data(), input.size());
}
std::string WebSafeBase64Decode(const StringPiece& input) {
  return modp::b64w_decode(input.data(), input.size());
}

}  // namespace strings
