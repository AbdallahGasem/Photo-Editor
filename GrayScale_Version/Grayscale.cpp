// program: finalprojectGS.cpp
// purpose: Final project for assignment 1
// Team IDs:20221012-20220294-20221101
// Authors names & IDs : Ahmed Karam(20221012) - Mohamed Abdelhamid Wagdy(20220294) - Abdallah Gassem(20221101)
// Emails: ahmedkaram2@hotmail.com - Mohamedabdelhamid2222003@gmail.com - abdallahgasem.fcaicu@gmail.com
// Date: October 2023 
// version: 2.0
//CS213-2023-20221012-20220294-20221101-A1-FULLGS 

#include<bits/stdc++.h>
#include "bmplib.cpp"
#include<unistd.h> // ?
using namespace std;
unsigned char imageGS[SIZE][SIZE];
unsigned char imageGS2[SIZE][SIZE] ;
unsigned char imageGS_FILTERed[SIZE][SIZE];

//Array to save directory path the size of the array is the maximum size of a path
char cwd[PATH_MAX];
//Filters implemented as functions 

void choose_filter(char x);
void filter1();
void filter2();
void filter3(); // A
void filter4(int x);    
void filter5(int x);
void filter6(char x);   // A
void filter7();
void filter8(int x);
void filter9(); // A
void filterA(int x);
void filterB(int a, int b , int c , int d );
void filterC(); // A
void filterD();
void filterE(double x);
void filterF(double x); // A 
int main()

{
    /*To load the picture using the read function we must get the current working directory and give it as
    arguments to the function so we do that using the function getcwd()*/

    string imgname,path="\\";
    cout<<"choose your desired filter: "<<endl<<"1-Black and White"<<endl<<"2-Invert filter\n"<<"3-Merge Filter"<<endl<<"4-Flip image"<<endl<<"5-Rotate Image"<<endl
    <<"6-Darken OR Lighten Filter"<<endl<<"7-Image Edges"<<endl<<"8-Enlarge Image"<<endl
    <<"9-Shrink Image"<<endl<<"A-Mirror Image"<<endl<<"B-shuffle Image"<<endl<<"C-Blur Image"<<endl<<"D-Crop Image"<<endl<<"E-Skew Horizontally"<<endl<<"F-Skew Vertically"<<endl;
    char f;cin>>f;
    cout << "Enter the source imageGS file name: ";
    cin >> imgname;
    imgname+=".bmp";
    path+=imgname;
    readGSBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()),imageGS);
    //The "choose_filter" function work as the program menu where user gets to pick his desired filter :)
    choose_filter(f);
    //writeGSBMP("filtered.bmp", imageGS_FILTERed); This function was used by us students for testing
    showGSBMP(imageGS_FILTERed);
    return 0;
}
void filter1() 
{
    //black and white
  for (int i = 0; i < SIZE; i++) 
  {
    for (int j = 0; j< SIZE; j++) 
    {

        if ( imageGS[i][j] > 127)
        {
            imageGS_FILTERed[i][j] = 255;
        }
        else
        {
            imageGS_FILTERed[i][j] = 0;
        }
    }
  }
}

void filter2()
{
    //invert color
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            imageGS_FILTERed[i][j]=255-imageGS[i][j];
        }    
    }
}

void filter3()
{    
    //merge 
    char cwd2[PATH_MAX];
    string image2_name , path2="\\";
    cout << "enter the seconed image name in your files to be merged : " ;
    cin >> image2_name ;
    image2_name+=".bmp";
    path2+=image2_name;
    readGSBMP(strcat(getcwd(cwd2, sizeof(cwd2)), path2.c_str()),imageGS2) ;

    // pixels loop :

    for (int i = 0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            // obtaining average of both images brightness to reach photo merging : 

            imageGS_FILTERed[i][j] = (imageGS[i][j]+imageGS2[i][j]) / 2 ;



        }

    }


}

void filter4(int x)
{
    //FLIP
  if (x==2)
  {
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j< SIZE; j++) 
            {
                imageGS_FILTERed[i][256-j]=imageGS[i][j];
            }
    }
  }
else if (x==1)
{
    for (int i = 0; i < SIZE; i++) 
    {
        for ( int j = 0; j< SIZE; j++) 
        {
            imageGS_FILTERed[256-i][j]=imageGS[i][j];
        }
    }

}
}

void filter5(int x)
{
    //rotate 90* 
if (x==1)
{
    for (int i = 0; i < SIZE; i++)
    {
        for(int j =0 ; j<SIZE; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[j][i];
        }
    }
    
}

    //rotate 180*
if (x==2)
{
 for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[255-i][255-j];
        }
    }
}   

    //rotate 270*
if (x==3)
{
    for (int i = 0; i < SIZE; i++)
    {
        for(int j =0 ; j<SIZE; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[255-j][255-i];
        }
    }
}

}

void filter6(char x)
{
    
    // darken condition :

    if (x == 'd' || x == 'D')
    {
        // pixels loop :

        for (int i = 0; i < SIZE ; i++)
        {
            for (int j = 0 ; j < SIZE; j++)
            {
                // reducing the image brightness by 50% :

                imageGS_FILTERed[i][j] = imageGS[i][j] - (imageGS[i][j]*0.5) ;
            }

        }


    }


    // lighten conditon :

    else
    {
        for (int i = 0; i < SIZE ; i++)
        {
            for (int j = 0 ; j < SIZE; j++)
            {
                // increasing the image brightness by 50% :
                if (imageGS[i][j] + (imageGS[i][j]*0.5)<=255)
                {
                    imageGS_FILTERed[i][j] = imageGS[i][j] + (imageGS[i][j]*0.5) ;    
                }
                else
                imageGS_FILTERed[i][j]=255;  
                
            }

        }
    }


}

void filter7()
{
  unsigned char imageGS_FILTERed1[SIZE][SIZE];
  int sum=0;
  for (int i = 0; i < SIZE; i++) 
  {
    for (int j =0; j< SIZE; j++) 
    {    
      sum+=imageGS[i][j];
    }
    }
  int avg=sum/(256*256);
  for (int i = 0; i < SIZE; i++) 
  {
    for (int j =0; j< SIZE; j++) 
    {
      if (imageGS[i][j]<avg) 
      {
        imageGS_FILTERed[i][j]=0;
      }else 
      {
        imageGS_FILTERed[i][j]=255;
      }
    }
    }
    int x=0;
    for (int i = 1; i < SIZE-1; i++) 
    {
      for (int j =0; j< SIZE; j++) 
      {
      if (imageGS_FILTERed[i][j]==0&&(imageGS_FILTERed[i-1][j]==255||imageGS_FILTERed[i-1][j+1]==255||imageGS_FILTERed[i-1][j-1]==255||imageGS_FILTERed[i][j+1]==255||imageGS_FILTERed[i][j-1]==255||imageGS_FILTERed[i][j+1]==255||imageGS_FILTERed[i+1][j]==255))
      {
        imageGS_FILTERed1[i][j]=0;
        x=i;
        for(int k=x+1; k<255 ;k++)
        {
          if (imageGS_FILTERed[k][j]==0&&(imageGS_FILTERed[k][j+1]!=255||imageGS_FILTERed[k][j-1]!=255))
          {
            imageGS_FILTERed1[k][j]=255;
          }else
          {
            break;
          }
        }
      }else
      {
        imageGS_FILTERed1[i][j]=255;
      }
    }
  }
    for (int i = 0; i < SIZE; i++)
    {
    for (int j =0; j< SIZE; j++) 
    {
      imageGS_FILTERed[i][j]=imageGS_FILTERed1[i][j];
    }
    }

  }

void filter8(int x)
{
    //first quarter
if (x==1)
{
    int arr[128][128];
    for (int i = 0; i < 128; i++)
    {
        for(int j = 0 ; j < 128 ; j++)
        {
            arr[i][j] = imageGS[i][j];
        }
    }
    int x=0,y=0;
    for (int i = 0; i < SIZE; i+=2)
    {
        y=0;
        for(int j = 0 ; j < SIZE ; j+=2)
        {
            imageGS_FILTERed[i][j]=arr[x][y];
            imageGS_FILTERed[i][j+1]=arr[x][y];
            imageGS_FILTERed[i+1][j]=arr[x][y];
            imageGS_FILTERed[i+1][j+1]=arr[x][y];
            y++;
        }
        x++;
    }
}
    //second quarter
if (x==2)
{
    int arr[128][128];
    for (int i = 0; i < 128; i++)
    {
        for(int j = 0 ; j < 128 ; j++)
        {
            arr[i][j] = imageGS[i][j+128];
        }
    }
    int x=0,y=0;
    for (int i = 0; i < SIZE; i+=2)
    {
        y=0;
        for(int j = 0 ; j < SIZE ; j+=2)
        {
            imageGS_FILTERed[i][j]=arr[x][y];
            imageGS_FILTERed[i][j+1]=arr[x][y];
            imageGS_FILTERed[i+1][j]=arr[x][y];
            imageGS_FILTERed[i+1][j+1]=arr[x][y];
            y++;
        }
        x++;
    }
}
    //third quarter
if (x==3)
{
    int arr[128][128];
    for (int i = 0; i < 128; i++)
    {
        for(int j = 0 ; j < 128 ; j++)
        {
            arr[i][j] = imageGS[i+128][j];
        }
    }
    int x=0,y=0;
    for (int i = 0; i < SIZE; i+=2)
    {
        y=0;
        for(int j = 0 ; j < SIZE ; j+=2)
        {
            imageGS_FILTERed[i][j]=arr[x][y];
            imageGS_FILTERed[i][j+1]=arr[x][y];
            imageGS_FILTERed[i+1][j]=arr[x][y];
            imageGS_FILTERed[i+1][j+1]=arr[x][y];
            y++;
        }
        x++;
    }
}
    //fourth quarter
if (x==4)
{
    int arr[128][128];
    for (int i = 0; i < 128; i++)
    {
        for(int j = 0 ; j < 128 ; j++)
        {
            arr[i][j] = imageGS[i+128][j+128];
        }
    }
    int x=0,y=0;
    for (int i = 0; i < SIZE; i+=2)
    {
        y=0;
        for(int j = 0 ; j < SIZE ; j+=2)
        {
            imageGS_FILTERed[i][j]=arr[x][y];
            imageGS_FILTERed[i][j+1]=arr[x][y];
            imageGS_FILTERed[i+1][j]=arr[x][y];
            imageGS_FILTERed[i+1][j+1]=arr[x][y];
            y++;
        }
        x++;
    }
}

}

void filter9()
{



    // whitening the plain image before applying the filter :

    for (int i = 0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++ )
        {
            
            imageGS_FILTERed[i][j] = 255 ;

        }
        

    }


    // downsizing factor "x" switchcase : 
    char x;
    cout << "Shrink To a:(1/2) , b:(1/3) OR c:(1/4): "<<endl;
    cin >> x ;

    switch (x)
    {
        /* the algorithm works on reducing image height(rows) and width(cols) by skipping n rows and n columns from the 
        main image. n is the downsizing factor . */

        case 'a':

            for (int i = 0 ; i < SIZE ; i++)
            {
                for (int j = 0 ; j < SIZE ; j++ )
                {
                    
                    imageGS_FILTERed[i/2][j/2] = imageGS[i][j]  ;

                }
                

            }
            break;

        case 'b':

            for (int i = 0 ; i < SIZE ; i++)
            {
                for (int j = 0 ; j < SIZE ; j++ )
                {
                    
                    imageGS_FILTERed[i/3][j/3] = imageGS[i][j]  ;

                }
                

            }
            break;

        case 'c':

            for (int i = 0 ; i < SIZE ; i++)
            {
                for (int j = 0 ; j < SIZE ; j++ )
                {
                    
                    imageGS_FILTERed[i/4][j/4] = imageGS[i][j]  ;

                }
                

            }
            break;
        
        default:
            break;
    }
}

void filterA(int x)
{

    if(x==1)
    {
      for(int i=0;i<256;i++)
      {
        for(int j=0; j<128;j++)
        {
          imageGS_FILTERed[i][j]=imageGS[i][j];
          imageGS_FILTERed[i][255-j]=imageGS[i][j];
        }
        }
    }else if(x==2)
    {
      for(int i=0;i<255;i++)
      {
        for(int j=0; j<128;j++)
        {
          imageGS_FILTERed[i][j]=imageGS[i][255-j];
          imageGS_FILTERed[i][j+127]=imageGS[i][j+127];
        }
      }
    }else if(x==3)
    {
      for(int i=0;i<128;i++)
      {
        for(int j=0; j<256;j++)
        {
          imageGS_FILTERed[i][j]=imageGS[i][j];
          imageGS_FILTERed[255-i][j]=imageGS[i][j];
        }
      }
    }else if(x==4)
    {
      for(int i=0;i<128;i++)
      {
        for(int j=0; j<256;j++)
        {
          imageGS_FILTERed[i][j]=imageGS[255-i][j];
          imageGS_FILTERed[i+127][j]=imageGS[i+127][j];
        }
      }
    }

}

void filterB(int a, int b , int c , int d )
{
//switch on first part of the picture
    int x=0 , y=0 ;
    switch (a)
    {
    case 1:
    x=0 , y=0 ; 
    for(int i = 0 ; i<128 ; i++)
    {
        y=0;
        for(int j =0 ; j<128 ; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[x][y];
            y++;
        }
        x++;
    }
    break;

    case 2:
    x=0 , y=128 ;
    for(int i = 0 ; i<128 ; i++)
    {
        y=128;
        for(int j =0 ; j<128 ; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[x][y];
            y++;
        }
        x++;
    }
    break;

    case 3:
    x=128 , y=0 ;
    for(int i = 0 ; i<128 ; i++)
    {
        y=0;
        for(int j =0 ; j<128 ; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[x][y];
            y++;
        }
        x++;
    }
    break;

    default:
    x=128 , y=128 ;
    for(int i = 0 ; i<128 ; i++)
    {
        y=128;
        for(int j =0 ; j<128 ; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[x][y];
            y++;
        }
        x++;
    }
    break;
    }
//switch on second part of the picture
    switch (b)
    {
    case 1:
    x=0 , y=0 ; 
    for(int i = 0 ; i<128 ; i++)
    {
        y=0;
        for(int j = 128 ; j<256 ; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[x][y];
            y++;
        }
        x++;
    }
    break;

    case 2:
    x=0 , y=128 ;
    for(int i = 0 ; i<128 ; i++)
    {
        y=128;
        for(int j = 128 ; j<256 ; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[x][y];
            y++;
        }
        x++;
    }
    break;

    case 3:
    x=128 , y=0 ;
    for(int i = 0 ; i<128 ; i++)
    {
        y=0;
        for(int j = 128 ; j<256 ; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[x][y];
            y++;
        }
        x++;
    }
    break;

    default:
    x=128 , y=128 ;
    for(int i = 0 ; i<128 ; i++)
    {
        y=128;
        for(int j = 128 ; j<256 ; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[x][y];
            y++;
        }
        x++;
    }
    break;
    }
//switch on third part of the picture
switch (c)
    {
    case 1:
    x=0 , y=0 ; 
    for(int i = 128 ; i<256 ; i++)
    {
        y=0;
        for(int j = 0 ; j<128 ; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[x][y];
            y++;
        }
        x++;
    }
    break;

    case 2:
    x=0 , y=128 ;
    for(int i = 128 ; i<256 ; i++)
    {
        y=128;
        for(int j = 0 ; j<128 ; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[x][y];
            y++;
        }
        x++;
    }
    break;

    case 3:
    x=128 , y=0 ;
    for(int i = 128 ; i<256 ; i++)
    {
        y=0;
        for(int j = 0 ; j<128 ; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[x][y];
            y++;
        }
        x++;
    }
    break;

    default:
    x=128 , y=128 ;
    for(int i = 128 ; i<256 ; i++)
    {
        y=128;
        for(int j = 0 ; j<128 ; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[x][y];
            y++;
        }
        x++;
    }
    break;
    }
//switch on fourth part of the picture 
    switch (d)
    {
    case 1:
    x=0 , y=0 ; 
    for(int i = 128 ; i<256 ; i++)
    {
        y=0;
        for(int j =128 ; j<256 ; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[x][y];
            y++;
        }
        x++;
    }
    break;

    case 2:
    x=0 , y=128 ;
    for(int i = 128 ; i<256 ; i++)
    {
        y=128;
        for(int j =128 ; j<256 ; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[x][y];
            y++;
        }
        x++;
    }
    break;

    case 3:
    x=128 , y=0 ;
    for(int i = 128 ; i<256 ; i++)
    {
        y=0;
        for(int j =128 ; j<256 ; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[x][y];
            y++;
        }
        x++;
    }
    break;

    default:
    x=128 , y=128 ;
    for(int i = 128 ; i<256 ; i++)
    {
        y=128;
        for(int j =128 ; j<256 ; j++)
        {
            imageGS_FILTERed[i][j]=imageGS[x][y];
            y++;
        }
        x++;
    }
    break;
    }
}

void filterC()
{
    
    // pixels loop :

    for (int i = 0 ; i < SIZE ; ++i)
    {
        for (int j = 0 ; j < SIZE ; ++j)
        {
            //applying "box blur" kernel values to achieve the blurness :

            /* this happens by applying 3x3 kernel all carry values of ones on each 3x3 pixels cluster in the image.
            the algo. as we get the average (mean) of the neighboring pixels to the center pixel at each cluster
            */


            imageGS_FILTERed[i][j] = ( imageGS[i-1][j-1] + imageGS[i-1][j] + imageGS[i-1][j+1] + imageGS[i][j-1] + \
            imageGS[i][j] + imageGS[i][j+1] + imageGS[i+1][j-1] + imageGS[i+1][j] + imageGS[i+1][j+1] ) / 9 ;    


        }
        
    }
}

void filterD()
{
  for(int i=0;i<256;i++){
    for(int j=0;j<256;j++){
      imageGS_FILTERed[i][j]= 255;
    }
  }
  int x,y,l,w;
  //variables to store the users dimensions
  cout<<"dimensions the user want to crop the image to: ";
  cin>>x>>y>>l>>w;
  for (int i=x;i<x+l;i++){
    for(int j=y;j<y+w;j++){
      imageGS_FILTERed[i][j]=imageGS[i][j];
    }
  }
}

void filterE(double x)
{
    double larger_size_of_temp_arr=tan(x)*256;
    int temp_array[SIZE][SIZE+int(larger_size_of_temp_arr)];
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE+int (larger_size_of_temp_arr);j++)
        {
            temp_array[i][j]=255;
        }
    }
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            imageGS_FILTERed[i][j]=255;
        }
    }
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            temp_array[i][j+int(larger_size_of_temp_arr)]=imageGS[i][j];
        }
    }
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            temp_array[i][j]=temp_array[i][j*2];
        }
    }
    
    for(int i=0;i<SIZE;i++)
    {
        
        for(int j=0;j<SIZE;j++)
        {
            imageGS_FILTERed[i][j]=temp_array[i][j];
            
        }
    }
    int foo=0;
    //int bar =(tan(x)*(tan(x)*2));
    for(int i=0;i<SIZE;i++)
    {
        foo=i/(1+(1/tan(x)));
        for(int j=0;j<256;j++)
        {
            if (j+foo>255)
            {
                break;
            }
            imageGS_FILTERed[i][j]=imageGS_FILTERed[i][j+foo];
            imageGS_FILTERed[i][j+foo]=255;
        }
        
    }
}

void filterF(double x)
{
    // whitnening the imagegsfiltered :

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            imageGS_FILTERed[i][j] = 255;
        }    
    }        

    double C,Jump,step = x;
    C=0;
    for (int i = 0; i < SIZE; i++)
    {
        Jump = SIZE * step;
        for (int j = 0; j < SIZE; j++)
        {
            imageGS_FILTERed[int(C) + int(Jump)][j] = imageGS[i][j];
            Jump -= step; // horizontal shrinkage 
        }
        C+=1-step;
    }
}




void choose_filter(char x)
{
    if (x=='1')
    {
        filter1();
    }
    
    if (x == '2')
    {
        filter2();
    }

    if(x == '3')
    {
        filter3();
    }

    if (x=='4')
    {
        int f4_input;
        cout<<"press 1 for vertical flip and press 2 for horizontal flip: ";
        cin>>f4_input;
        filter4(f4_input);
    }

    if (x=='5')
    {
        int f5_input;
        cout<<"press 1 For 90* flip / press 2 For 180* flip / press 3 For 270*: ";
        cin>>f5_input;
        filter5(f5_input);
    }

    if (x=='6')
    {
        cout << "do you want to (d)arken or (l)ighten ? " ;
        char x ;
        cin >> x ;
        filter6(x);
    }

    if(x=='7')
    {
        filter7();
    }

    if (x=='8')
    {
        int f8_input;
        cout<<"Enlarge which quarter of the picture 1-2-3-4 ?"<<endl;
        cin >> f8_input;
        filter8 (f8_input);
    }
    if(x=='9')
    {
        filter9();
    }
    if(x=='a' || x=='A')
    {
        int fA_input;
        cout<<"choose 1 for the left vertical mirror / 2 for the right vertical mirror / 3 for the upper horizontal mirror / 4 for the lower horizontal mirror"<<endl;
        cin>>fA_input;
        filterA(fA_input);
    }  
    if(x == 'b' || x == 'B' )
    {
        int a , b , c , d;
        cout<< "Enter the order of shuffle : ";
        cin>>a>>b>>c>>d;
        filterB(a,b,c,d);
    }
    if(x=='c' || x=='C')
    {
        filterC();
    }
    if(x=='d' || x=='D')
    {
        filterD();
    }
    if(x == 'e' || x == 'E')
    {
        double fE_input;
        cout<<"Enter angle of horizontal skew : ";
        cin>>fE_input;
        fE_input = fE_input*(M_PI/180);
        //cout<<fE_input;
        filterE(fE_input);
    }
    if(x=='f' || x=='F')
    {

        double fF_input;
        cout<<"Enter angle of vertical skew : ";
        cin>>fF_input;
        fF_input = fF_input*(M_PI/180);
        //cout<<fF_input;
        filterF(fF_input);

    }
}
//