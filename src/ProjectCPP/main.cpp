/*
2019-2020
PRODROMOS KAMPOURIDIS 3140065
*/


#include "FilterLinear.h"
#include "FilterGamma.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

int main(int argc, char** argv) {
	vector<Filter *> filters = vector<Filter *>();
	char input[256];
	string fileimage;
	if (argc < 2){ 
		cout << "Load single image" << endl;
		cin.getline(input, 256);
		fileimage = string(input);
	}
	else {
		Color rgb1 = (0, 0, 0);
		Color rgb2 = (0, 0, 0);  
		int i = 1;
		while (i < argc - 1) { 
			if (strcmp(argv[i], "-f") != 0) {
				cout << "Wrong Input" << endl;
				system("pause");
				return 11;
			}
			else {
				i++;
				if (i + 2 <= argc - 1 && strcmp(argv[i], "gamma") == 0) {
					i++;
					FilterGamma *g = new FilterGamma((float)atof(argv[i]));
					filters.push_back(g);
				}
				else if(i + 7 <= argc - 1 && strcmp(argv[i], "linear") == 0) {
					rgb1.x = (float)atof(argv[++i]); 
					rgb1.y = (float)atof(argv[++i]); 
					rgb1.z = (float)atof(argv[++i]);
					rgb2.x = (float)atof(argv[++i]);
					rgb2.y = (float)atof(argv[++i]);
					rgb2.z = (float)atof(argv[++i]);
					FilterLinear *l = new FilterLinear(rgb1,rgb2);
					filters.push_back(l);
				}
				else {
					cout << "Wrong input" << i << endl;
					system("pause");
					return 11;
				}
				i++; 
			}
		}

		fileimage = string(argv[argc - 1]);
	}
	size_t pos = fileimage.rfind(".");
	string  imagename = fileimage.substr(0, pos);
	string  imagetype = fileimage.substr(pos);
	string outfile = imagename + "_filtered" + imagetype;
	
	Image inputimage = Image();
	if (!inputimage.load(fileimage, "ppm")) {
		cout << "Error opening file: " << fileimage << "\n";
		system("pause");
		return 11;
	}
	cout << "Image dimensions are: " << inputimage.getWidth() << " x " << inputimage.getHeight() << endl;

	Image output = inputimage;
	cout << "Applying the filters" << endl;
	for (int i = 0; i < filters.size(); i++) {
		output = (*filters[i] << output);
	}
	if (!output.save(outfile, "ppm"))
		cout << "Could not create filtered image\n";
	else cout << "Filtered image created with filename: " << outfile << "\n";

	for (unsigned int i = 0; i < filters.size(); i++) {
		delete filters[i];
	}
	system("PAUSE");
	return 0;
}