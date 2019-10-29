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
	int number_choice;
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

	cout << "Would you like to add an effect to your image? (press 'y' for yes or 'n' for no)" << endl;
	cin >> choice;

	
	
	//For effect chaining, put it in a while loop that asks the user if they want to continue, and uses 
	//their choice to remain in the loop.

	/*
		cout << "Would you like to add an effect to your image? (press y for yes or n for no)" << endl;
		cin >> choice;
		while(choice == "y")
		{
			cout << "Select the image effect you want:" << endl
		<< "***Image Effects * **" << endl
		<< "1. Remove Red" << endl
		<< "2. Remove Blue" << endl
		<< "3. Remove Green" << endl
		<< "4. Negate Red" << endl
		<< "5. Negate Blue" << endl
		<< "6. Negate Green" << endl
		<< "7. Grayscale" << endl
		<< "8. Random Noise" << endl
		<< "9. High Contrast" << endl
		<< "*** Choose the number of the effect you want (1 = remove red)" << endl;
		cin >> choice;

		//Here you will add the switch case for the choices

		//After, add final question
		cout << "Would you like to add another effect to your image? ((press y for yes or n for no)" << endl;
		}
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

	// My while loop for multiple effects

	while (choice != "n")
	{
		cout << "Select the image effect you want:" << endl
			<< "***Image Effects * **" << endl
			<< "1. Remove Red" << endl
			<< "2. Remove Blue" << endl
			<< "3. Remove Green" << endl
			<< "4. Negate Red" << endl
			<< "5. Negate Blue" << endl
			<< "6. Negate Green" << endl
			<< "7. Grayscale" << endl
			<< "8. Random Noise" << endl
			<< "9. High Contrast" << endl
			<< "*** Choose the number of the effect you want (1 = remove red)" << endl;
		cin >> number_choice;

		switch (number_choice)
		{
		case 1:			//Remove Red
			for (int i = 0; i < data_vector.size(); i += 3)
			{
				data_vector[i] = 0;
			}
			break;

		case 2:			//Remove Green
			for (int i = 1; i < data_vector.size(); i += 3)
			{
				data_vector[i] = 0;
			}
			break;

		case 3:			//Remove Blue
			for (int i = 2; i < data_vector.size(); i += 3)
			{
				data_vector[i] = 0;
			}
			break;

		case 4:			//Negate Red
			for (int i = 0; i < data_vector.size(); i += 3)
			{
				data_vector[i] = 255 - data_vector[i];
			}
			break;

		case 5:			//Negate Green
			for (int i = 1; i < data_vector.size(); i += 3)
			{
				data_vector[i] = 255 - data_vector[i];
			}
			break;

		case 6:			//Negate Blue
			for (int i = 2; i < data_vector.size(); i += 3)
			{
				data_vector[i] = 255 - data_vector[i];
			}
			break;

		case 7:			//Grayscale
			for (int i = 0; i < data_vector.size(); i += 3)
			{
				int red = i;
				int green = i + 1;
				int blue = i + 2;
				int average = (data_vector[red] + data_vector[green] + data_vector[blue]) / 3;

				if (data_vector[red] != average || data_vector[green] != average || data_vector[blue] != average)
				{
					data_vector[red] = average;
					data_vector[green] = average;
					data_vector[blue] = average;
				}
			}
			break;

		case 8:			//Random Noise
			for (int i = 0; i < data_vector.size(); i++)
			{
				int random = (rand() % 20 + (-10));
				int new_num = data_vector[i] + random;

				if (new_num < 0)
				{
					data_vector[i] = 0;
				}
				else if (new_num > 255)
				{
					data_vector[i] = 255;

				}
				else
				{
					data_vector[i] = new_num;
				}
			}
			break;

		case 9:			//High Contrast
			for (int i = 0; i < data_vector.size(); i++)
			{
				if (data_vector[i] > (255 / 2))
				{
					data_vector[i] = 255;
				}
				else
				{
					data_vector[i] = 0;
				}
			}
			break;

		default:
			cout << "Error in choice, Please choose a number between 1 and 9" << endl;
		}

		cout << "Would you like to add another effect to your image? ((press y for yes or n for no)" << endl;
		cin >> choice;
	}
	
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