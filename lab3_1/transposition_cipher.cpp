#include "transposition_cipher.h"

TranspositionCipher::TranspositionCipher(int columns) : columns_(columns) {
    if (columns <= 0) {
        throw std::invalid_argument("Number of columns must be positive");
    }
}

// Шифрование
std::string TranspositionCipher::encrypt(const std::string& plaintext) {
    if (plaintext.empty()) {
        throw std::invalid_argument("Input text is empty");
    }

    // Проверка на невалидные символы
    for (char c : plaintext) {
        if (!isalnum(c) && !isspace(c)) {
            throw std::invalid_argument("Input text contains invalid characters");
        }
    }

    std::string sanitizedText;
    // Удаляем пробелы из входного текста
    for (char c : plaintext) {
        if (!isspace(c)) {
            sanitizedText += c;
        }
    }

    int rows = (sanitizedText.size() + columns_ - 1) / columns_; // Количество строк
    std::vector<std::string> table(rows, std::string(columns_, '\0')); // Используем '\0' для пустых ячеек
    int index = 0;

    // Заполнение таблицы
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns_; ++j) {
            if (index < sanitizedText.size()) {
                table[i][j] = sanitizedText[index++];
            }
        }
    }

    // Считывание текста по столбцам
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

// Дешифрование
std::string TranspositionCipher::decrypt(const std::string& ciphertext) {
    if (ciphertext.empty()) {
        throw std::invalid_argument("Input text is empty");
    }

    // Проверка на невалидные символы
    for (char c : ciphertext) {
        if (!isalnum(c)) {
            throw std::invalid_argument("Input text contains invalid characters");
        }
    }

    int rows = (ciphertext.size() + columns_ - 1) / columns_; // Количество строк
    int extraCells = (rows * columns_) - ciphertext.size(); // Лишние ячейки
    std::vector<std::string> table(rows, std::string(columns_, '\0'));

    int index = 0;

    // Заполнение таблицы столбцами
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

    // Чтение текста по строкам
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
