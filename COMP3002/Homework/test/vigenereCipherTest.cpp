#include "vigenereCipherTest.h"

#include <iostream>
#include <string>
#include <fstream>
#include <stack>

namespace test{
    void test_vigenereCipher(cipher::vigenereCipher& cipher){
        std::cout << "Start Test:\n\n";
        std::cout << "Start Key Test:\n";
        cipher.set_key("t3st");
        if(cipher::check_key(cipher)) {
                std::cout << "Key : " << cipher.get_key() << std::endl;
        }else{
                std::cout << "Key was wrong :" << cipher.get_key() << std::endl;
        }

        cipher.set_key("t!est");
        if(cipher::check_key(cipher)) {
                std::cout << "Key :" << cipher.get_key() << std::endl;
        }else{
                std::cout << "Key was wrong :" << cipher.get_key() << std::endl;
        }

        cipher.set_key("DFADS");
        if(cipher::check_key(cipher)) {
                 std::cout << "Key :" << cipher.get_key() << std::endl;
        }else{
                 std::cout << "Key was wrong :" << cipher.get_key() << std::endl;
        }

        std::cout << "\nStart char compare Test:\n";
        cipher.set_keyLetter('A');
        cipher.set_textLetter('b');
        //std::cout << "key char : " << cipher.get_keyLetter() << std::endl;
        std::cout << "text char : " << cipher.get_textLetter() << std::endl;



        std::cout << (int)'b' - (int)cipher::alpha::a - (int)'a'<< std::endl;
        std::cout << ((int)'b'-(int)'a')<< std::endl;


        std::cout <<"Test : a + y =  z";
        cipher::alpha test = cipher::alpha::a;
        char g = 'y';
        char c = test + g-1;

        std::cout <<"\n\nTest : w + d = a";
        test = cipher::alpha::d;
        g = 'w';
        c = test + g;


       //------------------------------------------------------------------------------------

        std::cout << "\nStart Read file Test:\n";
        cipher.set_inputFile("../vigenereCipher/files/input.txt");
        std::cout << "open : " << cipher.get_inputFile() << std::endl;
        std::string userInput;
        std::ifstream infile (cipher.get_inputFile());
        std::ofstream outfile;
        outfile.open ("../vigenereCipher/files/output.txt");
        cipher.set_count(-1);
        while(getline (infile,userInput)){
            for(char& c : userInput){
                cipher::alpha test = cipher.get_keyLetter();
                char out = test + c;
                outfile << out;
                std::cout << out << " "<< c <<  std::endl;
            }
            outfile << '\n';
        }
        outfile.close();
        infile.close();
        //---------------------------------------------------

        std::cout << "\nStart Read file Test:\n";
        cipher.set_inputFile("../vigenereCipher/files/output.txt");
        std::cout << "open : " << cipher.get_inputFile() << std::endl;
        std::ifstream einfile (cipher.get_inputFile());
        std::ofstream eoutfile;
        eoutfile.open ("../vigenereCipher/files/decryptedOutput.txt");
        cipher.set_count(-1);
        while(getline (einfile,userInput)){
            for(char& c : userInput){
                cipher::alpha test = cipher.get_keyLetter();
                char out = test - c;
                eoutfile << out;
                std::cout << out << " "<< c <<  std::endl;
            }
            eoutfile << '\n';
        }
    }
}
