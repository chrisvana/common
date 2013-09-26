#include <string>

std::string base64_encode(unsigned char const* , unsigned int len);

// MODIFIED
// std::string base64_decode(std::string const& s);
bool base64_decode(unsigned char const*, unsigned int len,
                   std::string* out);
// END MODIFIED

