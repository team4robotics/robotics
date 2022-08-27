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
		while (cube[5][0][1] != 'w' &&
			cube[5][1][0] != 'w' &&
			cube[5][1][2] != 'w' &&
			cube[5][2][0] != 'w')
		{
			if (wSideOnFace() == 0) {
				if (cube[0][0][1] == 'w')
				{
					bluecw();
					bluecw();
				}
				if (cube[0][1][0] == 'w')
				{
					redcw();
					redcw();
				}
				if (cube[0][1][2] == 'w')
				{
					orangecw();
					orangecw();
				}
				if (cube[0][2][1] == 'w')
				{
					greencw();
					greencw();
				}
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
};

int main()
{
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
		{{ 'y', 'w', 'y' }, { 'w', 'y', 'w' }, { 'y', 'w', 'y' }},
		{{ 'o', 'r', 'o' }, { 'o', 'r', 'o' }, { 'o', 'r', 'o' }},
		{{ 'g', 'b', 'g' }, { 'g', 'g', 'g' }, { 'g', 'b', 'g' }},
		{{ 'r', 'o', 'r' }, { 'o', 'r', 'o' }, { 'r', 'o', 'r' }},
		{{ 'b', 'g', 'b' }, { 'g', 'b', 'g' }, { 'b', 'g', 'b' }},
		{{ 'w', 'y', 'w' }, { 'y', 'w', 'y' }, { 'w', 'y', 'w' }}
	};
	Rubik rubik(debug2);
	rubik.printCube();
	rubik.wCross1();
	rubik.printCube();

	cout << rubik.wSideOnFace() << endl;

	return 0;
}