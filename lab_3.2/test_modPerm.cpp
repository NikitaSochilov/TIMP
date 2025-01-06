#include <UnitTest++/UnitTest++.h>
#include <locale>
#include <codecvt>
#include "modPerm.h"

// Вспомогательная функция для проверки равенства двух std::wstring
void CHECK_WSTRING_EQUAL(const std::wstring& expected, const std::wstring& actual) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    CHECK_EQUAL(converter.to_bytes(expected), converter.to_bytes(actual));
}

// Тестирование шифрования
TEST(SimpleEncryption) {
    modPermCipher cipher(L"213");
    std::wstring encrypted = cipher.encrypt(L"ПРИМЕР");
    CHECK_WSTRING_EQUAL(encrypted, L"ИРМПЕР");
}

// Тестирование расшифрования
TEST(SimpleDecryption) {
    modPermCipher cipher(L"213");
    std::wstring decrypted = cipher.decrypt(L"ИРМПЕР");
    CHECK_WSTRING_EQUAL(decrypted, L"ПРИМЕР");
}

// Тестирование шифрования с пустым текстом
TEST(EmptyTextEncryption) {
    modPermCipher cipher(L"213");
    CHECK_THROW(cipher.encrypt(L""), std::invalid_argument);
}

// Тестирование некорректного ключа
TEST(InvalidKey) {
    CHECK_THROW(modPermCipher cipher(L"2A1"), std::invalid_argument);
}

// Тестирование отрицательного ключа
TEST(NegativeKey) {
    CHECK_THROW(modPermCipher cipher(L"-123"), std::invalid_argument);
}

// Тестирование текста с недопустимыми символами
TEST(InvalidCharactersInText) {
    modPermCipher cipher(L"213");
    CHECK_THROW(cipher.encrypt(L"ПРИМЕР123"), std::invalid_argument);
}

// Тестирование шифрования с длинным текстом
TEST(LongTextEncryption) {
    modPermCipher cipher(L"123");
    std::wstring encrypted = cipher.encrypt(L"ЭТО ПРИМЕР ДЛЯ ТЕСТИРОВАНИЯ");
    CHECK(!encrypted.empty()); // Проверяем, что не пустой
}

// Тестирование расшифрования длинного текста
TEST(LongTextDecryption) {
    modPermCipher cipher(L"123");
    std::wstring decrypted = cipher.decrypt(L"ЗАШИФРОВАННЫЙ ТЕКСТ");
    CHECK(!decrypted.empty()); // Проверяем, что не пустой
}

// Основная функция для запуска тестов
int main(int argc, char* argv[]) {
    return UnitTest::RunAllTests();
}