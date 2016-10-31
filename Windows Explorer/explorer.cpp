    /*
	Name: Md. Rayhan Shikder
	Student ID: 0905060
	CSE Dept. Sec: A2
	L-1,T-2 term project
	Date of submission: 06.060.2011

	*/





#include <windows.h>
#include<direct.h>
#include<process.h>
# include "iGraphics.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>

////////////////function definition/////////////////////////////
////////////////////////////////////////////////////////////////




int countdrive();
void first();
void rbformenu(int mx,int my);
void drwbox();
int show_drive();
void back();
void s_drive(int j);
void tree();
int showt_drive();
void tree_tree();
void ts_drive(int j);
void dis_tree();
void drive_size();


struct node{ ////structure for tree
char stree[200];
struct node *next;
struct node *prev;
struct node *up;
struct node *down;
};

struct node *head=NULL, *dnhead=NULL;
void displaytree(struct node *nodp,struct node *nodc);





////////////////////////variable declaration//////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////


char fstr[8][15];
int dir_count;
char arr_drive[200];//for the drive path
char ad[200];/////////working as temp
char acp[200];

char file_name[400][100];//for the file name
char arr_dir[20][400][100];////////////storing the path of a directorie's folders
char sdrive[20][400][100];//////stores file name and showing it
char tarr_play[20][400][100];
char play[200];


char adrv[20][100];///////////////////showing the path name
char day[20][400][30];
char day2[20][400][30];
char rowc[20][20];
char rowfl[20][20];
char rowfr[20][20];

char size1[20][5000][20];//for size of file
char freesp[50];
char totalsp[50];//for the size of the drive

int row[100];

int dx, dy;
int rect_x,rect_y;
int dm;
int rmouse_x;
int rmouse_y;
int orgmx;
int orgmy;
int adr,x,y,adrs;
int sx=0,sy=0,sn=0;
int ff=0,down=0;
int file_count;
short cnter;
short counter,node_f=0;
short mode=1,
      node_r=0,
	  node_lf=0,node_llf=0,node_drbx=0,
	  node_dsize=0,
	  node_n=0,
	  shw=0,
	  bak=0;

typedef struct{
	unsigned a: 1;////////////// flags  (using bit field) /////////////
    unsigned b: 1;
	unsigned c: 1;
	unsigned d: 1;
}bit;

bit flag={0};





//////////////////////////////////////////////////////////////////////////
////////////////////////////////variables for tree/////////////////////////////////////
///////////////////////////////////////////////////////////////////////


char at[200];
char arrt_drive[200];
char tsdrive[400][100];//storing the name of file and giving it to tree_tree() for creating linked list
char tarr_dir[20][400][100];
char filet_name[400][100];
char ch[]={'C','D','E','F','G','H','I','J','K','L'};

int rowt[100],tfno=0,downtree=0,tdown=0,lk=0,chn=1,tt=0;
int dr=0,fr=0,leaf=0,tf,lj=0,ty,tj=0,tff=0,atr=0,abc=0;//for tree
short flag_tree=0;



///////////////////tree variable ends////////////////////////////////////







////////////////////////////////functions ////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////





int countdrive()// to count the drive numbers
{
	counter = 0;
	unsigned long n;
	n =_getdrives();
	n >>= 2;
	for(;n;){
		if(n&1)
			counter++;
		n >>= 1;
	}
	cnter =counter;
	return counter;
}






void inception()
{
	iSetColor(255,255,255);
    iFilledRectangle(0,0,1000,600);
	
	iSetColor(80, 80, 90);
	iText(350, 570,"Windows Explorer",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(100,100,150);
	iText(351, 571, "Windows Explorer",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(80,80, 90);
	iText(352,572,"Windows Explorer",GLUT_BITMAP_TIMES_ROMAN_24);
	
	iSetColor(10,10,10);
	iRectangle(100,529,600,25);

	iSetColor(230,220,250);
	iFilledRectangle(100,530,599,24);

	iSetColor(60,60,20);
	iText(110,535,"path:",GLUT_BITMAP_HELVETICA_18);

	iLine(180,60,180,500);
	iLine(10,500,990,500);
	iLine(10,60,10,500);
	iLine(10,60,990,60);
	iLine(990,60,990,500);

	
}




void drwbox()
{
	int lm,l;
	lm=adrs%3;
	l=adrs/3;

  iSetColor(210,235,250);
  iFilledRectangle(185+(lm*260),458-(l-down)*40,200,42);
  iSetColor(200,210,250);
  iRectangle(185+(lm*260),458-(l-down)*40,200,41);
  iSetColor(100,100,100);

iText(435,10,day[ff-1][adrs],GLUT_BITMAP_HELVETICA_18);
iText(640,10,day2[ff-1][adrs],GLUT_BITMAP_HELVETICA_18);

iText(435,10,day[ff-1][adrs],GLUT_BITMAP_HELVETICA_18);
iText(640,10,day2[ff-1][adrs],GLUT_BITMAP_HELVETICA_18);

iText(435,10,day[ff-1][adrs],GLUT_BITMAP_HELVETICA_18);
iText(640,10,day2[ff-1][adrs],GLUT_BITMAP_HELVETICA_18);
iSetColor(120,110,100);
iText(350,35,sdrive[ff-1][adrs],GLUT_BITMAP_HELVETICA_12);

iSetColor(150,100,100);
iText(355,10,"date created:",GLUT_BITMAP_HELVETICA_12);
iText(555,10,"date modified:",GLUT_BITMAP_HELVETICA_12);
iText(248,35,"File/Folder name:",GLUT_BITMAP_HELVETICA_12);


iSetColor(100,100,100);
iText(248,10,size1[ff-1][adrs],GLUT_BITMAP_HELVETICA_12);



}





void s_drive(int j)

{
	int k,l,lm,mn,g,h,sc;
char str1[20];
if(j==-1)
{
	iSetColor(10,10,10);
		iText(200,430,"No file Found",GLUT_BITMAP_TIMES_ROMAN_24);
}

else
{

for(k=down;k<j;k++){
    


mn=strlen(sdrive[ff-1][k]);
g=mn-3;
	
	
	for( h= 0;sdrive[ff-1][k][g] != '\0' && h<3;h++)
		str1[h] = sdrive[ff-1][k][g++];
	str1[h] = '\0';
	lm=k/3;







	
	if(down>0){
	 
		 if(k>29 && k<=(29+(down*3)) && (lm-down)>=0)
	 {
       l=k%3;
	   
	   if((strcmp(str1,"mp3")==0) || (strcmp(str1,"MP3")==0))
		   iShowBMP(190+(l*260),460-(lm-down)*40,"music1.bmp");

     else if((strcmp(str1,"avi")==0)||(strcmp(str1,"mp4")==0)) 
		   iShowBMP(190+(l*260),460-(lm-down)*40,"movie.bmp");
	 else if(strcmp(str1,"mkv")==0)
            iShowBMP(190+(l*260),460-(lm-down)*40,"movie.bmp");

	 else if((strcmp(str1,"jpg")==0)||(strcmp(str1,"JPG")==0))
            iShowBMP(190+(l*260),460-(lm-down)*40,"jpg1.bmp");
	 else if((strcmp(str1,"png")==0)||(strcmp(str1,"bmp")==0)||(strcmp(str1,"BMP")==0))
            iShowBMP(190+(l*260),460-(lm-down)*40,"jpg1.bmp");
	 else if(strcmp(str1,"cpp")==0) 
		   iShowBMP(190+(l*260),460-(lm-down)*40,"cpp.bmp");
     
	 else if(strcmp(str1,"exe")==0) 
		   iShowBMP(190+(l*260),460-(lm-down)*40,"exe.bmp");
	 else if(strcmp(str1,"pdf")==0) 
		   iShowBMP(190+(l*260),460-(lm-down)*40,"pdf.bmp");
	  else if((strcmp(str1,"rar")==0) || (strcmp(str1,"zip")==0) || (strcmp(str1,"tar")==0))
		   iShowBMP(190+(l*260),460-(lm-down)*40,"rar.bmp");



	   else

       iShowBMP(190+(l*260),460-(lm-down)*40,"folder2.bmp");
			iSetColor(10,10,10);
			iText(235+(l*260),470-(lm-down)*40,sdrive[ff-1][k],GLUT_BITMAP_HELVETICA_10);
	 }


		 
	 }






	 if(k<30 && k>=(down*3))
	 {
		 l=k%3;
		 lm=k/3;
		 if((strcmp(str1,"mp3")==0) || (strcmp(str1,"MP3")==0))
		   iShowBMP(190+(l*260),460-(lm-down)*40,"music1.bmp");

       else if((strcmp(str1,"avi")==0)||(strcmp(str1,"mp4")==0))
		   iShowBMP(190+(l*260),460-(lm-down)*40,"movie.bmp");

	   else if(strcmp(str1,"mkv")==0)
               iShowBMP(190+(l*260),460-(lm-down)*40,"movie.bmp");
	   
	   else if(strcmp(str1,"srt")==0)
              iShowBMP(190+(l*260),460-(lm-down)*40,"book.bmp");

	   else if((strcmp(str1,"jpg")==0)||(strcmp(str1,"JPG")==0))
            iShowBMP(190+(l*260),460-(lm-down)*40,"jpg1.bmp");
	   else if((strcmp(str1,"png")==0)||(strcmp(str1,"bmp")==0)||(strcmp(str1,"BMP")==0))
            iShowBMP(190+(l*260),460-(lm-down)*40,"jpg1.bmp");
	   else if(strcmp(str1,"cpp")==0) 
		   iShowBMP(190+(l*260),460-(lm-down)*40,"cpp.bmp");
	   else if(strcmp(str1,"exe")==0) 
		   iShowBMP(190+(l*260),460-(lm-down)*40,"exe.bmp");
	   else if(strcmp(str1,"pdf")==0) 
		   iShowBMP(190+(l*260),460-(lm-down)*40,"pdf.bmp");
	    else if((strcmp(str1,"rar")==0) || (strcmp(str1,"zip")==0) || (strcmp(str1,"tar")==0)) 
		   iShowBMP(190+(l*260),460-(lm-down)*40,"rar.bmp");



	    else
		 iShowBMP(190+(l*260),460-(lm-down)*40,"folder2.bmp");
			iSetColor(10,10,10);
			iText(235+(l*260),470-(lm-down)*40,sdrive[ff-1][k],GLUT_BITMAP_HELVETICA_10);


			}

}

}




iSetColor(10,10,10);

iText(160,535,adrv[ff-1],GLUT_BITMAP_HELVETICA_12);//for the path
iSetColor(150,150,180);
iText(190,20,rowfl[ff],GLUT_BITMAP_TIMES_ROMAN_24);//for the no of folder
iText(191,21,rowfl[ff],GLUT_BITMAP_TIMES_ROMAN_24);
iText(192,22,rowfl[ff],GLUT_BITMAP_TIMES_ROMAN_24);

iText(95,20,rowfr[ff],GLUT_BITMAP_TIMES_ROMAN_24);//for the no of folder
iText(96,21,rowfr[ff],GLUT_BITMAP_TIMES_ROMAN_24);
iText(97,22,rowfr[ff],GLUT_BITMAP_TIMES_ROMAN_24);

iShowBMP(10,510,"back3.bmp");
iShowBMP(850,540,"cut.bmp");
iShowBMP(900,540,"copy.bmp");
iShowBMP(950,540,"paste1.bmp");
iShowBMP(10,10,"f1.bmp");//to show the NO. OF FOLDERS
iShowBMP(135,2,"f5.bmp");
	iSetColor(240,230,220);
	iRectangle(10,510,50,48);

	//////////////////////////////////////////////for scrolling///////////////////////////////////////////////////////

		iSetColor(0,0,0);
		iLine(970,500,970,60);
		iLine(970,500,990,500);
		iSetColor(240,230,250);

		iFilledRectangle(970,500,20,-439);

		iSetColor(0,0,0);
		iLine(970,480,970,500);
		iLine(970,500,990,500);
		iShowBMP(970,482,"up4.bmp");
		iSetColor(150,150,150);
		iFilledRectangle(970,60,20,20);
		iSetColor(0,0,0);
		iLine(970,60,990,60);
		iLine(970,60,990,60);
		iLine(990,500,990,61);
		iShowBMP(970,61,"down4.bmp");
sc=356/(row[ff-1]/3-9);

iShowBMP(971,465-(down*sc),"scroll_bar3.bmp");
		iShowBMP(971,449-(down*sc),"scroll_bar1.bmp");
		iShowBMP(971,433-(down*sc),"scroll_bar4.bmp");
		


//	}

}


int show_drive()
{
	int j=1,dno=0,fno=0;//at first it is getting a folder so dno is initialized 1 
	
	int l=0;
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	SYSTEMTIME Systime,Systime1;		
		hFind = FindFirstFile(arr_drive, &FindFileData);
	
    
	if(hFind == INVALID_HANDLE_VALUE)
	{
		
	   return -1;
	}

	else
	{
		
		strcpy(file_name[0],FindFileData.cFileName);
		flag.a=1;
		strcpy(ad,arr_drive);
	 ad[strlen(ad)-1]='\0';
	
	}


    while(FindNextFile(hFind, &FindFileData) != 0)
     {
     if(ff>1 && j==1)
	 {
		 l=-1;//for removing the . folder

		}
	 else
	 {
		 strcpy(arr_dir[ff-1][0],"nothing");///////////notun add korsi... check kora lagbe...

		 if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){
     strcpy(file_name[j],FindFileData.cFileName);
	 strcpy(sdrive[ff-1][l],file_name[j]);
     
	 
     strcat(ad,file_name[j]);
	 
	 strcat(ad,"\\*");
	 
	 strcpy(arr_dir[ff-1][j],ad);

	 strcpy(tarr_play[ff-1][j],"no file");////..........for playing...................//////////////////


        
	 FileTimeToSystemTime(&FindFileData.ftCreationTime,&Systime);
	 FileTimeToSystemTime(&FindFileData.ftLastAccessTime,&Systime1);

	 sprintf(day[ff-1][j-1],"%1d%s%1d%s%1d",Systime.wDay,".",Systime.wMonth,".",Systime.wYear);
	 sprintf(day2[ff-1][j-1],"%1d%s%1d%s%1d",Systime1.wDay,".",Systime1.wMonth,".",Systime1.wYear);

	 ad[0]='\0';
	 strcpy(ad,arr_drive);
	 ad[strlen(ad)-1]='\0';
	 dno++;
	 
		 }

		 else
		 {
             strcpy(file_name[j],FindFileData.cFileName);
	 strcpy(sdrive[ff-1][l],file_name[j]);
     
	 
     strcat(ad,file_name[j]);
	 
	 strcat(ad,"\\*");
	 
	 strcpy(arr_dir[ff-1][j],ad);
      
		 
	 strcpy(tarr_play[ff-1][j],arr_dir[ff-1][j]);////..........for playing...................//////////////////

        
	 FileTimeToSystemTime(&FindFileData.ftCreationTime,&Systime);
	 FileTimeToSystemTime(&FindFileData.ftLastAccessTime,&Systime1);

	 if(FindFileData.nFileSizeLow/1000000 > 1)
					sprintf(size1[ff-1][fno],"%.3f %s",(float)FindFileData.nFileSizeLow/1000000,"Mb");
				else
					sprintf(size1[ff-1][fno],"%.3f %s",(float)FindFileData.nFileSizeLow/1000,"Kb");


	 sprintf(day[ff-1][j-1],"%1d%s%1d%s%1d",Systime.wDay,".",Systime.wMonth,".",Systime.wYear);
	 sprintf(day2[ff-1][j-1],"%1d%s%1d%s%1d",Systime1.wDay,".",Systime1.wMonth,".",Systime1.wYear);

	 ad[0]='\0';
	 strcpy(ad,arr_drive);
	 ad[strlen(ad)-1]='\0';
	 fno++;
		 }

	 }

	 j++;
	 l++;
	 
	 


     }
	FindClose(hFind);


	printf("\n folder:%d",dno);
	printf("\n file: %d",fno);//calculating the number of file and folder
	
sprintf(rowfl[ff],"%d",fno);
sprintf(rowfr[ff],"%d",dno);




if(strcmp(arr_drive,"C:\\\\*")==0)
return j;

	else
	{
    if(ff>1 && dno>1)
return(j-2);
	else if(dno==1)
		return (j-1);
	else
		return (j-1);
	}




    
}


void back()
{
  if(shw==1)
  {
	  if(ff==0){
	  shw=0;
	  mode=1;}
	  if(ff!=0){
		  shw=1;
	  }
	  bak=0;
	  
  }
}


void drive_size()
{
	char str[100];
	int rsp=0,rx,ry;
	rx=atoi(freesp);
	ry=atoi(totalsp);
    
	rsp=((ry-rx)*250)/ry;
     
	iSetColor(210,225,250);
	iRectangle(190+(sx)*150,370-(sy)*150,150,90);
    iRectangle(191+(sx)*150,369-(sy)*150,150,90);

	iSetColor(150,220,240);
	iRectangle(325,34,250,11);

	iSetColor(50,150,200);
	iFilledRectangle(325,35,rsp,10);

	iSetColor(100,100,100);

	iText(345,10,freesp,GLUT_BITMAP_HELVETICA_18);
	iText(560,10,totalsp,GLUT_BITMAP_HELVETICA_18);
iSetColor(150,150,50);
	iText(250,10,"Free Space:",GLUT_BITMAP_HELVETICA_12);
	iText(480,10,"Total Space:",GLUT_BITMAP_HELVETICA_12);


	sprintf(str,"Local Disk(%c)",ch[sn]);
	    iSetColor(100,100,100);
		iText(185,35,str,GLUT_BITMAP_HELVETICA_18);
      
}

void rbformenu(int mx,int my)
{
	
	iSetColor(200,230,220);
//	iFilledRectangle(mx,my-20,70,20);
	//iSetColor(10,10,10);
	iRectangle(mx,my-153,153,153);
    iSetColor(0,0,0);
	//iText(mx+20,my-15,"Explore",GLUT_BITMAP_HELVETICA_12);
	iShowBMP(mx,my-152,"explore.bmp");
}



void iDraw()
{
	
	

	iClear();
	//
	iSetColor(10,10,10);

iText(dm,565,"WINDOWS",GLUT_BITMAP_TIMES_ROMAN_24);
	inception();
	
	if((tff%2)==0)
	tree();
	else
		dis_tree();

	if(ff == 0)
		first();


	if(node_drbx==1)
		drwbox();

    
	
	if(shw==1)
		s_drive(lj);
	if(node_r==1)
      rbformenu(rmouse_x,rmouse_y);

	if(bak==1)
		back();

	if((flag_tree==1)&&(tff%2)==1)
		displaytree(head,dnhead);

	if(node_dsize==1)
		drive_size();



}





/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
	
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		


       orgmx=mx;
	   orgmy=my;
	   printf("%d %d\n",orgmx,orgmy);////////printing the co-ordinate of the cursor






		////////////////////////////////to enter into a folder///////////////////////////////////////////
	   ///////////////////////////////////////////////////////////////////////////////////


	if( (mx>=rmouse_x && mx<=rmouse_x +70 && my>=rmouse_y-20 && my<=rmouse_y && node_lf==1) || (mx>=rmouse_x && mx<=rmouse_x+1 && my>=rmouse_y && my<=rmouse_y+1 && node_llf==1) )
	{
		node_n=1;
		mode=0;
		node_dsize=0;
		node_r=0;
		node_f=0;
		down=0;
		node_drbx=0;
		
		node_lf=0;
		if(ff!=0){
		

		   // strcpy(arr_drive,arr_dir[ff-1][adr+1]);
		    //strcpy(adrv[ff],arr_drive);
			strcpy(acp,arr_dir[ff-1][adr+1]);
		    strcpy(adrv[ff],acp);
		
			if(strcmp(tarr_play[ff-1][adr+1],"no file")==0)
			{
				printf("\n not file");
			strcpy(arr_drive,acp);
			ff++;
				lj=show_drive();
		row[ff-1]=lj;//the row number of every 2D array is stored here
						//sprintf(rowc[ff-1],"%d",row[ff-1]);
		
			//strcpy(adrv[ff],acp);
			}
			else
			{
				strcpy(play,acp);
				play[strlen(play)-1]='\0';
				ShellExecute(NULL,"open",play,0,0,SW_SHOW);
			printf("the file is>> %s",play);
				sprintf(rowc[ff-1],"%d",row[ff-1]);
		
			}
		}

		shw=1;
		if(ff==0)
		{ff++;
			lj=show_drive();
		row[ff-1]=lj;//the row number of every 2D array is stored here
						sprintf(rowc[ff-1],"%d",row[ff-1]);
		}
		
		printf("\n\nthe string is:%s\n",arr_drive);
		
		printf("\nff>%d",ff);
		
	}

	else
	{
		node_r=0;
	node_lf=0;
	node_drbx=0;
	}





	   /////////////////////////////for back click///////////////////////////////////////////
	   ///////////////////////////////////////////////////////////////////////////////////


	   if(mx>=10 && mx<=58 && my>=510 && my<=558 && mode==0)
	   {
		   node_drbx=0;
		   bak=1;
		   down=0;
		   ff--;
		   printf("ff>%d",ff);

		   if(ff!=0)
			   lj=row[ff-1];
	   }






       /////////////////////////////for down click////////////////////////////////////////
	   ///////////////////////////////////////////////////////////////////////////////////



	   if(mx>970 && mx<=985 && my>=61 && my<78 && row[ff-1]>=30 && down<((row[ff-1]/3)-9))
	   {
		   down ++;
		   printf("\ndown > %d",down);
		   node_drbx=0;
	   }






	   /////////////////////////////for up click///////////////////////////////////////////
	   ///////////////////////////////////////////////////////////////////////////////////

	   if(mx>970 && my<=985 && my>484 && my<500 && down>0)
	   {
		   down--;
        printf("\nup > %d",down);
		node_drbx=0;
	   }
   
		
	}






//////////////////////////////////for double click///////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////



		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && ff!=0)

	{
		if(((mx>190 && mx<390)|| (mx>450&&mx<650) || (mx>710&&mx<910)) && my>105 && my<490)
		{
		rmouse_x=mx;
		rmouse_y=my;
		mx=mx-190;
		my=my-105;
		my=385-my;

			x=mx/260;
			
			y=my/39;
			
		
			adr=(y+down)*3+x;
			adrs=adr;
			if(ff>=2)
				adr = adr+1;
			if(ff<2)
				adr=adr;
		
			if(adr<=row[ff-1]){

				
			node_r=0;
			node_llf=1;
			node_drbx=1;
			}
			else
			{
				node_r=0;
				node_llf=0;
				node_drbx=0;
			}
		}

	}








/////////////////////////////////to enter into a drive /////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////
		
 ULARGE_INTEGER a,b,c;
 unsigned x=1024*1024*1024;

	if((button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && ff==0)||(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && ff==0))
	{

       sx=(mx-190)/150;
	   sy=(430-my)/130;
	   sn=(sy*5)+sx;

		
		short ij=0;
		node_drbx=0;
		if( (mx>=190 && mx<=330 && my>=350 && my<=460 && mode ==1 && ij<counter))//showing option to explore
		{
			rmouse_x=mx;
			rmouse_y=my;
			printf("%d",mx);
		
			if(button ==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
		node_r=1;
		node_lf=1;
			}
			else
			{
				node_r = 0;
				node_lf=0;
				node_llf=1;
			}
		
        
		 GetDiskFreeSpaceEx("c:\\",&a,&b,&c);

				sprintf(freesp,"%u",a.QuadPart/x);
				sprintf(totalsp,"%u",b.QuadPart/x);
					strcat(freesp," GB");
        strcat(totalsp," GB");
		node_dsize=1;

		strcpy(arr_drive,"C:\\");
		strcat(arr_drive,"\\*");
		strcpy(adrv[ff],arr_drive);
		}

		else {
			node_r=0;
			node_dsize=0;
		ij++;
		}


		if( (mx>=340 && mx<=480 && my>=350 && my<=460 && mode==1 && ij<counter) )
		{
            rmouse_x=mx;
			rmouse_y=my;
				if(button ==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
			
		node_r=1;
		node_lf=1;
			}
			else
			{
				node_r = 0;
				node_lf=0;
				node_llf=1;
			}

			GetDiskFreeSpaceEx("d:\\",&a,&b,&c);

				sprintf(freesp,"%u",a.QuadPart/x);
				sprintf(totalsp,"%u",b.QuadPart/x);
					strcat(freesp," GB");
        strcat(totalsp," GB");
		node_dsize=1;

		strcpy(arr_drive,"D:\\");
		strcat(arr_drive,"\\*");

		strcpy(adrv[ff],arr_drive);
		printf("\n%s",arr_drive);
		}
		ij++;



        if(mx>=490 && mx<=630 && my>=350 && my<=460 && mode==1 && ij<counter)
		{
			rmouse_x=mx;
			rmouse_y=my;
		if(button ==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
			
		node_r=1;
		node_lf=1;
			}
		else
			{
				node_r = 0;
				node_lf=0;
				node_llf=1;
			}


		GetDiskFreeSpaceEx("e:\\",&a,&b,&c);

				sprintf(freesp,"%u",a.QuadPart/x);
				sprintf(totalsp,"%u",b.QuadPart/x);
					strcat(freesp," GB");
        strcat(totalsp," GB");
		node_dsize=1;

		strcpy(arr_drive,"E:\\");
		strcat(arr_drive,"\\*");
		strcpy(adrv[ff],arr_drive);
		}ij++;

		if(mx>=640 && mx<=780 && my>=350 && my<=460 && mode==1 && ij<counter)
		{
           rmouse_x=mx;
			rmouse_y=my;
		if(button ==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
			
		node_r=1;
		node_lf=1;
			}
		else
			{
				node_r = 0;
				node_lf=0;
				node_llf=1;
			}

		GetDiskFreeSpaceEx("f:\\",&a,&b,&c);

				sprintf(freesp,"%u",a.QuadPart/x);
				sprintf(totalsp,"%u",b.QuadPart/x);
					strcat(freesp," GB");
        strcat(totalsp," GB");
		node_dsize=1;


		strcpy(arr_drive,"F:\\");
		strcat(arr_drive,"\\*");
		strcpy(adrv[ff],arr_drive);
		}ij++;


       if(mx>=790 && mx<=930 && my>=350 && my<=460 && mode==1 && ij<counter)
		{
           rmouse_x=mx;
			rmouse_y=my;
		if(button ==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
			
		node_r=1;
		node_lf=1;
			}
		else
			{
				node_r = 0;
				node_lf=0;
				node_llf=1;
			}

		GetDiskFreeSpaceEx("g:\\",&a,&b,&c);

				sprintf(freesp,"%u",a.QuadPart/x);
				sprintf(totalsp,"%u",b.QuadPart/x);
					strcat(freesp," GB");
        strcat(totalsp," GB");
		node_dsize=1;


		strcpy(arr_drive,"G:\\");
		strcat(arr_drive,"\\*");
		strcpy(adrv[ff],arr_drive);
		}ij++;

	   if(mx>=190 && mx<=330 && my>=200 && my<=310 && mode==1 && ij<counter)
		{
           rmouse_x=mx;
			rmouse_y=my;
		if(button ==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
			
		node_r=1;
		node_lf=1;
			}
		else
			{
				node_r = 0;
				node_lf=0;
				node_llf=1;
			}

		GetDiskFreeSpaceEx("h:\\",&a,&b,&c);

				sprintf(freesp,"%u",a.QuadPart/x);
				sprintf(totalsp,"%u",b.QuadPart/x);
					strcat(freesp," GB");
        strcat(totalsp," GB");
		node_dsize=1;


		strcpy(arr_drive,"H:\\");
		strcat(arr_drive,"\\*");
		strcpy(adrv[ff],arr_drive);
		}ij++;
        
	   if(mx>=340 && mx<=480 && my>=200 && my<=310 && mode==1 && ij<counter)
		{
           rmouse_x=mx;
			rmouse_y=my;
			if(button ==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
			
		node_r=1;
		node_lf=1;
			}
		else
			{
				node_r = 0;
				node_lf=0;
				node_llf=1;
			}

		GetDiskFreeSpaceEx("i:\\",&a,&b,&c);

				sprintf(freesp,"%u",a.QuadPart/x);
				sprintf(totalsp,"%u",b.QuadPart/x);
					strcat(freesp," GB");
        strcat(totalsp," GB");
		node_dsize=1;


		strcpy(arr_drive,"I:\\");
		strcat(arr_drive,"\\*");
		strcpy(adrv[ff],arr_drive);
		}ij++;
	    
	   if(mx>=490 && mx<=630 && my>=200 && my<=310 && mode==1 && ij<counter)
		{
           rmouse_x=mx;
			rmouse_y=my;
			if(button ==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
			
		node_r=1;
		node_lf=1;
			}
		else
			{
				node_r = 0;
				node_lf=0;
				node_llf=1;
			}


		GetDiskFreeSpaceEx("j:\\",&a,&b,&c);

				sprintf(freesp,"%u",a.QuadPart/x);
				sprintf(totalsp,"%u",b.QuadPart/x);
					strcat(freesp," GB");
        strcat(totalsp," GB");
		node_dsize=1;


		strcpy(arr_drive,"J:\\");
		strcat(arr_drive,"\\*");
		strcpy(adrv[ff],arr_drive);
		}ij++;

	   if(mx>=640 && mx<=780 && my>=200 && my<=310 && mode==1 && ij<counter)
		{
           rmouse_x=mx;
			rmouse_y=my;
		if(button ==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
			
		node_r=1;
		node_lf=1;
			}
		else
			{
				node_r = 0;
				node_lf=0;
				node_llf=1;
			}

		GetDiskFreeSpaceEx("k:\\",&a,&b,&c);

				sprintf(freesp,"%u",a.QuadPart/x);
				sprintf(totalsp,"%u",b.QuadPart/x);
					strcat(freesp," GB");
        strcat(totalsp," GB");
		node_dsize=1;



		strcpy(arr_drive,"K:\\");
		strcat(arr_drive,"\\*");
		strcpy(adrv[ff],arr_drive);
		}ij++;

	   if(mx>=790 && mx<=930 && my>=200 && my<=310 && mode==1 && ij<counter)
		{
           rmouse_x=mx;
			rmouse_y=my;
		if(button ==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
			
		node_r=1;
		node_lf=1;
			}
		else
			{
				node_r = 0;
				node_lf=0;
				node_llf=1;
			}


		GetDiskFreeSpaceEx("l:\\",&a,&b,&c);

				sprintf(freesp,"%u",a.QuadPart/x);
				sprintf(totalsp,"%u",b.QuadPart/x);
					strcat(freesp," GB");
        strcat(totalsp," GB");
		node_dsize=1;


		strcpy(arr_drive,"L:\\");
		strcat(arr_drive,"\\*");
		strcpy(adrv[ff],arr_drive);
		}ij++;






		
	}




/////////////////////////////for right button to enter into the directories of a drive//////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && ff!=0)

	{
		if(((mx>190 && mx<390)|| (mx>450&&mx<650) || (mx>710&&mx<910)) && my>105 && my<490)
		{
		rmouse_x=mx;
		rmouse_y=my;
		mx=mx-190;
		my=my-105;
		my=385-my;

			x=mx/260;
			
			y=my/39;
			
		
			adr=(y+down)*3+x;
			adrs=adr;
			if(ff>=2)
				adr = adr+1;
		
			if(adr<=row[ff-1]){
			
			node_r=1;
			node_lf=1;
			node_drbx=1;
			}
			else
			{
				node_r=0;
				node_lf=0;
				node_drbx=0;
			}
		}
		else
		{
			node_drbx=0;
			node_r=0;
			node_lf=0;
		}

	}











	//////////////////////////////////////for the tree ////////////////////
	///////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////






			if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			{
				if(mx>14 && mx<31 && my>(70+(14-countdrive())*30 )&& my<450)
				{
			
					ty=(450-my)/30;
					atr=ty;


					sprintf(arrt_drive,"%c",ch[atr]);
                     printf("\natr>>%d",atr);
						strcat(arrt_drive,":\\");
						strcat(arrt_drive,"\\*");

					
				if(tff!=0){
					strcpy(arrt_drive,tarr_dir[tff-1][atr+1]);//sending the path of a folder to the showt_drive() function
					}
			if(tff==0)
				tff=1;
			else
				tff=0;
				
				tj=showt_drive();
               
				
				rowt[tff-1]=tj;//the row number of every 2D array is stored here
					
				head=NULL,dnhead=NULL;
				tree_tree();/////calling function to store in linklist and to show the tree in igraphics
		
				printf("\n\nthe tree string is:%s\n",arrt_drive);
		
				printf("\ntff>%d",tff);
					}



/////////////////////////////for down click///////////////////////////////////////////
	   ///////////////////////////////////////////////////////////////////////////////////

				if(mx>170 && mx<=190 && my>=61 && my<78 && lk>0)
	   {
		   tdown ++;
		   printf("\ntdown >> %d",tdown);
		   node_drbx=0;
		   
	   }






	   /////////////////////////////for up click///////////////////////////////////////////
	   ///////////////////////////////////////////////////////////////////////////////////

	   if(mx>170 && mx<=190 && my>484 && my<500 && tdown>0)
	   {
		   tdown--;
        printf("\nup > %d",tdown);
		node_drbx=0;
	   }




			}


}///// iMouse function ends here...



//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////// function for storing the file name for tree///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////


int showt_drive()
{
	int j=1,dno=0,fno=0;//at first it is getting a folder so dno is initialized 1 
	
	
	int l=0;
	
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	
		

		hFind = FindFirstFile(arrt_drive, &FindFileData);
	
    
	if(hFind == INVALID_HANDLE_VALUE)
	{
		
	   return -1;
	}

	else
	{
		
		strcpy(filet_name[0],FindFileData.cFileName);
		flag.a=1;
		strcpy(at,arrt_drive);
	 at[strlen(at)-1]='\0';
	
	}


    while(FindNextFile(hFind, &FindFileData) != 0)
     {
     if(tff>1 && j==1)
	 {
		 l=-1;////////////////////////////////////for removing the . folder

		}
	 else
	 {

		 if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){
     strcpy(filet_name[j],FindFileData.cFileName);
	 strcpy(tsdrive[dno],filet_name[j]);
     
	 
     strcat(at,filet_name[j]);
	 
	 strcat(at,"\\*");
	 
	 strcpy(tarr_dir[tff-1][dno],at);
	 at[0]='\0';
	 strcpy(at,arrt_drive);
	 at[strlen(at)-1]='\0';
	 dno++;
	 
		 }

		

	 }

	 j++;
	 l++;
	 
	 


     }//while loop ends

	FindClose(hFind);


	printf("\n folder:%d",dno);
	printf("\n file: %d",fno);//calculating the number of file and folder
	




return dno;

}











/*void iSetMousePositionsTimer()
{
	POINT pm;
	RECT lprect;
	printf("(x,y): ");
	GetCursorPos(&pm);
	GetWindowRect(GetForegroundWindow(), &lprect);
	iMouseX = pm.x-	lprect.left-8; //you may need to tune this 8
	iMouseY = iScreenHeight-(pm.y-lprect.top)+28; //you may need to tune this 28
	printf("%d %d\n", iMouseX, iMouseY);
}
*/



/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
			iPauseTimer(1);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
		iResumeTimer(1);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here

}



void first()// showing the drive icons
{
	int x = 220,y = 370;
	int p=40,q=450;
	char ch = 'C',str[15] =  "Local Disk";

	
	for(int i = 0,k=0;i < countdrive();i++,x += 150,ch += 1,k++){
		if(x >= 930)
		{
			x = 220;
			y -= 150;
		}
		p=40;
		q-=30;
		iShowBMP(x,y,"drivefinal.bmp");
		sprintf(str,"Local Disk(%c)",ch);
		
		strcpy(fstr[k],str);
		iText( x-30,y-20 ,str,GLUT_BITMAP_TIMES_ROMAN_24);
		
	}

}



void tree()
{
    int x = 220,y = 370;
	int p=30,q=460;
	char ch = 'C',str[15] =  "Local Disk";

	iShowBMP(20,450,"computer1.bmp");
	iText(40,450,"COMPUTER",GLUT_BITMAP_HELVETICA_12);
	 

	for(int i = 0,k=0;i <(countdrive()-1);i++,x += 150,ch += 1,k++){
		
		p=32;
		q-=30;
		sprintf(str,"Local Disk(%c)",ch);
		
		strcpy(fstr[k],str);
	
		iText(p,q,str,GLUT_BITMAP_HELVETICA_12);



		iShowBMP(15,q,"next5.bmp");
	}

}





int main()
{

	iInitialize(1000, 600, "Windows Explorer");
	return 0;
}	













//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////****  treeeeee  ****////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct node *createfronttree(char data[],struct node *head);
struct node *createdowntree(char data[],int dhead,struct node *head,struct node *dnhead);
void displaytree(struct node *nodp,struct node *nodc);
void subtree(struct node *dnd);
struct node *searchtree(struct node *tmp,int dhead);
void rightsubtree(struct node *rnd);

 
short flag1=1,flag2=1;


void tree_tree()
{
	
    int si;
	char data[200];
    
	//printf("\nrowt>> %d",rowt[tff-1]);
    for(si=0;si<rowt[tff-1];si++){
       // printf("1:front tree 2:down tree");
        //scanf("%d",&chce);
        //fflush(stdin);



   //if(chce==1){

   // printf("enter your number:");

    strcpy(data,tsdrive[si]);
    
		head=createfronttree(data,head);
   //}
    /*else if(chce==2)
    {

        printf("\nenter the number under which you want to create a down tree:");
        scanf("%d",&dt);
        fflush(stdin);
        printf("enter your number:");
    scanf("%d",&data);
    fflush(stdin);

        dnhead=createdowntree(data,dt,head,dnhead);

    }*/


    //printf("\nafter adding the element the tree is :");
    
    }
//displaytree(head,dnhead);
//printf("\ntree ttt");


}





struct node *createfronttree(char data[],struct node *head)
{
    struct node *temp=head, *newp;
    if(NULL==head)
    {
       // printf("\ndata>>%s\n",data);
        head=(struct node *)malloc(sizeof(struct node));
        strcpy(head->stree,data);
        head->prev=head;
        head->next=head;
        head->up=head;
        head->down=head;

    }
    else
    {

    while(temp->next!=head )
        temp=temp->next;



        newp=(struct node *)malloc(sizeof(struct node));
        
		strcpy(newp->stree,data);
        newp->next=temp->next;
        newp->prev=temp;
        (newp->prev)->next=newp;
        (newp->next)->prev=newp;
        newp->down=newp;
        newp->up=newp;


    }
    return head;

}
/*struct node *searchtree(struct node *tmp,int dhead)
{
    struct node *temp=tmp, *tmp1;
    while(temp->a!=dhead && temp->next!=tmp && flag1 ==1)//condition abar check korte hobe
    {
        temp=temp->next;
        flag2==1;
    }

    if(temp->a==dhead)
    return temp;

    tmp=temp;//taking the last of the row as tmp
    //temp=temp->down;
    while(temp->a!=dhead && temp->down!=tmp && flag2==1)
    {
        temp=temp->down;
        flag1==1;
    }

    if(temp->a==dhead)
    return temp;

    tmp=temp;

    else
    {
        if((temp->next==tmp) && (temp->down==tmp) )
        {

            if(temp->prev==temp){
            searchtree(tmp->up,dhead);
            flag2=0;
            flag1=1;
            }
            else if(tem->up==temp)
            {
                searchtree(tmp->prev,dhead);
            flag1=0;
            flag2=1;
            }
        }
        searchtree(tmp,dhead);
    }
}

struct node *createdowntree(int data,int dhead,struct node *head,struct node *dnhd)
{
    struct node *temp=head, *newp, *dnhead=dnhd;
      temp =searchtree(temp,dhead)


    dnhead = temp;

    if(temp->down==temp){

    newp=(struct node *)malloc(sizeof(struct node));
    newp->a=data;
        newp->down=temp;
        newp->up=temp;
        (newp->up)->down=newp;
        (newp->down)->up=newp;
        newp->next=newp;
        newp->prev=newp;

        dnhead=temp;

}
    else{
        while(temp->down!=dnhead)//condition abar check korte hobe
    {
        temp=temp->down;
    printf("m");
    }
    printf("\ndddd::%d\n",temp->a);

    newp=(struct node *)malloc(sizeof(struct node));
        newp->a=data;
        newp->down=temp->down;
        newp->up=temp;
        (newp->up)->down=newp;
        (newp->down)->up=newp;
        newp->next=newp;
        newp->prev=newp;

        //dnhead=temp;
    }
    return dnhead;
    //return;
}
*/

void dis_tree()
{
	int sc=0;
	int x = 220,y = 370;
	int p=30,q=460;
	char str[15] =  "Local Disk";

	iShowBMP(20,450,"computer1.bmp");
	iText(40,450,"COMPUTER",GLUT_BITMAP_HELVETICA_12);

tfno+=countdrive();

for(int i = 0,k=0; i<(countdrive()+lk) ;i++,x += 150){//////////////////////for starts


	//	ch = 'C';
		
		if(tdown>atr)
			k=rowt[tff-1];

		if(i<13 && i>=(tdown+k)){//printf("%d",tdown);

			p=32;
		    q=i;
           

			sprintf(str,"Local Disk(%c)",ch[i]);
	    strcpy(fstr[k],str);
	    iSetColor(10,10,10);
		iText(p,430-(q-tdown)*30,str,GLUT_BITMAP_HELVETICA_12);
        iShowBMP(15,430-(q-tdown)*30,"next5.bmp");
		
//ch += chn;


		if(tff!=0){////////////////////atr if starts
			if(i==atr) 
			{
				flag_tree=1;
				i=(i+rowt[tff-1]);
				lk=rowt[tff-1];
			}
			
			

		}/////////atr if ends
		
		
		
		
		}/////////////i<12 if ends
		 
		

tt=(lk+(atr+1)-13);

	if(i>(lk+atr) && (i-tdown)>=0 && tdown>tt && i<=(tdown+tt+1))
		{
			p=32;
			q=i;
			sprintf(str,"Local Disk(%c)",ch[i-lk]);
	    strcpy(fstr[k],str);
	    iSetColor(10,10,10);
		iText(p,430-(q-tdown)*30,str,GLUT_BITMAP_HELVETICA_12);
        iShowBMP(15,430-(q-tdown)*30,"next5.bmp");
			
		}

	}/////////////////////////////////////////////////////for loop ends



iSetColor(0,0,0);
		iLine(170,500,170,60);
		iLine(170,500,190,500);
		iSetColor(240,230,250);

		iFilledRectangle(170,500,20,-439);

		iSetColor(0,0,0);
		iLine(170,480,170,500);
		iLine(170,500,190,500);
		iShowBMP(170,482,"up4.bmp");
		iSetColor(150,150,150);
		iFilledRectangle(170,60,20,20);
		iSetColor(0,0,0);
		iLine(170,60,190,60);
		iLine(170,60,190,60);
		iLine(190,500,190,61);
		iShowBMP(170,61,"down4.bmp");
		sc=356/(row[ff-1]/3-9);

		//iShowBMP(171,465-(down*sc),"scroll_bar3.bmp");
		//iShowBMP(171,449-(down*sc),"scroll_bar1.bmp");
	//	iShowBMP(171,433-(down*sc),"scroll_bar4.bmp");
		






}




void displaytree(struct node *nodp,struct node *nodc)
{
	//abc=0;
	abc=atr;
	int q=430-((atr+1)*30);
//	char sarr[200];
    struct node *head1=nodp,*temp=nodp,*dnhead1=nodc;
    //
    if(temp==NULL);
    else
    {

        do
        {

            if(abc<(13-1) && abc>=(atr-tdown) && (abc-tdown)<(13-tdown) ){//this condition is ok
				iShowBMP(30,q-(abc-atr-tdown)*30,"next5.bmp");
				iSetColor(10,10,10);
				iText(48,q-(abc-atr-tdown)*30,temp->stree,GLUT_BITMAP_HELVETICA_12);
			}// /////////////////// 1 no if ends

			/*	if(tdown>atr){
	 
		 if(abc>12 && abc<=(12+tdown) &&(abc-tdown)>=0) ////////// && (lm-down)>=0)
	 {
       //l=k%3;
	  
            iShowBMP(30,q-(abc-(tdown+atr))*30,"next5.bmp");//,460-(lm-down)*40,"movie.bmp");
			iSetColor(10,10,10);
			iText(48,q-(abc-(tdown+atr))*30,temp->stree,GLUT_BITMAP_HELVETICA_12);
	 }


		 
	 }///   ////////////////////// 2 no if ends*/



			abc++;
            temp=temp->next;
        }//////  ///////////do ends

     while(temp!=head1);
	 

 }//else ends
    
    return;

}





void subtree(struct node *dnd)
{
    struct node *dnhead2=dnd;

struct node *temp=dnd;
       while(temp->down!=dnhead2)
       {temp=temp->down;
       // printf("\ngggg: %s ",temp->stree);
        rightsubtree(temp);


       }
       return;
}

void rightsubtree(struct node *rnd)
{
    struct node *rnhead=rnd;

    struct node *temp=rnd;
    while(temp->next!=rnhead)
    {
        temp=temp->next;
       //printf("\nrrr: %s ",temp->stree);
       subtree(temp);
    }
    return;
}