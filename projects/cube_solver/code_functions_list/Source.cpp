#include<iostream>
#include<array>
#include<algorithm>

using namespace std;

class Rubik {
private:
	char cube[6][3][3] = {
		{{ ' ', ' ', ' ' }, { ' ', 'y', ' ' }, { ' ', ' ', ' ' }},
		{{ ' ', ' ', ' ' }, { ' ', 'r', ' ' }, { ' ', ' ', ' ' }},
		{{ ' ', ' ', ' ' }, { ' ', 'g', ' ' }, { ' ', ' ', ' ' }},
		{{ ' ', ' ', ' ' }, { ' ', 'o', ' ' }, { ' ', ' ', ' ' }},
		{{ ' ', ' ', ' ' }, { ' ', 'b', ' ' }, { ' ', ' ', ' ' }},
		{{ ' ', ' ', ' ' }, { ' ', 'w', ' ' }, { ' ', ' ', ' ' }}
	};

public:
	Rubik(int a[6][3][3]) {
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					cube[i][j][k] = a[i][j][k];
	}

	void printCube() {
		cout << "==============================" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "        ";
			for (int j = 0; j < 3; j++)
				cout << cube[0][i][j] << " ";
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < 3; i++) {
			for (int c = 1; c <= 4; c++) {
				for (int j = 0; j < 3; j++) {
					cout << cube[c][i][j] << " ";
				}
				cout << "  ";
			}
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < 3; i++) {
			cout << "        ";
			for (int j = 0; j < 3; j++)
				cout << cube[5][i][j] << " ";
			cout << endl;
		}
	}
	
	int wSideOnFace() {
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
	void wCross1() {
		//cout << "hehe debugging" << endl;
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
					else {
						bluecw();
						bluecw();
					}
				}
				if (cube[0][1][0] == 'w')
				{
					if (cube[5][1][0] == 'w')
						yellowccw();
					else {
						redcw();
						redcw();
					}
				}
				if (cube[0][2][1] == 'w')
				{
					if (cube[5][0][1])
						yellowccw();
					else {
						greencw();
						greencw();
					}
				}
				if (cube[0][1][2] == 'w')
				{
					if (cube[5][1][2])
						yellowccw();
					else {
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
					if (cube[4][0][1] == 'w')
					{
						redccw();
						bluecw();
						redccw();
					}
					else if (cube[2][0][1] == 'w')
					{
						redcw();
						greenccw();
						redcw();
					}
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

	void wCross2() {
		while (cube[1][2][1] != 'r' ||
			cube[2][2][1] != 'g' ||
			cube[3][2][1] != 'o' ||
			cube[4][2][1] != 'b') {
			if (cube[1][2][0] == cube[1][2][2] && cube[2][2][0] == cube[2][2][2] && cube[3][2][0]
				== cube[3][2][2 && cube[4][2][0] == cube[4][2][2] && cube[1][2][0] != cube[1][2][1]
				&& cube[2][2][0] != cube[2][2][1] && cube[3][2][0] != cube[3][2][1] && cube[4][2][0]
				!= cube[4][2][1]) {
				if (cube[1][2][1] == cube[4][2][0] || cube[2][2][0] == cube[2][2][1]) {
					// equivalent to pll_z
				}
				else {
					// equivalent to pll_h
				}
			}
			if (cube[1][2][0] == cube[1][2][1] && cube[1][2][1] == cube[1][2][2]) {
				// equivalent to pll_ua and/or pll_ub
			}
		}
	}

	void wFace1() { // plugging in corners
		while (cube[5][0][0] != 'w' ||
			cube[5][0][2] != 'w' ||
			cube[5][2][0] != 'w' ||
			cube[5][2][2] != 'w') {
			// ...
		}
	}

	void wFace2() { // fixing corners
		while () {
			if (cube[1][2][0] != cube[1][2][2] && cube[2][2][0] != cube[2][2][2] && cube[3][2][0]
				!= cube[3][2][2] && cube[4][2][0] != cube[4][2][2]) {
				// diagonals
			}
			if ((cube[1][2][0] == cube[1][2][2] && cube[2][2][0] != cube[2][2][2] && cube[3][2][0]
					!= cube[3][2][2] && cube[4][2][0] != cube[4][2][2]) ||
				(cube[1][2][0] != cube[1][2][2] && cube[2][2][0] == cube[2][2][2] && cube[3][2][0]
					!= cube[3][2][2] && cube[4][2][0] != cube[4][2][2]) ||
				(cube[1][2][0] != cube[1][2][2] && cube[2][2][0] != cube[2][2][2] && cube[3][2][0]
					== cube[3][2][2] && cube[4][2][0] != cube[4][2][2]) ||
				(cube[1][2][0] != cube[1][2][2] && cube[2][2][0] != cube[2][2][2] && cube[3][2][0]
					!= cube[3][2][2] && cube[4][2][0] == cube[4][2][2])) {
				// headlights
			}
		}
	}
	
	void oll() {
		red();
		if (cube[0][0][0] == 'y' && cube[0][0][1] == 'y' && cube[0][0][2] == 'y' && cube[0][1][0] == 'y' && cube[0][1][1] == 'y'
			&& cube[0][1][2] == 'y' && cube[0][2][1] == 'y' && cube[2][0][0] == 'y' && cube[2][0][2] == 'y') {

			oll_u();
		}
		if (cube[0][1][0] == 'y' && cube[0][0][1] == 'y' && cube[0][2][0] == 'y' && cube[0][0][2] == 'y' && cube[0][1][1] == 'y'
			&& cube[1][0][0] == 'y' && cube[1][0][2] == 'y' && cube[2][0][1] == 'y' && cube[4][0][1] == 'y') {

			oll_pi();
		}
		if (cube[0][0][1] == 'y' && cube[0][1][0] == 'y' && cube[0][1][1] == 'y' && cube[0][1][2] == 'y' && cube[0][2][0] == 'y' 
			&& cube[0][2][1] == 'y' && cube[2][2][1] == 'y' && cube[4][0][0] == 'y' && cube[3][0][2] == 'y') {

			oll_Asune();
		}
		if (cube[0][0][0] == 'y' && cube[0][0][1] == 'y' && cube[0[1][1] == 'y' && cube[0][1][2] == 'y' && cube[0][2][0] == 'y'
			&& cube[0][2][1] == 'y' && cube[2][0][2] == 'y' && cube[3][0][2] == 'y' && cube[4][0][2] == 'y') {
			oll_sune();
		}
		if (cube[0][0][1] == 'y' && cube[0][0][2] == 'y' == cube[0][1][1] && 'y' && cube[0][1][2] = 'y'
			&& cube[0][1][0] == 'y' && cube[0][2][1] == 'y' && cube[0][2][2] = 'y' && cube[2][0][0] == 'y' && cube[4][0][2] == 'y') {
			oll_t();
		}
		if (cube[0][0][0] == 'y' && cube[0][0][1] == 'y' && cube[0][1][0] == 'y' && cube[0][1][1] == 'y' && 
			cube[0][1][2] == 'y' && cube[2][2][1] == 'y' && cube[2][2][2] == 'y' && cube[3][0][2] == 'y' && cube[2][0][0] == 'y') {
			oll_l();
		}
		if (cube[0][1][0] == 'y' && cube[0][0][1] == 'y' && cube[0][2][0] == 'y' && cube[0][0][2] == 'y' && cube[0][1][1] == 'y'
			&& cube[1][0][0] == 'y' && cube[1][0][2] == 'y' && cube[3][0][0] == 'y' && cube[3][0][2] ==  'y') {
			oll_h();
		}
	}
	//OLL ALGO
	void oll_pi() {//yes
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

	void oll_u() {//yes
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

	void oll_t() {//yes
		bluecw();
		redcw();
		greenccw();
		redccw();
		blueccw();
		redcw();
		greencw();
		redccw();

	}

	void oll_Asune() {//yes
		greenccw();
		yellowccw();
		greencw();
		yellowccw();
		greenccw();
		yellowcw();
		yellowcw();
		greencw();
	}

	void oll_h() {
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

	void oll_l() {
		redcw();
		greenccw();
		redccw();
		bluecw();
		redcw();
		greencw();
		redccw();
		blueccw();
	}

	void oll_sune() {//yes
		greencw();
		yellowcw();
		greenccw();
		yellowcw();
		greencw();
		yellowcw();
		yellowcw();
		greenccw();
	}

	void red() {
		switch () {
		case sune:
			while (cube[0][0][0] != 'y') {
				yellowccw();
			}
		case asune:
			while (cube[0][0][2] != 'y') {
				yellowccw();
			}
		case l:
			while (cube[1][0][0] != 'y') {
				yellowccw();
			}
		case t:
			while (cube[1][0][0] != 'y') {
				yellowccw();
			}
		case h:
			while (cube[2][0][0] != 'y') {
				yellowccw();
			}
		case pi:
			while (cube[1][0][0] != 'y' && cube[1][0][2] != 'y') {
				yellowccw();
			}
		case u:
			while (cube[1][0][0] != 'y') {
				yellowccw();
			}
		}
	}


	void f2l() {
		//algorithm

		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				if (cube[i][0][1] == 'g' || cube[i][0][1] == 'o' && cube[4][0][1] == 'g' || cube[4][0][1] == 'o') {
					if (cube[4][0][1] == 'g') {
						yellowcw();
						yellowcw();
						if (cube[1][0][1] == 'g' && cube[0][2][1] == 'o') {
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
					if (cube[4][0][1] == 'o') {
						yellowcw();
						yellowcw();
						if (cube[3][0][1] == 'o' && cube[0][1][2] == 'g') {
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
			else {
				if (cube[i][0][1] == 'g'|| cube[i][0][1] == 'o') {

				}
				else if (cube[i][1][0] == 'g'|| cube[i][1][0] == 'o') {

				}
				else if (cube[i][1][2] == 'g' || cube[i][1][2] == 'o') {

				}
			}
		}

		if (cube[2][0][1] == 'g' && cube[0][2][1] == 'r') {
			yellowccw();
			redccw();
			yellowccw();
			redcw();
			yellowcw();
			greencw();
			yellowcw();
			greenccw();
		}

		if (cube[1][0][1] == 'r' && cube[0][1][0] == 'g') {
			yellowcw();
			greencw();
			yellowcw();
			greenccw();
			yellowccw();
			redccw();
			yellowccw();
			redcw();
		}

		if (cube[4][0][1] == 'b' && cube[0][0][1] == 'r') {
			yellowcw();
			redcw();
			yellowcw();
			redccw();
			yellowccw();
			blueccw();
			yellowccw();
			bluecw();
		}
		if (cube[1][0][1] == 'r' && cube[0][1][0] == 'b') {
			yellowccw();
			blueccw();
			yellowccw();
			bluecw();
			yellowcw();
			redcw();
			yellowcw();
			redccw();
		}
		if (cube[3][0][1] == 'o' && cube[0][1][0] == 'b') {
			yellowccw();
			blueccw();
			yellowccw();
			bluecw();
			orangecw();
			yellowcw();
			orangeccw();
		}
		if (cube[4][0][1] == 'b' && cube[0][0][1] == 'o') {
			yellowcw();
			orangecw();
			yellowcw();
			orangeccw();
			yellowccw();
			blueccw();
			yellowccw();
			bluecw();
		}
		if (cube[3][0][1] == 'o' && cube[0][1][2] == 'g') {
			yellowccw();
			greenccw();
			yellowccw();
			greencw();
			yellowccw();
			orangecw();
			yellowcw();
			orangeccw();

		}
		if (cube[1][0][1] == 'g' && cube[0][2][1] == 'o') {
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

	void pll() {
		if (cube[1][0][0] != cube[1][0][2] && cube[2][0][0] != cube[2][0][2] && cube[3][0][0]
			!= cube[3][0][2] && cube[4][0][0] != cube[4][0][2]) {
			pll_diag();
		}
		if ((cube[1][0][0] == cube[1][0][2] && cube[2][0][0] != cube[2][0][2] && cube[3][0][0]
				!= cube[3][0][2] && cube[4][0][0] != cube[4][0][2]) ||
			(cube[1][0][0] != cube[1][0][2] && cube[2][0][0] == cube[2][0][2] && cube[3][0][0]
				!= cube[3][0][2] && cube[4][0][0] != cube[4][0][2]) ||
			(cube[1][0][0] != cube[1][0][2] && cube[2][0][0] != cube[2][0][2] && cube[3][0][0]
				== cube[3][0][2] && cube[4][0][0] != cube[4][0][2]) ||
			(cube[1][0][0] != cube[1][0][2] && cube[2][0][0] != cube[2][0][2] && cube[3][0][0]
				!= cube[3][0][2] && cube[4][0][0] == cube[4][0][2])) {
			pll_headlights();
		}

		if (cube[1][0][0] == cube[1][0][2] && cube[2][0][0] == cube[2][0][2] && cube[3][0][0]
			== cube[3][0][2] && cube[4][0][0] == cube[4][0][2] && cube[1][0][0] != cube[1][0][1]
			&& cube[2][0][0] != cube[2][0][1] && cube[3][0][0] != cube[3][0][1] && cube[4][0][0]
			!= cube[4][0][1]) {
			if (cube[1][0][1] == cube[4][0][0] || cube[2][0][0] == cube[2][0][1]) {
				pll_z();
			}
			else {
				pll_h();
			}
		}
		if (cube[1][0][0] == cube[1][0][1] && cube[1][0][1] == cube[1][0][2]) {
			pll_ua(); // or pll_ub();
		}
	}
	//  y r g o b w


private:
	void rotate(char& a, char& b, char& c, char& d) {
		char tmp = a;
		a = b;
		b = c;
		c = d;
		d = tmp;
	}
	void clockwise90(
		char& faceTL, char& faceTC, char& faceTR,
		char& faceCL, char& faceCR,
		char& faceBL, char& faceBC, char& faceBR,

		char& sideTL, char& sideTC, char& sideTR,
		char& sideRT, char& sideRC, char& sideRB,
		char& sideBR, char& sideBC, char& sideBL,
		char& sideLB, char& sideLC, char& sideLT
		)
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
		char& faceTL, char& faceTC, char& faceTR,
		char& faceCL, char& faceCR,
		char& faceBL, char& faceBC, char& faceBR,

		char& sideTL, char& sideTC, char& sideTR,
		char& sideRT, char& sideRC, char& sideRB,
		char& sideBR, char& sideBC, char& sideBL,
		char& sideLB, char& sideLC, char& sideLT
		)
	{
		// face switching
		rotate(faceTL, faceTR, faceBR, faceBL);
		rotate(faceTC, faceCR, faceBC, faceCL);

		// side switching
		rotate(sideTL, sideRT, sideBR, sideLB);
		rotate(sideTC, sideRC, sideBC, sideLC);
		rotate(sideTR, sideRB, sideBL, sideLT);
	}
	void yellowcw() {
		clockwise90(
			cube[0][0][0], cube[0][0][1], cube[0][0][2],
			cube[0][1][0], cube[0][1][2],
			cube[0][2][0], cube[0][2][1], cube[0][2][2],

			cube[1][0][2], cube[1][0][1], cube[1][0][0],
			cube[4][0][2], cube[4][0][1], cube[4][0][0],
			cube[3][0][2], cube[3][0][1], cube[3][0][0],
			cube[2][0][2], cube[2][0][1], cube[2][0][0]
		);
	}
	void yellowccw() {
		counterclockwise90(
			cube[0][0][0], cube[0][0][1], cube[0][0][2],
			cube[0][1][0], cube[0][1][2],
			cube[0][2][0], cube[0][2][1], cube[0][2][2],

			cube[1][0][2], cube[1][0][1], cube[1][0][0],
			cube[4][0][2], cube[4][0][1], cube[4][0][0],
			cube[3][0][2], cube[3][0][1], cube[3][0][0],
			cube[2][0][2], cube[2][0][1], cube[2][0][0]
		);
	}
	void redcw() {
		clockwise90(
			cube[1][0][0], cube[1][0][1], cube[1][0][2],
			cube[1][1][0], cube[1][1][2],
			cube[1][2][0], cube[1][2][1], cube[1][2][2],

			cube[0][0][0], cube[0][1][0], cube[0][2][0],
			cube[2][0][0], cube[2][1][0], cube[2][2][0],
			cube[5][0][0], cube[5][1][0], cube[5][2][0],
			cube[4][2][2], cube[4][1][2], cube[4][0][2]
		);
	}
	void redccw() {
		counterclockwise90(
			cube[1][0][0], cube[1][0][1], cube[1][0][2],
			cube[1][1][0], cube[1][1][2],
			cube[1][2][0], cube[1][2][1], cube[1][2][2],

			cube[0][0][0], cube[0][1][0], cube[0][2][0],
			cube[2][0][0], cube[2][1][0], cube[2][2][0],
			cube[5][0][0], cube[5][1][0], cube[5][2][0],
			cube[4][2][2], cube[4][1][2], cube[4][0][2]
		);
	}
	void greencw() {
		clockwise90(
			cube[2][0][0], cube[2][0][1], cube[2][0][2],
			cube[2][1][0], cube[2][1][2],
			cube[2][2][0], cube[2][2][1], cube[2][2][2],

			cube[0][2][0], cube[0][2][1], cube[0][2][2],
			cube[3][0][0], cube[3][1][0], cube[3][2][0],
			cube[5][0][2], cube[5][0][1], cube[5][0][0],
			cube[1][2][2], cube[1][1][2], cube[1][0][2]
		);
	}
	void greenccw() {
		counterclockwise90(
			cube[2][0][0], cube[2][0][1], cube[2][0][2],
			cube[2][1][0], cube[2][1][2],
			cube[2][2][0], cube[2][2][1], cube[2][2][2],

			cube[0][2][0], cube[0][2][1], cube[0][2][2],
			cube[3][0][0], cube[3][1][0], cube[3][2][0],
			cube[5][0][2], cube[5][0][1], cube[5][0][0],
			cube[1][2][2], cube[1][1][2], cube[1][0][2]
		);
	}// yellow, red, green, orange, blue, white(by row)
	void orangecw() {
		clockwise90(
			cube[3][0][0], cube[3][0][1], cube[3][0][2],
			cube[3][1][0], cube[3][1][2],
			cube[3][2][0], cube[3][2][1], cube[3][2][2],

			cube[0][2][2], cube[0][1][2], cube[0][0][2],
			cube[4][0][0], cube[4][1][0], cube[4][2][0],
			cube[5][2][2], cube[5][1][2], cube[5][0][2],
			cube[2][2][2], cube[2][1][2], cube[2][0][2]
		);
	}
	void orangeccw() {
		counterclockwise90(
			cube[3][0][0], cube[3][0][1], cube[3][0][2],
			cube[3][1][0], cube[3][1][2],
			cube[3][2][0], cube[3][2][1], cube[3][2][2],

			cube[0][2][2], cube[0][1][2], cube[0][0][2],
			cube[4][0][0], cube[4][1][0], cube[4][2][0],
			cube[5][2][2], cube[5][1][2], cube[5][0][2],
			cube[2][2][2], cube[2][1][2], cube[2][0][2]
		);
	}
	void bluecw() {
		clockwise90(
			cube[4][0][0], cube[4][0][1], cube[4][0][2],
			cube[4][1][0], cube[4][1][2],
			cube[4][2][0], cube[4][2][1], cube[4][2][2],

			cube[0][0][2], cube[0][0][1], cube[0][0][0],
			cube[1][0][0], cube[1][1][0], cube[1][2][0],
			cube[5][2][0], cube[5][2][1], cube[5][2][2],
			cube[3][2][2], cube[3][1][2], cube[3][0][2]
		);
	}
	void blueccw() {
		counterclockwise90(
			cube[4][0][0], cube[4][0][1], cube[4][0][2],
			cube[4][1][0], cube[4][1][2],
			cube[4][2][0], cube[4][2][1], cube[4][2][2],

			cube[0][0][2], cube[0][0][1], cube[0][0][0],
			cube[1][0][0], cube[1][1][0], cube[1][2][0],
			cube[5][2][0], cube[5][2][1], cube[5][2][2],
			cube[3][2][2], cube[3][1][2], cube[3][0][2]
		);
	}
	void whitecw() {
		clockwise90(
			cube[5][0][0], cube[5][0][1], cube[5][0][2],
			cube[5][1][0], cube[5][1][2],
			cube[5][2][0], cube[5][2][1], cube[5][2][2],

			cube[1][2][0], cube[1][2][1], cube[1][2][2],
			cube[2][2][0], cube[2][2][1], cube[2][2][2],
			cube[3][2][0], cube[3][2][1], cube[3][2][2],
			cube[4][2][0], cube[4][2][1], cube[4][2][2]
		);
	}
	void whiteccw() {
		counterclockwise90(
			cube[5][0][0], cube[5][0][1], cube[5][0][2],
			cube[5][1][0], cube[5][1][2],
			cube[5][2][0], cube[5][2][1], cube[5][2][2],

			cube[1][2][0], cube[1][2][1], cube[1][2][2],
			cube[2][2][0], cube[2][2][1], cube[2][2][2],
			cube[3][2][0], cube[3][2][1], cube[3][2][2],
			cube[4][2][0], cube[4][2][1], cube[4][2][2]
		);
	}

	void inputcw(int i)
	{
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

	void f2l_solve(int i, int k) {
		// U, L, D, R
		if (i == 2) {
			bluecw();
			yellowcw();
			blueccw();
			yellowccw();
		}
		else {
			greenccw();
			yellowccw();
			greencw();
			yellowcw();
		}

	}

	void same_colour(int i) {
		if (i == 3) {
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

	void pll_diag() {
		if () {
			yellowcw();
			redcw();
			greenccw();
			redccw();
			greenccw();
			redcw();
			greencw();
			redccw();
			yellowccw();
			redcw();
			greencw();
			redccw();
			greenccw();
			redccw();
			yellowcw();
			redcw();
			yellowccw();
		}

		if () {
			yellowcw();
			greencw();
			orangeccw();
			greenccw();
			orangeccw();
			greencw();
			orangecw();
			greenccw();
			yellowccw();
			greencw();
			orangecw();
			greenccw();
			orangeccw();
			greenccw();
			yellowcw();
			greencw();
			yellowccw();
		}

		if () {
			yellowcw();
			orangecw();
			blueccw();
			orangeccw();
			blueccw();
			orangecw();
			bluecw();
			orangeccw();
			yellowccw();
			orangecw();
			bluecw();
			orangeccw();
			blueccw();
			orangeccw();
			yellowcw();
			orangecw();
			yellowccw();
		}

		if () {
			yellowcw();
			bluecw();
			redccw();
			blueccw();
			redccw();
			bluecw();
			redcw();
			blueccw();
			yellowccw();
			bluecw();
			redcw();
			blueccw();
			redccw();
			blueccw();
			yellowcw();
			bluecw();
			yellowccw();
		}

		//F R U' R' U' R U R' F' R U R' U' R' F R F'
	}

	void pll_headlights() {
		//R U R' U' R' F R2 U' R' U' R U R' F'
	}

	void pll_h() {
		//M2 U M2 U2 M2 U M2
	}

	void pll_ua() {
		//R U' R U R U R U' R' U' R2
	}

	void pll_ub() {
		//R2 U R U R' U' R' U' R' U R'
	}

	void pll_z() {
		//M' U M2 U M2 U M' U2 M2
	}
};

int main()
{
<<<<<<< HEAD
	if (faces == 
	{ { 'y', 'y', 'y' }, { 'y', 'y', 'y' }, { 'y', 'y', 'y' },
		{ 'r', 'r', 'r' }, { 'r', 'r', 'r' }, { 'r', 'r', 'r' },
		{ 'g', 'g', 'g' }, { 'g', 'g', 'g' }, { 'g', 'g', 'g' },
		{ 'o', 'o', 'o' }, { 'o', 'o', 'o' }, { 'o', 'o', 'o' },
		{ 'b', 'b', 'b' }, { 'b', 'b', 'b' }, { 'b', 'b', 'b' },
		{ 'w', 'w', 'w' }, { 'w', 'w', 'w' }, { 'w', 'w', 'w' }}) {
		rubik.printCube();
		return 0;
	}

=======
>>>>>>> origin/main
	int faces[6][3][3] = {
		{{ 'g', 'r', 'r' }, { 'g', 'y', 'y' }, { 'g', 'y', 'y' }},
		{{ 'w', 'w', 'w' }, { 'o', 'r', 'r' }, { 'o', 'r', 'r' }},
		{{ 'o', 'g', 'g' }, { 'y', 'g', 'g' }, { 'y', 'b', 'b' }},
		{{ 'o', 'o', 'y' }, { 'o', 'o', 'y' }, { 'r', 'r', 'y' }},
		{{ 'b', 'b', 'r' }, { 'b', 'b', 'w' }, { 'b', 'b', 'w' }},
		{{ 'g', 'w', 'w' }, { 'g', 'w', 'w' }, { 'b', 'o', 'o' }}
	};
	int debug1[6][3][3] = {
		{{ 'y', 'y', 'y' }, { 'y', 'y', 'y' }, { 'y', 'y', 'y' }},
		{{ 'r', 'r', 'r' }, { 'r', 'r', 'r' }, { 'r', 'r', 'r' }},
		{{ 'g', 'g', 'g' }, { 'g', 'g', 'g' }, { 'g', 'g', 'g' }},
		{{ 'o', 'o', 'o' }, { 'o', 'o', 'o' }, { 'o', 'o', 'o' }},
		{{ 'b', 'b', 'b' }, { 'b', 'b', 'b' }, { 'b', 'b', 'b' }},
		{{ 'w', 'w', 'w' }, { 'w', 'w', 'w' }, { 'w', 'w', 'w' }}
	};
	int debug2[6][3][3] = {
		{{ 'y', 'y', 'g' }, { 'y', 'y', 'g' }, { 'o', 'o', 'o' }},
		{{ 'r', 'r', 'g' }, { 'r', 'r', 'y' }, { 'r', 'r', 'y' }},
		{{ 'w', 'w', 'w' }, { 'g', 'g', 'g' }, { 'g', 'g', 'g' }},
		{{ 'b', 'o', 'o' }, { 'w', 'o', 'o' }, { 'w', 'o', 'o' }},
		{{ 'y', 'b', 'b' }, { 'y', 'b', 'b' }, { 'y', 'b', 'b' }},
		{{ 'r', 'r', 'r' }, { 'w', 'w', 'b' }, { 'w', 'w', 'b' }}
	};


	Rubik rubik(debug2);
	rubik.printCube();
	rubik.wCross1();
	rubik.printCube();



	return 0;
}