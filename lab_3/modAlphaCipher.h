#pragma once
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <iostream>

class modAlphaCipher {
private:
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; 
    std::map<wchar_t, int> alphaNum; 
    std::vector<int> key; // ключ 

    // Преобразование строки в числовой вектор
    std::vector<int> convert(const std::wstring& s);

    // Преобразование числового вектора в строку
    std::wstring convert(const std::vector<int>& v);

public:
    modAlphaCipher() = delete; 
    modAlphaCipher(const std::wstring& skey); 

    std::wstring encrypt(const std::wstring& open_text);   
    std::wstring decrypt(const std::wstring& cipher_text); 
};
