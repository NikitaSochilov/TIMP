#include <UnitTest++/UnitTest++.h>
#include "modAlphaCipher.h"

// шифрование пустого текста
TEST(TestEncryptEmptyText) {
    modAlphaCipher cipher(L"АБВ");
    std::wstring encrypted = cipher.encrypt(L"");
    CHECK(encrypted == L""); 
}

// дешифрование пустого текста
TEST(TestDecryptEmptyText) {
    modAlphaCipher cipher(L"АБВ");
    std::wstring decrypted = cipher.decrypt(L"");
    CHECK(decrypted == L""); 
}

// шифрование текста с недопустимыми символами
TEST(TestLowerCaseCharacterInText) {
    modAlphaCipher cipher(L"АБВ");
    CHECK_THROW(cipher.encrypt(L"привет"), std::invalid_argument); 
}

// дешифрование текста с недопустимыми символами
TEST(TestLowerCaseCharacterInKey) {
    modAlphaCipher cipher(L"АБВ");
    CHECK_THROW(cipher.decrypt(L"привет"), std::invalid_argument); 
}

// шифрование текста с невалидными символами
TEST(TestForeignCharacterInText) {
    modAlphaCipher cipher(L"АБВ");
    CHECK_THROW(cipher.encrypt(L"Hello"), std::invalid_argument); 
}

// шифрование минимального ключа
TEST(TestMinimalKey) {
    modAlphaCipher cipher(L"Б");
    std::wstring encrypted = cipher.encrypt(L"ПРИВЕТ"); 
    CHECK(encrypted == L"РСЙГЁУ"); 
}

// шифрование длинного ключа
TEST(TestLongKey) {
    modAlphaCipher cipher(L"АБВАБВАБВАБВАБВ");
    std::wstring encrypted = cipher.encrypt(L"ПРИВЕТ"); 
    CHECK(encrypted == L"ПСКВЁФ"); 
}

// Тест на правильность шифрования
TEST(TestEncryptionCorrectness) {
    modAlphaCipher cipher(L"АБВ");
    std::wstring encrypted = cipher.encrypt(L"ПРИВЕТ");
    CHECK(encrypted == L"ПСКВЁФ"); 
}

// Тест на правильность дешифрования
TEST(TestDecryptionCorrectness) {
    modAlphaCipher cipher(L"АБВ");
    std::wstring decrypted = cipher.decrypt(L"ПСКВЁФ");
    CHECK(decrypted == L"ПРИВЕТ"); 
}

int main() {
    return UnitTest::RunAllTests();
}
