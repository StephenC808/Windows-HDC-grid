#include <windows.h>
#include <iostream>   // for cerr
#include <stdio.h>
#include <conio.h> 
#include "resource.h"
#include "Line.h"

class square:   public line
        {
   protected:  int width;
               COLORREF RGB_fill_color;
   public:     square()  {  x = 0;      y = 0; RGB_color=RGB(0,0,0);
                            length = 0; width = 0; RGB_fill_color=RGB(0,0,0); }
               square(  int xval,       int yval, int r, int g, int b,
                        int ilength,    int iwidth,
                        int fill_r, int fill_g, int fill_b  );
			   ~square();
               void  draw(HDC hdc);
               void  set_width( int iwidth );
               int   get_width();
        };

//---------------------Methods for square class---------------------------
square::square( int xval,       int yval, int r, int g, int b,
                      int ilength,    int iwidth,
                      int fill_r, int fill_g, int fill_b  )
                      : line( xval, yval, r, g, b, ilength)
                         {   set_width(iwidth);  
                             RGB_fill_color =RGB(fill_r, fill_g, fill_b);}

square::~square(){}
                                    
void  square::set_width( int iwidth )  {  width = iwidth;   }

int   square::get_width()              {  return( width );  }

void  square::draw(HDC hDC)
      {	 HPEN pen=NULL;
		 HPEN pen2=NULL;
		 HBRUSH brush=NULL;
		

		 if (pen)DeleteObject(pen); //delete previous created pen
		 if (pen2)DeleteObject(pen2); //delete previous created pen
		 if (brush)DeleteObject(brush); //delete previous created brush

		 HRGN rgn = CreateRectRgn(x+2, y+2, x-2+length, y-2+width); //Sets region to inside square
         
		 brush = CreateSolidBrush (RGB_fill_color); //Create brush
		 SelectObject(hDC,brush); //select into context
		 FillRgn(hDC, rgn, brush); // Fill selected region

		 pen=CreatePen(PS_SOLID,1,RGB_color);  // Create a new pen
         SelectObject(hDC,pen); // select pen into context
         Rectangle(hDC, x, y, x+length, y+width);

		
         
		 pen2=CreatePen(PS_SOLID,1,RGB_fill_color); // Create a new pen
         SelectObject(hDC,pen2); // select pen into context
         Rectangle(hDC, x+2, y+2, x-2+length, y-2+width);

		 
	
      }