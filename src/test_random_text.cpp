#include "text_handler.h"

int main(){
	srand(time(NULL));


	char filename[] = "lusiadas.txt";

	cout << "\n\nTesting random access for " <<  &filename[0] << "\n\n";

	char text[300];
	random_text("lusiadas.txt", &text[0], 300);

	cout.write(&text[0], 300);

	cout << "\n\n Testing again ";

	/*for(int i=0; i<100000000; i++){
		if((i%10000000) == 0)
			cout << ".";
	}*/
	cout << "\n\n";

	for(int i=0; i<10; i++){
		random_text(&filename[0], &text[0], 300);

		cout.write(&text[0], 300);

		cout << "\n-------------------------------\n";
	}
	cout << "\n\n Test done.\n\n";

}
