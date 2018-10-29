#ifndef INC_vigenereCipher_H
#define INC_vigenereCipher_H

#include <iostream>
#include <string>
#include <stack>

namespace cipher{
    //enum class builds the key
    enum class alpha{a=1,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};

    class vigenereCipher{
    public:
        //ctor
        vigenereCipher();

        //getters and setters----------------------------------------
        //set the key
        void set_key(std::string key);
        //return the key
        std::string get_key() const;
        //set the input file path
        void set_inputFile(std::string key);
        //get the output file path
        std::string get_inputFile() const;
        void set_outputFile(std::string key);
        //get the output file path
        std::string get_outputFile() const;
        //set the char for a key
        void set_keyLetter(char letter);
        // return the key as a alpha type
        alpha get_keyLetter();
        //set the count for key
        void set_count(int count);
        //set the text char
        void set_textLetter(char letter);
        //return a char of the text
        char get_textLetter() const;

    private:
        //variables
        std::string key;
        std::string inputFile;
        std::string outputfile;
        char keyLetter;
        char textLetter;
        int keyCount;
    };
    //free functions
    //run the cipher
    void run_vigenereCipher(vigenereCipher& cipher);
    //encrypt the file
    void encrypt(vigenereCipher& cipher);
    //decrypt the file
    void decrypt(vigenereCipher& cipher);
    //check the key for wrong characters
    bool check_key(vigenereCipher& cipher);
    //open file
    void openFile(vigenereCipher& cipher);
    //check if files are ==
    void check_file();

    //overload operators
    char &operator+(alpha& a, char& b);
    char &operator-(alpha& a, char& b);
} //end cipher namespace
#endif
