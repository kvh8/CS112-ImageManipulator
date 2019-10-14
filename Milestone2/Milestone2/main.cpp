#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{

	ifstream infile;
	ofstream outfile;
	int choice;
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

	/*
	Will need to change this to a loop that asks the user if they want to add another affect to the output.ppm
	
	cout << "Select the image effect you want:" << endl
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

	/*
	for (int i = 0; i < data_vector.size(); i += 3)
	{
		data_vector[i] = 0;
	}
	*/

	//Remove Green

	/*
	for (int i = 1; i < data_vector.size(); i += 3)
	{
		data_vector[i] = 0;
	}
	*/

	//Remove Blue

	/*
	for (int i = 2; i < data_vector.size(); i += 3)
	{
		data_vector[i] = 0;
	}
	*/

	//Negate Red

	/*
	for (int i = 0; i < data_vector.size(); i += 3)
	{
		data_vector[i] = 255 - data_vector[i];
	}
	*/

	//Negate Green

	/*
	for (int i = 1; i < data_vector.size(); i += 3)
	{
		data_vector[i] = 255 - data_vector[i];
	}
	*/

	//Negate Blue

	/*
	for (int i = 2; i < data_vector.size(); i += 3)
	{
		data_vector[i] = 255 - data_vector[i];
	}
	*/

	//Grayscale

	/*for (int i = 0; i < data_vector.size(); i += 3)
	{
		int red = i;
		int green = i + 1;
		int blue = i + 2;
		int average = (data_vector[red] + data_vector[green] + data_vector[blue]) / 3;

		//Maybe if statement instead

		if (data_vector[red] != average || data_vector[green] != average || data_vector[blue] != average)
		{
			data_vector[red] = average;
			data_vector[green] = average;
			data_vector[blue] = average;
		}

		**Problem with this was it only changed the first three values and never went to next three
		
		for (int j = 0; j <= 2; j++)
		{
			data_vector[j] = average;
		}

	}
	*/






}
