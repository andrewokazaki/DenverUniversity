#ifndef INC_vigenereCipher_H
#define INC_vigenereCipher_H

#include <iostream>
#include <string>
#include <stack>

namespace cipher{

    enum class alpha{a=1,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};

    class vigenereCipher{
    public:
        vigenereCipher();

        //getters and setters
        void set_key(std::string key);
        std::string get_key() const;
        void set_inputFile(std::string key);
        std::string get_inputFile() const;
        void set_outputFile(std::string key);
        std::string get_outputFile() const;
        void set_keyLetter(char letter);
        alpha get_keyLetter();
        void set_count(int count);
        void set_textLetter(char letter);
        char get_textLetter() const;

    private:
        std::string key;
        std::string inputFile;
        std::string outputfile;
        char keyLetter;
        char textLetter;
        int keyCount;
    };

    void run_vigenereCipher(vigenereCipher& cipher);
    void encrypt(vigenereCipher& cipher);
    void decrypt(vigenereCipher& cipher);
    bool check_key(vigenereCipher& cipher);
    void openFile(vigenereCipher& cipher);
//overload operator
    char &operator+(alpha& a, char& b);
    char &operator-(alpha& a, char& b);
} //end cipher namespace
#endif
