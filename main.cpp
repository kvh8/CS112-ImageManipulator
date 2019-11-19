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
	//int number_choice;
	string choice;
	string line1;
	int width = 0;
	int height = 0;
	string line2;
	string line3;
	string line4;
	string in_file_name;
	string out_file_name;
	vector<int> data_vector;
	vector<vector<int>> image_vector;

	//User Input/Output/Choice

	cout << "Provide the name of the ppm file you would like to read from" << endl;
	cin >> in_file_name;

	cout << "Provide the name of the file you would like to write to" << endl;
	cin >> out_file_name;

	//choice cout/cin
	/*
	cout << "Would you like to add an effect to your image? (press 'y' for yes or 'n' for no)" << endl;
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

	getline(infile, line2, ' ');
	width = stoi(line2);

	getline(infile, line3);
	height = stoi(line3);

	getline(infile, line4);


	while (infile.good() == true)
	{
		
		int value = 0;
		infile >> value;
		data_vector.push_back(value); 
		
		// The above does the same as below
		/*getline(infile, line4);
		istringstream data_row{ line4 };

		while (data_row.good() == true)
		{
			string temp_data;

			getline(data_row, temp_data, ' ');

			if (temp_data.length() > 0)
			{
				data_vector.push_back(stoi(temp_data));
			}

		}*/
	}
	
	while (image_vector.size() < (height))
	{	
		vector<int> temp;
		for (int i = 0; i < data_vector.size(); i++)
		{		
			if (temp.size() < (width * 3))
			{
				temp.push_back(data_vector[i]);
			}
			else
			{
				image_vector.push_back(temp);
				temp.clear();
				temp.push_back(data_vector[i]);
			}
		}
		
	}


	// Mirror

	/*for (int i = 0; i < image_vector.size(); i++)
	{
		for (int j = 0, k = (image_vector[i].size() - 1); j < image_vector[i].size() && k >= 0; j++, k--)
		{
			image_vector[i][j] = image_vector[i][k];
			image_vector[i][k] = image_vector[i][j];
		}
	}*/
	
	// Vertical Flip

	/*for (int i = 0; i < image_vector.size(); i++)
	{
		for (int j = 0, k = (image_vector[i].size() - 1); j < (image_vector[i].size() / 2) && k >= (image_vector[i].size() / 2); j+= 3, k-= 3)
		{
			int back_blue = image_vector[i][k];
			int back_green = image_vector[i][k - 1];
			int back_red = image_vector[i][k - 2];
			int front_red = image_vector[i][j];
			int front_green = image_vector[i][j + 1];
			int front_blue = image_vector[i][j + 2];

			image_vector[i][j] = back_red;
			image_vector[i][j + 1] = back_green;
			image_vector[i][j + 2] = back_blue;
			image_vector[i][k] = front_blue;
			image_vector[i][k - 1] = front_green;
			image_vector[i][k - 2] = front_red;
		}
	}*/

	// Horizontal Flip

	for (int i = 0; i < image_vector.size(); i++)
	{
		for (int j = (image_vector.size() - 1), k = 0; j >= (image_vector.size()) && k < (image_vector[i].size() / 2); j--, k += 3)
		{	
			int top_red = image_vector[i][k];
			int top_green = image_vector[i][k + 1];
			int top_blue = image_vector[i][k + 2];
			int bottom_red = image_vector[j][k];
			int bottom_green = image_vector[j][k + 1];
			int bottom_blue = image_vector[j][k + 2];

			image_vector[i][k] = bottom_red;
			image_vector[i][k + 1] = bottom_green;
			image_vector[i][k + 2] = bottom_blue;
			image_vector[j][k] = top_red;
			image_vector[j][k + 1] = top_green;
			image_vector[j][k + 2] = top_blue;


			/*int top = image_vector[j][i];
			int bottom = image_vector[image_vector[j].size() - 1 - i][i];

			image_vector[j][i] = bottom;
			image_vector[image_vector[j].size() - 1 - i][i] = top;


			for (int k = 0; k < image_vector[i].size(); k++)
			{
				int top = image_vector[i][k];
				int bottom = image_vector[j][k];

				image_vector[i][k] = bottom;
				image_vector[j][k] = top;
			}*/

		}
	}


	// Blur
	/*
	For each pixel in a given row, set the pixel's red value to the average of itself and its horizontally adjacent neighbors 
	(i.e. i + 1, i - 1). For border cases, just take the average of the singular neighbor.
			a. Do the same procedure for the pixel's green and blue values
	For each pixel in a given column, set the pixel's red value to be the average of itself and its vertically adjacent neighbors 
	(i.e. j + 1, j - 1). For border cases, just take the average of the singular neighbor. 
			a. Do the same procedure for the pixel's green and blue values. Do this 10 times to get an extreme blur like the 
			one depicted in my image.
	*/
	/*for (int i = 0; i < image_vector.size(); i++)
	{
		for (int j = 0; j < image_vector[i].size(); j+= 3)
		{
			int neighbor_r = j + 3;
			int neighbor_l = j - 3;
			int neighbor_d = i + 1;
			int neighbor_u = i - 1;

			if (neighbor_l < 0)
			{
				image_vector[i][j] = (image_vector[i][j] + image_vector[i][neighbor_r]) / 2;
			}
			else if (neighbor_r > image_vector[i].size() - 1)
			{
				image_vector[i][j] = (image_vector[i][j] + image_vector[i][neighbor_l]) / 2;
			}
			else
			{
				image_vector[i][j] = (image_vector[i][j] + image_vector[i][neighbor_l] + image_vector[i][neighbor_r]) / 3;
			}

			if (neighbor_u < 0)
			{
				image_vector[i][j] = (image_vector[i][j] + image_vector[neighbor_d][j]) / 2;
			}
			else if (neighbor_d > image_vector.size() - 1)
			{
				image_vector[i][j] = (image_vector[i][j] + image_vector[neighbor_u][j]) / 2;
			}
			else
			{
				image_vector[i][j] = (image_vector[i][j] + image_vector[neighbor_d][j] + image_vector[neighbor_u][j]) / 3;
			}
		}
	}*/

	// Pixlate
	/*
	To pixelate an image, take a reference pixel P and a distance D and make all pixels adjacent to P 
	in a DxD block the same as P. Then, skip over D pixels and repeat the process for a new P. 
	For example, given a D of 2, here is how we would pixelate the following matrix:
	*/
	/*for (int i = 0; i < image_vector.size(); i+= 3)
	{
		for (int j = 0; i < image_vector[i].size(); j+= 3)
		{
			int right = j + 1;
			int right1 = j + 2;
			int below = i + 1;
			int below1 = i + 2;

			//reference pixel is j = 0
			//distance is three

			int red = image_vector[i][j];
			int red2 = image_vector[below][j];
			int red3 = image_vector[below1][j];
			int green = image_vector[i][right];
			int green1 = image_vector[below][right];
			int green2 = image_vector[below1][right];
			int blue = image_vector[i][right1];
			int blue1 = image_vector[below][right1];
			int blue2 = image_vector[below1][right1];

			image_vector[below][j] = red;
			image_vector[below1][j] = red;
			image_vector[i][right] = red;
			image_vector[below][right] = red;
			image_vector[below1][right];
			image_vector[i][right1] = red;
			image_vector[below][right1] = red;
			image_vector[below1][right1] = red;

		}
	}*/

	// Rotate 90 degrees

	/*
		This one is probably the most conceptually difficult. Essentially, you will need to turn the first row 
		into the last column, the 2nd row into the 2nd to last column, etc. until you turn the last row into the 
		first column. Remember to also change your image's dimensions (2nd line in PPM file)!
	*/

		//switch height and width
		/*int temp = height;
		height = width;
		width = height;*/


// My while loop for multiple effects

/*	while (choice != "n")
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
	*/

	infile.close();







	
	//Output file

	outfile.open(out_file_name);

	outfile << line1 << endl
		<< line2 << endl
		<< line3 << endl
		<< line4 << endl;

	
	
	/*for (int i = 0; i < data_vector.size(); i++)
	{
		outfile << data_vector[i] << ' ';
	}*/
	
	

	for (int i = 0; i < image_vector.size(); i++)
	{
		for (int j = 0; j < image_vector[i].size(); j++)
		{
			outfile << image_vector[i][j] << ' ';
		}
		outfile << endl;
	}
	


	outfile.close();


}