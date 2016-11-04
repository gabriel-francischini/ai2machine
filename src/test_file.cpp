#include <iostream>
#include <fstream>
using namespace std;

#define BUFF_SIZE 400

int main(){
	
	// Since the Lusiads were written in Portuguese,
	// we need this piece for correctly displaying it in
	// portuguese windows command prompt
	setlocale(LC_ALL, "Portuguese");
	
	// This holds the file itself with the text
	fstream lusiadas;

	// This buff is for reading the file
	char buff[BUFF_SIZE];

	// This actually opens the text for reading
	lusiadas.open("lusiadas.txt");
	
	// This reads 10 junks of BUFF_SIZE lenght
	// out of the text file and put it on buff[],
	// then we print it to the console
	for(int i=0; i<10;i++){

		// This is the actual reading instruction
		lusiadas.read(&buff[0], BUFF_SIZE);

		// This one is for printing to the stdout
		// we could not use "cout <<" because that
		// is a not-counted method. i.e. it tries
		// to guess the lenght of the text and expects
		// a null-terminating character, but we
		// don't have such a character in our text
		// Also, it's a lot safer for buffer overflow hacking attacks
		cout.write(buff, BUFF_SIZE);
	}

	for(int i=0; i<(BUFF_SIZE*10); i++)
		cout << "\b";

	cout << "Test okay!";

	// Close the text file
	lusiadas.close();
	return 0;


}