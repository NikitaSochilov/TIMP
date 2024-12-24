/**
 * @file modAlphaCipher.h
 * @brief Заголовочный файл для шифровки Гронсвельда.
 *
 * @author 
 * Сочилов Н. М.
 * 
 * @date 
 * 19 декабря 2024 г.
 */

#pragma once
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>

/**
 * @class modAlphaCipher
 * @brief Предоставляет методы шифровки и дешифровки шифра Гронсвельда.
 */
class modAlphaCipher {
private:
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; 
    std::map<wchar_t, int> alphaNum; 
    std::vector<int> key;

    /**
     * @brief Преобразует строку в вектор на основе алфавита.
     * @param s Входная строка для преобразования.
     * @return Вектор чисел, представляющий строку.
     * @throw std::invalid_argument Если строка содержит символы, отсутствующие в алфавите.
     */
    std::vector<int> convert(const std::wstring& s);

    /**
     * @brief Преобразует числовой вектор обратно в строку на основе алфавита.
     * @param v Входной вектор для преобразования.
     * @return Строка, соответствующая вектору.
     * @throw std::invalid_argument Если индекс в векторе выходит за пределы алфавита.
     */
    std::wstring convert(const std::vector<int>& v);

public:
    /**
     * @brief Конструктор по умолчанию удалён, чтобы всегда требовался ключ.
     */
    modAlphaCipher() = delete;

    /**
     * @brief Конструктор для инициализации шифра с ключом.
     * @param skey Строка-ключ, используемая для шифровки и дешифровки.
     */
    modAlphaCipher(const std::wstring& skey);

    /**
     * @brief Шифрует открытую строку.
     * @param open_text Входная строка для шифровки.
     * @return Зашифрованная строка.
     * @throw std::exception В случае возникновения ошибки при шифровке.
     */
    std::wstring encrypt(const std::wstring& open_text);

    /**
     * @brief Дешифрует зашифрованную строку.
     * @param cipher_text Входная строка для дешифровки.
     * @return Расшифрованная строка.
     * @throw std::exception В случае возникновения ошибки при дешифровке.
     */
    std::wstring decrypt(const std::wstring& cipher_text);
};
