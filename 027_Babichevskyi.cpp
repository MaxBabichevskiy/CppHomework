//Babichevskyi Maxim 027
//
//Переробити раніше написаний перекладач через vector.

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
using namespace std;

class Dictionary {
    vector<string>word_engl;
    vector<string>word_rus;
    ifstream f1;
    ifstream f2;
public:
    Dictionary() {}
    Dictionary(string filename1, string filename2) {
        Load(filename1, filename2);
    }
    void Load(string filename1, string filename2) {
        Load(filename1, word_engl);
        Load(filename2, word_rus);
    }
    int getSize(string filename) {
        int i = 0;
        string temp;
        ifstream filetxt;
        filetxt.open(filename);
        if (!filetxt.is_open()) {
            cout << "Error, no access to file " << endl;
            return false;
        }
        else {
            while (!filetxt.eof()) {
                getline(filetxt, temp);
                ++i;
            }
        }
        filetxt.close();
        return i;
    }
    int Load(string path1, vector<string>&word) {
        /*if (size1 == size2)
            size = size1;
        if (size1 != size2)
            throw 0;*/
        int i = 0;
        string temp;
        ifstream filetxt;
        filetxt.open(path1);
        if (!filetxt.is_open()) {
            cout << "Error, no access to file " << path1 << endl;
            return false;
        }
        else {
            while (!filetxt.eof()) {
                getline(filetxt, temp);
                word.push_back(temp);
            }
        }
        filetxt.close();
        return i;
    }
    string Translate(string word, string choise) {
        int i = 0;
        if (choise == "ENG-RU") {
            for (; i < word_engl.size(); i++) {
                if (word_engl[i] == word) {
                    return word_rus[i];
                }
            }
        }
        if (choise == "RU-ENG") {
            for (; i < word_rus.size(); i++) {
                if (word_rus[i] == word) {
                    return word_engl[i];
                }
            }
        }
        return "unknown word";
    }
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        Dictionary dictionary("Eng.txt", "Rus.txt");
        cout << "dictionary.Translate(\"access\", \"ENG - RU\")\t";
        cout << dictionary.Translate("access", "ENG-RU") << endl;
        cout << "dictionary.Translate(\"play\", \"ENG - RU\")\t";
        cout << dictionary.Translate("play", "ENG-RU") << endl;
        cout << "dictionary.Translate(\"королевский\", \"RU - ENG\")\t";
        cout << dictionary.Translate("королевский", "RU-ENG") << endl;
        cout << "dictionary.Translate(\"пофіваглр\", \"RU - ENG\")\t";
        cout << dictionary.Translate("пофіваглр", "RU-ENG") << endl;
    }
    catch (int e) {
        cout << "Error, different number of vocabulary words" << endl;
    }
    catch (...) {
        cout << "Unknown Error" << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
