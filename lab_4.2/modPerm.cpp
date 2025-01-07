#include "modPerm.h"
#include <stdexcept>
#include <locale>

/**
 * @brief Конструктор, инициализирующий ключ шифрования.
 * 
 * @param skey Строка, представляющая ключ для шифрования. 
 * @throws std::invalid_argument Если ключ пуст или содержит недопустимые символы.
 */
modPermCipher::modPermCipher(const std::wstring& skey) {
    if (skey.empty()) {
        throw std::invalid_argument("Ошибка: ключ не может быть пустым. Пожалуйста, введите положительное целое число.");
    }
    alphabet = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯabcdefghijklmnopqrstuvwxyz"; // поддержка русского и английского алфавитов
    validateKey(skey);
    for (auto& ch : skey) {
        key.push_back(wchar_t(ch) - L'0');
    }
}

/**
 * @brief Валидация ключа.
 * 
 * Проверяет, что ключ состоит только из цифр и является положительным целым числом.
 *
 * @param skey Ключ для валидации.
 * @throws std::invalid_argument Если ключ содержит недопустимые символы или является неположительным.
 */
void modPermCipher::validateKey(const std::wstring& skey) {
    for (const auto& ch : skey) {
        if (!iswdigit(ch)) {
            throw std::invalid_argument("Ошибка: ключ должен состоять только из цифр. Пожалуйста, введите положительное целое число.");
        }
    }

    // Проверка на нулевой или отрицательный ключ
    int keyValue = std::stoi(skey);
    if (keyValue <= 0) {
        throw std::invalid_argument("Ошибка: ключ должен быть положительным целым числом. Пожалуйста, введите корректный ключ.");
    }
}

/**
 * @brief Валидация текста перед шифрованием или расшифрованием.
 *
 * Проверяет, что текст не пустой и содержит только допустимые символы.
 *
 * @param text Текст для валидации.
 * @throws std::invalid_argument Если текст пустой или содержит недопустимые символы.
 */
void modPermCipher::validateText(const std::wstring& text) {
    if (text.empty()) {
        throw std::invalid_argument("Ошибка: текст не может быть пустым. Пожалуйста, введите текст для шифрования/расшифрования.");
    }
    for (const auto& ch : text) {
        if (alphabet.find(ch) == std::wstring::npos) {
            throw std::invalid_argument("Ошибка: текст должен содержать только буквы из заданного алфавита (русские и английские буквы).");
        }
    }
}

/**
 * @brief Шифрование текста.
 *
 * Применяет смещения, заданные ключом, к открытом тексту.
 *
 * @param open_text Открытый текст для шифрования.
 * @return Зашифрованный текст.
 * @throws std::invalid_argument Если текст не валиден.
 */
std::wstring modPermCipher::encrypt(const std::wstring& open_text) {
    validateText(open_text);
    std::wstring result;
    int keySize = key.size();

    for (size_t i = 0; i < open_text.size(); ++i) {
        int shift = key[i % keySize];
        wchar_t ch = open_text[i];
        int index = alphabet.find(ch);
        if (index != std::wstring::npos) {
            result.push_back(alphabet[(index + shift) % alphabet.size()]);
        }
    }
    return result;
}

/**
 * @brief Расшифрование текста.
 *
 * Применяет обратные смещения, заданные ключом, к зашифрованному тексту.
 *
 * @param cipher_text Зашифрованный текст для расшифрования.
 * @return Расшифрованный текст.
 * @throws std::invalid_argument Если текст не валиден.
 */
std::wstring modPermCipher::decrypt(const std::wstring& cipher_text) {
    validateText(cipher_text);
    std::wstring result;
    int keySize = key.size();

    for (size_t i = 0; i < cipher_text.size(); ++i) {
        int shift = key[i % keySize];
        wchar_t ch = cipher_text[i];
        int index = alphabet.find(ch);
        if (index != std::wstring::npos) {
            result.push_back(alphabet[(index - shift + alphabet.size()) % alphabet.size()]);
        }
    }
    return result;
}