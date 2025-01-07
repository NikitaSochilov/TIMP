#pragma once
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>

/**
 * @class modAlphaCipher
 * @brief Класс для шифрования и расшифрования текста методом Гронсфельда.
 *
 * Этот класс реализует шифрование и расшифрование русского текста на основе
 * заданного ключа. Ключ представляет собой последовательность цифр, которые
 * указывают смещение для каждого символа в алфавите.
 */
class modAlphaCipher {
private:
    /// Строка, представляющая алфавит (русский алфавит).
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; 
    /// Ассоциативный массив, связывающий символы алфавита с их индексами.
    std::map<wchar_t, int> alphaNum; 
    /// Вектор, содержащий ключ шифрования в числовом формате.
    std::vector<int> key; 

    /**
     * @brief Преобразование строки в вектор чисел.
     * @param s Строка для преобразования.
     * @return Вектор целых чисел, представляющий индексы символов в алфавите.
     * @throws std::invalid_argument Если строка содержит недопустимые символы.
     */
    std::vector<int> convert(const std::wstring& s);

    /**
     * @brief Преобразование вектора чисел в строку.
     * @param v Вектор целых чисел для преобразования.
     * @return Строка, созданная из указанных индексов.
     * @throws std::out_of_range Если любой индекс выходит за пределы алфавита.
     */
    std::wstring convert(const std::vector<int>& v);

public:
    /// Запрет конструктора по умолчанию.
    modAlphaCipher() = delete; 

    /**
     * @brief Конструктор, инициализирующий ключ шифрования.
     * @param skey Строка, представляющая ключ для шифрования.
     * @throw std::invalid_argument Если ключ содержит недопустимые символы.
     */
    modAlphaCipher(const std::wstring& skey); 

    /**
     * @brief Шифрование текста.
     * @param open_text Открытый текст для шифрования.
     * @return Зашифрованный текст.
     * @throws std::exception Если возникает ошибка при шифровании.
     */
    std::wstring encrypt(const std::wstring& open_text); 

    /**
     * @brief Расшифрование текста.
     * @param cipher_text Зашифрованный текст для расшифрования.
     * @return Расшифрованный текст.
     * @throws std::exception Если возникает ошибка при расшифровке.
     */
    std::wstring decrypt(const std::wstring& cipher_text); 
};