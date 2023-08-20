#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

class Rubik
{
private:
	char cube[6][3][3] = {
		{{' ', ' ', ' '}, {' ', 'y', ' '}, {' ', ' ', ' '}},
		{{' ', ' ', ' '}, {' ', 'r', ' '}, {' ', ' ', ' '}},
		{{' ', ' ', ' '}, {' ', 'g', ' '}, {' ', ' ', ' '}},
		{{' ', ' ', ' '}, {' ', 'o', ' '}, {' ', ' ', ' '}},
		{{' ', ' ', ' '}, {' ', 'b', ' '}, {' ', ' ', ' '}},
		{{' ', ' ', ' '}, {' ', 'w', ' '}, {' ', ' ', ' '}}};

public:
	Rubik(int a[6][3][3])
	{
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					cube[i][j][k] = a[i][j][k];
	}

	void printCube()
	{
		cout << "==============================" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "        ";
			for (int j = 0; j < 3; j++)
				cout << cube[0][i][j] << " ";
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			for (int c = 1; c <= 4; c++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << cube[c][i][j] << " ";
				}
				cout << "  ";
			}
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			cout << "        ";
			for (int j = 0; j < 3; j++)
				cout << cube[5][i][j] << " ";
			cout << endl;
		}
	}

	int wSideOnFace()
	{
		for (int i = 0; i < 5; i++)
		{
			if (cube[i][0][1] == 'w')
				return i;
			if (cube[i][1][0] == 'w')
				return i;
			if (cube[i][1][2] == 'w')
				return i;
			if (cube[i][2][1] == 'w')
				return i;
		}
		return 5;
	}
	void wCross1()
	{
		// cout << "hehe debugging" << endl;
		while (cube[5][0][1] != 'w' ||
			cube[5][1][0] != 'w' ||
			cube[5][1][2] != 'w' ||
			cube[5][2][1] != 'w')
		{
			if (wSideOnFace() == 0)
			{
				if (cube[0][0][1] == 'w')
				{
					if (cube[5][2][1] == 'w')
						yellowccw();
					else
					{
						bluecw();
						bluecw();
					}
				}
				if (cube[0][1][0] == 'w')
				{
					if (cube[5][1][0] == 'w')
						yellowccw();
					else
					{
						redcw();
						redcw();
					}
				}
				if (cube[0][2][1] == 'w')
				{
					if (cube[5][0][1])
						yellowccw();
					else
					{
						greencw();
						greencw();
					}
				}
				if (cube[0][1][2] == 'w')
				{
					if (cube[5][1][2])
						yellowccw();
					else
					{
						orangecw();
						orangecw();
					}
				}
			}
			else if (wSideOnFace() == 1)
			{
				if (cube[1][2][1] == 'w')
				{
					redcw();
					bluecw();
				}
				else if (cube[1][1][0] == 'w')
				{
					redcw();
					yellowcw();
					redccw();
				}
				else if (cube[1][1][2] == 'w')
				{
					redccw();
					yellowcw();
					redcw();
				}
				if (cube[1][0][1] == 'w')
				{
					if (mbcube[4][0][1] == 'w')
					{
						redccw();
						bluecw();
						redccw();
					}
					/*else if (cube[2][0][1] == 'w')
					{
						redcw();
						greenccw();
						redcw();
					}*/
					else
					{
						redcw();
						greenccw();
						redcw();
					}
				}
			}
			else if (wSideOnFace() == 2)
			{
				if (cube[2][2][1] == 'w')
				{
					greencw();
					redcw();
				}
				else if (cube[2][1][0] == 'w')
				{
					greencw();
					yellowcw();
					greenccw();
				}
				else if (cube[2][1][2] == 'w')
				{
					greenccw();
					yellowcw();
					greencw();
				}
				if (cube[2][0][1] == 'w')
				{
					if (cube[1][0][1] == 'w')
					{
						greenccw();
						redcw();
						greenccw();
					}
					else if (cube[3][0][1] == 'w')
					{
						greencw();
						orangeccw();
						greencw();
					}
					else
					{
						greencw();
						orangeccw();
						greencw();
					}
				}
			}
			else if (wSideOnFace() == 3)
			{
				if (cube[3][2][1] == 'w')
				{
					orangecw();
					greencw();
				}
				else if (cube[3][1][0] == 'w')
				{
					orangecw();
					yellowcw();
					orangeccw();
				}
				else if (cube[3][1][2] == 'w')
				{
					orangeccw();
					yellowcw();
					orangecw();
				}
				if (cube[3][0][1] == 'w')
				{
					if (cube[2][0][1] == 'w')
					{
						orangeccw();
						greencw();
						orangeccw();
					}
					else if (cube[4][0][1] == 'w')
					{
						orangecw();
						blueccw();
						orangecw();
					}
					else
					{
						orangecw();
						blueccw();
						orangecw();
					}
				}
			}
			else if (wSideOnFace() == 4)
			{
				if (cube[4][2][1] == 'w')
				{
					bluecw();
					orangecw();
				}
				else if (cube[4][1][0] == 'w')
				{
					bluecw();
					yellowcw();
					blueccw();
				}
				else if (cube[4][1][2] == 'w')
				{
					blueccw();
					yellowcw();
					bluecw();
				}
				if (cube[4][0][1] == 'w')
				{
					if (cube[3][0][1] == 'w')
					{
						blueccw();
						orangecw();
						blueccw();
					}
					else if (cube[1][0][1] == 'w')
					{
						bluecw();
						redccw();
						bluecw();
					}
					else
					{
						bluecw();
						redccw();
						bluecw();
					}
				}
			}
		}
	}
	void wCross2()
	{
		while (cube[1][2][1] != 'r' || cube[2][2][1] != 'g' || cube[3][2][1] != 'o' || cube[4][2][1] != 'b')
		{
			if (cube[1][2][0] == cube[1][2][2] && cube[2][2][0] == cube[2][2][2] && cube[3][2][0] == cube[3][2][2] && cube[4][2][0] == cube[4][2][2] && cube[1][2][0] != cube[1][2][1] && cube[2][2][0] != cube[2][2][1] && cube[3][2][0] != cube[3][2][1] && cube[4][2][0] != cube[4][2][1])
			{
				if (cube[1][2][1] == cube[4][2][0] || cube[2][2][0] == cube[2][2][1])
				{
					white_pll_z();
				}
				else
				{
					white_pll_h();
				}
			}
			if (cube[1][2][0] == cube[1][2][1])
			{
				white_pll_uaub(1);
			}
			if (cube[2][2][0] == cube[2][2][1])
			{
				white_pll_uaub(2);
			}
			if (cube[3][2][0] == cube[3][2][1])
			{
				white_pll_uaub(3);
			}
			if (cube[4][2][0] == cube[4][2][1])
			{
				white_pll_uaub(4);
			}
		}
	}

	int wCornerOnFace()
	{
		for (int i = 0; i < 5; i++)
		{
			if (cube[i][0][0] == 'w')
				return i;
			if (cube[i][0][2] == 'w')
				return i;
			if (cube[i][2][0] == 'w')
				return i;
			if (cube[i][2][2] == 'w')
				return i;
		}
		return 5;
	}
	void wFace1()
	{ // plugging in corners
		while (cube[5][0][0] != 'w' ||
				cube[5][0][2] != 'w' ||
				cube[5][2][0] != 'w' ||
				cube[5][2][2] != 'w')
		{
			if (wCornerOnFace() == 0) {
				if (cube[0][0][0] == 'w') {
					redcw();
					yellowccw();
					redccw();
				}
				else if (cube[0][0][2] == 'w') {
					bluecw();
					yellowccw();
					blueccw();
				}
				else if (cube[0][2][0] == 'w') {
					orangecw();
					yellowccw();
					orangeccw();
				}
				else if (cube[0][2][2] == 'w') {
					greencw();
					yellowccw();
					greenccw();
				}
			}
			else if (cube[1][2][0] == 'w' || cube[1][2][2] == 'w' ||
				cube[2][2][0] == 'w' || cube[2][2][2] == 'w' ||
				cube[3][2][0] == 'w' || cube[3][2][2] == 'w' ||
				cube[4][2][0] == 'w' || cube[4][2][2] == 'w')
			{
				switch(wCornerOnFace()) {
					case 1:
						if (cube[1][2][0] == 'w') {
							blueccw();
							yellowcw();
							bluecw();
						}
						if (cube[1][2][2] == 'w') {
							greencw();
							yellowccw();
							greenccw();
						}
					case 2:
						if (cube[2][2][0] == 'w') {
							redccw();
							yellowcw();
							redcw();
						}
						if (cube[2][2][2] == 'w') {
							orangecw();
							yellowccw();
							orangeccw();
						}
					case 3:
						if (cube[3][2][0] == 'w') {
							greenccw();
							yellowcw();
							greencw();
						}
						if (cube[3][2][2] == 'w') {
							bluecw();
							yellowccw();
							blueccw();
						}
					case 4:
						if (cube[4][2][0] == 'w') {
							orangeccw();
							yellowcw();
							orangecw();
						}
						if (cube[4][2][2] == 'w') {
							redcw();
							yellowccw();
							redccw();
						}
				}
			}
			else {
				switch(wCornerOnFace()) {
					case 1:
						if (cube[1][0][0] == 'w') {
							yellowccw();
							blueccw();
							yellowcw();
							bluecw();
						}
						if (cube[1][0][2] == 'w') {
							yellowcw();
							greencw();
							yellowccw();
							greenccw();
						}
					case 2:
						if (cube[2][0][0] == 'w') {
							yellowccw();
							redccw();
							yellowcw();
							redcw();
						}
						if (cube[2][0][2] == 'w') {
							yellowcw();
							orangecw();
							yellowccw();
							orangeccw();
						}
					case 3:
						if (cube[3][0][0] == 'w') {
							yellowccw();
							greenccw();
							yellowcw();
							greencw();
						}
						if (cube[3][0][2] == 'w') {
							yellowcw();
							bluecw();
							yellowccw();
							blueccw();
						}
					case 4:
						if (cube[1][0][0] == 'w') {
							yellowccw();
							orangeccw();
							yellowcw();
							orangecw();
						}
						if (cube[1][0][2] == 'w') {
							yellowcw();
							redcw();
							yellowccw();
							redccw();
						}
				}
			}
		}
	}
	void white_pll_diag()
	{
		greencw();
		orangecw();
		whiteccw();
		orangeccw();
		whiteccw();
		orangeccw();
		whitecw();
		orangeccw();
		greenccw();
		orangecw();
		whitecw();
		rightccw();
		whiteccw();
		orangeccw();
		greencw();
		orangecw();
		greenccw();
	}
	void white_pll_headlights(int n)
	{
		if (n == 1)
		{
			orangecw();
			whitecw();
			rightccw();
			whiteccw();
			orangeccw();
			greencw();
			orangecw();
			orangecw();
			whiteccw();
			orangeccw();
			whiteccw();
			orangecw();
			whitecw();
			orangeccw();
			greenccw();
		}
		if (n == 2)
		{
			bluecw();
			whitecw();
			blueccw();
			whiteccw();
			blueccw();
			redcw();
			bluecw();
			bluecw();
			whiteccw();
			blueccw();
			whiteccw();
			bluecw();
			whitecw();
			blueccw();
			redccw();
		}
		if (n == 3)
		{
			orangecw();
			whitecw();
			orangeccw();
			whiteccw();
			orangeccw();
			bluecw();
			orangecw();
			orangecw();
			whiteccw();
			orangeccw();
			whiteccw();
			orangecw();
			whitecw();
			orangeccw();
			blueccw();
		}
		if (n == 4)
		{
			greencw();
			whitecw();
			greenccw();
			whiteccw();
			greenccw();
			orangecw();
			greencw();
			greencw();
			whiteccw();
			greenccw();
			whitecw();
			greencw();
			whitecw();
			greenccw();
			orangeccw();
		}
		// R U R' U' R' F R2 U' R' U' R U R' F'
	}
	void white_pll_h()
	{
		orangeccw();
		orangeccw();
		redccw();
		redccw();
		whitecw();
		orangeccw();
		orangeccw();
		redccw();
		redccw();
		whitecw();
		whitecw();
		orangeccw();
		orangeccw();
		redccw();
		redccw();
		whitecw();
		orangeccw();
		orangeccw();
		redccw();
		redccw();
	}
	void white_pll_uaub(int n)
	{
		// 1 = red, 2 = green, 3 = orange, 4 = blue
		int x, r;
		if (n == 1)
		{
			x = 3;
			r = 4;
		}
		if (n == 2)
		{
			x = 4;
			r = 1;
		}
		if (n == 3)
		{
			x = 1;
			r = 2;
		}
		if (n == 4)
		{
			x = 2;
			r = 3;
		}
		if (cube[x][1][1] == cube[r][0][1])
		{
			inputcw(r);
			inputcw(r);
			whitecw();
			inputcw(r);
			whitecw();
			inputccw(r);
			whiteccw();
			inputccw(r);
			whiteccw();
			inputccw(r);
			whitecw();
			inputccw(r);
			// R2 U R U R' U' R' U' R' U R'
		}
		else
		{
			inputcw(r);
			whiteccw();
			inputcw(r);
			whitecw();
			inputcw(r);
			whitecw();
			inputcw(r);
			whiteccw();
			inputccw(r);
			whiteccw();
			inputcw(r);
			inputcw(r);
			// R U' R U R U R U' R' U' R2
		}
	}
	void white_pll_z()
	{
		whiteccw();
		whiteccw();
		whitecw();
		whitecw();
		whitecw();
		whitecw();
		whitecw();
		whitecw();
		whitecw();
		whitecw();
		whitecw();
		whitecw();
		whitecw();
		whitecw();
		whitecw();
		whitecw();
		whitecw();
		whitecw();
		whiteccw();
		whiteccw();
		whitecw();
		whitecw();
		whitecw();
		whitecw();
		whitecw();
		whitecw();
	}
	void wFace2()
	{ // fixing corners
		while (true)
		{
			if (cube[1][2][0] != cube[1][2][2] && cube[2][2][0] != cube[2][2][2] && cube[3][2][0] != cube[3][2][2] && cube[4][2][0] != cube[4][2][2])
			{
				white_pll_diag();
			}
			if (cube[1][2][0] == cube[1][2][2] && cube[2][2][0] != cube[2][2][2] && cube[3][2][0] != cube[3][2][2] && cube[4][2][0] != cube[4][2][2])
			{
				white_pll_headlights(1); // face green
			}
			if ((cube[1][2][0] != cube[1][2][2] && cube[2][2][0] == cube[2][2][2] && cube[3][2][0] != cube[3][2][2] && cube[4][2][0] != cube[4][2][2]) && cube[1][2][0] == cube[3][2][2])
			{
				white_pll_headlights(2); // green is same face red
			}
			if (cube[1][2][0] != cube[1][2][2] && cube[2][2][0] != cube[2][2][2] && cube[3][2][0] == cube[3][2][2] && cube[4][2][0] != cube[4][2][2])
			{
				white_pll_headlights(3); // face blue
			}
			if (cube[1][2][0] != cube[1][2][2] && cube[2][2][0] != cube[2][2][2] && cube[3][2][0] != cube[3][2][2] && cube[4][2][0] == cube[4][2][2])
			{
				white_pll_headlights(4); // orange
			}
		}
	}

	void white_face() {
		wCross1(); // plugging in edge pieces
		wCross2(); // fixing edge pieces
		wFace1(); // plugging in corner pieces
		wFace2(); // fixing corner pieces
	}

	void oll()
	{
		for (int i = 0; i < 4; i++) {
			if (cube[0][0][0] == 'y' && cube[0][0][1] == 'y' && cube[0][0][2] == 'y' && cube[0][1][0] == 'y' && cube[0][1][1] == 'y' && cube[0][1][2] == 'y' && cube[0][2][1] == 'y' && cube[2][0][0] == 'y' && cube[2][0][2] == 'y')
			{
				oll_u(); //yes
				break;
			}
			if (cube[0][0][1] == 'y' && cube[0][2][1] == 'y' && cube[0][1][0] == 'y' && cube[0][1][2] == 'y' && cube[0][1][1] == 'y' && cube[2][0][0] == 'y' && cube[2][0][2] == 'y' && cube[1][0][2] == 'y' && cube[4][0][0] == 'y')
			{
				oll_pi(); // yes
				break;
			}
			if (cube[0][0][1] == 'y' && cube[0][1][0] == 'y' && cube[0][1][1] == 'y' && cube[0][1][2] == 'y' && cube[0][1][0] == 'y' && cube[0][2][0] == 'y' && cube[1][0][0] == 'y' && cube[4][0][0] == 'y' && cube[3][0][0] == 'y')
			{
				oll_Asune(); //yes
				break;
			}
			if (cube[0][0][1] == 'y' && cube[0][1][0] /*"row 1" */ == 'y' && cube[0][1][1] == 'y' && cube[0][1][2] == 'y' && cube[0][2][0] == 'y' && cube[0][2][1] == 'y' && cube[2][0][2] == 'y' && cube[3][0][2] == 'y' && cube[4][0][2] == 'y')
			{
				oll_sune(); //broken
				break;
			}
			if (cube[0][0][1] == 'y' && cube[0][0][2] == 'y' == cube[0][1][1] && 'y' && cube[0][1][2] == 'y' && cube[0][1][0] == 'y' && cube[0][2][1] == 'y' && cube[0][2][2] = 'y' && cube[2][0][0] == 'y' && cube[4][0][2] == 'y')
			{
				oll_t(); // debugged
				break;
			}
			if (cube[0][0][0] == 'y' && cube[0][0][1] == 'y' && cube[0][1][0] == 'y' && cube[0][1][1] == 'y' &&
				cube[0][1][2] == 'y' && cube[0][2][1] == 'y' && cube[0][2][2] == 'y' && cube[3][0][2] == 'y' && cube[1][0][0] == 'y')
			{
				oll_l();
				break;
			}
			if (cube[0][1][0] == 'y' && cube[2][0][0] == 'y' && cube[0][1][1] == 'y' && cube[0][1][2] == 'y' && cube[0][1][1] == 'y' && cube[0][2][1] == 'y' && cube[2][0][2] == 'y' && cube[3][0][0] == 'y' && cube[3][0][2] == 'y')
			{
				oll_h();
				break;
			}
			if (cube[0][1][1] == 'y' && cube[1][0][1] == 'y' && cube[2][0][1] == 'y' && cube[3][0][1] == 'y' && cube[4][0][1] == 'y') {
				oll_dot();
				break;
			}
			if (cube[0][1][0] == 'y' && cube[0][1][1] == 'y' && cube[0][1][2] == 'y' &&cube[1][0][1] == 'y' && cube[3][0][1] == 'y') {
				oll_i();
				break;
			}
			if (cube[0][1][1] == 'y' && cube[0][1][2] == 'y' && cube[0][2][1] == 'y' && cube[2][0][1] == 'y' && cube[3][0][1] == 'y') {
				oll_LS();
				break;
			}
			yellowccw():
		}
	}
	// OLL ALGO
	void oll_dot()
	{//F R U R' U' F' f R U R' U' f'
		greencw();
		redcw();
		yellowcw();
		redccw();
		yellowccw();
		greenccw();
		yellowccw();
		blueccw();
		redcw();
		yellowcw();
		redccw();
		yellowccw();
		bluecw();
	}
	void oll_i() {
		//F R U R' U' F'
		while (cube[0][0][1] != 'y')
		{
			yellowccw();
		}
		greencw();
		redcw();
		yellowcw();
		redccw();
		yellowccw();
		greenccw();
	}
	void oll_LS() {
		while (cube[0][1][2] != 'y' && cube[0][2][1] != 'y') {
			yellowccw();
		}
		//f R U R' U' f'
		blueccw();
		redcw();
		yellowcw();
		redccw();
		yellowccw();
		bluecw();
	}
	void oll_pi()
	{
		while (cube[1][0][0] != 'y' && cube[1][0][2] != 'y')
		{
			yellowccw();
		}
		greencw();
		yellowcw();
		yellowcw();
		greencw();
		greencw();
		yellowccw();
		greencw();
		greencw();
		yellowccw();
		greencw();
		greencw();
		yellowcw();
		yellowcw();
		greencw();
	}

	void oll_u()
	{ // yes
		while (cube[1][0][0] != 'y')
		{
			yellowccw();
		}
		greencw();
		greencw();
		whitecw();
		greenccw();
		yellowcw();
		yellowcw();
		greencw();
		whiteccw();
		greenccw();
		yellowcw();
		yellowcw();
		greenccw();
	}

	void oll_t()
	{ // yes
		while (cube[1][0][0] != 'y')
		{
			yellowccw();
		}
		greencw();
		orangecw();
		blueccw();
		orangeccw();
		greenccw();
		orangecw();
		bluecw();
		orangeccw();
	}

	void oll_Asune()
	{ // yes
		while (cube[0][0][2] != 'y')
		{
			yellowccw();
		}
		greenccw();
		yellowccw();
		greencw();
		yellowccw();
		greenccw();
		yellowcw();
		yellowcw();
		greencw();
	}

	void oll_h()
	{
		while (cube[2][0][0] != 'y')
		{
			yellowccw();
		}
		greenccw();
		yellowccw();
		greencw();
		yellowccw();
		greenccw();
		yellowcw();
		greencw();
		yellowccw();
		greenccw();
		yellowcw();
		yellowcw();
		greencw();
	}

	void oll_l()
	{
		while (cube[1][0][0] != 'y')
		{
			yellowccw();
		}
		redcw();
		greenccw();
		redccw();
		bluecw();
		redcw();
		greencw();
		redccw();
		blueccw();
	}

	void oll_sune()
	{
		while (cube[0][0][1] != 'y')
		{
			yellowccw();
		}
		greencw();
		yellowcw();
		greenccw();
		yellowcw();
		greencw();
		yellowcw();
		yellowcw();
		greenccw();
	}

	void f2l_find(int x, char y, char t, int s[0][0][0], int o[0][0][0], bool tf = false)
	{ // finds position of y side on edge
		switch (x)
		{
		case 0: // checks the yellow face
			if (cube[0][0][1] == y || cube[0][0][1] == t)
			{
				if (cube[3][0][1] == y || cube[3][0][1] == t)
				{
					if (cube[0][0][1] == y)
					{
						s = cube[0][0][1];
						o = cube[3][0][1];
					}
					else
					{
						s = cube[3][0][1];
						o = cube[0][0][1];
						tf = true;
					}
				}
			}

<<<<<<< HEAD
                                                                 void f2l_find(int x, char y, char t, int s[0][0][0], int o[0][0][0], bool tf = false) { // finds position of y side on edge
                                                                 switch(x);
                                                                 case 0: //checks the yellow face
                                                                     
                                                                 if (cube[0][0][1] == y || cube[0][0][1] == t) {
                                                                 if (cube[4][0][1] == y || cube[4][0][1] == t) {
                                                                    if (cube[0][0][1] == y) {
                                                                        s = cube[0][0][1];
                                                                 o = cube[4][0][1];
                                                                    }
                                                                    else {
                                                                 s = cube[4][0][1];
                                                                 o = cube[0][0][1];
                                                                 tf = true;
                                                                    }
                                                                 }
                                                                 }
                                        
                                                                 else if (cube[0][1][0] == y || cube[0][1][0] == t) {
                                                                 if (cube[1][0][1] == y || cube[1][0][1] == t) {
                                                                 if (cube[0][1][0] == y) {
                                                                 s = cube[0][1][0];
                                                                 o = cube[1][0][1];
                                                                 }
                                                                 else {
                                                                 s = cube[1][0][1];
                                                                 o = cube[0][1][0];
                                                                 tf = true;
                                                                 }
                                                                 }
                                                                 }
                                                                 
                                                                 else if (cube[0][1][2] == y || cube[0][1][2] == t) {
                                                                 if (cube[3][0][1] == y || cube[3][0][1] == t) {
                                                                 if (cube[0][1][2] == y) {
                                                                 s = cube[0][1][2];
                                                                 o = cube[3][0][1];
                                                                 }
                                                                 else {
                                                                 s = cube[3][0][1];
                                                                 o = cube[0][1][2];
                                                                 tf = true;
                                                                 }
                                                                 }
                                                                 }
                                                                 
                                                                 else if (cube[0][2][1] == y || cube[0][2][1] == t) {
                                                                 if (cube[2][0][1] == y || cube[2][0][1] == t) {
                                                                 if (cube[0][2][1] == y) {
                                                                 o = cube[2][0][1];

                                                                 s = cube[0][2][1];
                                                                 }
                                                                 else {
                                                                 s = cube[2][0][1];
                                                                 o = cube[0][2][1];
                                                                 tf = true;
                                                                 }
                                                                 }
                                                                 }
                                                                 
                                                                     case 1: // checks the green face and half of red and orange
                                                                                                                
                                                                     else if (cube[2][1][0] == y || cube[2][1][0] == t) {
                                                                     if (cube[1][1][2] == y || cube[1][1][2] == t) {
                                                                     if (cube[2][1][0] == y) {
                                                                     s = cube[2][1][0];
                                                                 o = cube[1][1][2];

                                                                     }
                                                                     else {
                                                                     s = cube[1][1][2];
                                                                 o = cube[2][1][0];
                                                                 tf = true;
                                                                     }
                                                                     }
                                                                     }
                                                                     
                                                                     else if (cube[2][1][2] == y || cube[2][1][2] == t) {
                                                                     if (cube[3][1][0] == y || cube[3][1][0] == t) {
                                                                     if (cube[2][1][2] == y) {
                                                                     s = cube[2][1][2];
                                                                 o = cube[3][1][0];
                                                                     }
                                                                     else {
                                                                     s = cube[3][1][0];
                                                                 o = cube[2][1][2];
                                                                 tf = true;
                                                                     }
                                                                     }
                                                                     }
                                                                                                                                          
                                                                     case 2: // checks blue face and other half of red and yellow
                                                                    
                                            
                                                                     else if (cube[4][1][0] == y || cube[4][1][0] == t) {
                                                                     if (cube[3][1][2] == y || cube[3][1][2] == t) {
                                                                     if (cube[4][1][0] == y) {
                                                                     s = cube[4][1][0];
                                                                 o = cube[3][1][2];
                                                                     }
                                                                     else {
                                                                     s = cube[3][1][2];
                                                                 o = cube[4][1][0];
                                                                 tf = true;
                                                                     }
                                                                     }
                                                                     }
                                                                     
                                                                     else if (cube[4][1][2] == y || cube[4][1][2] == t) {
                                                                     if (cube[1][1][0] == y || cube[1][1][0] == t) {
                                                                     if (cube[4][1][2] == y) {
                                                                     s = cube[4][1][2];
                                                                 o = cube[1][1][0];
                                                                     }
                                                                     else {
                                                                     s = cube[1][1][0];
                                                                 o = cube[4][1][2];
                                                                 tf = true;
                                                                     }
                                                                     }
                                                                     }
                                                                     
                                                                 default:
                                                                     break;
                                                                    /*for (int i = 0; i < 4; i++) {
                                                                        for(int k = 0; k < 2; k++) {
                                                                 if (cube[i][k][1] == y || cube[i][k][1] == t){
                                                                 if (k == 0 && cube[0][k][1]) {
                                                                 
                                                                 x = cube[i][k][1]];
            }
                                                                 }
            if (cube[i][k][2] == y || cube[i][k][1] == t){
                x = cube[i][k][2];
            }
            if (cube[i][k][0] == y || cube[i][k][1] == t){
                x = cube[i][k][0]];
            }
                                                                        }
                                                                    }*/
                                                                 }
	void f2l() {
		//algorithm
                                                                 int s[0][0][0];
                                                                 int o[0][0][0];
                                                                 bool g = false;
                                                                 
                                                                 else {
                                                                 f2lfind(0, 'g', 'r', s, o, g);
                                                                 if(s[1] == 'g' && o[1] == 'r') {
                                                                 break;
                                                                 }
                                                                 if (g == true) { //if the edge is on yellow face, solves
                                                                 back: if(o[1] == '0') {
                                                                 while (cube[2][0][1] != 'g' && cube[0][1][0] != 'r') { //rotates until the case is true
                                                                 yellowcw();
                                                                 
                                                                 }
                                                                 yellowccw();
                                                                 redccw();
                                                                 yellowccw();
                                                                 redcw();
                                                                 yellowcw();
                                                                 greencw();
                                                                 yellowcw();
                                                                 greenccw();
                                                                 }
                                                                 else if(s[1] == '0') {
                                                                 while (cube[1][0][1] != 'r' && cube[0][2][1] != 'g') { //rotates until the case is true
                                                                 yellowcw();
                                                                 }
                                                                 yellowcw();
                                                                 greencw();
                                                                 yellowcw();
                                                                 greenccw();
                                                                 yellowccw();
                                                                 redccw();
                                                                 yellowccw();
                                                                 redcw();
                                                                 }
                                                                 break;
                                                                 }// yellow = 0 green = 1 red = 2 blue = 3 orange = 4 white = 5
                                                                                                                             
                                                                 if(o[1] == 2 && s[1] == 1) {
                                                                 greencw();
                                                                 yellowcw();
                                                                 greenccw();
                                                                 yellowccw();
                                                                 redccw();
                                                                 yellowccw();
                                                                 redcw();
                                                                 goto back;
                                                                 }
                                                                 
                                                                 if(o[1] == 1    && s[1] == 4 || o[1] == 4 && s[1] == 1) {
                                                                 redcw();
                                                                 yellowcw();
                                                                 redccw();
                                                                 yellowccw();
                                                                 blueccw();
                                                                 yellowccw();
                                                                 bluecw();
                                                                 goto back;
                                                                 }
                                                                 
                                                                 if(o[1] == 4 && s[1] == 3 || o[1] == 3 && s[1] == 4) {
                                                                 bluecw();
                                                                 yellowcw();
                                                                 blueccw();
                                                                 yellowccw();
                                                                 orangeccw();
                                                                 yellowccw();
                                                                 orangecw();
                                                                 goto back;
                                                                 }
                                                                 
                                                                 if(o[1] == 3 && s[1] == 2 || o[1] == 2 && s[1] == 3) {
                                                                 orangecw();
                                                                 yellowcw();
                                                                 orangeccw();
                                                                 yellowccw();
                                                                 greenccw();
                                                                 yellowccw();
                                                                 greencw();
                                                                 goto back;
                                                                 }
                                                                 
                                                                 } //next case
                                                                 
                                                                
                                                                 else {
                                                                 f2lfind(0, 'b', 'r', s, o, g);
                                                                 if (g == true) { //if the edge is on yellow face, solves
                                                                 back1: if(o[1] == '0') {
                                                                 while (cube[3][0][1] != 'b' && cube[0][0][1] != 'r') { //rotates until the case is true
                                                                 yellowcw();
                                                                 
                                                                 }
                                                                 yellowcw();
                                                                 redcw();
                                                                 yellowcw();
                                                                 redccw();
                                                                 yellowccw();
                                                                 blueccw();
                                                                 yellowccw();
                                                                 bluecw();
                                                                 }
                                                                 else if(s[1] == '0') {
                                                                 while (cube[1][0][1] != 'r' && cube[0][1][0] != 'b') { //rotates until the case is true
                                                                 yellowcw();
                                                                 }
                                                                 yellowccw();
                                                                 blueccw();
                                                                 yellowccw();
                                                                 bluecw();
                                                                 yellowcw();
                                                                 redcw();
                                                                 yellowcw();
                                                                 redccw();
                                                                 }
                                                                 }
                                                                 
                                                                 if(o[1] == 2 && s[1] == 1 || o[1] == 1 && s[1] == 2) {
                                                                 greencw();
                                                                 yellowcw();
                                                                 greenccw();
                                                                 yellowccw();
                                                                 redccw();
                                                                 yellowccw();
                                                                 redcw();
                                                                 goto back1;
                                                                 }
                                                                 
                                                                 if(o[1] == 4 && s[1] == 1) {
                                                                 redcw();
                                                                 yellowcw();
                                                                 redccw();
                                                                 yellowccw();
                                                                 blueccw();
                                                                 yellowccw();
                                                                 bluecw();
                                                                 goto back1;
                                                                 }
                                                                 
                                                                 if(o[1] == 4 && s[1] == 3 || o[1] == 3 && s[1] == 4) {
                                                                 bluecw();
                                                                 yellowcw();
                                                                 blueccw();
                                                                 yellowccw();
                                                                 orangeccw();
                                                                 yellowccw();
                                                                 orangecw();
                                                                 goto back1;
                                                                 }
                                                                 
                                                                 if(o[1] == 3 && s[1] == 2 || o[1] == 2 && s[1] == 3) {
                                                                 orangecw();
                                                                 yellowcw();
                                                                 orangeccw();
                                                                 yellowccw();
                                                                 greenccw();
                                                                 yellowccw();
                                                                 greencw();
                                                                 goto back1;
                                                                 }
                                                                 }//next case
                                                                 
                                                                 else {
                                                                 f2lfind(0, 'b', 'o', s, o, g);
                                                                 if (g == true) { //if the edge is on yellow face, solves
                                                                 back2: if(o[1] == '0') {
                                                                 while (cube[4][0][1] != 'b' && cube[0][0][1] != 'o') { //rotates until the case is true
                                                                 yellowcw();
                                                                 
                                                                 }
                                                      
                                                                 orangecw();
                                                                 yellowccw();
                                                                 orangeccw();
                                                                 yellowccw();
                                                                 orangecw();
                                                                 yellowcw();
                                                                 bluecw();
                                                                 yellowcw();
                                                                 blueccw();
                                                                 }
                                                                 else if(s[1] == '0') {
                                                                 while (cube[2][0][1] != 'o' && cube[0][2][1] != 'b') { //rotates until the case is true
                                                                 yellowcw();
                                                                 }
                                                          
                                                                 blueccw();
                                                                 yellowccw();
                                                                 bluecw();
                                                                 yellowcw();
                                                                 orangecw();
                                                                 yellowcw();
                                                                 orangeccw();
                                                                 }
                                                                 }
                                                                 
                                                                 if(o[1] == 2 && s[1] == 1 || o[1] == 1 && s[1] == 2) {
                                                                 greencw();
                                                                 yellowcw();
                                                                 greenccw();
                                                                 yellowccw();
                                                                 redccw();
                                                                 yellowccw();
                                                                 redcw();
                                                                 goto back2;
                                                                 }
                                                                 
                                                                 if(o[1] == 4 && s[1] == 1 || s[1] == 4 && o[1] == 1) {
                                                                 redcw();
                                                                 yellowcw();
                                                                 redccw();
                                                                 yellowccw();
                                                                 blueccw();
                                                                 yellowccw();
                                                                 bluecw();
                                                                 goto back2;
                                                                 }
                                                                 
                                                                 if(o[1] == 4 && s[1] == 3) {
                                                                 bluecw();
                                                                 yellowcw();
                                                                 blueccw();
                                                                 yellowccw();
                                                                 orangeccw();
                                                                 yellowccw();
                                                                 orangecw();
                                                                 goto back2;
                                                                 }
                                                                 
                                                                 if(o[1] == 3 && s[1] == 2 || o[1] == 2 && s[1] == 3) {
                                                                 orangecw();
                                                                 yellowcw();
                                                                 orangeccw();
                                                                 yellowccw();
                                                                 greenccw();
                                                                 yellowccw();
                                                                 greencw();
                                                                 goto back2;
                                                                 }
                                                                 }
                                                                 
                                                                 else {
                                                                 f2lfind(0, 'g', 'o', s, o, g);
                                                                 if (g == true) { //if the edge is on yellow face, solves
                                                                 back3: if(o[1] == '0') {
                                                                 while (cube[1][0][1] != 'g' && cube[0][1][0] != 'o') { //rotates until the case is true
                                                                 yellowcw();
                                                                 
                                                                 }
                            
                                                                 orangecw();
                                                                 yellowcw();
                                                                 orangeccw();
                                                                 yellowccw();
                                                                 greenccw();
                                                                 yellowccw();
                                                                 greencw();
                                                                 }
                                                                 else if(s[1] == '0') {
                                                                 while (cube[3][0][1] != 'o' && cube[0][0][1] != 'g') { //rotates until the case is true
                                                                 yellowcw();
                                                                 }
                                                                 yellowccw();
                                                                 greenccw();
                                                                 yellowccw();
                                                                 greencw();
                                                                 yellowcw();
                                                                 orangecw();
                                                                 yellowcw();
                                                                 orangeccw();
                                                                 }
                                                                 }
                                                                 
                                                                 if(o[1] == 2 && s[1] == 1 || o[1] == 1 && s[1] == 2) {
                                                                 greencw();
                                                                 yellowcw();
                                                                 greenccw();
                                                                 yellowccw();
                                                                 redccw();
                                                                 yellowccw();
                                                                 redcw();
                                                                 goto back3;
                                                                 }
                                                                 
                                                                 if(o[1] == 4 && s[1] == 1 || s[1] == 4 && o[1] == 1) {
                                                                 redcw();
                                                                 yellowcw();
                                                                 redccw();
                                                                 yellowccw();
                                                                 blueccw();
                                                                 yellowccw();
                                                                 bluecw();
                                                                 goto back3;
                                                                 }
                                                                 
                                                                 if(o[1] == 4 && s[1] == 3 || o[1] == 3 && s[1] == 4) {
                                                                 bluecw();
                                                                 yellowcw();
                                                                 blueccw();
                                                                 yellowccw();
                                                                 orangeccw();
                                                                 yellowccw();
                                                                 orangecw();
                                                                 goto back3;
                                                                 }
                                                                 
                                                                 if(o[1] == 2 && s[1] == 3) {
                                                                 orangecw();
                                                                 yellowcw();
                                                                 orangeccw();
                                                                 yellowccw();
                                                                 greenccw();
                                                                 yellowccw();
                                                                 greencw();
                                                                 goto back3;
                                                                 }
                                                                 }
                                                                
=======
			else if (cube[0][1][0] == y || cube[0][1][0] == t)
			{
				if (cube[2][0][1] == y || cube[2][0][1] == t)
				{
					if (cube[0][1][0] == y)
					{
						s = cube[0][1][0];
						o = cube[2][0][1];
					}
					else
					{
						s = cube[2][0][1];
						o = cube[0][1][0];
						tf = true;
					}
				}
			}

			else if (cube[0][1][2] == y || cube[0][1][2] == t)
			{
				if (cube[4][0][1] == y || cube[4][0][1] == t)
				{
					if (cube[0][1][2] == y)
					{
						s = cube[0][1][2];
						o = cube[4][0][1];
					}
					else
					{
						s = cube[4][0][1];
						o = cube[0][1][2];
						tf = true;
					}
				}
			}
			else if (cube[0][2][1] == y || cube[0][2][1] == t)
			{
				if (cube[1][0][1] == y || cube[1][0][1] == t)
				{
					if (cube[0][2][1] == y)
					{
						o = cube[1][0][1];
						s = cube[0][2][1];
					}
					else
					{
						s = cube[1][0][1];
						o = cube[0][2][1];
						tf = true;
					}
				}
			}

		case 1: // checks the green face and half of red and orange

			else if (cube[1][1][0] == y || cube[1][1][0] == t)
			{
				if (cube[2][1][2] == y || cube[2][1][2] == t)
				{
					if (cube[1][1][0] == y)
					{
						s = cube[1][1][0];
						o = cube[2][1][2];
					}
					else
					{
						s = cube[2][1][2];
						o = cube[1][1][0];
						tf = true;
					}
				}
			}

			else if (cube[1][1][2] == y || cube[1][1][2] == t)
			{
				if (cube[4][1][0] == y || cube[4][1][0] == t)
				{
					if (cube[1][1][2] == y)
					{
						s = cube[1][1][2];
						o = cube[4][1][0];
					}
					else
					{
						s = cube[4][1][0];
						o = cube[1][1][2];
						tf = true;
					}
				}
			}
		case 2: // checks blue face and other half of red and yellow

			else if (cube[3][1][0] == y || cube[3][1][0] == t)
			{
				if (cube[4][1][2] == y || cube[4][1][2] == t)
				{
					if (cube[3][1][0] == y)
					{
						s = cube[3][1][0];
						o = cube[4][1][2];
					}
					else
					{
						s = cube[4][1][2];
						o = cube[3][1][0];
						tf = true;
					}
				}
			}

			else if (cube[3][1][2] == y || cube[3][1][2] == t)
			{
				if (cube[2][1][0] == y || cube[2][1][0] == t)
				{
					if (cube[3][1][2] == y)
					{
						s = cube[3][1][2];
						o = cube[2][1][0];
					}
					else
					{
						s = cube[2][1][0];
						o = cube[3][1][2];
						tf = true;
					}
				}
			}

		default:
			break;
		}
	}
	void f2l()
	{
		// algorithm
		int s[0][0][0];
		int o[0][0][0];
		bool g = false;

		else
		{
			f2l_find(0, 'g', 'r', s, o, g);
			if (s[1] == 'g' && o[1] == 'r')
			{
				break;
			}
			if (g == true)
			{ // if the edge is on yellow face, solves
			back:
				if (o[1] == '0')
				{
					while (cube[1][0][1] != 'r' && cube[0][1][0] != 'g')
					{ // rotates until the case is true
						yellowcw();
					}
					yellowccw();
					redccw();
					yellowccw();
					redcw();
					yellowcw();
					greencw();
					yellowcw();
					greenccw();
				}
				else if (s[1] == '0')
				{
					while (cube[2][0][1] != 'g' && cube[0][2][1] != 'r')
					{ // rotates until the case is true
						yellowcw();
					}
					yellowcw();
					greencw();
					yellowcw();
					greenccw();
					yellowccw();
					redccw();
					yellowccw();
					redcw();
				}
				break;
			} // yellow = 0 green = 1 red = 2 blue = 3 orange = 4 white = 5

			if (o[1] == 1 && s[1] == 2)
			{
				greencw();
				yellowcw();
				greenccw();
				yellowccw();
				redccw();
				yellowccw();
				redcw();
				goto back;
			}

			if (o[1] == 2 && s[1] == 3 || o[1] == 3 && s[1] == 2)
			{
				redcw();
				yellowcw();
				redccw();
				yellowccw();
				blueccw();
				yellowccw();
				bluecw();
				goto back;
			}

			if (o[1] == 3 && s[1] == 4 || o[1] == 4 && s[1] == 3)
			{
				bluecw();
				yellowcw();
				blueccw();
				yellowccw();
				orangeccw();
				yellowccw();
				orangecw();
				goto back;
			}

			if (o[1] == 4 && s[1] == 1 || o[1] == 1 && s[1] == 4)
			{
				orangecw();
				yellowcw();
				orangeccw();
				yellowccw();
				greenccw();
				yellowccw();
				greencw();
				goto back;
			}

		} // next case

		else
		{
			f2lfind(0, 'b', 'r', s, o, g);
			if (g == true)
			{ // if the edge is on yellow face, solves
			back1:
				if (o[1] == '0')
				{
					while (cube[4][0][1] != 'b' && cube[0][0][1] != 'r')
					{ // rotates until the case is true
						yellowcw();
					}
					yellowcw();
					redcw();
					yellowcw();
					redccw();
					yellowccw();
					blueccw();
					yellowccw();
					bluecw();
				}
				else if (s[1] == '0')
				{
					while (cube[1][0][1] != 'r' && cube[0][1][0] != 'b')
					{ // rotates until the case is true
						yellowcw();
					}
					yellowccw();
					blueccw();
					yellowccw();
					bluecw();
					yellowcw();
					redcw();
					yellowcw();
					redccw();
				}
			}

			if (o[1] == 1 && s[1] == 2 || o[1] == 2 && s[1] == 1)
			{
				greencw();
				yellowcw();
				greenccw();
				yellowccw();
				redccw();
				yellowccw();
				redcw();
				goto back1;
			}

			if (o[1] == 3 && s[1] == 2)
			{
				redcw();
				yellowcw();
				redccw();
				yellowccw();
				blueccw();
				yellowccw();
				bluecw();
				goto back1;
			}

			if (o[1] == 3 && s[1] == 4 || o[1] == 4 && s[1] == 3)
			{
				bluecw();
				yellowcw();
				blueccw();
				yellowccw();
				orangeccw();
				yellowccw();
				orangecw();
				goto back1;
			}

			if (o[1] == 4 && s[1] == 1 || o[1] == 1 && s[1] == 4)
			{
				orangecw();
				yellowcw();
				orangeccw();
				yellowccw();
				greenccw();
				yellowccw();
				greencw();
				goto back1;
			}
		} // next case

		else
		{
			f2lfind(0, 'b', 'o', s, o, g);
			if (g == true)
			{ // if the edge is on yellow face, solves
			back2:
				if (o[1] == '0')
				{
					while (cube[3][0][1] != 'b' && cube[0][0][1] != 'o')
					{ // rotates until the case is true
						yellowcw();
					}

					orangecw();
					yellowcw();
					orangeccw();
					yellowccw();
					blueccw();
					yellowccw();
					bluecw();
				}
				else if (s[1] == '0')
				{
					while (cube[1][0][1] != 'o' && cube[0][2][1] != 'b')
					{ // rotates until the case is true
						yellowcw();
					}

					blueccw();
					yellowccw();
					bluecw();
					yellowcw();
					orangecw();
					yellowcw();
					orangeccw();
				}
			}

			if (o[1] == 1 && s[1] == 2 || o[1] == 2 && s[1] == 1)
			{
				greencw();
				yellowcw();
				greenccw();
				yellowccw();
				redccw();
				yellowccw();
				redcw();
				goto back2;
			}

			if (o[1] == 3 && s[1] == 2 || s[1] == 3 && o[1] == 2)
			{
				redcw();
				yellowcw();
				redccw();
				yellowccw();
				blueccw();
				yellowccw();
				bluecw();
				goto back2;
			}

			if (o[1] == 3 && s[1] == 4)
			{
				bluecw();
				yellowcw();
				blueccw();
				yellowccw();
				orangeccw();
				yellowccw();
				orangecw();
				goto back2;
			}

			if (o[1] == 4 && s[1] == 1 || o[1] == 1 && s[1] == 4)
			{
				orangecw();
				yellowcw();
				orangeccw();
				yellowccw();
				greenccw();
				yellowccw();
				greencw();
				goto back2;
			}
		}

		else
		{
			f2lfind(0, 'g', 'o', s, o, g);
			if (g == true)
			{ // if the edge is on yellow face, solves
			back3:
				if (o[1] == '0')
				{
					while (cube[2][0][1] != 'g' && cube[0][1][0] != 'o')
					{ // rotates until the case is true
						yellowcw();
					}

					orangecw();
					yellowcw();
					orangeccw();
					yellowccw();
					greenccw();
					yellowccw();
					greencw();
				}
				else if (s[1] == '0')
				{
					while (cube[3][0][1] != 'o' && cube[0][0][1] != 'g')
					{ // rotates until the case is true
						yellowcw();
					}

					greenccw();
					yellowccw();
					greencw();
					yellowcw();
					orangecw();
					yellowcw();
					orangeccw();
				}
			}

			if (o[1] == 1 && s[1] == 2 || o[1] == 2 && s[1] == 1)
			{
				greencw();
				yellowcw();
				greenccw();
				yellowccw();
				redccw();
				yellowccw();
				redcw();
				goto back3;
			}

			if (o[1] == 3 && s[1] == 2 || s[1] == 3 && o[1] == 2)
			{
				redcw();
				yellowcw();
				redccw();
				yellowccw();
				blueccw();
				yellowccw();
				bluecw();
				goto back3;
			}

			if (o[1] == 3 && s[1] == 4 || o[1] == 4 && s[1] == 3)
			{
				bluecw();
				yellowcw();
				blueccw();
				yellowccw();
				orangeccw();
				yellowccw();
				orangecw();
				goto back3;
			}

			if (o[1] == 1 && s[1] == 4)
			{
				orangecw();
				yellowcw();
				orangeccw();
				yellowccw();
				greenccw();
				yellowccw();
				greencw();
				goto back3;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
			{
				if (cube[i][0][1] == 'g' || cube[i][0][1] == 'o' && cube[4][0][1] == 'g' || cube[4][0][1] == 'o')
				{
					if (cube[4][0][1] == 'g')
					{
						yellowcw();
						yellowcw();
						if (cube[1][0][1] == 'g' && cube[0][2][1] == 'o')
						{
							yellowcw();
							orangecw();
							yellowcw();
							orangeccw();
							yellowccw();
							greenccw();
							yellowcw();
							greencw();
						}
					}
					else
					{
						s = cube[3][0][1];
						o = cube[0][0][1];
						tf = true;
					}
				}
			}

			else if (cube[0][1][0] == y || cube[0][1][0] == t)
			{
				if (cube[2][0][1] == y || cube[2][0][1] == t)
				{
					if (cube[0][1][0] == y)
					{
						s = cube[0][1][0];
						o = cube[2][0][1];
					}
					else
					{
						s = cube[2][0][1];
						o = cube[0][1][0];
						tf = true;
					}
				}
			}

			else if (cube[0][1][2] == y || cube[0][1][2] == t)
			{
				if (cube[4][0][1] == y || cube[4][0][1] == t)
				{
					if (cube[0][1][2] == y)
					{
						s = cube[0][1][2];
						o = cube[4][0][1];
					}
					else
					{
						s = cube[4][0][1];
						o = cube[0][1][2];
						tf = true;
					}
				}
			}

			else if (cube[0][2][1] == y || cube[0][2][1] == t)
			{
				if (cube[1][0][1] == y || cube[1][0][1] == t)
				{
					if (cube[0][2][1] == y)
					{
						o = cube[1][0][1];

						s = cube[0][2][1];
					}
					else
					{
						s = cube[1][0][1];
						o = cube[0][2][1];
						tf = true;
					}
				}
			}

		case 1: // checks the green face and half of red and orange

			else if (cube[1][1][0] == y || cube[1][1][0] == t)
			{
				if (cube[2][1][2] == y || cube[2][1][2] == t)
				{
					if (cube[1][1][0] == y)
					{
						s = cube[1][1][0];
						o = cube[2][1][2];
					}
					else
					{
						s = cube[2][1][2];
						o = cube[1][1][0];
						tf = true;
					}
				}
			}

			else if (cube[1][1][2] == y || cube[1][1][2] == t)
			{
				if (cube[4][1][0] == y || cube[4][1][0] == t)
				{
					if (cube[1][1][2] == y)
					{
						s = cube[1][1][2];
						o = cube[4][1][0];
					}
					else
					{
						s = cube[4][1][0];
						o = cube[1][1][2];
						tf = true;
					}
				}
			}

		case 2: // checks blue face and other half of red and yellow

			else if (cube[3][1][0] == y || cube[3][1][0] == t)
			{
				if (cube[4][1][2] == y || cube[4][1][2] == t)
				{
					if (cube[3][1][0] == y)
					{
						s = cube[3][1][0];
						o = cube[4][1][2];
					}
					else
					{
						s = cube[4][1][2];
						o = cube[3][1][0];
						tf = true;
					}
				}
			}

			else if (cube[3][1][2] == y || cube[3][1][2] == t)
			{
				if (cube[2][1][0] == y || cube[2][1][0] == t)
				{
					if (cube[3][1][2] == y)
					{
						s = cube[3][1][2];
						o = cube[2][1][0];
					}
					else
					{
						s = cube[2][1][0];
						o = cube[3][1][2];
						tf = true;
					}
				}
			}

		default:
			break;
			/*for (int i = 0; i < 4; i++) {
				for(int k = 0; k < 2; k++) {
		 if (cube[i][k][1] == y || cube[i][k][1] == t){
		 if (k == 0 && cube[0][k][1]) {

		 x = cube[i][k][1]];
}
		 }
if (cube[i][k][2] == y || cube[i][k][1] == t){
x = cube[i][k][2];
}
if (cube[i][k][0] == y || cube[i][k][1] == t){
x = cube[i][k][0]];
}
				}
			}*/
		}
		void f2l()
		{
			// algorithm
			int s[0][0][0];
			int o[0][0][0];
			bool g = false;
			if (cube[2][0][1] == 'g' && cube[0][2][1] == 'r')
			{ // if already in correct position, solves
				yellowccw();
				redccw();
				yellowccw();
				redcw();
				yellowcw();
				greencw();
				yellowcw();
				greenccw();
			}

			else if (cube[1][0][1] == 'r' && cube[0][1][0] == 'g')
			{
				yellowcw();
				greencw();
				yellowcw();
				greenccw();
				yellowccw();
				redccw();
				yellowccw();
				redcw();
			}

			else
			{
				f2lfind(0, 'g', 'r', s, o, g);
				if (s[1] == 'g' && o[1] == 'r')
				{
					break;
				}
				if (g == true)
				{ // if the edge is on yellow face, solves
				back:
					if (o[1] == '0')
					{
						while (cube[1][0][1] != 'r' && cube[0][1][0] != 'g')
						{ // rotates until the case is true
							yellowcw();
						}
						yellowccw();
						redccw();
						yellowccw();
						redcw();
						yellowcw();
						greencw();
						yellowcw();
						greenccw();
					}
					else if (s[1] == '0')
					{
						while (cube[2][0][1] != 'g' && cube[0][2][1] != 'r')
						{ // rotates until the case is true
							yellowcw();
						}
						yellowcw();
						greencw();
						yellowcw();
						greenccw();
						yellowccw();
						redccw();
						yellowccw();
						redcw();
					}
					break;
				}

				if (o[1] == 'g' && s[1] == 'r')
				{
					greencw();
					yellowcw();
					greenccw();
					yellowccw();
					redccw();
					yellowccw();
					redcw();
					goto back;
				}

				if (o[1] == 'r' && s[1] == 'b' || o[1] == 'b' && s[1] == 'r')
				{
					redcw();
					yellowcw();
					redccw();
					yellowccw();
					blueccw();
					yellowccw();
					bluecw();
					goto back;
				}

				if (o[1] == 'b' && s[1] == 'o' || o[1] == 'o' && s[1] == 'b')
				{
					bluecw();
					yellowcw();
					blueccw();
					yellowccw();
					orangeccw();
					yellowccw();
					orangecw();
					goto back;
				}

				if (o[1] == 'o' && s[1] == 'g' || o[1] == 'g' && s[1] == 'o')
				{
					orangecw();
					yellowcw();
					orangeccw();
					yellowccw();
					greenccw();
					yellowccw();
					greencw();
					goto back;
				}

			} // next case

			if (cube[4][0][1] == 'b' && cube[0][0][1] == 'r')
			{
				yellowcw();
				redcw();
				yellowcw();
				redccw();
				yellowccw();
				blueccw();
				yellowccw();
				bluecw();
			}
			if (cube[1][0][1] == 'r' && cube[0][1][0] == 'b')
			{
				yellowccw();
				blueccw();
				yellowccw();
				bluecw();
				yellowcw();
				redcw();
				yellowcw();
				redccw();
			}

			else
			{
				f2lfind(0, 'b', 'r', s, o, g);
				if (g == true)
				{ // if the edge is on yellow face, solves
					if (o[1] == '0')
					{
						while (cube[4][0][1] != 'b' && cube[0][0][1] != 'r')
						{ // rotates until the case is true
							yellowcw();
						}
						yellowcw();
						redcw();
						yellowcw();
						redccw();
						yellowccw();
						blueccw();
						yellowccw();
						bluecw();
					}
					else if (s[1] == '0')
					{
						while (cube[1][0][1] != 'r' && cube[0][1][0] != 'b')
						{ // rotates until the case is true
							yellowcw();
						}
						yellowccw();
						blueccw();
						yellowccw();
						bluecw();
						yellowcw();
						redcw();
						yellowcw();
						redccw();
					}
				}

				if (o[1] == 'g' && s[1] == 'r' || o[1] == 'r' && s[1] == 'g')
				{
					greencw();
					yellowcw();
					greenccw();
					yellowccw();
					redccw();
					yellowccw();
					redcw();
					goto back;
				}

				if (o[1] == 'b' && s[1] == 'r')
				{
					redcw();
					yellowcw();
					redccw();
					yellowccw();
					blueccw();
					yellowccw();
					bluecw();
					goto back;
				}

				if (o[1] == 'b' && s[1] == 'o' || o[1] == 'o' && s[1] == 'b')
				{
					bluecw();
					yellowcw();
					blueccw();
					yellowccw();
					orangeccw();
					yellowccw();
					orangecw();
					goto back;
				}

				if (o[1] == 'o' && s[1] == 'g' || o[1] == 'g' && s[1] == 'o')
				{
					orangecw();
					yellowcw();
					orangeccw();
					yellowccw();
					greenccw();
					yellowccw();
					greencw();
					goto back;
				}
			}

			for (int i = 0; i < 4; i++)
			{
				if (i == 0)
				{
					if (cube[i][0][1] == 'g' || cube[i][0][1] == 'o' && cube[4][0][1] == 'g' || cube[4][0][1] == 'o')
					{
						if (cube[4][0][1] == 'g')
						{
							yellowcw();
							yellowcw();
							if (cube[1][0][1] == 'g' && cube[0][2][1] == 'o')
							{
								yellowcw();
								orangecw();
								yellowcw();
								orangeccw();
								yellowccw();
								greenccw();
								yellowcw();
								greencw();
							}
						}
						if (cube[4][0][1] == 'o')
						{
							yellowcw();
							yellowcw();
							if (cube[3][0][1] == 'o' && cube[0][1][2] == 'g')
							{
								yellowccw();
								greenccw();
								yellowccw();
								greencw();
								yellowccw();
								orangecw();
								yellowcw();
								orangeccw();
							}
						}
					}
				}
				else
				{
					if (cube[i][0][1] == 'g' || cube[i][0][1] == 'o')
					{
					}
					else if (cube[i][1][0] == 'g' || cube[i][1][0] == 'o')
					{
					}
					else if (cube[i][1][2] == 'g' || cube[i][1][2] == 'o')
					{
					}
				}
			}

			if (cube[2][0][1] == 'g' && cube[0][2][1] == 'r')
			{
				yellowccw();
				redccw();
				yellowccw();
				redcw();
				yellowcw();
				greencw();
				yellowcw();
				greenccw();
			}

			if (cube[1][0][1] == 'r' && cube[0][1][0] == 'g')
			{
				yellowcw();
				greencw();
				yellowcw();
				greenccw();
				yellowccw();
				redccw();
				yellowccw();
				redcw();
			}

			if (cube[4][0][1] == 'b' && cube[0][0][1] == 'r')
			{
				yellowcw();
				redcw();
				yellowcw();
				redccw();
				yellowccw();
				blueccw();
				yellowccw();
				bluecw();
			}
			if (cube[1][0][1] == 'r' && cube[0][1][0] == 'b')
			{
				yellowccw();
				blueccw();
				yellowccw();
				bluecw();
				yellowcw();
				redcw();
				yellowcw();
				redccw();
			}
			if (cube[3][0][1] == 'o' && cube[0][1][0] == 'b')
			{
				yellowccw();
				blueccw();
				yellowccw();
				bluecw();
				orangecw();
				yellowcw();
				orangeccw();
			}
			if (cube[4][0][1] == 'b' && cube[0][0][1] == 'o')
			{
				yellowcw();
				orangecw();
				yellowcw();
				orangeccw();
				yellowccw();
				blueccw();
				yellowccw();
				bluecw();
			}
			if (cube[3][0][1] == 'o' && cube[0][1][2] == 'g')
			{
				yellowccw();
				greenccw();
				yellowccw();
				greencw();
				yellowccw();
				orangecw();
				yellowcw();
				orangeccw();
			}
			if (cube[1][0][1] == 'g' && cube[0][2][1] == 'o')
			{
				yellowcw();
				orangecw();
				yellowcw();
				orangeccw();
				yellowccw();
				greenccw();
				yellowcw();
				greencw();
			}
		}

		void pll()
		{
			if (cube[1][0][0] != cube[1][0][2] && cube[2][0][0] != cube[2][0][2] && cube[3][0][0] != cube[3][0][2] && cube[4][0][0] != cube[4][0][2])
			{
				pll_diag();
			} // diag
			if (cube[1][0][0] == cube[1][0][2] && cube[2][0][0] != cube[2][0][2] && cube[3][0][0] != cube[3][0][2] && cube[4][0][0] != cube[4][0][2])
			{
				pll_headlights(1); // face green
			}
			if ((cube[1][0][0] != cube[1][0][2] && cube[2][0][0] == cube[2][0][2] && cube[3][0][0] != cube[3][0][2] && cube[4][0][0] != cube[4][0][2]) && cube[1][0][0] == cube[3][0][2])
			{
				pll_headlights(2); // green is same face red
			}
			if (cube[1][0][0] != cube[1][0][2] && cube[2][0][0] != cube[2][0][2] && cube[3][0][0] == cube[3][0][2] && cube[4][0][0] != cube[4][0][2])
			{
				pll_headlights(3); // face blue
			}
			if (cube[1][0][0] != cube[1][0][2] && cube[2][0][0] != cube[2][0][2] && cube[3][0][0] != cube[3][0][2] && cube[4][0][0] == cube[4][0][2])
			{
				pll_headlights(4); // orange
			}
			// headlights

			if (cube[1][0][0] == cube[1][0][2] && cube[2][0][0] == cube[2][0][2] && cube[3][0][0] == cube[3][0][2] && cube[4][0][0] == cube[4][0][2] && cube[1][0][0] != cube[1][0][1] && cube[2][0][0] != cube[2][0][1] && cube[3][0][0] != cube[3][0][1] && cube[4][0][0] != cube[4][0][1])
			{
				if (cube[1][0][1] == cube[4][0][0])
				{
					pll_z();
				}
				else
				{
					pll_h();
				}
			}
			if (cube[1][0][0] == cube[1][0][1])
			{
				pll_uaub(1);
			}
			if (cube[2][0][0] == cube[2][0][1])
			{
				pll_uaub(2);
			}
			if (cube[3][0][0] == cube[3][0][1])
			{
				pll_uaub(3);
			}
			if (cube[4][0][0] == cube[4][0][1])
			{
				pll_uaub(4);
			}
		}
		//  y r g o b w
		void pll_diag()
		{
			greencw();
			orangecw();
			yellowccw();
			orangeccw();
			yellowccw();
			orangeccw();
			yellowcw();
			orangeccw();
			greenccw();
			orangecw();
			yellowcw();
			rightccw();
			yellowccw();
			orangeccw();
			greencw();
			orangecw();
			greenccw();
		}

		void pll_headlights(int n)
		{
			if (n == 1)
			{
				orangecw();
				yellowcw();
				rightccw();
				yellowccw();
				orangeccw();
				greencw();
				orangecw();
				orangecw();
				yellowccw();
				orangeccw();
				yellowccw();
				orangecw();
				yellowcw();
				orangeccw();
				greenccw();
			}
			if (n == 2)
			{
				bluecw();
				yellowcw();
				blueccw();
				yellowccw();
				blueccw();
				redcw();
				bluecw();
				bluecw();
				yellowccw();
				blueccw();
				yellowccw();
				bluecw();
				yellowcw();
				blueccw();
				redccw();
			}
			if (n == 3)
			{
				orangecw();
				yellowcw();
				orangeccw();
				yellowccw();
				orangeccw();
				bluecw();
				orangecw();
				orangecw();
				yellowccw();
				orangeccw();
				yellowccw();
				orangecw();
				yellowcw();
				orangeccw();
				blueccw();
			}
			if (n == 4)
			{
				greencw();
				yellowcw();
				greenccw();
				yellowccw();
				greenccw();
				orangecw();
				greencw();
				greencw();
				yellowccw();
				greenccw();
				yellowcw();
				greencw();
				yellowcw();
				greenccw();
				orangeccw();
			}
			// R U R' U' R' F R2 U' R' U' R U R' F'
		}

		void pll_h()
		{
			orangeccw();
			orangeccw();
			redccw();
			redccw();
			yellowcw();
			orangeccw();
			orangeccw();
			redccw();
			redccw();
			yellowcw();
			yellowcw();
			orangeccw();
			orangeccw();
			redccw();
			redccw();
			yellowcw();
			orangeccw();
			orangeccw();
			redccw();
			redccw();
		}

		void pll_uaub(int n)
		{
			// 1 = red, 2 = green, 3 = orange, 4 = blue
			int x, r;
			if (n == 1)
			{
				x = 3;
				r = 4;
			}
			if (n == 2)
			{
				x = 4;
				r = 1;
			}
			if (n == 3)
			{
				x = 1;
				r = 2;
			}
			if (n == 4)
			{
				x = 2;
				r = 3;
			}
			if (cube[x][1][1] == cube[r][0][1])
			{
				inputcw(r);
				inputcw(r);
				yellowcw();
				inputcw(r);
				yellowcw();
				inputccw(r);
				yellowccw();
				inputccw(r);
				yellowccw();
				inputccw(r);
				yellowcw();
				inputccw(r);
				// R2 U R U R' U' R' U' R' U R'
			}
			else
			{
				inputcw(r);
				yellowccw();
				inputcw(r);
				yellowcw();
				inputcw(r);
				yellowcw();
				inputcw(r);
				yellowccw();
				inputccw(r);
				yellowccw();
				inputcw(r);
				inputcw(r);
				// R U' R U R U R U' R' U' R2
			}
		}
		void pll_z()
		{//M' U M2 U M2 U M' U2 M2
			orangecw();
			redcw();

			yellowcw();

			orangeccw();
			orangeccw();
			redccw();
			redccw();

			yellowcw();

			orangeccw();
			redccw();
			orangeccw();
			redccw();

			yellowcw();

			orangecw();
			redcw();

			yellowcw();
			yellowcw();

			redccw();
			redccw();
			orangeccw();
			orangeccw();
		}

	private:
		void rotate(char &a, char &b, char &c, char &d)
		{
			char tmp = a;
			a = b;
			b = c;
			c = d;
			d = tmp;
		}
		void clockwise90(
			char &faceTL, char &faceTC, char &faceTR,
			char &faceCL, char &faceCR,
			char &faceBL, char &faceBC, char &faceBR,

			char &sideTL, char &sideTC, char &sideTR,
			char &sideRT, char &sideRC, char &sideRB,
			char &sideBR, char &sideBC, char &sideBL,
			char &sideLB, char &sideLC, char &sideLT)
		{
			// face switching
			rotate(faceTL, faceBL, faceBR, faceTR);
			rotate(faceTC, faceCL, faceBC, faceCR);

			// side switching
			rotate(sideTL, sideLB, sideBR, sideRT);
			rotate(sideTC, sideLC, sideBC, sideRC);
			rotate(sideTR, sideLT, sideBL, sideRB);
		}
		void counterclockwise90(
			char &faceTL, char &faceTC, char &faceTR,
			char &faceCL, char &faceCR,
			char &faceBL, char &faceBC, char &faceBR,

			char &sideTL, char &sideTC, char &sideTR,
			char &sideRT, char &sideRC, char &sideRB,
			char &sideBR, char &sideBC, char &sideBL,
			char &sideLB, char &sideLC, char &sideLT)
		{
			// face switching
			rotate(faceTL, faceTR, faceBR, faceBL);
			rotate(faceTC, faceCR, faceBC, faceCL);

			// side switching
			rotate(sideTL, sideRT, sideBR, sideLB);
			rotate(sideTC, sideRC, sideBC, sideLC);
			rotate(sideTR, sideRB, sideBL, sideLT);
		}
		void yellowcw()
		{
			clockwise90(
				cube[0][0][0], cube[0][0][1], cube[0][0][2],
				cube[0][1][0], cube[0][1][2],
				cube[0][2][0], cube[0][2][1], cube[0][2][2],

				cube[1][0][2], cube[1][0][1], cube[1][0][0],
				cube[4][0][2], cube[4][0][1], cube[4][0][0],
				cube[3][0][2], cube[3][0][1], cube[3][0][0],
				cube[2][0][2], cube[2][0][1], cube[2][0][0]);
		}
		void yellowccw()
		{
			counterclockwise90(
				cube[0][0][0], cube[0][0][1], cube[0][0][2],
				cube[0][1][0], cube[0][1][2],
				cube[0][2][0], cube[0][2][1], cube[0][2][2],

				cube[1][0][2], cube[1][0][1], cube[1][0][0],
				cube[4][0][2], cube[4][0][1], cube[4][0][0],
				cube[3][0][2], cube[3][0][1], cube[3][0][0],
				cube[2][0][2], cube[2][0][1], cube[2][0][0]);
		}
		void redcw()
		{
			clockwise90(
				cube[1][0][0], cube[1][0][1], cube[1][0][2],
				cube[1][1][0], cube[1][1][2],
				cube[1][2][0], cube[1][2][1], cube[1][2][2],

				cube[0][0][0], cube[0][1][0], cube[0][2][0],
				cube[2][0][0], cube[2][1][0], cube[2][2][0],
				cube[5][0][0], cube[5][1][0], cube[5][2][0],
				cube[4][2][2], cube[4][1][2], cube[4][0][2]);
		}
		void redccw()
		{
			counterclockwise90(
				cube[1][0][0], cube[1][0][1], cube[1][0][2],
				cube[1][1][0], cube[1][1][2],
				cube[1][2][0], cube[1][2][1], cube[1][2][2],

				cube[0][0][0], cube[0][1][0], cube[0][2][0],
				cube[2][0][0], cube[2][1][0], cube[2][2][0],
				cube[5][0][0], cube[5][1][0], cube[5][2][0],
				cube[4][2][2], cube[4][1][2], cube[4][0][2]);
		}
		void greencw()
		{
			clockwise90(
				cube[2][0][0], cube[2][0][1], cube[2][0][2],
				cube[2][1][0], cube[2][1][2],
				cube[2][2][0], cube[2][2][1], cube[2][2][2],

				cube[0][2][0], cube[0][2][1], cube[0][2][2],
				cube[3][0][0], cube[3][1][0], cube[3][2][0],
				cube[5][0][2], cube[5][0][1], cube[5][0][0],
				cube[1][2][2], cube[1][1][2], cube[1][0][2]);
		}
		void greenccw()
		{
			counterclockwise90(
				cube[2][0][0], cube[2][0][1], cube[2][0][2],
				cube[2][1][0], cube[2][1][2],
				cube[2][2][0], cube[2][2][1], cube[2][2][2],

				cube[0][2][0], cube[0][2][1], cube[0][2][2],
				cube[3][0][0], cube[3][1][0], cube[3][2][0],
				cube[5][0][2], cube[5][0][1], cube[5][0][0],
				cube[1][2][2], cube[1][1][2], cube[1][0][2]);
		} // yellow, red, green, orange, blue, white(by row)
		void orangecw()
		{
			clockwise90(
				cube[3][0][0], cube[3][0][1], cube[3][0][2],
				cube[3][1][0], cube[3][1][2],
				cube[3][2][0], cube[3][2][1], cube[3][2][2],

				cube[0][2][2], cube[0][1][2], cube[0][0][2],
				cube[4][0][0], cube[4][1][0], cube[4][2][0],
				cube[5][2][2], cube[5][1][2], cube[5][0][2],
				cube[2][2][2], cube[2][1][2], cube[2][0][2]);
		}
		void orangeccw()
		{
			counterclockwise90(
				cube[3][0][0], cube[3][0][1], cube[3][0][2],
				cube[3][1][0], cube[3][1][2],
				cube[3][2][0], cube[3][2][1], cube[3][2][2],

				cube[0][2][2], cube[0][1][2], cube[0][0][2],
				cube[4][0][0], cube[4][1][0], cube[4][2][0],
				cube[5][2][2], cube[5][1][2], cube[5][0][2],
				cube[2][2][2], cube[2][1][2], cube[2][0][2]);
		}
		void bluecw()
		{
			clockwise90(
				cube[4][0][0], cube[4][0][1], cube[4][0][2],
				cube[4][1][0], cube[4][1][2],
				cube[4][2][0], cube[4][2][1], cube[4][2][2],

				cube[0][0][2], cube[0][0][1], cube[0][0][0],
				cube[1][0][0], cube[1][1][0], cube[1][2][0],
				cube[5][2][0], cube[5][2][1], cube[5][2][2],
				cube[3][2][2], cube[3][1][2], cube[3][0][2]);
		}
		void blueccw()
		{
			counterclockwise90(
				cube[4][0][0], cube[4][0][1], cube[4][0][2],
				cube[4][1][0], cube[4][1][2],
				cube[4][2][0], cube[4][2][1], cube[4][2][2],

				cube[0][0][2], cube[0][0][1], cube[0][0][0],
				cube[1][0][0], cube[1][1][0], cube[1][2][0],
				cube[5][2][0], cube[5][2][1], cube[5][2][2],
				cube[3][2][2], cube[3][1][2], cube[3][0][2]);
		}
		void whitecw()
		{
			clockwise90(
				cube[5][0][0], cube[5][0][1], cube[5][0][2],
				cube[5][1][0], cube[5][1][2],
				cube[5][2][0], cube[5][2][1], cube[5][2][2],

				cube[1][2][0], cube[1][2][1], cube[1][2][2],
				cube[2][2][0], cube[2][2][1], cube[2][2][2],
				cube[3][2][0], cube[3][2][1], cube[3][2][2],
				cube[4][2][0], cube[4][2][1], cube[4][2][2]);
		}
		void whiteccw()
		{
			counterclockwise90(
				cube[5][0][0], cube[5][0][1], cube[5][0][2],
				cube[5][1][0], cube[5][1][2],
				cube[5][2][0], cube[5][2][1], cube[5][2][2],

				cube[1][2][0], cube[1][2][1], cube[1][2][2],
				cube[2][2][0], cube[2][2][1], cube[2][2][2],
				cube[3][2][0], cube[3][2][1], cube[3][2][2],
				cube[4][2][0], cube[4][2][1], cube[4][2][2]);
		}

		void inputcw(int i)
		{
			i = i % 6;
			if (i == 0)
				yellowcw();
			else if (i == 1)
				redcw();
			else if (i == 2)
				greencw();
			else if (i == 3)
				orangecw();
			else if (i == 4)
				bluecw();
			else if (i == 5)
				whitecw();
		}
		void inputccw(int i)
		{
			i = i % 6;
			if (i == 0)
				yellowccw();
			else if (i == 1)
				redccw();
			else if (i == 2)
				greenccw();
			else if (i == 3)
				orangeccw();
			else if (i == 4)
				blueccw();
			else if (i == 5)
				whiteccw();
		}

		void f2l_solve(int i, int k)
		{
			// U, L, D, R
			if (i == 2)
			{
				bluecw();
				yellowcw();
				blueccw();
				yellowccw();
			}
			else
			{
				greenccw();
				yellowccw();
				greencw();
				yellowcw();
			}
		}

		void same_colour(int i)
		{
			if (i == 3)
			{
				blueccw();
				yellowcw();
				yellowcw();
				bluecw();
				yellowccw();
				orangeccw();
				yellowcw();
				orangecw();
			}
		}
	};

	int main()
	{
		int cube[6][3][3] = {
			{{'g', 'r', 'r'}, {'g', 'y', 'y'}, {'g', 'y', 'y'}},
			{{'w', 'w', 'w'}, {'o', 'r', 'r'}, {'o', 'r', 'r'}},
			{{'o', 'g', 'g'}, {'y', 'g', 'g'}, {'y', 'b', 'b'}},
			{{'o', 'o', 'y'}, {'o', 'o', 'y'}, {'r', 'r', 'y'}},
			{{'b', 'b', 'r'}, {'b', 'b', 'w'}, {'b', 'b', 'w'}},
			{{'g', 'w', 'w'}, {'g', 'w', 'w'}, {'b', 'o', 'o'}}};
		int debug1[6][3][3] = {
			{{'y', 'y', 'y'}, {'y', 'y', 'y'}, {'y', 'y', 'y'}},
			{{'r', 'r', 'r'}, {'r', 'r', 'r'}, {'r', 'r', 'r'}},
			{{'g', 'g', 'g'}, {'g', 'g', 'g'}, {'g', 'g', 'g'}},
			{{'o', 'o', 'o'}, {'o', 'o', 'o'}, {'o', 'o', 'o'}},
			{{'b', 'b', 'b'}, {'b', 'b', 'b'}, {'b', 'b', 'b'}},
			{{'w', 'w', 'w'}, {'w', 'w', 'w'}, {'w', 'w', 'w'}}};
		int debug2[6][3][3] = {
			{{'y', 'y', 'g'}, {'y', 'y', 'g'}, {'o', 'o', 'o'}},
			{{'r', 'r', 'g'}, {'r', 'r', 'y'}, {'r', 'r', 'y'}},
			{{'w', 'w', 'w'}, {'g', 'g', 'g'}, {'g', 'g', 'g'}},
			{{'b', 'o', 'o'}, {'w', 'o', 'o'}, {'w', 'o', 'o'}},
			{{'y', 'b', 'b'}, {'y', 'b', 'b'}, {'y', 'b', 'b'}},
			{{'r', 'r', 'r'}, {'w', 'w', 'b'}, {'w', 'w', 'b'}}};

		Rubik rubik(debug2);
		rubik.printCube();
		rubik.wCross1();
		rubik.wCross2();
		rubik.f2l();
		rubik.oll();
		rubik.pll();
		rubik.printCube();

		return 0;
	}
