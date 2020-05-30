#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H

#include <string>

namespace atbash_cipher {

    const std::string PLAIN_ALPHA("abcdefghijklmnopqrstuvwxyz");
    const std::string CIPHER_ALPHA("zyxwvutsrqponmlkjihgfedcba");
    constexpr char PLAIN_BASE = 'a';
    constexpr char CIPHER_BASE = 'z';
    constexpr int CIPHER_SEQ_SIZE = 5;

    const std::string encode(const std::string &input);
    const std::string decode(const std::string &input);

}  // namespace atbash_cipher

#endif // ATBASH_CIPHER_H
