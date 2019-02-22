//This project was created on Feb 18, 2019
//Daniel Aguila
//For a Intro to Programming project

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void getRidofWhite(ifstream&, ofstream&);
void amountOfCharacters(ifstream&, ofstream&);
void amountOfWords(ifstream&, ofstream&);
void replaceVowels(ifstream&, ofstream&);
void reverseOrderLines(ifstream&, ofstream&);


int main() {
    string fileInput;
    int option;
    cout << "Input direct/relative file Path: ";
    cin >> fileInput;
    cout << endl;
    //Open the files
    ifstream inStream(fileInput);
    ofstream writeFile("output.txt");
    //Check for fails
    if(inStream.fail()){
        cerr << "ERROR: OPENING FILE\n";
    }
    else{
        cout << "choose a menu (Int): \n"
                "\t1) Get rid of blank spaces\n"
                "\t2) Amount of characters\n"
                "\t3) Amount of words\n"
                "\t4) Replace Vowels with 3's\n"
                "\t5) Reverse order of lines\n"
                "Enter option number: ";
        cin >> option;
        //Call function base on option
        switch (option) {
            case 1:
                getRidofWhite(inStream, writeFile);
                break;
            case 2:
                amountOfCharacters(inStream, writeFile);
                break;
            case 3:
                amountOfWords(inStream, writeFile);
                break;
            case 4:
                replaceVowels(inStream, writeFile);
                break;
            case 5:
                reverseOrderLines(inStream, writeFile);
                break;
            default:
                cout << "ERROR: Input out of bounds";
                break;
        }
    }
    //Close files
    writeFile.close();
    inStream.close();
    return 0;
}

void getRidofWhite(ifstream& file, ofstream& write){
    string line;
    //Remove white spaces
    while(getline(file, line)) {
        line.erase(remove(line.begin(),line.end(),' '), line.end());
        write << line << endl;
    }
}
void amountOfCharacters(ifstream& file, ofstream& write){
    string temp;
    long int cnt = 0;
    //Count for characters in the files
        while(getline(file, temp)){
        temp.erase(remove(temp.begin(),temp.end(),' '), temp.end());
        cnt += temp.length();
    }
        write << cnt;
}
void amountOfWords(ifstream& file, ofstream& write){
    string temp;
    long cnt = 0;
    //Count for words in the files
    while(file >> temp){
        cnt++;
    }
    write << cnt;
}
void replaceVowels(ifstream& file, ofstream& write) {
    string word;
    //Replace vowels with 3's
    while(getline(file, word)){
        for(unsigned int i = 0; i < word.length(); i++) {
            switch (word[i]) {
                case 'a':
                case 'A':
                case 'e':
                case 'E':
                case 'i':
                case 'I':
                case 'o':
                case 'O':
                case 'u':
                case 'U':
                    word[i] = '3';
                    break;
                default:
                    break;
            }
        }
            write << word << "\n";
        }
    }
void reverseOrderLines(ifstream& file, ofstream& write){
    //Reverse the order of lineS
    string temp;
    string reverse;
    while(getline(file, temp)){
        reverse = temp + "\n" + reverse;
    }
    write << reverse;
}
