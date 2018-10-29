#include "vigenereCipher.h"

#include <iostream>
#include <string>
#include <fstream>
#include <stack>

namespace cipher{
    //ctor
    vigenereCipher::vigenereCipher(){
        inputFile = "files/input.txt";
        keyCount = -1;
    }
    //Getters and setters--------------------------------------------------------------
    //Set the key to all upper
    void vigenereCipher::set_key(std::string key) {
        transform(key.begin(), key.end(), key.begin(), ::toupper);
        this->key = key;
    }
    //Reset the count
    void vigenereCipher::set_count(int count){
        keyCount = count;
    }
    //get the key
    std::string vigenereCipher::get_key() const{return key;}
    //set path to input file
    void vigenereCipher::set_inputFile(std::string inputFile){ this->inputFile = inputFile;}
    //return the input file path
    std::string vigenereCipher::get_inputFile() const{ return inputFile;}
    //set the key letter
    void vigenereCipher::set_keyLetter(char letter){keyLetter = letter;}
    //return the key letter
    alpha vigenereCipher::get_keyLetter(){
        keyCount += 1;
        alpha x = static_cast<alpha>(key.at(keyCount%key.length()) - 'A');
        return x;
    }
    //set the text letter which is a char
    void vigenereCipher::set_textLetter(char letter){textLetter = letter;}
    //get the text letter
    char vigenereCipher::get_textLetter() const{return textLetter;}
    //end getter and setters-----------------------------------------------------------------

    //run the cipher
    void run_vigenereCipher(vigenereCipher& cipher){
        //user input
        //std::string userInput;
        //std::cout << "\nWelcome to the Vigenere Cipher\n";
        //std::cout << "Would you like to encrypt or decrypt?\n";
        //std::cout << "(encrypt/decrypt/run) : ";
        //std::cin >> userInput;
        encrypt(cipher);
        decrypt(cipher);
        check_file();
        //different choices
        /*
        if(userInput == "encrypt"){
            encrypt(cipher);
        }else if(userInput == "decrypt"){
            decrypt(cipher);
        }else if(userInput == "run"){
            encrypt(cipher);
            decrypt(cipher);
            check_file();
        }
        else{ //error state
            std::cout << "\nIncorrect Input\n";
            run_vigenereCipher(cipher);
        }*/
    }

    //encript the file
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
        //start encryption----------------------------------------------
        cipher.set_inputFile("../vigenereCipher/files/input.txt");
        std::cout << "\nopen : " << cipher.get_inputFile() << std::endl;
        std::ifstream infile (cipher.get_inputFile());
        std::ofstream outfile;
        cipher.set_count(-1);
        outfile.open ("../vigenereCipher/files/output.txt");
        while(getline (infile,userInput)){
            for(char& c : userInput){
                cipher::alpha test = cipher.get_keyLetter();
                char out = test + c;
                outfile << out;
            }
            outfile << '\n';
        }
        outfile.close();
    }
    //decrypt the file
    void decrypt(vigenereCipher& cipher){
        //start the decrytion
        std::string userInput;
        std::cout << "\nStart Read file Test:\n";
        cipher.set_inputFile("../vigenereCipher/files/output.txt");
        std::ifstream einfile (cipher.get_inputFile());
        std::ofstream eoutfile;
        eoutfile.open ("../vigenereCipher/files/decryptedOutput.txt");
        cipher.set_count(-1);
        while(getline (einfile,userInput)){
            for(char& c : userInput){
                cipher::alpha test = cipher.get_keyLetter();
                char out = test - c;
                eoutfile << out;
            }
            eoutfile << '\n';
        }
        eoutfile.close();
    }
    //compare the input and output of the decrypter
    void check_file(){
        bool flag = true;
        std::string value1, value2;
        std::ifstream infile ("../vigenereCipher/files/input.txt");
        std::ifstream outfile ("../vigenereCipher/files/decryptedOutput.txt");
        while(getline(infile,value1)){
            getline(outfile,value2);
            if(value1 == value2){
                std::cout << value1 << "  =  " << value2 << std::endl;
            }else{
                flag = false;
                break;
            }
        }
        if(flag == true){
            std::cout << " -----------Correct!---------- " << std::endl;
        }else{
            std::cout << value1 << "  --------------Incorrect--------------  " << value2 << std::endl;
        }

    }

    //check if the key is correct
    bool check_key(vigenereCipher& cipher){
        for(char& c : cipher.get_key()){
            if(!std::isalpha(c)){
                return false;
            }
        }
        return true;
    }

    //overload the + operator
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
                outChar = value +'a'-1;
            }
        }
        return outChar;
    }

    //overload the - operator
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



