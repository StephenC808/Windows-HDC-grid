#include <windows.h>
#include <iostream>   // for cerr
#include <stdio.h>
#include <conio.h> 
#include "resource.h"

class   point
        {
   protected:  int   x;
               int   y;
			   COLORREF RGB_color;
               
   public:     point()  {  x = 0;   y = 0; RGB_color=RGB(0,0,0); }
			   point( int xval, int yval);
               point( int xval, int yval, int r,int g,int b );
			   ~point();
               void  draw(HDC hdc);
               void  set_x( int xval );
               void  set_y( int yval );
               int   get_x();
               int   get_y();
			   void display_point(void);
        };

//=== methods for point class ===============================
point::point( int xval, int yval){x = xval; y = yval;}

point::point( int xval, int yval, int r, int g, int b )
                         {      x = xval;
                                y = yval;      
                                RGB_color =RGB(r,g,b);  }

point::~point(){}
                            
void  point::set_x( int xval )       {  x = xval;      }

void  point::set_y( int yval )       {  y = yval;      }

int   point::get_x()                 {  return( x );   }

int   point::get_y()                 {  return( y );   }

void  point::draw(HDC hDC)
      {  
         int i,j;      
         for( i= -2; i<3; i++ )
            for( j = -2; j<3; j++ )
               SetPixel(hDC, x+i, y+j,RGB_color);   
      }

void point::display_point()
{
	cout << "(" << x << ", " << y << ") ";
}