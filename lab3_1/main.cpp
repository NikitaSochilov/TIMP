#include <iostream>
#include <stdexcept>
#include <string>
#include "transposition_cipher.h"

int main() {
    try {
        int columns;
        std::cout << "Введите количество столбцов для шифрования/дешифрования: ";
        std::cin >> columns;
        std::cin.ignore(); // Очистка буфера

        TranspositionCipher cipher(columns); // Создаем объект шифра

        int choice;
        std::cout << "Выберите действие:\n1. Зашифровать текст\n2. Расшифровать текст\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore(); // Очистка буфера

        std::string text;
        if (choice == 1) {
            std::cout << "Введите текст для шифрования: ";
            std::getline(std::cin, text);

            std::string encryptedText = cipher.encrypt(text);
            std::cout << "Зашифрованный текст: " << encryptedText << std::endl;
        } else if (choice == 2) {
            std::cout << "Введите зашифрованный текст для расшифровки: ";
            std::getline(std::cin, text);

            std::string decryptedText = cipher.decrypt(text);
            std::cout << "Расшифрованный текст: " << decryptedText << std::endl;
        } else {
            std::cout << "Неверный выбор!" << std::endl;
        }

    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}

