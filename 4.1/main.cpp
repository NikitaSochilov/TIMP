/**
 * @file main.cpp
 * @brief Точка входа для программы, использующей шифр Гронсвельда для шифровки и дешифровки текста.
 * 
 * @author 
 * Сочилов Н. М.
 * 
 * @date 
 * 19 декабря 2024 г.
 */

#include "modAlphaCipher.h"
#include <iostream>
#include <locale>

/**
 * @brief Проверяет, содержит ли строка только заглавные буквы алфавита и символ 'Ё'.
 * @param s Проверяемая строка.
 * @return true, если строка валидна; false если строка не валидна.
 */
bool isValid(const std::wstring& s) {
    for (auto c : s) {
        if (!iswupper(c) && c != L'Ё') {
            return false;
        }
    }
    return true;
}

/**
 * @brief Основная функция программы.
 * Реализует взаимодействие с пользователем для выполнения операций шифровки и дешифровки текста.
 * @return Код завершения программы (0 - успешное выполнение).
 */
int main() {
    try {
        // Установка локали для поддержки русского языка
        std::locale loc("ru_RU.UTF-8");
        std::locale::global(loc);

        std::wstring key, text; 
        int op; 

        std::wcout << L"Введите ключ: ";
        std::wcin >> key;

        // Инициализация шифра с заданным ключом
        modAlphaCipher cipher(key);

        do {
            std::wcout << L"Выберите операцию (0 - выход, 1 - зашифровать, 2 - расшифровать): ";
            std::wcin >> op;

            if (op > 2) {
                std::wcout << L"Несуществующая операция\n";
            } else if (op > 0) {
                std::wcout << L"Введите текст: ";
                std::wcin >> text;

                // Проверка текста на корректность
                if (isValid(text)) {
                    if (op == 1) {
                        // Шифрование текста
                        std::wcout << L"Зашифрованный текст: " << cipher.encrypt(text) << std::endl;
                    } else {
                        // Дешифрование текста
                        std::wcout << L"Расшифрованный текст: " << cipher.decrypt(text) << std::endl;
                    }
                } else {
                    std::wcout << L"Некорректный текст для шифрования/расшифрования\n";
                }
            }
        } while (op != 0); // Выполнять до выбора операции "0 - выход"
    } catch (const std::exception& e) {
        // Обработка исключений
        std::wcerr << L"Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
