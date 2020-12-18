#define _CRT_SECURE_NO_WARNINGS
#include "Highscore.h"

std::stringstream updatescore(int number, int point, char* nameP)
{
	int pointH[5];
	int pointplayer = point;


	char name[5][10];

	char nameplayer[10];

	for (int loop = 0; loop < 10; loop++)
	{
		nameplayer[loop] = nameP[loop];
	}
	FILE* p;

	p = fopen("score.txt", "r");
	for (int loop = 0; loop < 5; loop++)
	{
		fscanf(p, "%s", &name[loop]);
		fscanf(p, "%d", &pointH[loop]);
	}
	fclose(p);

	for (int loop = 0; loop < 5; loop++)
	{
		if (pointplayer > pointH[loop])
		{


			if (loop < 4)
			{
				if (number == 1)
				{
					pointH[4] = pointH[3];
				}
				else
				{
					for (int loopname = 0; loopname < 10; loopname++)
					{
						name[4][loopname] = name[3][loopname];
					}
				}

			}

			if (loop < 3)
			{
				if (number == 1)
				{
					pointH[3] = pointH[2];
				}
				else
				{
					for (int loopname = 0; loopname < 10; loopname++)
					{
						name[3][loopname] = name[2][loopname];
					}
				}

			}

			if (loop < 2)
			{
				if (number == 1)
				{
					pointH[2] = pointH[1];
				}
				else
				{
					for (int loopname = 0; loopname < 10; loopname++)
					{
						name[2][loopname] = name[1][loopname];
					}
				}

			}

			if (loop < 1)
			{
				if (number == 1)
				{
					pointH[1] = pointH[0];
				}
				else
				{
					for (int loopname = 0; loopname < 10; loopname++)
					{
						name[1][loopname] = name[0][loopname];
					}
				}

			}



			if (number == 1)
			{
				pointH[loop] = pointplayer;
			}
			else
			{
				for (int loopname = 0; loopname < 10; loopname++)
				{
					if (nameplayer[loopname] == ' ')
					{
						nameplayer[loopname] = '_';
					}
					name[loop][loopname] = nameplayer[loopname];


				}
			}

			break;

		}
	}

	p = fopen("score.txt", "w");
	for (int loop = 0; loop < 5; loop++)
	{

		fprintf(p, "%s %d\n", name[loop], pointH[loop]);
	}
	fclose(p);

	std::stringstream Hscorename, Hscorescore;
	Hscorename << "1        " << name[0] << "\n"
		<< "2        " << name[1] << "\n"
		<< "3        " << name[2] << "\n"
		<< "4        " << name[3] << "\n"
		<< "5        " << name[4] << "\n";
	//hightscname.setString(Hscorename.str());

	Hscorescore << "  -->   " << pointH[0] << "\n"
		<< "  -->   " << pointH[1] << "\n"
		<< "  -->   " << pointH[2] << "\n"
		<< "  -->   " << pointH[3] << "\n"
		<< "  -->   " << pointH[4] << "\n";
	//hightscscore.setString(Hscorescore.str());

	if (number == 0)
	{
		return Hscorename;
	}
	if (number == 1)
	{
		return Hscorescore;
	}
}