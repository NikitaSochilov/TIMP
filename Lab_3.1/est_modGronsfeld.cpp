#include <UnitTest++/UnitTest++.h>
#include "modGronsfeld.h"
#include <locale>
#include <codecvt> // Для преобразования wstring в string

// Вспомогательная функция для сравнения std::wstring
void CHECK_WSTRING_EQUAL(const std::wstring& expected, const std::wstring& actual) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    CHECK_EQUAL(converter.to_bytes(expected), converter.to_bytes(actual));
}

TEST(EmptyTextEncryption) {
    modAlphaCipher cipher(L"КЛЮЧ");
    std::wstring original = L"";
    std::wstring encrypted = cipher.encrypt(original);
    CHECK_WSTRING_EQUAL(original, encrypted); // Пустой текст остается пустым
}

TEST(LowercaseInputEncryption) {
    modAlphaCipher cipher(L"КЛЮЧ");
    std::wstring invalidInput = L"пример"; // Нижний регистр
    CHECK_THROW(cipher.encrypt(invalidInput), std::invalid_argument);
}

TEST(InvalidCharacterInputEncryption) {
    modAlphaCipher cipher(L"КЛЮЧ");
    std::wstring invalidInput = L"Пример123"; // Неверные символы
    CHECK_THROW(cipher.encrypt(invalidInput), std::invalid_argument);
}

TEST(MinimalKey) {
    modAlphaCipher cipher(L"К");
    std::wstring original = L"ПРИМЕР";
    std::wstring encrypted = cipher.encrypt(original);
    CHECK(original != encrypted); // Текст зашифрован
}

TEST(LongKey) {
    modAlphaCipher cipher(L"КЛЮЧКЛЮЧКЛЮЧКЛЮЧ");
    std::wstring original = L"ПРИМЕР";
    std::wstring encrypted = cipher.encrypt(original);
    CHECK(original != encrypted); // Текст зашифрован
    std::wstring decrypted = cipher.decrypt(encrypted);
    CHECK_WSTRING_EQUAL(original, decrypted); // Проверка расшифрования
}

TEST(NormalEncryption) {
    modAlphaCipher cipher(L"КЛЮЧ");
    std::wstring original = L"ПРИМЕР";
    std::wstring encrypted = cipher.encrypt(original);
    CHECK(original != encrypted); // Текст зашифрован
}

TEST(EmptyTextDecryption) {
    modAlphaCipher cipher(L"КЛЮЧ");
    std::wstring original = L"";
    std::wstring decrypted = cipher.decrypt(original);
    CHECK_WSTRING_EQUAL(original, decrypted); // Пустой текст остается пустым
}

TEST(LowercaseInputDecryption) {
    modAlphaCipher cipher(L"КЛЮЧ");
    std::wstring invalidInput = L"пример"; // Нижний регистр
    CHECK_THROW(cipher.decrypt(invalidInput), std::invalid_argument);
}

TEST(CorrectDecryption) {
    modAlphaCipher cipher(L"КЛЮЧ");
    std::wstring original = L"ПРИМЕР";
    std::wstring encrypted = cipher.encrypt(original);
    std::wstring decrypted = cipher.decrypt(encrypted);
    CHECK_WSTRING_EQUAL(original, decrypted); // Должно корректно расшифровываться
}

int main(int argc, char* argv[]) {
    return UnitTest::RunAllTests();
}