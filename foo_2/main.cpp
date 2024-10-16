#include <iostream>
#include "transposition_cipher.h"

void checkTranspositionCipher(const std::string& text, int columns) {
    TranspositionCipher cipher(columns);
    std::string ciphertext = cipher.encrypt(text);
    std::string decryptedText = cipher.decrypt(ciphertext);
    std::cout << "Columns: " << columns << std::endl;
    std::cout << text << std::endl;
    std::cout << ciphertext << std::endl;
    std::cout << decryptedText << std::endl;
}

int main() {
    checkTranspositionCipher("HELLOWORLD", 4);
    return 0;
}