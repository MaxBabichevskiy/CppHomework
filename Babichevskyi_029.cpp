//Babichevskyi 029

﻿#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

// Функция для поиска слова в словаре
void searchWord(map<string, string>& dict, const string& word) {
    auto it = dict.find(word);
    if (it == dict.end()) {
        cout << "Слово не найдено в словаре" << endl;
    }
    else {
        cout << "Значение слова " << it->first << " - " << it->second << endl;
    }
}

// Функция для добавления слова в словарь
void addWord(map<string, string>& dict, const string& word, const string& meaning) {
    auto it = dict.find(word);
    if (it == dict.end()) {
        dict[word] = meaning;
        cout << "Слово успешно добавлено в словарь" << endl;
    }
    else {
        cout << "Слово уже есть в словаре" << endl;
    }
}

// Функция для удаления слова из словаря
void removeWord(map<string, string>& dict, const string& word) {
    auto it = dict.find(word);
    if (it == dict.end()) {
        cout << "Слово не найдено в словаре" << endl;
    }
    else {
        dict.erase(it);
        cout << "Слово успешно удалено из словаря" << endl;
    }
}

// Функция для редактирования значения слова в словаре
void editWord(map<string, string>& dict, const string& word, const string& newMeaning) {
    auto it = dict.find(word);
    if (it == dict.end()) {
        cout << "Слово не найдено в словаре" << endl;
    }
    else {
        it->second = newMeaning;
        cout << "Значение слова успешно изменено" << endl;
    }
}

// Функция для чтения словаря из файла
void readDictionaryFromFile(map<string, string>& dict, const string& filename) {
    ifstream fin(filename);
    if (fin.is_open()) {
        string word, meaning;
        while (fin >> word >> meaning) {
            dict[word] = meaning;
        }
        cout << "Словарь успешно загружен из файла" << endl;
    }
    else {
        cout << "Не удалось открыть файл" << endl;
    }
}

// Функция для записи словаря в файл
void saveDictionaryToFile(map<string, string>& dict, const string& filename) {
    ofstream fout(filename);
    if (fout.is_open()) {
        for (auto& pair : dict) {
            fout << pair.first << " " << pair.second << endl;
        }
        cout << "Словарь успешно сохранен в файл" << endl;
    }
    else {
        cout << "Не удалось открыть файл" << endl;
    }
}

int main() {
    map<string, string> dict; // Контейнер map для хранения словаря

    // Примеры использов
    while (true) {
        // Вывод меню
        cout << endl;
        cout << "Меню:" << endl;
        cout << "1. Поиск слова" << endl;
        cout << "2. Добавление слова" << endl;
        cout << "3. Удаление слова" << endl;
        cout << "4. Редактирование значения слова" << endl;
        cout << "5. Чтение словаря из файла" << endl;
        cout << "6. Запись словаря в файл" << endl;
        cout << "7. Выход" << endl;

        // Чтение выбора пользователя
        int choice;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: { // Поиск слова
            string word;
            cout << "Введите слово: ";
            cin >> word;
            searchWord(dict, word);
            break;
        }
        case 2: { // Добавление слова
            string word, meaning;
            cout << "Введите слово: ";
            cin >> word;
            cout << "Введите значение: ";
            cin >> meaning;
            addWord(dict, word, meaning);
            break;
        }
        case 3: { // Удаление слова
            string word;
            cout << "Введите слово: ";
            cin >> word;
            removeWord(dict, word);
            break;
        }
        case 4: { // Редактирование значения слова
            string word, newMeaning;
            cout << "Введите слово: ";
            cin >> word;
            cout << "Введите новое значение: ";
            cin >> newMeaning;
            editWord(dict, word, newMeaning);
            break;
        }
        case 5: { // Чтение словаря из файла
            string filename;
            cout << "Введите имя файла: ";
            cin >> filename;
            readDictionaryFromFile(dict, filename);
            break;
        }
        case 6: { // Запись словаря в файл
            string filename;
            cout << "Введите имя файла: ";
            cin >> filename;
            saveDictionaryToFile(dict, filename);
            break;
        }
        case 7: { // Выход
            return 0;
        }
        default:
            cout << "Некорректный выбор" << endl;
        }
    }
