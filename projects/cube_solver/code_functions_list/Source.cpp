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
			else
			{
				int face1 = wSideOnFace(), face2;
				if (face1 == 1)
				{
					if (cube[4][0][1] == 'w')
						face2 = 4;
					else if (cube[2][0][1] == 'w')
						face2 = 2;
					else
						face2 = -2;
				}
				else if (face1 == 2)
				{
					if (cube[1][0][1] == 'w')
						face2 = 1;
					else if (cube[3][0][1] == 'w')
						face2 = 3;
					else
						face2 = -3;
				}
				else if (face1 == 3)
				{
					if (cube[2][0][1] == 'w')
						face2 = 2;
					else if (cube[4][0][1] == 'w')
						face2 = 4;
					else
						face2 = -4;
				}
				else if (face1 == 4)
				{
					if (cube[3][0][1] == 'w')
						face2 = 3;
					else if (cube[1][0][1] == 'w')
						face2 = 1;
					else
						face2 = -5;
				}

				if (face2 < 0)
				{
					inputcw(face1);
					inputccw(abs(face2));
				}
			}
		}
	}
	void oll() {
		oll_facered();
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
			// yellow, red, green, orange, blue, white(by row)
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
			while (faces[0][0][0] != 'y') {
				yellowccw();
			}
		case asune:
			while (faces[0][0][2] != 'y') {
				yellowccw();
			}
		case l:
			while (faces[1][0][0] != 'y') {
				yellowccw();
			}
		case t:
			while (faces[1][0][0] != 'y') {
				yellowccw();
			}
		case h:
			while (faces[2][0][0] != 'y') {
				yellowccw();
			}
		case pi:
			while (faces[1][0][0] != 'y' && faces[1][0][2] != 'y') {
				yellowccw();
			}
		case u:
			while (faces[1][0][0] != 'y') {
				yellowccw();
			}
		}
	}

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
		if (i = 2) {
			bluecw();
			yellowcw();
			blueccw();
			yellowccw();
		}

	}

	void same_colour(int i) {
		if (i = 3) {
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
	if (faces == 
		{ 'y', 'y', 'y' }, { 'y', 'y', 'y' }, { 'y', 'y', 'y' },
		{ 'r', 'r', 'r' }, { 'r', 'r', 'r' }, { 'r', 'r', 'r' },
		{ 'g', 'g', 'g' }, { 'g', 'g', 'g' }, { 'g', 'g', 'g' },
		{ 'o', 'o', 'o' }, { 'o', 'o', 'o' }, { 'o', 'o', 'o' },
		{ 'b', 'b', 'b' }, { 'b', 'b', 'b' }, { 'b', 'b', 'b' },
		{ 'w', 'w', 'w' }, { 'w', 'w', 'w' }, { 'w', 'w', 'w' }) {
		rubik.printCube();
		return 0;
	}

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