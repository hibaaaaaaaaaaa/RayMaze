#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <GL/glut.h>
#include <conio.h>
#include <math.h>
#include<time.h>
#define PI 3.14159265359
#include "Textureppm/TX3.ppm"
#include "Textureppm/PAV.ppm"
#include "Textureppm/monster2.ppm"
#include "Textureppm/test.ppm"
#include "Textureppm/won.ppm"
#include "Textureppm/lost.ppm"
#include "Textureppm/BIGWINDOW.ppm"
#include "Textureppm/PAV2.ppm"
#include "Textureppm/lv1.ppm"

float degToRad(float a) { return a*PI/180.0;} //conversion du deg au rad
float FixAng(float a){ if(a>359){ a-=360;} if(a<0){ a+=360;} return a;} //pour assuer les valeurs [0;2PI]
 
float px,py; //player positin
float pdx,pdy; //player direction
float theta; //player angle
float frame1,frame2,fps;
  
         //structure buttons  
typedef struct 
{ int w,a,d,s; //button state on off
}ButtonKeys;ButtonKeys Keys;


float minute=3;


        //player
void drawPlayer(int l){
	float c1,c2,c3,c4;
	int c5;
	if(l==1 || l==2){c1=1/3.2;c2=795;c3=1/3.1;c4=10;c5=4;};
	if(l==3){c1=1/2.66;c2=775;c3=1/2.65;c4=6;c5=2;};

	glColor3f(1,1,0);//yellow
	glPointSize(c5);
	glBegin(GL_POINTS);
	glVertex2i(px*c1+c2,py*c3);
	glEnd();
	
	glLineWidth(1);
   glBegin(GL_LINES);
   glVertex2i(px*c1+c2,py*c3);
   glVertex2i(px*c1+pdx*c4+c2,py*c3+pdy*c4);
   glEnd();
}

void drawHealth(){
	glColor3f(255,255,255);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160 ,15 ); //cordonnee cote 1
        glVertex2i(400, 15 ); // cordonnee cote 2
        glVertex2i(400 ,33 ); //cordonnee cote 3
        glVertex2i(160, 33); //cordonnee  cote 4
        glEnd();
      
        if(minute>=2.9 && minute<3){
        
		glColor3f(0,1,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-3, 15+3 ); // cordonnee cote 2
        glVertex2i(400-3 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
         if(minute>=2.8 && minute<2.9){
        
		glColor3f(0,1,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-13, 15+3 ); // cordonnee cote 2
        glVertex2i(400-13 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
         if(minute>=2.7 && minute<2.8){
        
		glColor3f(0,1,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-23, 15+3 ); // cordonnee cote 2
        glVertex2i(400-23 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
         if(minute>=2.6 && minute<2.7){
        
		glColor3f(0,1,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-33, 15+3 ); // cordonnee cote 2
        glVertex2i(400-33 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
     if(minute>=2.5 && minute<2.6){
        
		glColor3f(0,1,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-43, 15+3 ); // cordonnee cote 2
        glVertex2i(400-43 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
         if(minute>=2.4 && minute<2.5){
        
		glColor3f(0,1,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-53, 15+3 ); // cordonnee cote 2
        glVertex2i(400-53 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
          if(minute>=2.3 && minute<2.4){
        
		glColor3f(0,1,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-63, 15+3 ); // cordonnee cote 2
        glVertex2i(400-63 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
          if(minute>=2.2 && minute<2.3){
        
		glColor3f(0,1,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-73, 15+3 ); // cordonnee cote 2
        glVertex2i(400-73 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
          if(minute>=2.1 && minute<2.2){
        
		glColor3f(0,1,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-83, 15+3 ); // cordonnee cote 2
        glVertex2i(400-83 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
          if(minute>=2 && minute<2.1){
        
		glColor3f(0,1,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-93, 15+3 ); // cordonnee cote 2
        glVertex2i(400-93 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
          if(minute>=1.9 && minute<2){
        
		glColor3f(1,0.5,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-103, 15+3 ); // cordonnee cote 2
        glVertex2i(400-103,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
          if(minute>=1.8 && minute<1.9){
        
		glColor3f(1,0.5,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-113, 15+3 ); // cordonnee cote 2
        glVertex2i(400-113 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
           if(minute>=1.7 && minute<1.8){
        
		glColor3f(1,0.5,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-123, 15+3 ); // cordonnee cote 2
        glVertex2i(400-123 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
           if(minute>=1.6 && minute<1.7){
        
		glColor3f(1,0.5,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-133, 15+3 ); // cordonnee cote 2
        glVertex2i(400-133 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
           if(minute>=1.5 && minute<1.6){
        
		glColor3f(1,0.5,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-143, 15+3 ); // cordonnee cote 2
        glVertex2i(400-143 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
           if(minute>=1.4 && minute<1.5){
        
		glColor3f(1,0.5,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-153, 15+3 ); // cordonnee cote 2
        glVertex2i(400-153 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
           if(minute>=1.3 && minute<1.4){
        
		glColor3f(1,0.5,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-163, 15+3 ); // cordonnee cote 2
        glVertex2i(400-163 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
           if(minute>=1.2 && minute<1.3){
        
		glColor3f(1,0.5,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-173, 15+3 ); // cordonnee cote 2
        glVertex2i(400-173 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
           if(minute>=1.1 && minute<1.2){
        
		glColor3f(1,0.5,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-183, 15+3 ); // cordonnee cote 2
        glVertex2i(400-183 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
           if(minute>=1 && minute<1.1){
        
		glColor3f(1,0.5,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-193, 15+3 ); // cordonnee cote 2
        glVertex2i(400-193 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
           if(minute>=0.9 && minute<1){
        
		glColor3f(1,0,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-203, 15+3 ); // cordonnee cote 2
        glVertex2i(400-203 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
           else if(minute>=0.2 && minute<0.9){
        
		glColor3f(1,0,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-213, 15+3 ); // cordonnee cote 2
        glVertex2i(400-213 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
           if(minute>0.1 && minute<0.2){
        
		glColor3f(1,0,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-223, 15+3 ); // cordonnee cote 2
        glVertex2i(400-223 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
         if(minute==0.1){
        
		glColor3f(1,0,0);
	glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(160+3,15+3 ); //cordonnee cote 1
        glVertex2i(400-233, 15+3 ); // cordonnee cote 2
        glVertex2i(400-233 ,33-3 ); //cordonnee cote 3
        glVertex2i(160+3, 33-3); //cordonnee  cote 4
        glEnd();}
}
   
int mapX1=8; //map width level 1
int mapY1=8; //map height level 1
int mapS1=64; //map cube size level 1
int mapW1[]=  // map wall level 1
{
 1,2,3,5,5,1,2,3,
 5,0,1,0,5,1,0,5,
 3,0,0,4,4,0,0,5,
 2,5,5,0,3,2,1,1,
 1,0,0,0,0,0,1,2,
 2,0,0,0,0,0,0,3,
 2,3,0,1,0,1,0,1,
 1,3,2,1,5,5,3,2,
 
};

 
        
int mapX2=8; //map width level 2
int mapY2=8; //map height level 2
int mapS2=64; //map cube size level 2
int mapW2[]=  // map wall level 2
{
 1,1,1,2,2,1,1,2,
 1,0,1,3,0,1,0,1,
 1,0,0,4,0,0,1,1,
 1,1,2,3,0,0,0,2,
 3,0,0,0,0,1,1,1,
 1,0,0,0,0,4,0,1,
 2,3,0,1,0,1,0,1,
 1,1,2,2,3,2,1,3,
 
}; 
    
int mapX3=31; //map width level 3
int mapY3=31; //map height level 3
int mapS3=16; //map cube size level 3
int mapW3[]=  // map wall level 3
{
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,
 1,0,0,0,1,4,1,1,0,0,1,0,1,0,1,0,0,0,0,1,1,0,0,1,0,1,0,1,0,0,1,
 1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,1,
 1,1,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,1,0,1,
 1,0,0,1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,1,
 1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,
 1,0,0,0,1,1,1,1,0,0,1,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,1,1,1,1,
 1,0,1,0,1,1,1,1,1,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,1,1,1,0,0,1,
 1,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,1,
 1,0,0,0,0,0,0,4,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,1,
 1,0,0,1,0,0,0,1,0,1,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,
 1,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,
 1,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,1,0,1,1,1,1,1,1,1,0,0,1,0,0,1,
 1,0,1,0,0,1,0,1,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1,
 1,1,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,1,1,1,4,1,1,1,0,0,1,0,0,1,
 1,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,1,0,0,0,1,1,0,1,1,1,1,4,1,
 1,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,0,0,0,0,1,
 1,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,4,1,1,0,0,0,0,0,0,1,
 1,0,1,1,0,1,0,1,1,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
 1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,
 1,0,0,1,0,1,1,1,0,0,1,0,0,0,0,1,0,1,1,0,0,0,0,1,1,0,0,0,1,0,1,
 1,0,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,1,0,1,
 1,1,1,1,0,1,1,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,
 1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,
 1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,
 1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

        



	
       //Map2D
void Map2D(int l){
	int x,y,xo,yo;
	int mapX,mapY,*T,c1,c2;
	if(l==1){mapX=mapX1;mapY=mapY1;T=mapW1;c1=20;c2=795;};
	if(l==2){mapX=mapX2;mapY=mapY2;T=mapW2;c1=20;c2=795;};
	if(l==3){mapX=mapX3;mapY=mapY3+1;T=mapW3;c1=6;c2=775;};
	
	
	for(y=0;y<mapY;y++){
		for(x=0;x<mapX;x++){
			if(T[y*mapX+x]>=1 && T[y*mapX+x]!=4){
				glColor3f(1,1,1);} // white color
		else if(T[y*mapX+x]==4){
				glColor3f(1,0,0);} // red color	
			else{
				glColor3f(0,0,0);} //black  color 
        xo=x*c1;yo=y*c1;
        
        glBegin(GL_QUADS);	//dessin un quadrilatere		
        glVertex2i(xo+1 +c2 ,yo +1); //cordonnee cote 1
        glVertex2i(xo +1+c2, yo+c1-1 ); // cordonnee cote 2
        glVertex2i(xo+c1-1+c2 ,yo+c1-1 ); //cordonnee cote 3
        glVertex2i(xo+c1-1 +c2, yo+1 ); //cordonnee  cote 4
        glEnd();
}
}
}	
        // func calculating distance
float dist(float ax,float ay,float bx,float by,float ang ) //function that returns the distance between the player and rays 
{
	return cos(degToRad(ang))*(bx-ax)-sin(degToRad(ang))*(by-ay);
}

typedef struct       //All veriables per sprite
{
 int type;           //static, key, enemy
 int state;          //on off
 int map;            //texture to show
 float x,y,z;        //position
}sprite; sprite sp[1];
int depth[120];      //hold wall line depth to compare for sprite depth





         // draw 2D rays
void drawRays2D(int l)
{
	
    int r,mx,my,mp,d;
    float rx,ry,ra,xo,yo;//disT;
    ra=FixAng(theta+30);
    int c1,c2,mapS,*T1,*T2,*T3,mapX,mapY;
    float c3,c4;
    if(l==1){mapX=mapX1;mapY=mapY1;c1=64;c2=8;mapS=mapS1;T1=mapW1;T2=lv1;T3=PAV2;c3=1;c4=0.5;};
    if(l==2){mapX=mapX2;mapY=mapY2;c1=64;c2=8;mapS=mapS2;T1=mapW2;T2=TX3;T3=PAV;c3=0.5;c4=0.1;};
    if(l==3){mapX=mapX3;mapY=mapY3;c1=16;c2=31;mapS=mapS3;T1=mapW3;T2=test;T3=WINDOW;c3=0.2;c4=0.2;}
    
    
    for (r=0;r<120;r++)
    {    //vertical
     int vmt=0,hmt=0;
      d=0;
        float disV=100000;// we are looking for the shortest ray that hits first(hori or verti), so we initialize the vertical distance betwwen the player nd the end of the ray very high
        float vx,vy;//vertical line's x and y position
        float nTan=tan(degToRad(ra));
        if(cos(degToRad(ra))>0.001){rx=(((int)px/c1)*c1)+c1;ry=(px-rx)*nTan+py;xo=c1;yo=-xo*nTan;}//looking left
        else if(cos(degToRad(ra))<-0.001){rx=(((int)px/c1)*c1)-0.0001;ry=(px-rx)*nTan+py;xo=-c1;yo=-xo*nTan;}//looking right
        else {rx=px;ry=py;d=c2;}//looking up or down
        while (d<c2)
        {
            mx=(int)(rx)/c1;my=(int)(ry)/c1;mp=my*mapX+mx;
            if ( mp>0 && mp <mapX*mapY && T1[mp]>0){  vmt=T1[mp]-1;vx=rx; vy= ry; disV=dist(px,py,vx,vy,ra);d=c2;}//hit the wall
            else{rx+=xo;ry+=yo;d+=1;}//next line
        }
        //horizontal
        d=0;
        float disH=100000;// we are looking for the shortest ray that hits first(hori or verti), so we initialize the horizontal distance betwwen the player nd the end of the ray very high
        //float hx=px,hy=py;//horizontal line's x and y position
        float hx,hy;
		float aTan=1/tan(degToRad(ra));
        if(sin(degToRad(ra))> 0.001){ry=(((int)py/c1)*c1)-0.0001;rx=(py-ry)*aTan+px;yo=-c1;xo=-yo*aTan;}//looking up
        else if (sin(degToRad(ra))<-0.001){ry=(((int)py/c1)*c1)+c1;rx=(py-ry)*aTan+px;yo=c1;xo=-yo*aTan;}//looking down
        else {rx=px;ry=py;d=c2;}//looking left or right
        while (d<c2)
        {
            mx=(int)(rx)/c1;my=(int)(ry)/c1;mp=my*mapX+mx;
            if (mp >0 && mp<mapX*mapY && T1[mp]>0){  hmt=T1[mp]-1; hx=rx; hy= ry; disH=dist(px,py,hx,hy,ra); d=c2;}//hit the wall
            else{rx+=xo;ry+=yo;d+=1;}//next line
        }

        float shade=1;
        if(disV<disH){hmt=vmt;shade=0.5; rx=vx ;ry=vy; disH=disV;}
        int ca=FixAng(theta-ra);//avoid fish eye
		disH=disH*cos(degToRad(ca)) ;//distance btw player and ray angle
        int lineH=(mapS*640)/disH;//line Height
        float ty_step=32.0/(float)lineH; //creaating texture y variable step by diving the wall height (32) cuz the textures are (32.32) by the line height
        float ty_off=0; // create an offset variable to be hald the difference beetween the scrren height and the line height
        if(lineH>640){ty_off=(lineH-640)/2.0; lineH=640;}
        int line0 = 320- (lineH/2); //lineOffset
        
       depth[r]=disH;
       
         //Draw 3D Walls
        
        int y;
        float ty=ty_off*ty_step; // texture y values
        float tx; // textures x values
        if(shade==1){ tx=(int)(rx/2.0)%32; if(ra>180){ tx=31-tx;}}  //textures are half the size thats why we divide by 2
        else { tx=(int)(ry/2.0)%32; if(ra>90 && ra<270){ tx=31-tx;}}
        for(y=0;y<lineH;y++){ // we were drawing line with a solid line color but now inside this loop we re doing it zith pixels
       
 		int pixel=((int)ty*32+(int)tx)*3+(hmt*32*32*3);
 		int red  = T2[pixel+0]*shade;
 		int green =T2[pixel+1]*shade;
 		int blue  =T2[pixel+2]*shade;
 		glPointSize(8);glColor3ub(red,green,blue);glBegin(GL_POINTS);glVertex2i(r*8,y+line0 );glEnd();
        ty+=ty_step;// add the step to textures y each pixels
        }


 	// drawing floor
 	
       for(y=line0+lineH;y<640;y++) //start drawing from the buttom to the scrren edge
 	{
  		float dy=y-(640/2.0), deg=degToRad(ra), raFix=cos(degToRad(FixAng(theta-ra)));
 		 tx=px/2 + cos(deg)*158*2*32/dy/raFix;
 		 ty=py/2 - sin(deg)*158*2*32/dy/raFix;
  		int pixel=(((int)(ty)&31)*32 + ((int)(tx)&31))*3;
  		int red   =T3[pixel+0]*c3;
  		int green =T3[pixel+1]*c3;
 		int blue  =T3[pixel+2]*c3;
  		glPointSize(8);glColor3ub(red,green,blue); glBegin(GL_POINTS); glVertex2i(r*8,y); glEnd();
  
     //drawing ceiling
  	 pixel=(((int)(ty)&31)*32 + ((int)(tx)&31))*3;
  		red   =T3[pixel+0]*c4;
  		green =T3[pixel+1]*c4;
 		blue  =T3[pixel+2]*c4;
  		glPointSize(8);glColor3ub(red,green,blue); glBegin(GL_POINTS); glVertex2i(r*8,640-y); glEnd();
		  }
  
 
        ra=FixAng(ra-0.5);
    }
}




int gamestate=0,timer=0;


//Monster
void drawSprite(){
  if(px <sp[0].x+20 && px>sp[0].x-20 && py<sp[0].y+40 && py>sp[0].y-40  ){gamestate=7;}
  
  
  
int spx=(int)sp[0].x/64,spy=(int)sp[0].y/64;          //normal grid position
 int spx_add=((int)sp[0].x+15)/64, spy_add=((int)sp[0].y+15)/64; //normal grid position plus     offset
 int spx_sub=((int)sp[0].x-15)/64, spy_sub=((int)sp[0].y-15)/64; //normal grid position subtract offset
 if(sp[0].x>px && mapW2[spy*8+spx_sub]==0){ sp[0].x-=0.018*fps;}
 if(sp[0].x<px && mapW2[spy*8+spx_add]==0){ sp[0].x+=0.018*fps;}
 if(sp[0].y>py && mapW2[spy_sub*8+spx]==0){ sp[0].y-=0.018*fps;}
 if(sp[0].y<py && mapW2[spy_add*8+spx]==0){ sp[0].y+=0.018*fps;}

    float sx=sp[0].x-px;
    float sy=sp[0].y-py;
    float sz=sp[0].z;


    float CS=cos(degToRad(theta)),SN=sin(degToRad(theta));
    float a=sy*CS+sx*SN;
    float b=sx*CS-sy*SN;
    sx=a;
    sy=b;

    sx=(sx*108.0/sy)+(120/2);
    sy=(sz*108.0/sy)+(80/2);

    int x,y;
    int scale=32*80/b;
    if(scale<0){scale=0;
    }
    if (scale>120){scale=120;
    }
float t_x=0, t_y=31,t_x_step=31.5/(float)scale,t_y_step=32/(float)scale;
    for(x=sx-scale/2;x<sx+scale/2;x++)
    {
    	t_y=31;
        for(y=0;y<scale;y++)
        {
        	
            if(x>0 && x <120 && b<depth[x])
            {
            	int pixel=((int)t_y*32+(int)t_x)*3;
 		int red  = monster2[pixel+0];
 		int green =monster2[pixel+1];
 		int blue  =monster2[pixel+2];	
 		if(red!=255 && green!=0 && blue!=255){
 		
                glPointSize(8);glColor3ub(red,green,blue);glBegin(GL_POINTS);glVertex2i(x*8,sy*8-y*8);glEnd();}
                t_y-=t_y_step;
                if(t_y<0){t_y=0;}
                }
            }
            t_x+=t_x_step;
        }

    }


//SCREEN WON/LOST
void screen(int v) //draw any full screen image. 120x80 pixels
{
 int x,y;
 int *T;
 //if(v==1){ T=title;}
 if(v==2){ T=won;}
 if(v==3){ T=lost;}
 for(y=0;y<80;y++)
 {
  for(x=0;x<120;x++)
  {
   int pixel=(y*120+x)*3;
   int red   =T[pixel+0];
   int green =T[pixel+1];
   int blue  =T[pixel+2];
   glPointSize(8); glColor3ub(red,green,blue); glBegin(GL_POINTS); glVertex2i(x*8,y*8); glEnd();
  }


}}


void init()
{
	glClearColor(0.3,0.3,0.3,0);//window gray color
	px=150; py=400; theta=90;
    pdx=cos(degToRad(theta)); pdy=-sin(degToRad(theta)); 
    sp[0].type=1; sp[0].state=1; sp[0].map=0; sp[0].x=6*64; sp[0].y=5*64;   sp[0].z=20; //enemy\
  
}


float fr1,fr2,fps;//FRAME PER SECOND;
void display()
{
//frames per second // we hold the current elapsed time ans substract that from the previous elapsed time
fr2=glutGet(GLUT_ELAPSED_TIME); fps=(fr2-fr1); fr1=glutGet(GLUT_ELAPSED_TIME);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer with current clearing color	
if(gamestate==0){init();timer=0;gamestate=1;}


if(gamestate==1){
	
	
		if(Keys.a==1){ //preciser  la direction du joueur
		theta+=0.1*fps;
	     	theta=FixAng(theta);
	     	pdx=cos(degToRad(theta));
			pdy=-sin(degToRad(theta));}
	if(Keys.d ==1){ //preciser la direction du joueur
		 	theta-=0.1*fps;
	     	theta=FixAng(theta);
	     	pdx=cos(degToRad(theta));
			pdy=-sin(degToRad(theta));}		
			
			

	// To avoid hitting walls we create a point with xoff , yoff		
	int xoff=0; if (pdx<0) {xoff-=20;} else {xoff+=20;}
	int yoff=0; if (pdy<0) {yoff-=20;} else {yoff+=20;}
	int pxgr=px/64;//player grid x position 
	int pxgr_add_xoff=(px+xoff)/64;
	int pxgr_sub_xoff=(px-xoff)/64; //for behind
	int pygr=py/64;//player grid y position 
	int pygr_add_yoff=(py+yoff)/64;
	int pygr_sub_yoff=(py-yoff)/64; //for behind
	
	
	
    if(Keys.w==1 ){ // faire avancer le joueur suivant la direction
		    if( mapW1[pygr*mapX1+pxgr_add_xoff]==0 ){px+=pdx*0.1*fps;}
		     if( mapW1[pygr_add_yoff*mapX1+pxgr]==0 ){py+=pdy*0.1*fps;}	}
		     
	if(Keys.s==1){ //  faire avancer le joueur suivant la direction
		   if( mapW1[pygr*mapX1+pxgr_sub_xoff]==0 )  {px-=pdx*0.1*fps;}
           if( mapW1[pygr_sub_yoff*mapX1+pxgr]==0 ) {py-=pdy*0.1*fps;}}
           
 
 drawRays2D(1);
  Map2D(1);
 drawPlayer(1);

glutPostRedisplay(); //Fonction plaçant en file d'attente d'événements un ordre de rafraîchissement de la fenêtre d'affichage
glColor3f(255,255,255);
glRasterPos3f(10,630,0);
char time[]="T I M E : ";
char health[]="H E A L T H :";
char level[] = "L E V E L : 1";
int i;
for(i=0;i<strlen(time);i++){
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,time[i]);
}
glRasterPos3f(10,30,0);	
for(i=0;i<strlen(health);i++){
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,health[i]);
}
glRasterPos3f(820,630,0);	
for(i=0;i<strlen(level);i++){
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,level[i]);
}
  system("cls");
    char buf[100];
    gcvt(minute,5,buf);
    glRasterPos3f(110,630,0);
    for(i=0;i<strlen(buf);i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,buf[i]);}
		minute=minute-0.001;
drawHealth();
 
}
if( (int)px/64==6 && (int)py/64==1 && minute>0.1){gamestate=2;};
if(gamestate==2){screen(2);timer+=1*fps;if(timer>4000){timer=0;gamestate=4;minute=3;}};
if(minute<=0.1){gamestate=3;}
if(gamestate==3){screen(3);timer+=1*fps;if(timer>4000){timer=0;gamestate=0;minute=3;mapW1[20]=4;mapW1[21]=4;}
};
if(gamestate==4) {init();timer=0;gamestate=5;}
if(gamestate==5){
//	buttons
	if(Keys.a==1){ //preciser  la direction du joueur
		theta+=0.1*fps;
	     	theta=FixAng(theta);
	     	pdx=cos(degToRad(theta));
			pdy=-sin(degToRad(theta));}
	if(Keys.d ==1){ //preciser la direction du joueur
		 	theta-=0.1*fps;
	     	theta=FixAng(theta);
	     	pdx=cos(degToRad(theta));
			pdy=-sin(degToRad(theta));}		
			
			

	// To avoid hitting walls we create a point with xoff , yoff		
	int xoff=0; if (pdx<0) {xoff-=20;} else {xoff+=20;}
	int yoff=0; if (pdy<0) {yoff-=20;} else {yoff+=20;}
	int pxgr=px/64;//player grid x position 
	int pxgr_add_xoff=(px+xoff)/64;
	int pxgr_sub_xoff=(px-xoff)/64; //for behind
	int pygr=py/64;//player grid y position 
	int pygr_add_yoff=(py+yoff)/64;
	int pygr_sub_yoff=(py-yoff)/64; //for behind
	
	
	
    if(Keys.w==1 ){ // faire avancer le joueur suivant la direction
		    if( mapW2[pygr*mapX2+pxgr_add_xoff]==0 ){px+=pdx*0.1*fps;}
		     if( mapW2[pygr_add_yoff*mapX2+pxgr]==0 ){py+=pdy*0.1*fps;}	}
		     
	if(Keys.s==1){ //  faire avancer le joueur suivant la direction
		   if( mapW2[pygr*mapX2+pxgr_sub_xoff]==0 )  {px-=pdx*0.1*fps;}
           if( mapW2[pygr_sub_yoff*mapX2+pxgr]==0 ) {py-=pdy*0.1*fps;}}
           
 
 drawRays2D(2);
 Map2D(2);
 drawPlayer(2);

glutPostRedisplay(); //Fonction plaçant en file d'attente d'événements un ordre de rafraîchissement de la fenêtre d'affichage
glColor3f(255,255,255);
glRasterPos3f(10,630,0);
char time[]="T I M E : ";
char health[]="H E A L T H :";
char level[] = "L E V E L : 2";
int i;
for(i=0;i<strlen(time);i++){
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,time[i]);
}
glRasterPos3f(10,30,0);	
for(i=0;i<strlen(health);i++){
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,health[i]);
}
glRasterPos3f(820,630,0);	
for(i=0;i<strlen(level);i++){
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,level[i]);
}
  system("cls");
    char buf[100];
    gcvt(minute,5,buf);
    glRasterPos3f(110,630,0);
    for(i=0;i<strlen(buf);i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,buf[i]);}
		minute=minute-0.001;
drawHealth();
 drawSprite();  
}
if( (int)px/64==1 && (int)py/64==1 && minute>0.1){gamestate=6;};
if(gamestate==6){screen(2);timer+=1*fps;if(timer>4000){timer=0;gamestate=8;minute=3;}};
if(minute<=0.1){gamestate=7;}
if(gamestate==7){screen(3);timer+=1*fps;if(timer>4000){timer=0;gamestate=4;minute=3;mapW2[19]=4;mapW2[45]=4;}
};
if(gamestate==8) {init();timer=0;gamestate=9;}
if(gamestate==9){
	
	
	
//	buttons
	if(Keys.a==1){ //preciser  la direction du joueur
		theta+=0.09*fps;
	     	theta=FixAng(theta);
	     	pdx=cos(degToRad(theta));
			pdy=-sin(degToRad(theta));}
	if(Keys.d ==1){ //preciser la direction du joueur
		 	theta-=0.09*fps;
	     	theta=FixAng(theta);
	     	pdx=cos(degToRad(theta));
			pdy=-sin(degToRad(theta));}		
			
			

	// To avoid hitting walls we create a point with xoff , yoff		
	int xoff=0; if (pdx<0) {xoff-=10;} else {xoff+=10;}
	int yoff=0; if (pdy<0) {yoff-=10;} else {yoff+=10;}
	int pxgr=px/16;//player grid x position 
	int pxgr_add_xoff=(px+xoff)/16;
	int pxgr_sub_xoff=(px-xoff)/16; //for behind
	int pygr=py/16;//player grid y position 
	int pygr_add_yoff=(py+yoff)/16;
	int pygr_sub_yoff=(py-yoff)/16; //for behind
	
	
	
    if(Keys.w==1 ){ // faire avancer le joueur suivant la direction
		    if( mapW3[pygr*mapX3+pxgr_add_xoff]==0 ){px+=pdx*0.05*fps;}
		     if( mapW3[pygr_add_yoff*mapX3+pxgr]==0 ){py+=pdy*0.05*fps;}	}
		     
	if(Keys.s==1){ //  faire avancer le joueur suivant la direction
		   if( mapW3[pygr*mapX3+pxgr_sub_xoff]==0 )  {px-=pdx*0.05*fps;}
           if( mapW3[pygr_sub_yoff*mapX3+pxgr]==0 ) {py-=pdy*0.05*fps;}}
           
           

	
	

 drawRays2D(3);
 Map2D(3);
 drawPlayer(3);

glutPostRedisplay(); //Fonction plaçant en file d'attente d'événements un ordre de rafraîchissement de la fenêtre d'affichage
glColor3f(255,255,255);
glRasterPos3f(10,630,0);
char time[]="T I M E : ";
char health[]="H E A L T H :";
char level[] = "L E V E L : 3";
int i;
for(i=0;i<strlen(time);i++){
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,time[i]);
}
glRasterPos3f(10,30,0);	
for(i=0;i<strlen(health);i++){
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,health[i]);
}
glRasterPos3f(820,630,0);	
for(i=0;i<strlen(level);i++){
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,level[i]);
}
  system("cls");
    char buf[100];
    gcvt(minute,5,buf);
    glRasterPos3f(110,630,0);
    for(i=0;i<strlen(buf);i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,buf[i]);}
		minute=minute-0.001;
drawHealth();}
if( (int)px/16==5 && (int)py/16==2 && minute>0.1){gamestate=10;};
if(gamestate==10){screen(2);timer+=1*fps;if(timer>4000){timer=0;}
};
if(minute<=0.1){gamestate=11;}
if(gamestate==11){screen(3);timer+=1*fps;if(timer>4000){timer=0;gamestate=8;minute=3;mapW3[67]=4;mapW3[486]=4;mapW3[525]=4;mapW3[579]=4;mapW3[317]=4;
}
};

glutPostRedisplay(); //Fonction plaçant en file d'attente d'événements un ordre de rafraîchissement de la fenêtre d'affichage

 glutSwapBuffers();//Fonction assurant le swap entre les deux buffers d'affichage dans le cas où le double buffering est utilisé.

}
// set the key buttion to 1 when the key is pressed
void ButtonDown(unsigned char key,int x,int y){
	int c1,mapX,*T;
	if(gamestate==1){c1=64;mapX=mapX1;T=mapW1;
	}
	if(gamestate==5){c1=64;mapX=mapX2;T=mapW2;
	}
	if(gamestate==9){c1=16;mapX=mapX3;T=mapW3;
	}
	if(key=='a'){Keys.a=1;}
	if(key =='d'){Keys.d=1;}
	if(key=='w'){Keys.w=1;}
	if(key=='s'){Keys.s=1;}
	
	// To open doors
	if (key=='e'){
	int xoff=0; if (pdx<0) {xoff=-20;} else {xoff=20;}
	int yoff=0; if (pdy<0) {yoff=-20;} else {yoff=20;}

	int pxgr=px/c1;//player grid x position 
	int pxgr_add_xoff=(px+xoff)/c1;
	int pxgr_sub_xoff=(px-xoff)/c1; //for behind
	int pygr=py/c1;//player grid y position 
	int pygr_add_yoff=(py+yoff)/c1;
	int pygr_sub_yoff=(py-yoff)/c1; //for behind
	   if( T[pygr*mapX+pxgr_add_xoff]==4 ){T[pygr*mapX+pxgr_add_xoff]=0;}
	   if( T[pygr_add_yoff*mapX+pxgr]==4 ){T[pygr_add_yoff*mapX+pxgr]=0;}
	  if ( T[pygr*mapX+pxgr_sub_xoff]==4 ) {T[pygr*mapX+pxgr_sub_xoff]=0;}
	   if( T[pygr_sub_yoff*mapX+pxgr]==4 ){T[pygr_sub_yoff*mapX+pxgr]=0;}
	}
	glutPostRedisplay();}
// set the key button to zero automatically after pressing so that the player can keep moving	
void ButtonUp(unsigned char key,int x,int y){
	if(key=='a'){Keys.a=0;}
	if(key =='d'){Keys.d=0;}
	if(key=='w'){Keys.w=0;}
	if(key=='s'){Keys.s=0;}
//	mapW[191]=4;
	glutPostRedisplay();}
	


		
void resize(int w,int h)
{
	glutReshapeWindow(960,640);
}



int main(int argc, char** argv)
{ 
 glutInit(&argc, argv); //Initialize GLUT
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
 glutInitWindowSize(960,640); //set window's initial width & height 
 glutInitWindowPosition(glutGet(GLUT_SCREEN_WIDTH)/2-960/2,glutGet(GLUT_SCREEN_HEIGHT)/2-640/2);
 glutCreateWindow("Jeu 3D");//Create window with given title
 gluOrtho2D(0,960,640,0);//left,right,top,bottom
 init();
 glutDisplayFunc(display); // Définit la fonction exécutée automatiquement par GLUT quand un événement intervient entraînant le rafraîchissement de l'image affichée
 glutReshapeFunc(resize); 
 glutKeyboardFunc(ButtonDown);//Définit la fonction exécutée automatiquement par GLUT lorsqu'une touche ASCII du clavier est frappée. Au moment de son exécution, cette fonction recevra les paramètres key, x et y 
 glutKeyboardUpFunc(ButtonUp);

 //glutTimerFunc(50,counter ,0);
 glutMainLoop();//fnct qui assure la boucle principale d'affichage

 return 0;
}









