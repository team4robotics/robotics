#include<iostream>
#include<array>
#include<algorithm>

using namespace std;

class Rubik {
private:
	/*
		0 --> white face - UP
		1 --> orange face - LEFT
		2 --> green face - FRONT
		3 --> red face - RIGHT
		4 --> blue face - BACK
		5 --> yellow face - DOWN
	*/
	int cube[6][3][3] = {
		{{ -1, -1, -1 }, { -1, 0, -1 }, { -1, -1, -1 }},	// white face --> top, middle, bottom row
		{{ -1, -1, -1 }, { -1, 1, -1 }, { -1, -1, -1 }},	// orange face --> top, middle, bottom row
		{{ -1, -1, -1 }, { -1, 2, -1 }, { -1, -1, -1 }},	// green face --> top, middle, bottom row
		{{ -1, -1, -1 }, { -1, 3, -1 }, { -1, -1, -1 }},	// red face --> top, middle, bottom row
		{{ -1, -1, -1 }, { -1, 4, -1 }, { -1, -1, -1 }},	// blue face --> top, middle, bottom row
		{{ -1, -1, -1 }, { -1, 5, -1 }, { -1, -1, -1 }}		// yellow face --> top, middle, bottom row
	};

public:
	Rubik(int a[6][3][3]) {
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					cube[i][j][k] = a[i][j][k];
	}

	void printCube() {
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
					cout << cube[i][j][k] << " ";
				cout << endl;
			}
			cout << endl;
		}
	}

// private:
	// green face is front, white face is top
	void fcw() { // Front
		array<int, 8> face = {
			cube[2][0][0],
			cube[2][0][1],
			cube[2][0][2],
			cube[2][1][2],
			cube[2][2][2],
			cube[2][2][1],
			cube[2][2][0],
			cube[2][1][0]
		};
		array<int, 12> side = {
			cube[0][2][0], cube[0][2][1], cube[0][2][2],
			cube[3][0][0], cube[3][1][0], cube[3][2][0],
			cube[5][0][2], cube[5][0][1], cube[5][0][0],
			cube[1][2][2], cube[1][1][2], cube[1][0][2]
		};

		std::rotate(face.begin(), face.begin() + 5, face.end());
		std::rotate(side.begin(), side.begin() + 9, side.end());

		cube[2][0][0] = face[0];
		cube[2][0][1] = face[1];
		cube[2][0][2] = face[2];
		cube[2][1][2] = face[3];
		cube[2][2][2] = face[4];
		cube[2][2][1] = face[5];
		cube[2][2][0] = face[6];
		cube[2][1][0] = face[7];

		cube[0][2][0] = side[0]; cube[0][2][1] = side[1]; cube[0][2][2] = side[2];
		cube[3][0][0] = side[3]; cube[3][1][0] = side[4]; cube[3][2][0] = side[5];
		cube[5][0][2] = side[6]; cube[5][0][1] = side[7]; cube[5][0][0] = side[8];
		cube[1][2][2] = side[9]; cube[1][1][2] = side[10]; cube[1][0][2] = side[11];
	}
	void fccw() { // Front Prime
		fcw(); fcw(); fcw();
	}
	void bcw() { // Bottom

	}
	void bccw() { // Bottom Prime
		bcw(); bcw(); bcw();
	}

	void ucw() { // Up
		
	}
	void uccw() { // Up Prime
		ucw(); ucw(); ucw();
	}
	void dcw() { // Down
		
	}
	void dccw() { // Down Prime
		dcw(); dcw(); dcw();
	}

	void rcw() { // Right

	}
	void rccw() { // Right Prime
		rcw(); rcw(); rcw();
	}
	void lcw() { // Left

	}
	void lccw() { // Left Prime
		lcw(); lcw(); lcw();
	}
};

int main()
{
	int faces[6][3][3] = {
		{{ 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }},	// white face --> top, middle, bottom row
		{{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 }},	// green face --> top, middle, bottom row
		{{ 2, 2, 2 }, { 2, 2, 2 }, { 2, 2, 2 }},	// orange face --> top, middle, bottom row
		{{ 3, 3, 3 }, { 3, 3, 3 }, { 3, 3, 3 }},	// blue face --> top, middle, bottom row
		{{ 4, 4, 4 }, { 4, 4, 4 }, { 4, 4, 4 }},	// red face --> top, middle, bottom row
		{{ 5, 5, 5 }, { 5, 5, 5 }, { 5, 5, 5 }}		// yellow face --> top, middle, bottom row
	};
	Rubik rubik(faces);
	rubik.fcw();
	rubik.printCube();

	return 0;
}