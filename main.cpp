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

	//User Input/Output/Choice

	cout << "Provide the name of the ppm file you would like to read from" << endl;
	cin >> in_file_name;

	cout << "Provide the name of the file you would like to write to" << endl;
	cin >> out_file_name;

	/*cout << "Select the image effect you want:" << endl
		<< "***Image Effects * **" << endl
		<< "1. Remove Red" << endl
		<< "2. Remove Blue" << endl
		<< "3. Remove Green" << endl
		<< "4. Negate Red" << endl
		<< "5. Negate Blue" << endl
		<< "6. Negate Green" << endl
		<< "7. Grayscale" << endl
		<< "*** Choose the number of the effect you want (1 = remove red)" << endl;
	cin >> choice;
	*/


	// Reading the file

	infile.open(in_file_name);

	if (!infile.good())
	{
		cout << "Error: Could not open file" << endl;

		return 1;
	}

	getline(infile, line1);

	getline(infile, line2);

	getline(infile, line3);


	while (infile.good() == true)
	{
		/*
		int value = 0;
		infile >> value;
		data_vector.push_back(value);
		*/
		// The above does the same as below

		getline(infile, line4);
		istringstream data_row{ line4 };

		while (data_row.good() == true)
		{
			string temp_data;

			getline(data_row, temp_data, ' ');

			if (temp_data.length() > 0)
			{
				data_vector.push_back(stoi(temp_data));
			}

		}

	}


	//Remove Red

	/*for (int i = 0; i < data_vector.size(); i += 3)
	{
		data_vector[i] = 0;
	}
	*/

	//Remove Green

	/*for (int i = 1; i < data_vector.size(); i += 3)
	{
		data_vector[i] = 0;
	}
	*/

	//Remove Blue

	/*for (int i = 2; i < data_vector.size(); i += 3)
	{
		data_vector[i] = 0;
	}
	*/

	//Negate Red

	/*for (int i = 0; i < data_vector.size(); i += 3)
	{
		data_vector[i] = 255 - data_vector[i];
	}
	*/

	//Negate Green

	/*for (int i = 1; i < data_vector.size(); i += 3)
	{
		data_vector[i] = 255 - data_vector[i];
	}
	*/

	//Negate Blue

	/*for (int i = 2; i < data_vector.size(); i += 3)
	{
		data_vector[i] = 255 - data_vector[i];
	}
	*/

	//Grayscale


	infile.close();
	
	//Output file

	outfile.open(out_file_name);

	outfile << line1 << endl
		<< line2 << endl
		<< line3 << endl;

	for (int i = 0; i < data_vector.size(); i++)
	{
		outfile << data_vector[i] << ' ';
	}

	outfile.close();


}