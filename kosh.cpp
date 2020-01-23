#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
void drawg(float x1,float y1,float x2,float y2,int l);
main()
{
  int gd=0,gm;
  int l;
do{
  printf("Enter level to draw:");
  scanf("%d",&l);
   initgraph(&gd,&gm," ");
   setcolor(5);
    drawg(25,470,601,470,l);

}while(l==-1);
  getch();
}
void drawg(float x1,float y1,float x2,float y2,int l)
{
    if(l==0)
    {
        line(x1,y1,x2,y2);
    return ;}
    else

{
    drawg(x1,y1,(x2+2*x1)/3,y2,l-1);
    setcolor(2);
    drawg((x2+2*x1)/3,y2,(x2+x1)/2,(y1-((x2-x1)/3.46410161513775)),l-1);
    setcolor(6);
    drawg((x2+x1)/2,(y1-((x2-x1)/3.46410161513775)),(2*x2+x1)/3,y2,l-1);
    setcolor(10);
    drawg((2*x2+x1)/3,y2,x2,y2,l-1);
}
}
