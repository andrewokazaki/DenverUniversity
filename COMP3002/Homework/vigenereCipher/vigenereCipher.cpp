#include "vigenereCipher.h"

#include <iostream>
#include <string>
#include <fstream>
#include <stack>

namespace cipher{
    vigenereCipher::vigenereCipher(){
        inputFile = "files/input.txt";
        keyCount = -1;
    }
    void vigenereCipher::set_key(std::string key) {
        transform(key.begin(), key.end(), key.begin(), ::toupper);

        this->key = key;
    }
    void vigenereCipher::set_count(int count){
        keyCount = count;
    }
    std::string vigenereCipher::get_key() const{return key;}
    void vigenereCipher::set_inputFile(std::string inputFile){ this->inputFile = inputFile;}
    std::string vigenereCipher::get_inputFile() const{ return inputFile;}
    void vigenereCipher::set_outputFile(std::string key){ this->outputfile = outputfile;}
    std::string vigenereCipher::get_outputFile() const{ return outputfile;}
    void vigenereCipher::set_keyLetter(char letter){keyLetter = letter;}
    alpha vigenereCipher::get_keyLetter(){
        keyCount += 1;
        alpha x = static_cast<alpha>(key.at(keyCount%key.length()) - 'A');
        return x;
    }
    void vigenereCipher::set_textLetter(char letter){textLetter = letter;}
    char vigenereCipher::get_textLetter() const{return textLetter;}

    void run_vigenereCipher(vigenereCipher& cipher){
        std::string userInput;
        std::cout << "\nWelcome to the Vigenere Cipher\n";
        std::cout << "Would you like to encrypt or decrypt?\n";
        std::cout << "(encrypt/decrypt) : ";
        std::cin >> userInput;
        if(userInput == "encrypt"){
            encrypt(cipher);
        }else if(userInput == "decrypt"){
            //decript();
        }else{
            std::cout << "\nIncorrect Input\n";
            run_vigenereCipher(cipher);
        }
    }

    void encrypt(vigenereCipher& cipher){
        std::string userInput;
        std::cout << "\nWelcome to the Encrypter\n";
        //Key---------------------------------------------------
        std::cout << "Set the Key: ";
        std::cin >> userInput;
        cipher.set_key(userInput);
        if(!check_key(cipher)){
            std::cout << "The Key was Incorrect ";
            encrypt(cipher);
        }
        std::cout << "The Key was set to : " << cipher.get_key();
        //--------------------------------------------------------
        cipher.set_inputFile("../vigenereCipher/files/input.txt");
        std::cout << "\nopen : " << cipher.get_inputFile() << std::endl;
        std::ifstream infile (cipher.get_inputFile());
        std::ofstream outfile;
        outfile.open ("../vigenereCipher/files/output.txt");
        while(getline (infile,userInput)){
            for(char& c : userInput){
                cipher::alpha test = cipher.get_keyLetter();
                char out = test + c;
                outfile << out;
            }
            outfile << '\n';
        }
        //----------------------------------------------------------

    }

    void decrypt(vigenereCipher& cipher){

    }
    bool check_key(vigenereCipher& cipher){
        for(char& c : cipher.get_key()){
            if(!std::isalpha(c)){
                return false;
            }
        }
        return true;
    }
    char &operator+(alpha& K, char& b) {
        char outChar = b;
        if (std::isalpha(b)) {
            if(std::isupper(b)){
                int x = b - 'A' + 1;
                int y = (int)K;
                int value = (x+y)%26;
                if(value == 0){value = 26;}
                outChar = value+'A'-1;
            }else{
                int x = b - 'a' + 1;
                int y = (int)K;
                int value = (x+y)%26;
                if(value == 0){value = 26;}
                //std::cout<< value << std::endl;
                outChar = value +'a'-1;
            }
        }
        return outChar;
    }
    char &operator-(alpha& K, char& b) {
        char outChar = b;
        if (std::isalpha(b)) {
            if(std::isupper(b)){
                int text = b - 'A' + 1;
                int ky = (int)K;
                int value = (text-ky+26)%26;
                if(value == 0){value = 26;}
                outChar = value+'A'-1;
            }else{
                int text = b - 'a' + 1;
                int ky = (int)K;
                int value = (text-ky+26)%26;
                if(value == 0){value = 26;}
                //std::cout<< value << std::endl;
                outChar = value +'a'-1;
            }
        }
        return outChar;
    }

}//end of namespace boardGame 



