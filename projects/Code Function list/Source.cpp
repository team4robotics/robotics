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
		//        c c c
		//c c c   c c c  c c c  c c c
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
	Rubik rubik(faces);
	rubik.printCube();
	rubik.greencw();
	rubik.printCube();
	rubik.greenccw();
	rubik.printCube();

	return 0;
}