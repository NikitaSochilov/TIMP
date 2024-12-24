/**
 * @file transposition_cipher.cpp
 * @brief Реализация шифра маршрутной перестановки.
 * @author 
 * Сочилов Н. М.
 * 
 * @date 
 * 19 декабря 2024 г.
 */

#include "transposition_cipher.h"

/**
 * @brief Конструктор для инициализации шифра с заданным количеством столбцов.
 * @param columns Количество столбцов в таблице перестановок.
 * @throw std::invalid_argument Если количество столбцов не является положительным числом.
 */
TranspositionCipher::TranspositionCipher(int columns) : columns_(columns) {
    if (columns <= 0) {
        throw std::invalid_argument("Number of columns must be positive");
    }
}

/**
 * @brief Шифрует входной текст методом перестановок.
 * @param plaintext Входной текст для шифрования.
 * @return Зашифрованный текст.
 * @throw std::invalid_argument Если входной текст пуст или содержит недопустимые символы.
 */
std::string TranspositionCipher::encrypt(const std::string& plaintext) {
    if (plaintext.empty()) {
        throw std::invalid_argument("Input text is empty");
    }

    // Проверка входного текста на наличие недопустимых символов
    for (char c : plaintext) {
        if (!isalnum(c) && !isspace(c)) {
            throw std::invalid_argument("Input text contains invalid characters");
        }
    }

    // Удаляем пробелы из текста для подготовки к шифрованию
    std::string sanitizedText;
    for (char c : plaintext) {
        if (!isspace(c)) {
            sanitizedText += c;
        }
    }

    // Вычисляем количество строк в таблице перестановок
    int rows = (sanitizedText.size() + columns_ - 1) / columns_;

    // Создаем таблицу с заданным количеством строк и столбцов, заполненную '\0'
    std::vector<std::string> table(rows, std::string(columns_, '\0'));
    int index = 0;

    // Заполняем таблицу символами текста построчно
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns_; ++j) {
            if (index < sanitizedText.size()) {
                table[i][j] = sanitizedText[index++];
            }
        }
    }

    // Формируем зашифрованный текст, считывая символы из таблицы по столбцам
    std::string ciphertext;
    for (int j = 0; j < columns_; ++j) {
        for (int i = 0; i < rows; ++i) {
            if (table[i][j] != '\0') { // Игнорируем пустые ячейки
                ciphertext += table[i][j];
            }
        }
    }

    return ciphertext;
}

/**
 * @brief Дешифрует зашифрованный текст методом перестановок.
 * @param ciphertext Входной зашифрованный текст.
 * @return Расшифрованный текст.
 * @throw std::invalid_argument Если входной текст пуст или содержит недопустимые символы.
 */
std::string TranspositionCipher::decrypt(const std::string& ciphertext) {
    if (ciphertext.empty()) {
        throw std::invalid_argument("Input text is empty");
    }

    // Проверка входного текста на наличие недопустимых символов
    for (char c : ciphertext) {
        if (!isalnum(c)) {
            throw std::invalid_argument("Input text contains invalid characters");
        }
    }

    // Вычисляем количество строк в таблице и количество лишних ячеек в последней строке
    int rows = (ciphertext.size() + columns_ - 1) / columns_;
    int extraCells = (rows * columns_) - ciphertext.size();

    // Создаем таблицу с заданным количеством строк и столбцов, заполненную '\0'
    std::vector<std::string> table(rows, std::string(columns_, '\0'));
    int index = 0;

    // Заполняем таблицу символами текста по столбцам
    for (int j = 0; j < columns_; ++j) {
        for (int i = 0; i < rows; ++i) {
            // Пропускаем лишние ячейки в последней строке
            if (i == rows - 1 && j >= columns_ - extraCells) {
                continue;
            }
            if (index < ciphertext.size()) {
                table[i][j] = ciphertext[index++];
            }
        }
    }

    // Формируем расшифрованный текст, считывая символы из таблицы построчно
    std::string plaintext;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns_; ++j) {
            if (table[i][j] != '\0') { // Игнорируем пустые ячейки
                plaintext += table[i][j];
            }
        }
    }

    return plaintext;
}
