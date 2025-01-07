#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <locale>
#include <map>
#include <algorithm>
#include <iostream>

/**
 * @class modPermCipher
 * @brief Класс для шифрования и расшифрования текста с использованием шифра перестановок.
 *
 * Этот класс поддерживает шифрование и расшифрование текста на основе заданного ключа,
 * который определяет смещения символов в алфавите.
 */
class modPermCipher {
private:
    std::wstring alphabet; ///< Строка, представляющая алфавит для шифрования/расшифрования.
    std::vector<int> key; ///< Вектор, представляющий ключ шифрования.

public:
    /**
     * @brief Конструктор, инициализирующий ключ шифрования.
     *
     * Этот метод принимает ключ в виде строки и преобразует его в вектор целых чисел.
     * @param skey Строка, представляющая ключ для шифрования.
     * @throws std::invalid_argument Если ключ пустой или содержит недопустимые символы.
     */
    modPermCipher(const std::wstring& skey); 

    /**
     * @brief Шифрование текста.
     *
     * Применяет смещения, заданные ключом, к открытом тексту.
     * @param open_text Открытый текст для шифрования.
     * @return Зашифрованный текст.
     * @throws std::invalid_argument Если текст не валиден.
     */
    std::wstring encrypt(const std::wstring& open_text);   

    /**
     * @brief Расшифрование текста.
     *
     * Применяет обратные смещения, заданные ключом, к зашифрованному тексту.
     * @param cipher_text Зашифрованный текст для расшифрования.
     * @return Расшифрованный текст.
     * @throws std::invalid_argument Если текст не валиден.
     */
    std::wstring decrypt(const std::wstring& cipher_text); 

    /**
     * @brief Валидация ключа.
     *
     * Проверяет, что ключ состоит только из цифр и является положительным целым числом.
     * @param key Ключ для валидации.
     * @throws std::invalid_argument Если ключ содержит недопустимые символы или является неположительным.
     */
    void validateKey(const std::wstring& key); 

    /**
     * @brief Валидация текста перед шифрованием или расшифрованием.
     *
     * Проверяет, что текст не пустой и содержит только допустимые символы.
     * @param text Текст для валидации.
     * @throws std::invalid_argument Если текст пустой или содержит недопустимые символы.
     */
    void validateText(const std::wstring& text); 
};