#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;


int main(int argc, char* argv[])
{
//Your program should prompt the user for an input and output 
//file as well as the operation that the user would like to perform

	ifstream infile;
	ofstream outfile;
	string choice;
	string line1;
	string line2;
	string line3;
	string line4;
	string in_file_name;
	string out_file_name;
	vector<int> data_vector;

	cout << "Provide the name of the ppm file you would like to read from" << endl;
	cin >> in_file_name;

	cout << "Provide the name of the file you would like to write to" << endl;
	cin >> out_file_name;

	cout << "Select the image effect you want:" << endl
		<< "***Image Effects * **" << endl
		<< "1. Remove Red" << endl
		<< "2. Remove Blue" << endl
		<< "3. Remove Green" << endl
		<< "4. Negate Red" << endl
		<< "5. Negate Blue" << endl
		<< "6. Negate Green" << endl
		<< "7. Grayscale" << endl;
	cin >> choice




}