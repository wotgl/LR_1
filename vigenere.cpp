#include "vigenere.h"
#include <string>

const int alphabet_length = 26;
const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";



std::string encryption(std::string msg, std::string key){
    std::string ans = "";

    int i = 0, temp = key.length();
    while (msg.length() != key.length() && msg.length() > key.length()) {
        if (i < temp) {
            key += key[i];
            i++;
        } else {
            i = 0;
        }
    }

    int temp_msg[alphabet_length], temp_key[alphabet_length];
    for (int i = 0; i < alphabet_length; i++) {
        for (int j = 0; j < alphabet_length; j++) {
            if (msg[i] == alphabet[j]) temp_msg[i] = j;
            if (key[i] == alphabet[j]) temp_key[i] = j;
        }
    }

    for (int i = 0; i < msg.length(); i++){
        int temp;
        temp = (temp_msg[i] + temp_key[i]) % alphabet_length;
        ans += alphabet[temp];
    }

    return ans;
}

std::string decryption(std::string msg, std::string key){
    std::string ans = "";

    int i = 0, temp = key.length();
    while (msg.length() != key.length() && msg.length() > key.length()) {
        if (i < temp) {
            key += key[i];
            i++;
        } else {
            i = 0;
        }
    }

    int temp_msg[alphabet_length], temp_key[alphabet_length];
    for (int i = 0; i < alphabet_length; i++) {
        for (int j = 0; j < alphabet_length; j++) {
            if (msg[i] == alphabet[j]) temp_msg[i] = j;
            if (key[i] == alphabet[j]) temp_key[i] = j;
        }
    }

    for (int i = 0; i < msg.length(); i++){
        int temp;
        temp = (temp_msg[i] - temp_key[i] + 26) % alphabet_length;
        ans += alphabet[temp];
    }

    return ans;
}


bool check(std::string text){
    bool check = true;
    bool *f =  new bool[text.length()];

    for (int i = 0; i < text.length(); i++) f[i] = false;

    for (int i = 0; i < text.length(); i++){
        for (int j = 0; j < alphabet_length; j++){
            if (text[i] == alphabet[j]) f[i] = true;
        }
    }

    for (int i = 0; i < text.length(); i++){
        if(!f[i]) check = false;
    }

    delete f;
    return check;
}
