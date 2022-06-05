#include <iostream>
#include <fstream>
#include <string>
#include "ppm.h"


using namespace std;


float* image::ReadPPM(const char * filename, int * w, int * h) {
	string p;
	int rgb;
	ifstream myfile(filename, ios::binary);
	if (myfile) {
		myfile >> p >> (*w) >> (*h) >> rgb;
		myfile.get();
		cout << p << " " << "Width: " << *w << ", Height: " << *h << ", rgb: " << rgb << endl;
		unsigned int size = (*w) * (*h) * 3; 
		if (p != "P6") { 
			cerr << "This isnt P6." << "\n";
			system("pause");
			return NULL;
		}
		if (rgb != 255) { 
			cerr << "This isnt 255." << "\n";
			system("pause");
			return NULL;
		}
		float* farray = new float[size]; 
		cout << "size " << size << endl;
		for (unsigned int i = 0; i < size; i++) {
		
			farray[i] = (myfile.get()) / 255.0f;  
		}
		myfile.close();
		system("pause");
		return farray;
	}
	else {
		cerr << "Unable to open file " << "\n";
		system("pause");
	}
	return 0;

}

bool image::WritePPM(const float * data, int w, int h, const char * filename) {
	ofstream writter(filename, ios::binary);
	if (writter) {
		string magicNumber = "P6";
		int maxNumber = 255;
		writter << magicNumber << " " << w << " " << h << " " << maxNumber << "\n"; 
		for (size_t i = 0; i < w * h * 3; i++) {
			char toWrite = (char)((unsigned char)(data[i] * 255.f));
			writter.write(&toWrite, 1);
		}
		writter.close();
		return true;
	}
	else {
		std::cerr << "Failed to open File: " << filename << std::endl;
		return false;
	}
}
