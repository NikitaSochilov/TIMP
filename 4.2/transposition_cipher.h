/**
 * @file transposition_cipher.h
 * @brief Заголовочный файл для шифра маршрутной перестановки.
 * @author 
 * Сочилов Н. М.
 * 
 * @date 
 * 19 декабря 2024 г.
 */

#ifndef TRANSPOSITION_CIPHER_H
#define TRANSPOSITION_CIPHER_H

#include <string>
#include <vector>
#include <stdexcept>

/**
 * @class TranspositionCipher
 * @brief Класс, реализующий шифрование и дешифрование текста методом перестановок.
 */
class TranspositionCipher {
public:
    /**
     * @brief Конструктор для инициализации шифра с заданным количеством столбцов.
     * @param columns Количество столбцов в таблице перестановок.
     * @throw std::invalid_argument Если количество столбцов не является положительным числом.
     */
    TranspositionCipher(int columns);

    /**
     * @brief Шифрует входной текст методом перестановок.
     * @param plaintext Входной текст для шифрования.
     * @return Зашифрованный текст.
     * @throw std::invalid_argument Если входной текст пуст или содержит недопустимые символы.
     */
    std::string encrypt(const std::string& plaintext);

    /**
     * @brief Дешифрует зашифрованный текст методом перестановок.
     * @param ciphertext Входной зашифрованный текст.
     * @return Расшифрованный текст.
     * @throw std::invalid_argument Если входной текст пуст или содержит недопустимые символы.
     */
    std::string decrypt(const std::string& ciphertext);

private:
    int columns_; ///< Количество столбцов в таблице перестановок.
};

#endif
