#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>
class modAlphakey
{
private:
    int key1;
public:
    modAlphakey()=delete;
    modAlphakey(const int& key) :key1(key) {};
    std::wstring encrypt(const std::wstring& open_text);
    std::wstring decrypt(const std::wstring& cipher_text);
};