#include <windows.h>
#include <iostream>   // for cerr
#include <stdio.h>
#include <conio.h> 
#include "resource.h"
#include "Point.h"

class   line:   public point
        {
   protected:  int   length;
   public:     line()  {  x = 0;   y = 0; RGB_color=RGB(0,0,0);  length = 0;  }
               line( int xval, int yval, int r,int g,int b , int ilength);
			   ~line();
               void  draw(HDC hDC);
               void  set_len( int ilength );
               int   get_len();
        };

//=== methods for line class ================================
      line::line( int xval, int yval, int r, int g, int b, int ilength): point( xval, yval, r,g,b)
                                     {  set_len(ilength);  }
	  line::~line(){}
                                     
void  line::set_len( int ilength )   {  length = ilength;  }

int   line::get_len()                {  return( length );  }

void  line::draw(HDC hDC)
      {
       
		 HPEN pen=NULL;
		 if (pen)DeleteObject(pen); //delete previous created pen
		         
		 pen=CreatePen(PS_SOLID,1,RGB_color);  // Create a new pen
         SelectObject(hDC,pen); // select pen into context
         MoveToEx (hDC,x,y,NULL);
		 LineTo(hDC,x+length,y);
       }