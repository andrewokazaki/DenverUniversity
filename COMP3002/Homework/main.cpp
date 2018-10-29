#include <iostream>
#include "tickTackToe/tickTackToe.h"
#include "vigenereCipher/vigenereCipher.h"
#include "test/vigenereCipherTest.h"

int main() {

try{
	//create new cipher
	cipher::vigenereCipher cipher;
	//test::test_vigenereCipher(cipher); //test
	cipher::run_vigenereCipher(cipher); //run
}catch (std::exception e){
	std::cerr << "caught: " << e.what() << '\n';
}catch(...){
	std::cerr << "caught unknown error \n"; 
}
	std::cout<<"DONE"<<std::endl;
    return 0;
}
