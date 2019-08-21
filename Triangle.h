#include <windows.h>
#include <iostream>  
#include <stdio.h>
#include <conio.h> 
#include "resource.h"

class triangle
{
	protected:  
               COLORREF RGB_fill_color;
			   COLORREF RGB_color;
			   int x1;
			   int y1;
			   int x2;
			   int y2;
			   int x3; 
			   int y3;

	public:  
		triangle()  {  x1 = 0; y1 = 0; x2=0; y2=0; x3=0; y3=0; RGB_color=RGB(0,0,0); RGB_fill_color=RGB(0,0,0); }
               triangle(  int xval, int yval,  int xval2, int yva2, int xval3, int yva3,
                        int r, int g, int b, int fill_r, int fill_g, int fill_b  );
			   ~triangle();
               void  draw(HDC hdc);
};

//---------------------Methods for triangle class---------------------------
triangle::triangle( int xval1, int yval1, int xval2, int yval2,int xval3, int yval3,
					int r, int g, int b, int fill_r, int fill_g, int fill_b ){  
		x1 = xval1; y1=yval1;
		x2 = xval2; y2=yval2;
		x3 = xval3; y3=yval3;

		RGB_color =RGB(r,g,b);
		RGB_fill_color=RGB(fill_r, fill_g, fill_b);

	}

triangle::~triangle(){}

	void  triangle::draw(HDC hDC)
      {	 HPEN pen=NULL;
		 HPEN pen2=NULL;
		 HBRUSH brush=NULL;


		 if (pen)DeleteObject(pen); //delete previous created pen
		
         if (brush)DeleteObject(brush);

		 POINT vertices[] = { {x1, y1}, {x2, y2}, {x3, y3} };
		 POINT vertices1[] = { {x1+1, y1-1}, {x2+1, y2-1}, {x3+1, y3-1} };
		 Polygon(hDC, vertices1, sizeof(vertices1) / sizeof(vertices1[0]));
		 Polygon(hDC, vertices, sizeof(vertices) / sizeof(vertices[0]));

		 

		 pen=CreatePen(PS_SOLID,2,RGB_color);  // Create a new pen
         SelectObject(hDC,pen); // select pen into context
		 
		
		 
		 HRGN rgn = CreatePolygonRgn(vertices,3,WINDING);
		 brush = CreateSolidBrush (RGB_fill_color);
		 FillRgn(hDC, rgn, brush);
      }