#include "modGronsfeld.h"

// Конструктор, инициализирующий ключ
modAlphaCipher::modAlphaCipher(const std::wstring& skey) {
    for (unsigned i = 0; i < numAlpha.size(); i++) {
        alphaNum[numAlpha[i]] = i;
    }
    key = convert(skey);
}

/**
 * @brief Преобразование строки в числовой вектор.
 * @param s Строка для преобразования.
 * @return Вектор целых чисел, представляющий индексы символов.
 * @throws std::invalid_argument Если строка содержит недопустимые символы.
 */
std::vector<int> modAlphaCipher::convert(const std::wstring& s) {
    std::vector<int> result;
    for (auto c : s) {
        if (alphaNum.find(c) == alphaNum.end()) {
            throw std::invalid_argument("Invalid character in text.");
        }
        result.push_back(alphaNum[c]);
    }
    return result;
}

/**
 * @brief Преобразование числового вектора в строку.
 * @param v Вектор целых чисел.
 * @return Строка, созданная из указанных индексов.
 * @throws std::out_of_range Если индекс выходит за пределы алфавита.
 */
std::wstring modAlphaCipher::convert(const std::vector<int>& v) {
    std::wstring result;
    for (auto i : v) {
        if (i >= numAlpha.size()) {
            throw std::out_of_range("Index out of bounds in decryption.");
        }
        result.push_back(numAlpha[i]);
    }
    return result;
}

/**
 * @brief Шифрование текста.
 * @param open_text Открытый текст для шифрования.
 * @return Зашифрованный текст.
 * @throws std::exception Если возникает ошибка при шифровании.
 */
std::wstring modAlphaCipher::encrypt(const std::wstring& open_text) {
    try {
        std::vector<int> work = convert(open_text);
        for (unsigned i = 0; i < work.size(); i++) {
            work[i] = (work[i] + key[i % key.size()]) % numAlpha.size();
        }
        return convert(work);
    } catch (const std::exception& e) {
        std::wcerr << L"Encryption error: " << e.what() << std::endl;
        throw;
    }
}

/**
 * @brief Расшифрование текста.
 * @param cipher_text Зашифрованный текст для расшифрования.
 * @return Расшифрованный текст.
 * @throws std::exception Если возникает ошибка при расшифровке.
 */
std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text) {
    try {
        std::vector<int> work = convert(cipher_text);
        for (unsigned i = 0; i < work.size(); i++) {
            work[i] = (work[i] + numAlpha.size() - key[i % key.size()]) % numAlpha.size();
        }
        return convert(work);
    } catch (const std::exception& e) {
        std::wcerr << L"Decryption error: " << e.what() << std::endl;
        throw;
    }
}