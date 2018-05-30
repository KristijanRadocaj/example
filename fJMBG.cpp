// fJMBG.cpp : Defines the entry point for the console application.
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>



using namespace std;

int fJMBG(char *JMBG);

int main()
{
	string jmbg;
	char *JMBG;
	int r=0;
	FILE* f = fopen("cases.txt", "r");

	while (fscanf(f,"%s ", JMBG)!= NULL)
	{
		r = fJMBG(JMBG);

		switch (r)
		{
		case 1:
			cout << r << ": JMBG sadrži znakove razlièite od brojeva.";
			break;
		case 2:
			cout << r << ": Duljina JMBG-a nije jednaka 13.";
			break;
		case 3:
			cout << r << ": Neisparvno unesena godina roðenja.";
			break;
		case 4:
			cout << r << ": Neispravno unesen mejsec roðenja.";
			break;
		case 5:
			cout << r << ": Neispravno unesen dan roðenja.";
			break;
		case 6:
			cout << r << ": Neispravna regija roðenja.";
			break;
		case 7:
			cout << r << ": Krivi kontrolni broj.";
			break;
		default:
			cout << r << ": JMBG je ispravan!";
			break;
		}
		cout << "\n";
	}
	system("pause");
    return 0;
}

int fJMBG(char *JMBG)
{
	int i = 0, god = 0, mm = 0, dd = 0, rr = 0, k = 0, rez = 0;
	bool leap = false;

	while (JMBG[i]-48 != -48)
	{
		if ((JMBG[i] - 48) < 0 || (JMBG[i] - 48) > 9)
		{
			// JMBG sadrži znakove
			return 1;
		}
		i++;
	}
	if (i != 13)
	{
		//JMBG razlièit od 13 znamenki 
		return 2;
	}
	i = 0;
	do
	{
		if (i == 0)
		{
			dd = dd + (JMBG[i] - 48) * 10;
		}
		else if (i == 1)
		{
			dd = dd + (JMBG[i] - 48);
		}
		else if (i == 2)
		{
			mm = mm + (JMBG[i] - 48) * 10;
		}
		else if (i == 3)
		{
			mm = mm + (JMBG[i] - 48);
		}
		else if (i == 4 && (JMBG[i] - 48) == 0)
		{
			god = 2000;
		}
		else if (i == 4 && (JMBG[i] - 48) != 0)
		{
			if ((JMBG[i] - 48) ==9)
			{
				god = 1900;
			}
			else
			{
				//neispravan godina rodjenja
				return 3;
			}
		}
		else if (i == 5)
		{
			if (god == 2000)
			{
				if ((JMBG[i] - 48)>8)
				{
					return 3;
				}
			}
			else
			{
				god = god + (JMBG[i] - 48) * 10;
			}
		}
		else if (i == 6)
		{
			god = god + (JMBG[i] - 48);

		}
		else if ( i == 7)
		{
			rr = rr + (JMBG[i] - 48) * 10;
		}
		else if (i == 8)
		{
			rr = rr + (JMBG[i] - 48);
		}
		else if (i==12)
		{
			k = JMBG[i] - 48;
		}

		i++;
	} while (JMBG[i]-48 != -48);

	if (god % 4 != 0)
	{
		leap = false;
	}
	else if (god % 100 == 0)
	{
		leap = true;
	}
	else if (god % 400 == 0)
	{
		leap = true;
	}
	else
	{
		leap = false;
	}

	if (mm<13)
	{
		switch (mm)
		{
		case 2:
			if (leap == true)
			{
				if (dd>29)
				{
					// dan u mjesecu neispravan
					return 5;
				}
			}
			else
			{
				if (dd>28)
				{
					return 5;
				}
			}
			break;
		case 4:
			if (dd>30)
			{
				return 5;
			}
			break;
		case 6:
			if (dd>30)
			{
				return 5;
			}
			break;
		case 9:
			if (dd>30)
			{
				return 5;
			}
			break;
		case 11:
			if (dd>30)
			{
				return 5;
			}
			break;
		default:
			if (dd>31)
			{
				return 5;
			}
			break;
		}
	}
	else
	{
		//krivo unesen mjesec rodjenja
		return 4;
	}

	if (rr<30 || rr>39)
	{
		//regija je krivo unesena
		if (rr != 3)
		{
			return 6;
		}
		
	}

	rez = (JMBG[0] - 48) * 7 + (JMBG[1] - 48) * 6 + (JMBG[2] - 48) * 5 + (JMBG[3] - 48) * 4 + (JMBG[4] - 48) * 3 + (JMBG[5] - 48) * 2 + (JMBG[6] - 48) * 7 + (JMBG[7] - 48) * 6 + (JMBG[8] - 48) * 5 + (JMBG[9] - 48) * 4 + (JMBG[10] - 48) * 3 + (JMBG[11] - 48) * 2;
	rez = rez % 11;
	rez = 11 - rez;

	if (k != rez)
	{
		//krivi kontrolni broj
		return 7;
	}

	return 0;
}

