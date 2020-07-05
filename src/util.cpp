#include "wordSort.h"
#include <vector>
#include <iostream>
#include <string>
#include <vector>

vector<unsigned char> encode (const string s) {
    string str = s;
    vector<unsigned wchar_t> buff;

    int len = str.length();
    buff.resize(len);
    memcpy(&buff[0], str.c_str(), len);
    return buff;
}
