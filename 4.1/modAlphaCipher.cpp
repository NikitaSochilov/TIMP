/**
 * @file modAlphaCipher.cpp
 * @brief Реализация методов класса modAlphaCipher.
 *
 * @author 
 * Сочилов Н. М.
 * 
 * @date 
 * 19 декабря 2024 г.
 */

#include "modAlphaCipher.h"

/**
 * @brief Конструктор для инициализации шифра с ключом.
 * @param skey Строка-ключ, используемая для шифровке и дешифровке.
 */
modAlphaCipher::modAlphaCipher(const std::wstring& skey) {
    for (unsigned i = 0; i < numAlpha.size(); i++) {
        alphaNum[numAlpha[i]] = i;
    }
    key = convert(skey);
}

/**
 * @brief Преобразует строку в числовой вектор на основе алфавита.
 * @param s Входная строка для преобразования.
 * @return Вектор чисел, представляющий строку.
 * @throw std::invalid_argument Если строка содержит символы, отсутствующие в алфавите.
 */
std::vector<int> modAlphaCipher::convert(const std::wstring& s) {
    std::vector<int> result;
    for (auto c : s) {
        if (alphaNum.find(c) == alphaNum.end()) {
            throw std::invalid_argument("Недопустимый символ в тексте.");
        }
        result.push_back(alphaNum[c]);
    }
    return result;
}

/**
 * @brief Преобразует числовой вектор обратно в строку на основе алфавита.
 * @param v Входной вектор для преобразования.
 * @return Строка, соответствующая вектору.
 * @throw std::invalid_argument Если индекс в векторе выходит за пределы алфавита.
 */
std::wstring modAlphaCipher::convert(const std::vector<int>& v) {
    std::wstring result;
    for (size_t i = 0; i < v.size(); ++i) {
        if (static_cast<size_t>(v[i]) >= numAlpha.size()) {
            throw std::invalid_argument("Индекс вышел за границу");
        }
        result += numAlpha[v[i]];
    }
    return result;
}

/**
 * @brief Шифрует открытую строку.
 * @param open_text Входная строка для шифрования.
 * @return Зашифрованная строка.
 * @throw std::exception В случае возникновения ошибки при шифровании.
 */
std::wstring modAlphaCipher::encrypt(const std::wstring& open_text) {
    try {
        std::vector<int> work = convert(open_text);
        for (unsigned i = 0; i < work.size(); i++) {
            work[i] = (work[i] + key[i % key.size()]) % numAlpha.size();
        }
        return convert(work);
    } catch (const std::exception& e) {
        std::wcerr << L"Ошибка шифрования: " << e.what() << std::endl;
        throw;
    }
}

/**
 * @brief Дешифрует зашифрованную строку.
 * @param cipher_text Входная строка для дешифрования.
 * @return Расшифрованная строка.
 * @throw std::exception В случае возникновения ошибки при дешифровании.
 */
std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text) {
    try {
        std::vector<int> work = convert(cipher_text);
        for (unsigned i = 0; i < work.size(); i++) {
            work[i] = (work[i] + numAlpha.size() - key[i % key.size()]) % numAlpha.size();
        }
        return convert(work);
    } catch (const std::exception& e) {
        std::wcerr << L"Ошибка дешифрования: " << e.what() << std::endl;
        throw;
    }
}
