#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <array>
#include <map>



using namespace std;

int main()
{
	vector<char> firstElement;
	vector<char> secondElement;
	multimap<string, string> dna;
	string line;
	ifstream myfile;
	myfile.open("3jze_seq.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{

			if (line[6] == '-' || line[8] == '-')
			{
				//myfile.ignore(1);
				continue;
			}
			firstElement.push_back(line[6]);
			secondElement.push_back(line[8]);
			cout << line[6] << " " << line[8] << endl;
		}
		myfile.close();
	}
	else
		cout << "Unable to open a file \n";

	for (int i = 0; i < (firstElement.size() / 4); i = i + 4)
	{
		string first;
		string second;
		for (int j = 0; j < 4; j++)
		{
			first.push_back(firstElement[i + j]);
		}
		for (int g = 0; g < 4; g++)
		{
			second.push_back(secondElement[i + g]);
		}
		dna.insert(pair <string, string>(first, second));
	}
	multimap<string, string> ::iterator iterator;
	for (iterator = dna.begin(); iterator != dna.end(); iterator++)
	{
		cout << iterator->first << "	" << iterator->second << endl;
	}
	while (1)
	{
		string value;
		cout << "Please enter the DNA sequence you want to search for or type q to quit " << "\n";
		cin >> value;
		if (value == "q")
		{
			break;
		}
		else if (dna.find(value)== dna.end())
		{
			cout << "There is no such a sequence\n";
			continue;
		}
		auto iterator = dna.find(value);
		cout << "For the sequence:" << "\n" << iterator->first << "\n" << "The shape is:" << "\n"
			<< iterator->second << "\n";

	}
	return 0;
}

