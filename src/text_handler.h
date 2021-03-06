#ifndef TEXT_HANDLER
#define TEXT_HANDLER

#include <iostream>
#include <fstream>
#include <time.h>
#include <random>

using namespace std;

long int file_size(char *filename);

mt19937 txt(1493 + time(NULL));

void random_text(const char *filename, char *buffer, long int buffer_size){

	long int size_of_file = file_size( (char *) filename);

	uniform_int_distribution<int> dist_file(0, size_of_file-1);


	ifstream file(filename, ios::binary | ios::ate);

	if( file.is_open() ){

		file.seekg(dist_file(txt));
		file.read(buffer, buffer_size);

		file.close();
	}
	else{
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
		cout << "File " << filename << " couldn't be open for random text access. Aborting.";

		file.close();
		exit(-1);
	}

}

// This functions gets the size of a file
long int file_size(char *filename){
	
	// First we open the file at the last position
	ifstream file(filename, ios::binary | ios::ate);

	if( file.is_open() ){
		// We discover the number of the position we are (the last one)
		long int size = file.tellg();


		// Closing the file because of error-failure reasons...
		file.close();

		// We return the place of the last position of 
		// the file, which may be the size of it
		return size;
	}

	else{
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
		cout << "File " << filename << " couldn't be open for size determining. Aborting.";

		file.close();
		exit(-1);
	}

}

#endif 