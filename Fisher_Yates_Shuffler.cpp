// Fisher_Yates_Shuffler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <numeric>
#include <iostream>
#include <string>
#include <filesystem>
#include "dirent.h"
#include <random>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	random_device rd;
	mt19937 eng(rd());
	ofstream num_sav;
	ifstream num_red;
	int length, res, size=0, tmp;
	vector<int> numbers;
	numbers.reserve(500);
	char *part, *next_part;
	DIR  *dir;
	struct dirent *ent;
	string name = "s7";

	num_sav.open("C:\\Users\\Kage-kun\\Desktop\\rvl\\x64\\Debug\\Exp140715\\"+name+"-SS\\" + name + "-test-num.txt");
	num_red.open("C:\\Users\\Kage-kun\\Desktop\\rvl\\x64\\Debug\\Exp140715\\" + name + "-SS\\" + name + "-rel-num.txt");
	if ((dir = opendir("C:\\Users\\Kage-kun\\Desktop\\rvl\\x64\\Debug\\Exp140715\\s7-SS\\")) != NULL)
	{
		while ((ent=readdir(dir))!=NULL)
		{
			part = strtok_s(ent->d_name,"-", &next_part);
			if (part!=NULL)
			{
				part = strtok_s(0, "-", &next_part);
				if (part!=NULL)
				{
					numbers.push_back(1);
					numbers[size]= atoi(part);
					size++;
				}
				
			}
			
		}
		closedir(dir);
	}
	else
	{
		perror("");
		return EXIT_FAILURE;
	}
	/*length = floor(size / 2);

	for (size_t i = 0; i < length; i++)
	{
		uniform_int_distribution<> result(i, size-1);
		res = result(eng);
		cout << i << " at " << res << " = " << numbers[res] << endl;
		tmp = numbers[i];
		numbers[i] = numbers[res];
		numbers[res] = tmp;
	}

	sort(numbers.begin(), numbers.end());

	for (size_t i = 0; i < length; i++)
	{
		num_sav << numbers[i] << endl;
		num_sav.flush();
	}*/
	int rel_num;
	num_red >> rel_num;
	for (size_t i = 0; i < size; i++)
	{
		if (numbers[i]!= rel_num)
		{
			num_sav << numbers[i] << endl;
			num_sav.flush();
		}
		else if (numbers[i]== rel_num)
		{
			num_red >> rel_num;
		}
	}
	numbers.clear();
	num_sav.close();
	num_red.close();
	system("pause");
    return 0;
}

