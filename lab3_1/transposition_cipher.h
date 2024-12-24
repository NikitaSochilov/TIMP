#ifndef TRANSPOSITION_CIPHER_H
#define TRANSPOSITION_CIPHER_H

#include <string>
#include <vector>
#include <stdexcept>


class TranspositionCipher {
public:

    TranspositionCipher(int columns);


    std::string encrypt(const std::string& plaintext);


    std::string decrypt(const std::string& ciphertext);

private:
    int columns_; 
};

#endif  
