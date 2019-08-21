#include "Grid.h"
#include "Square.h"
#include "Triangle.h"
#include "Ellipse.h"

void main ()
{
	
	grid ourgrid;	//Declare object
	char file_name[13];	//Variable for data file name
	int a, b;

	cout << "Grid Data" <<ourgrid;
	cout << "\n\nEnter file name: ";
	cin >> file_name;//Input file name from console

	ifstream infile(file_name, ios::in); //Selects file using name input from console
	infile >>a>>b; //Assigns amount of rows and columns to variables a and b respectively
	if (infile!=NULL){
		infile >> ourgrid; //Inputs values from grid file into grid array
		cout << "\n\nPower grid data from file\n" << ourgrid; // Outputs values to console
		infile.close();} //Closes file
	else{cout << "\n Cannot open file " << file_name;} //If file cant be opened

	if (ourgrid.PowerOk()) // If all array locations have variables assigned to them
		cout << "\nPower is ok throughout grid";
	else
		ourgrid.WhereOff(); // Displays locations of errors in array, if any

	int c=0;
	for (c=0; c<26; c++){ cout << "\n";}

	HWND hWnd=GetForegroundWindow();
	HDC hDC=GetDC(hWnd);
			
	int k=0;
	int l=240;
	int m=0;
	int PEAKS=0;
	int VALLEYS=0;
	int high_peak=0;
	int highest_peak=0;
	int high_i;
	int high_j;
	int low_i;
	int low_j;
	int low_valley=0;
	int lowest_valley=0;
	square* SQUARE[42];
	point* peak[3];
	point* valley[3]; 
	triangle* tri[10];
	for (int i=0; i < GridRows; i++){	//Counter
			for (int j=0; j < GridCols; j++){	//Counter
				if (i==0 && j==0){//TOP LEFT CORNER
					if ((ourgrid.get_grid(i,j) > ourgrid.get_grid(i,j+1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j))
						&& (ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j+1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i,j+6))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j+6))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+5,j))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+5,j+1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+5,j+6))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 255,0,0);//red
							SQUARE[m]->draw(hDC);
							peak[PEAKS] = new point(i,j); //New point object to store location of peak
							PEAKS++; //Incrament
							high_peak=ourgrid.get_grid(i,j);
							if(high_peak > highest_peak){
								highest_peak= high_peak;
								high_i= i;
								high_j=j;
							}
					}else if((ourgrid.get_grid(i,j) < ourgrid.get_grid(i,j+1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j))
						&& (ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j+1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i,j+6))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j+6))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+5,j))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+5,j+1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+5,j+6))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,150,0);//Dark green
							SQUARE[m]->draw(hDC);
							valley[VALLEYS] = new point(i,j); //New point object to store location of valley 
							VALLEYS++; //Incriment
							low_valley = ourgrid.get_grid(i,j);
								if ((lowest_valley ==0)||(lowest_valley > low_valley)){
									lowest_valley = low_valley;
									low_i=i;
									low_j=j;
								}
						}else{
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,255,0);//green
							SQUARE[m]->draw(hDC);
						}
				}
				else if(i==0 && j==6){//Top right corner
						if ((ourgrid.get_grid(i,j) > ourgrid.get_grid(i,j-1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j-1))
						&& (ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i,j-6))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j-6))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+5,j-6))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+5,j-1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+5,j))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 255,0,0);//red
							SQUARE[m]->draw(hDC);
							peak[PEAKS] = new point(i,j); //New point object to store location of peak
							PEAKS++; //Incrament
							high_peak=ourgrid.get_grid(i,j);
							if(high_peak > highest_peak){
								highest_peak= high_peak;
								high_i= i;
								high_j=j;
							}
					}else if((ourgrid.get_grid(i,j) < ourgrid.get_grid(i,j-1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j-1))
						&& (ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i,j-6))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j-6))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+5,j-6))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+5,j-1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+5,j))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,150,0);//Dark green
							SQUARE[m]->draw(hDC);
							valley[VALLEYS] = new point(i,j); //New point object to store location of valley 
							VALLEYS++; //Incriment
							low_valley = ourgrid.get_grid(i,j);
								if ((lowest_valley ==0)||(lowest_valley > low_valley)){
									lowest_valley = low_valley;
									low_i=i;
									low_j=j;
								}
						}else{
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,255,0);//green
							SQUARE[m]->draw(hDC);
						}
							

				}
				else if(i==5 && j==0){//Bottom left corner
					if ((ourgrid.get_grid(i,j) > ourgrid.get_grid(i-1,j))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-1,j+1))
						&& (ourgrid.get_grid(i,j)>ourgrid.get_grid(i,j+1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i,j+6))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-1,j+6))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-5,j+6))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-5,j))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-5,j+1))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 255,0,0);//red
							SQUARE[m]->draw(hDC);
							peak[PEAKS] = new point(i,j); //New point object to store location of peak
							PEAKS++; //Incrament
							high_peak=ourgrid.get_grid(i,j);
							if(high_peak > highest_peak){
								highest_peak= high_peak;
								high_i= i;
								high_j=j;
							}
					}else if
						((ourgrid.get_grid(i,j) < ourgrid.get_grid(i-1,j))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-1,j+1))
						&& (ourgrid.get_grid(i,j)<ourgrid.get_grid(i,j+1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i,j+6))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-1,j+6))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-5,j+6))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-5,j))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-5,j+1))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,150,0);//Dark green
							SQUARE[m]->draw(hDC);
							valley[VALLEYS] = new point(i,j); //New point object to store location of valley 
							VALLEYS++; //Incriment
							low_valley = ourgrid.get_grid(i,j);
								if ((lowest_valley ==0)||(lowest_valley > low_valley)){
									lowest_valley = low_valley;
									low_i=i;
									low_j=j;
								}
						}else{
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,255,0);//green
							SQUARE[m]->draw(hDC);
						}
							
				}
				else if(i==5 && j==6){//Bottom right corner
					if ((ourgrid.get_grid(i,j) > ourgrid.get_grid(i-1,j-1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-1,j))
						&& (ourgrid.get_grid(i,j)>ourgrid.get_grid(i,j-1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-1,j-6))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i,j-6))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-5,j-1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-5,j))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-5,j-6))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 255,0,0);//red
							SQUARE[m]->draw(hDC);
							peak[PEAKS] = new point(i,j); //New point object to store location of peak
							PEAKS++; //Incrament
							high_peak=ourgrid.get_grid(i,j);
							if(high_peak > highest_peak){
								highest_peak= high_peak;
								high_i= i;
								high_j=j;
							}
									
					}else if
						((ourgrid.get_grid(i,j) < ourgrid.get_grid(i-1,j-1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-1,j))
						&& (ourgrid.get_grid(i,j)<ourgrid.get_grid(i,j-1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-1,j-6))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i,j-6))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-5,j-1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-5,j))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-5,j-6))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,150,0);//Dark green
							SQUARE[m]->draw(hDC);
							valley[VALLEYS] = new point(i,j); //New point object to store location of valley 
							VALLEYS++; //Incriment
							low_valley = ourgrid.get_grid(i,j);
								if ((lowest_valley ==0)||(lowest_valley > low_valley)){
									lowest_valley = low_valley;
									low_i=i;
									low_j=j;
								}
									
						}else{
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,255,0);//green
							SQUARE[m]->draw(hDC);
						}
				}
				else if((i==0 && j!=0)||(i==0 && j!=6)){//Top centre
					if ((ourgrid.get_grid(i,j) > ourgrid.get_grid(i,j-1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j-1))
						&& (ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j+1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i,j+1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+5,j-1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+5,j))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+5,j+1))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 255,0,0);//red
							SQUARE[m]->draw(hDC);
							peak[PEAKS] = new point(i,j); //New point object to store location of peak
							PEAKS++; //Incrament
							high_peak=ourgrid.get_grid(i,j);
							if(high_peak > highest_peak){
								highest_peak= high_peak;
								high_i= i;
								high_j=j;
							}
					}else if
						((ourgrid.get_grid(i,j) < ourgrid.get_grid(i,j-1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j-1))
						&& (ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j+1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i,j+1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+5,j-1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+5,j))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+5,j+1))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,150,0);//Dark green
							SQUARE[m]->draw(hDC);
							valley[VALLEYS] = new point(i,j); //New point object to store location of valley 
							VALLEYS++; //Incriment
							low_valley = ourgrid.get_grid(i,j);
								if ((lowest_valley ==0)||(lowest_valley > low_valley)){
									lowest_valley = low_valley;
									low_i=i;
									low_j=j;
								}
						}else{
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,255,0);//green
							SQUARE[m]->draw(hDC);
						}
				}
				else if((i!=0 && j==0)||(i!=5 && j==0)){ //Left centre
					if ((ourgrid.get_grid(i,j) > ourgrid.get_grid(i-1,j))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-1,j+1))
						&& (ourgrid.get_grid(i,j)>ourgrid.get_grid(i,j+1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j+1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-1,j+6))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i,j+6))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j+6))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 255,0,0);//red
							SQUARE[m]->draw(hDC);
							peak[PEAKS] = new point(i,j); //New point object to store location of peak
							PEAKS++; //Incrament
							high_peak=ourgrid.get_grid(i,j);
							if(high_peak > highest_peak){
								highest_peak= high_peak;
								high_i= i;
								high_j=j;
							}
					}else if((ourgrid.get_grid(i,j) < ourgrid.get_grid(i-1,j))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-1,j+1))
						&& (ourgrid.get_grid(i,j)<ourgrid.get_grid(i,j+1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j+1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-1,j+6))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i,j+6))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j+6))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,150,0);//Dark green
							SQUARE[m]->draw(hDC);
							valley[VALLEYS] = new point(i,j); //New point object to store location of valley 
							VALLEYS++; //Incriment
							low_valley = ourgrid.get_grid(i,j);
								if ((lowest_valley ==0)||(lowest_valley > low_valley)){
									lowest_valley = low_valley;
									low_i=i;
									low_j=j;
								}
						}else{
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,255,0);//green
							SQUARE[m]->draw(hDC);
						}
				}

				else if((i!=0 && j==6)||(i!=0 && j==6)){ //Right centre
					if ((ourgrid.get_grid(i,j) > ourgrid.get_grid(i-1,j))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-1,j-1))
						&& (ourgrid.get_grid(i,j)>ourgrid.get_grid(i,j-1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j-1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-1,j-6))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i,j-6))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j-6))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 255,0,0);//red
							SQUARE[m]->draw(hDC);
							peak[PEAKS] = new point(i,j); //New point object to store location of peak
							PEAKS++; //Incrament
							high_peak=ourgrid.get_grid(i,j);
							if(high_peak > highest_peak){
								highest_peak= high_peak;
								high_i= i;
								high_j=j;
							}
					}else if
						((ourgrid.get_grid(i,j) < ourgrid.get_grid(i-1,j))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-1,j-1))
						&& (ourgrid.get_grid(i,j)<ourgrid.get_grid(i,j-1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j-1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-1,j-6))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i,j-6))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j-6))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,150,0);//Dark green
							SQUARE[m]->draw(hDC);
							valley[VALLEYS] = new point(i,j); //New point object to store location of valley 
							VALLEYS++; //Incriment
							low_valley = ourgrid.get_grid(i,j);
								if ((lowest_valley ==0)||(lowest_valley > low_valley)){
									lowest_valley = low_valley;
									low_i=i;
									low_j=j;
								}
						}else{
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,255,0);//green
							SQUARE[m]->draw(hDC);
						}
				}

				else if((i==5 && j!=0)||(i==5 && j!=6)){//Bottom centre
					if ((ourgrid.get_grid(i,j) > ourgrid.get_grid(i,j-1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-1,j-1))
						&& (ourgrid.get_grid(i,j)>ourgrid.get_grid(i-1,j))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-1,j+1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i,j+1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-5,j-1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-5,j))&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-5,j+1))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 255,0,0);//red
							SQUARE[m]->draw(hDC);
							peak[PEAKS] = new point(i,j); //New point object to store location of peak
							PEAKS++; //Incrament
							high_peak=ourgrid.get_grid(i,j);
							if(high_peak > highest_peak){
								highest_peak= high_peak;
								high_i= i;
								high_j=j;
							}
					}else if
						((ourgrid.get_grid(i,j) < ourgrid.get_grid(i,j-1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-1,j-1))
						&& (ourgrid.get_grid(i,j)<ourgrid.get_grid(i-1,j))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-1,j+1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i,j+1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-5,j-1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-5,j))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-5,j+1))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,150,0);//Dark green
							SQUARE[m]->draw(hDC);
							valley[VALLEYS] = new point(i,j); //New point object to store location of valley 
							VALLEYS++; //Incriment
							low_valley = ourgrid.get_grid(i,j);
								if ((lowest_valley ==0)||(lowest_valley > low_valley)){
									lowest_valley = low_valley;
									low_i=i;
									low_j=j;
								}
						}else{
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,255,0);//green
							SQUARE[m]->draw(hDC);
						}
				}
				else{
					if ((ourgrid.get_grid(i,j) > ourgrid.get_grid(i-1,j-1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i-1,j))
						&& (ourgrid.get_grid(i,j)>ourgrid.get_grid(i-1,j+1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i,j+1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j+1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i+1,j-1))
						&&(ourgrid.get_grid(i,j)>ourgrid.get_grid(i,j-1))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,255,0);//red
							SQUARE[m]->draw(hDC);
							tri[PEAKS]= new triangle (k*50, l+50, (k*50)+50, l+50, (k*50)+10, l+10, 255,255,255,255,0,0);
							tri[PEAKS]->draw(hDC);
							tri[PEAKS]= new triangle ((k*50)+50, l+50, (k*50)+50, l+20, (k*50)+10, l+10, 255,255,255,255,0,0);
							tri[PEAKS]->draw(hDC);
							tri[PEAKS]= new triangle (k*50, l+50, (k*50)+10, l+10, k*50, l+30, 255,255,255,190,0,0);
							tri[PEAKS]->draw(hDC);
							peak[PEAKS] = new point(i,j); //New point object to store location of peak
							PEAKS++; //Incrament
							high_peak=ourgrid.get_grid(i,j);
							if(high_peak > highest_peak){
								highest_peak= high_peak;
								high_i= i;
								high_j=j;
							}
							//cout << "peak at location " << i << " " << j << endl;
					}else if
						((ourgrid.get_grid(i,j) < ourgrid.get_grid(i-1,j-1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i-1,j))
						&& (ourgrid.get_grid(i,j)<ourgrid.get_grid(i-1,j+1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i,j+1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j+1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i+1,j-1))
						&&(ourgrid.get_grid(i,j)<ourgrid.get_grid(i,j-1))){
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,150,0);//Dark green
							SQUARE[m]->draw(hDC);
							valley[VALLEYS] = new point(i,j); //New point object to store location of valley 
							VALLEYS++; //Incriment
							low_valley = ourgrid.get_grid(i,j);
								if ((lowest_valley ==0)||(lowest_valley > low_valley)){
									lowest_valley = low_valley;
									low_i=i;
									low_j=j;
								}
						}else{
							SQUARE[m]=new square (k*50, l, 0, 255, 255,  50, 50, 0,255,0);//green
							SQUARE[m]->draw(hDC);
						}
				}
				k++;
				m++; 
						
			}	
			l=l+50;
			k=0; //reset x co-ord to zero
		}
	cout << "The number of peaks is " << PEAKS << " at locations: ";
	for (int i=0; i<3 ; i++){
		peak[i]->display_point();
	}

	cout << "" << endl;

	cout << "The number of valleys is " << VALLEYS << " at locations: ";
	for (int i=0; i<3 ; i++){
		valley[i]->display_point();
	}
	
	cout << "\n\nthe highest peak is " << highest_peak << " at location (" << high_i << ", " << high_j << ")";
	cout << "\n\nthe lowest valley is " << lowest_valley << " at location (" << low_i << ", " << low_j << ")";
	
  }


