#include <iostream>
#include <fstream>

const int GridRows= 6;	//Number of rows in grid
const int GridCols =7;	//Number of columns in grid
using namespace std;


class grid{
	double PowerGrid[GridRows][GridCols];

		friend ostream& operator << (ostream&, const grid&); 
		friend istream& operator >> (istream&, grid&);	// Grant friendship to operators

	public:
		grid(){								//Constructor
			int i,j;
			for (i=0; i < GridRows; i++)	//Row counter
				for (j=0; j < GridCols; j++)	//Column counter
					PowerGrid [i][j] = i*10+j;
			}

	
		int PowerOk();	//Error check grid for outage
		void WhereOff();	//Prints location of outage
		int get_grid(int the_x, int the_y);
};

//-------------Function Definitions-----------------------------

int grid::PowerOk(){
	int ok =1;
	int i, j;

	for (i=0; i <GridRows && ok; i++)
		for(j=0; j < GridCols && ok ==1; j++)
			if (PowerGrid[i][j] == 0) //If location has no data
				ok = 0;
			return (ok);
}

void grid::WhereOff(){
	int i, j;
	int c=0;
	for (c=0; c<26; c++){ cout << "\n";}
	cout << "\n\nPower is off in grid cells: \n";
	for (i=0; i < GridRows; i++){
		for (j=0; j < GridCols; j++)
			if (PowerGrid[i][j] ==0)
			cout << "Power in " << i << " " << j << " " << "is " << PowerGrid[i][j] << "\n";
			}
		
}

ostream& operator << (ostream &os, const grid& gr)	//Overloading ostream opperator
{
	int i, j;
	for (i=0; i < GridRows; i++){	//Counter
		for (j=0; j < GridCols; j++){	//Counter
			os << " " << gr.PowerGrid[i][j];}cout << "\n";}	//Outputs grid data
	return os;
}

istream& operator >> (istream &is, grid& gr)	//Overloading istream operator
{
	int i,j;
	for (i=0; i < GridRows; i++){
		for (j=0; j < GridCols; j++){
			is >> gr.PowerGrid[i][j];
		}
	}
	return is;
}

int grid::get_grid(int the_x, int the_y){
	int x;
	int y;

	x= the_x;
	y =the_y;
	
	int val= PowerGrid[x][y];

	return val;
	
}
