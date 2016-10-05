#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;


#define BUFF_SIZE 400

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	cout << "Declarando variáveis\n";
	fstream lusiadas;

	char buff[BUFF_SIZE];
	
	cout << "Abrindo arquivo\n";
	lusiadas.open("lusiadas.txt");
	
	cout << "Lendo uma linha\n";
	lusiadas.read(&buff[0], BUFF_SIZE);
	
	cout << "Mostrando 400 caracteres\n";
	cout.write(buff, BUFF_SIZE);
	
	cout << "\n\nSizeof(char): " << sizeof(char);
	
	
	lusiadas.close();
	return 0;
}


