// DateList1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include  <iostream>
#include <iomanip>


int main()
{
	int YEAR1{};
	int YEAR2{};
	int MONTH1{};
	int MONTH2{};
	int DAY1{};
	int DAY2{};

	const int January{ 1 };
	const int Feburary{ 2 };
	const int March{ 3 };
	const int Apirl{ 4 };
	const int May{ 5 };
	const int June{ 6 };
	const int July{ 7 };
	const int August{ 8 };
	const int September{ 9 };
	const int October{ 10 };
	const int November{ 11 };
	const int December{ 12 };

	int SY{};
	int EY{};
	int SM{};
	int EM{};
	int SD{};
	int ED{};
	int DIM{};


	std::cin >> YEAR1;
	std::cin.ignore();
	std::cin >> MONTH1;
	std::cin.ignore();
	std::cin >> DAY1;
	std::cin.ignore();

	std::cout << '\n' << std::endl;
	std::cout << '\n' << std::endl;


	std::cin >> YEAR2;
	std::cin.ignore();
	std::cin >> MONTH2;
	std::cin.ignore();
	std::cin >> DAY2;
	std::cin.ignore();


	std::cout << '\n' << std::endl;
	std::cout << '\n' << std::endl;


	///switches input depending on earliest date entered first or second

	if (YEAR1 != YEAR2)
	{

		if (YEAR1 < YEAR2)
		{
			SY = YEAR1;
			SM = MONTH1;
			SD = DAY1;
			EY = YEAR2;
			EM = MONTH2;
			ED = DAY2;
		}

		if (YEAR1 > YEAR2)
		{
			SY = YEAR2;
			SM = MONTH2;
			SD = DAY2;
			EY = YEAR1;
			EM = MONTH1;
			ED = DAY1;
		}
	}
	if (MONTH1 != MONTH2 && YEAR1 == YEAR2)
	{
		if (YEAR1 == YEAR2 && MONTH1 > MONTH2)
		{
			SY = YEAR2;
			SM = MONTH2;
			SD = DAY2;
			EY = YEAR1;
			EM = MONTH1;
			ED = DAY1;

		}
		else
		{
			SY = YEAR1;
			SM = MONTH1;
			SD = DAY1;
			EY = YEAR2;
			EM = MONTH2;
			ED = DAY2;
		}
	}
	if (YEAR1 == YEAR2 && MONTH1 == MONTH2 && DAY1 > DAY2)
	{


		SY = YEAR2;
		SM = MONTH2;
		SD = DAY2;
		EY = YEAR1;
		EM = MONTH1;
		ED = DAY1;
	}
	if (YEAR1 == YEAR2 && MONTH1 == MONTH2 && DAY1 < DAY2)
	{
		SY = YEAR1;
		SM = MONTH1;
		SD = DAY1;
		EY = YEAR2;
		EM = MONTH2;
		ED = DAY2;
	}
	///makes it s only certain years and correct moths may be used
	if (SY > 1901 && EY < 2099 && SM <= 12)
	{
		while (SY <= EY)
		{
			///assigns months with corect number of days
			if (SY == EY && SM == EM && SD == ED)
			{
				break;
			}
			if (SM == 4 || SM == 6 || SM == 9 || SM == 11)

			{
				DIM = 30;
			}


			if (SM == 2)
			{
				DIM = 28;
			}

			if (SM == 1 || SM == 3 || SM == 5 || SM == 7 || SM == 8 || SM == 10 || SM == 12)
			{
				DIM = 31;
			}
			///stops proram if invalid day depending on month was entered
			if (SD > DIM)
			{
				std::cout << "invalid date entered" << std::endl;
				break;
			}
			///cycles through days until it hits last day of month
			while (SD < DIM)
			{
				SD++;
				std::cout << std::setfill('0');
				std::cout << SY << "-" << std::setw(2) << SM << "-" << std::setw(2) << SD << std::endl;
				if (SY == EY && SM == EM && SD == ED)
				{
					break;
				}
			}
			///cycles through months until end of year
			if (SM<12)
			{
				///breaks out of loop if start date already equals end date so to not add another month
				if (SY == EY && SM == EM && SD == ED)
				{
					break;
				}
				SM++;
				SD = 1;
				std::cout << std::setfill('0');
				std::cout << SY << "-" << std::setw(2) << SM << "-" << std::setw(2) << SD << std::endl;
			}
			///cycles through years at change of years
			if (SY < EY && SM == 12 && SD == DIM)
			{
				SY++;
				SM = 1;
				SD = 1;
				std::cout << std::setfill('0');
				std::cout << SY << "-" << std::setw(2) << SM << "-" << std::setw(2) << SD << std::endl;
				if (SY == EY && SM == EM && SD == ED)
				{
					break;
				}

			}


		}

	}
	else
	{
		std::cout << "invalid date entered" << std::endl;
	}

    return 0;
}

