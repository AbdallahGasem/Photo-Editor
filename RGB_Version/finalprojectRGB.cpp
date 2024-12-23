// program: finalprojectRGB.cpp
// purpose: Final project for BONUS assignment 1
// Team IDs:20221012-20220294-20221101
// Authors names & IDs : Ahmed Karam(20221012) - Mohamed Abdelhamid Wagdy(20220294) - Abdallah Gassem(20221101)
// Emails: ahmedkaram2@hotmail.com - Mohamedabdelhamid2222003@gmail.com - abdallahgasem.fcaicu@gmail.com
// Date: October 2023 
// version: 1.0
#include<bits/stdc++.h>
#include "bmplib.cpp"
#include<unistd.h>
using namespace std;
unsigned char imageRGB[SIZE][SIZE][RGB];
unsigned char imageRGB2[SIZE][SIZE][RGB];
unsigned char imageRGB_FILTERed[SIZE][SIZE][RGB];
//Array to save directory path the size of the array is the maximum size of a path
char cwd[PATH_MAX];
//Filters implemented as functions
void choose_filter(char x);
void filter1();
void filter2();
void filter3();
void filter4(int x);
void filter5(int x);
void filter6(char x);
void filter7();
void filter8(int x);
void filter9();
void filterA(int x);
void filterB(int a, int b , int c , int d );
void filterC();
void filterD();
void filterE(double x);
void filterF(double x);
int main()
{
    /*To load the picture using the read function we must get the current working directory and give it as
    arguments to the function so we do that using the function getcwd()*/

    string imgname,path="\\";
    cout<<"choose your desired filter: "<<endl<<"1-Black and White"<<endl<<"2-Invert filter\n"<<"3-Merge Filter"<<endl<<"4-Flip image"<<endl<<"5-Rotate Image"<<endl
    <<"6-Darken OR Lighten Filter"<<endl<<"7-Image Edges"<<endl<<"8-Enlarge Image"<<endl
    <<"9-Shrink Image"<<endl<<"A-Mirror Image"<<endl<<"B-shuffle Image"<<endl<<"C-Blur Image"<<endl<<"D-Crop Image"<<endl<<"E-Skew Horizontally"<<endl<<"F-Skew Vertically"<<endl;
    char f;cin>>f;
    cout << "Enter the source imageRGB file name: ";
    cin >> imgname;
    imgname+=".bmp";
    path+=imgname;
    readRGBBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()),imageRGB);
    //The "choose_filter" function work as the program menu where user gets to pick his desired filter :)
    choose_filter(f);
    //writeGSBMP("filtered.bmp", imageRGB_FILTERed); This function was used by us students for testing
    showRGBBMP(imageRGB_FILTERed);
    return 0;
}
void filter1() 
{
    //black and white
  for (int i = 0; i < SIZE; i++) 
  {
    for (int j = 0; j< SIZE; j++) 
    {
            int w=0;
            for(int k=0; k<RGB ; k++)
            {
                if(imageRGB[i][j][k]>127)
                {
                    imageRGB_FILTERed[i][j][k]=255;
                    w++;
                }
                else imageRGB_FILTERed[i][j][k]=0;
            }
            if (w>1)
            {
                imageRGB_FILTERed[i][j][0]=255;
                imageRGB_FILTERed[i][j][1]=255;
                imageRGB_FILTERed[i][j][2]=255;
            }
            else 
            {
                imageRGB_FILTERed[i][j][0]=0;
                imageRGB_FILTERed[i][j][1]=0;
                imageRGB_FILTERed[i][j][2]=0;
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
            for(int k = 0 ; k < RGB ; k++)
            {
                imageRGB_FILTERed[i][j][k]=255-imageRGB[i][j][k];
            }
            
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
    readRGBBMP(strcat(getcwd(cwd2, sizeof(cwd2)), path2.c_str()),imageRGB2) ;

    // pixels loop :

    for (int i = 0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            // obtaining average of both images brightness to reach photo merging : 

            for(int k=0 ; k<RGB ; k++)
            {

                imageRGB_FILTERed[i][j][k] = (imageRGB[i][j][k]+imageRGB2[i][j][k]) / 2 ;

            }
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
                for(int k = 0 ; k< RGB ; k++)
                {
                    imageRGB_FILTERed[i][256-j][k]=imageRGB[i][j][k];
                }
            }
    }
  }
else if (x==1)
{
    for (int i = 0; i < SIZE; i++) 
    {
        for ( int j = 0; j< SIZE; j++) 
        {
            for(int k = 0; k<RGB; k++)
            {
                imageRGB_FILTERed[256-i][j][k]=imageRGB[i][j][k];
            }
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
            for(int k=0; k<RGB ; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[j][i][k];
            }
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
            for(int k=0 ; k<RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[255-i][255-j][k];
            }
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
            for(int k=0 ; k<RGB ; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[255-j][255-i][k];
            }
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

                for(int k=0 ; k<RGB ; k++)
                {
                    imageRGB_FILTERed[i][j][k] = imageRGB[i][j][k] - (imageRGB[i][j][k]*0.5) ;
                }
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
                for (int k = 0; k < RGB ; k++)
                {
                if (imageRGB[i][j][k] + (imageRGB[i][j][k]*0.5)<=255)
                {
                    imageRGB_FILTERed[i][j][k] = imageRGB[i][j][k] + (imageRGB[i][j][k]*0.5) ;    
                }
                else
                imageRGB_FILTERed[i][j][k]=255;  
                
                }
                
            }

        }
    }


}

void filter7()
{
  unsigned char imageGS_FILTERed1[SIZE][SIZE][RGB];
  int sum=0;
  for (int i = 0; i < SIZE; i++) 
  {
    for (int j =0; j< SIZE; j++) 
    {    
      for (int k = 0; k < RGB; k++)
      {
        sum+=imageRGB[i][j][k];
      }
      
    }
    }
  int avg=sum/(256*256*3);
  for (int i = 0; i < SIZE; i++) 
  {
    for (int j =0; j< SIZE; j++) 
    {
      for (int k = 0; k < RGB; k++)
      {
        if (imageRGB[i][j][k]<avg) 
      {
        imageRGB_FILTERed[i][j][k]=0;
      }else 
      {
        imageRGB_FILTERed[i][j][k]=255;
      }
      }
      
    }
    }
    int x=0;
    for (int i = 1; i < SIZE-1; i++) 
    {
      for (int j =0; j< SIZE; j++) 
    {
        for (int k = 0; k < RGB; k++)
        {
        if (imageRGB_FILTERed[i][j][k]==0 &&(imageRGB_FILTERed[i-1][j][k]==255||imageRGB_FILTERed[i-1][j+1][k]==255||imageRGB_FILTERed[i-1][j-1][k]==255||imageRGB_FILTERed[i][j+1][k]==255||imageRGB_FILTERed[i][j-1][k]==255||imageRGB_FILTERed[i][j+1][k]==255||imageRGB_FILTERed[i+1][j][k]==255))
      {
        imageGS_FILTERed1[i][j][k]=0;
        x=i;
        for(int z=x+1; z<255 ;z++)
        {
          if (imageRGB_FILTERed[z][j][k]==0&&(imageRGB_FILTERed[z][j+1][k]!=255||imageRGB_FILTERed[z][j-1][k]!=255))
          {
            imageGS_FILTERed1[z][j][k]=255;
          }else
          {
            break;
          }
        }
      }else
      {
        imageGS_FILTERed1[i][j][k]=255;
      }
        }
        
    }
    }
    for (int i = 0; i < SIZE; i++)
    {
    for (int j =0; j< SIZE; j++) 
    {
      for (int k = 0; k < RGB; k++)
      {
        imageRGB_FILTERed[i][j][k]=imageGS_FILTERed1[i][j][k];
      }
      
    }
    }

  }

void filter8(int x)
{
    //first quarter
if (x==1)
{
    int arr[128][128][3];
    for (int i = 0; i < 128; i++)
    {
        for(int j = 0 ; j < 128 ; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                arr[i][j][k]= imageRGB[i][j][k];
            }
            
        }
    }
    int x=0,y=0,z=0;
    for (int i = 0; i < SIZE; i+=2)
    {
        y=0;
        for(int j = 0 ; j < SIZE ; j+=2)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
            imageRGB_FILTERed[i][j][k]=arr[x][y][z];
            imageRGB_FILTERed[i][j+1][k]=arr[x][y][z];
            imageRGB_FILTERed[i+1][j][k]=arr[x][y][z];
            imageRGB_FILTERed[i+1][j+1][k]=arr[x][y][z];
            z++;
            }
            
            y++;
        }
        x++;
    }
}
    //second quarter
if (x==2)
{
    int arr[128][128][3];
    for (int i = 0; i < 128; i++)
    {
        for(int j = 0 ; j < 128 ; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                arr[i][j][k] = imageRGB[i][j+128][k];
            }
            
        }
    }
    int x=0,y=0,z=0;
    for (int i = 0; i < SIZE; i+=2)
    {
        y=0;
        for(int j = 0 ; j < SIZE ; j+=2)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
            imageRGB_FILTERed[i][j][k]=arr[x][y][z];
            imageRGB_FILTERed[i][j+1][k]=arr[x][y][z];
            imageRGB_FILTERed[i+1][j][k]=arr[x][y][z];
            imageRGB_FILTERed[i+1][j+1][k]=arr[x][y][z];
            z++;
            }
            
            y++;
        }
        x++;
    }
}
    //third quarter
if (x==3)
{
    int arr[128][128][3];
    for (int i = 0; i < 128; i++)
    {
        for(int j = 0 ; j < 128 ; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                arr[i][j][k] = imageRGB[i+128][j][k];
            }
            
        }
    }
    int x=0,y=0,z=0;
    for (int i = 0; i < SIZE; i+=2)
    {
        y=0;
        for(int j = 0 ; j < SIZE ; j+=2)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
            imageRGB_FILTERed[i][j][k]=arr[x][y][z];
            imageRGB_FILTERed[i][j+1][k]=arr[x][y][z];
            imageRGB_FILTERed[i+1][j][k]=arr[x][y][z];
            imageRGB_FILTERed[i+1][j+1][k]=arr[x][y][z];
            z++;
            }
            
            y++;
        }
        x++;
    }
}
    //fourth quarter
if (x==4)
{
    int arr[128][128][3];
    for (int i = 0; i < 128; i++)
    {
        for(int j = 0 ; j < 128 ; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                arr[i][j][k] = imageRGB[i+128][j+128][k];
            }
            
        }
    }
    int x=0,y=0,z=0;
    for (int i = 0; i < SIZE; i+=2)
    {
        y=0;
        for(int j = 0 ; j < SIZE ; j+=2)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
            imageRGB_FILTERed[i][j][k]=arr[x][y][z];
            imageRGB_FILTERed[i][j+1][k]=arr[x][y][z];
            imageRGB_FILTERed[i+1][j][k]=arr[x][y][z];
            imageRGB_FILTERed[i+1][j+1][k]=arr[x][y][z];
                z++;
            }
            
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
           for (int k = 0; k < RGB; k++)
           {
            imageRGB_FILTERed[i][j][k] = 255 ;
           }
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
                    for(int k=0 ; k<RGB ; k++)
                    {
                        imageRGB_FILTERed[i/2][j/2][k]= imageRGB[i][j][k];
                    }
                }
            }
            break;

        case 'b':

            for (int i = 0 ; i < SIZE ; i++)
            {
                for (int j = 0 ; j < SIZE ; j++ )
                {
                    for(int k=0 ; k<RGB ; k++)
                    {
                        imageRGB_FILTERed[i/3][j/3][k]= imageRGB[i][j][k];
                    }
                }
            }
            
            break;

        case 'c':

            for (int i = 0 ; i < SIZE ; i++)
            {
                for (int j = 0 ; j < SIZE ; j++ )
                {
                    for(int k=0 ; k<RGB ; k++)
                    {
                        imageRGB_FILTERed[i/4][j/4][k]= imageRGB[i][j][k];
                    }
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
          for(int k=0;k<3;k++){
          imageRGB_FILTERed[i][j][k]=imageRGB[i][j][k];
          imageRGB_FILTERed[i][255-j][k]=imageRGB[i][j][k];
          }
        }
        }
    }else if(x==2)
    {
      for(int i=0;i<255;i++)
      {
        for(int j=0; j<128;j++)
        {
          for(int k=0;k<3;k++){
          imageRGB_FILTERed[i][j][k]=imageRGB[i][255-j][k];
          imageRGB_FILTERed[i][j+127][k]=imageRGB[i][j+127][k];
        }
      }
      }
    }else if(x==3)
    {
      for(int i=0;i<128;i++)
      {
        for(int j=0; j<256;j++)
        {
          for(int k=0;k<3;k++){
          imageRGB_FILTERed[i][j][k]=imageRGB[i][j][k];
          imageRGB_FILTERed[255-i][j][k]=imageRGB[i][j][k];
          }
        }
      }
    }else if(x==4)
    {
      for(int i=0;i<128;i++)
      {
        for(int j=0; j<256;j++)
        {
          for(int k=0;k<3;k++){
          imageRGB_FILTERed[i][j][k]=imageRGB[255-i][j][k];
          imageRGB_FILTERed[i+127][j][k]=imageRGB[i+127][j][k];
          }
        }
      }
    }

  }

void filterB(int a, int b , int c , int d )
{
//switch on first part of the picture
    int x=0 , y=0 ,z=0 ;
    switch (a)
    {
    case 1:
    x=0 , y=0 , z=0; 
    for(int i = 0 ; i<128 ; i++)
    {
        y=0;
        for(int j =0 ; j<128 ; j++)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[x][y][z];
                z++;
            }
            
            y++;
        }
        x++;
    }
    break;

    case 2:
    x=0 , y=128 , z=0;
    for(int i = 0 ; i<128 ; i++)
    {
        y=128;
        for(int j =0 ; j<128 ; j++)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[x][y][z];
                z++;
            }
            y++;
        }
        x++;
    }
    break;

    case 3:
    x=128 , y=0 ,z=0;
    for(int i = 0 ; i<128 ; i++)
    {
        y=0;
        for(int j =0 ; j<128 ; j++)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[x][y][z];
                z++;
            }
            
            y++;
        }
        x++;
    }
    break;

    default:
    x=128 , y=128 , z=0;
    for(int i = 0 ; i<128 ; i++)
    {
        y=128;
        for(int j =0 ; j<128 ; j++)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[x][y][z];
                z++;
            }
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
    x=0 , y=0 ,z=0; 
    for(int i = 0 ; i<128 ; i++)
    {
        y=0;
        for(int j = 128 ; j<256 ; j++)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[x][y][z];
                z++;
            }
            
            y++;
        }
        x++;
    }
    break;

    case 2:
    x=0 , y=128 ,z=0;
    for(int i = 0 ; i<128 ; i++)
    {
        y=128;
        for(int j = 128 ; j<256 ; j++)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[x][y][z];
                z++;
            }
            y++;
        }
        x++;
    }
    break;

    case 3:
    x=128 , y=0 ,z=0;
    for(int i = 0 ; i<128 ; i++)
    {
        y=0;
        for(int j = 128 ; j<256 ; j++)
        {   
            z=0;
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[x][y][z];
                z++;
            }
            y++;
        }
        x++;
    }
    break;

    default:
    x=128 , y=128 ,z=0 ;
    for(int i = 0 ; i<128 ; i++)
    {
        y=128;
        for(int j = 128 ; j<256 ; j++)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[x][y][z];
                z++;
            }
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
    x=0 , y=0 ,z=0; 
    for(int i = 128 ; i<256 ; i++)
    {
        y=0;
        for(int j = 0 ; j<128 ; j++)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[x][y][z];
                z++;
            }
            y++;
        }
        x++;
    }
    break;

    case 2:
    x=0 , y=128 , z=0;
    for(int i = 128 ; i<256 ; i++)
    {
        y=128;
        for(int j = 0 ; j<128 ; j++)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[x][y][z];
                z++;
            }
            y++;
        }
        x++;
    }
    break;

    case 3:
    x=128 , y=0 ,z=0 ;
    for(int i = 128 ; i<256 ; i++)
    {
        y=0;
        for(int j = 0 ; j<128 ; j++)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[x][y][z];
                z++;
            }
            y++;
        }
        x++;
    }
    break;

    default:
    x=128 , y=128 , z=0 ;
    for(int i = 128 ; i<256 ; i++)
    {
        y=128;
        for(int j = 0 ; j<128 ; j++)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[x][y][z];
                z++;
            }
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
    x=0 , y=0 ,z=0; 
    for(int i = 128 ; i<256 ; i++)
    {
        y=0;
        for(int j =128 ; j<256 ; j++)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[x][y][z];
                z++;

            }
            y++;
        }
        x++;
    }
    break;

    case 2:
    x=0 , y=128 , z=0 ;
    for(int i = 128 ; i<256 ; i++)
    {
        y=128;
        for(int j =128 ; j<256 ; j++)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[x][y][z];
                z++;
            }
            y++;
        }
        x++;
    }
    break;

    case 3:
    x=128 , y=0 ,z=0 ;
    for(int i = 128 ; i<256 ; i++)
    {
        y=0;
        for(int j =128 ; j<256 ; j++)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[x][y][z];
                z++;

            }
            y++;
        }
        x++;
    }
    break;

    default:
    x=128 , y=128 ,z=0 ;
    for(int i = 128 ; i<256 ; i++)
    {
        y=128;
        for(int j =128 ; j<256 ; j++)
        {
            z=0;
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=imageRGB[x][y][z];
                z++;
            }
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

            for(int k =0 ; k < RGB ; k++)
            {
            imageRGB_FILTERed[i][j][k]= ( imageRGB[i-1][j-1][k] + imageRGB[i-1][j][k] + imageRGB[i-1][j+1][k] + imageRGB[i][j-1][k] + \
            imageRGB[i][j][k] + imageRGB[i][j+1][k] + imageRGB[i+1][j-1][k] + imageRGB[i+1][j][k] + imageRGB[i+1][j+1][k] ) / 9 ;    
            }

        }
        
    }
}

void filterD()
{
  for(int i=0;i<256;i++){
    for(int j=0;j<256;j++){
      for(int k=0;k<3;k++){
        imageRGB_FILTERed[i][j][k]= 255;
      }
    }
  }
  int x,y,l,w;
  //
  cout<<"dimensions the user want to crop the image to : ";
  cin>>x>>y>>l>>w;
  for (int i=x;i<x+l;i++){
    for(int j=y;j<y+w;j++){
      for(int k=0;k<3;k++){
      imageRGB_FILTERed[i][j][k]=imageRGB[i][j][k];
    }
    }
  }
}

void filterE(double x)
{
    //create a temporary array to store our skewed picture before shrinking
    double larger_size_of_temp_arr=tan(x)*256;
    int temp_array[SIZE][SIZE+int(larger_size_of_temp_arr)][RGB];
    //making the background white in the temporary array
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE+int (larger_size_of_temp_arr);j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                temp_array[i][j][k]=255;
            }
        }
    }
    //making the background white in the filtered picture
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=255;
            }
        }
    }
    //copying original picture into the temporary array
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                temp_array[i][j+int(larger_size_of_temp_arr)][k]=imageRGB[i][j][k];
            }
            
        }
    }
    //shrink the picture in the temporary array
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                temp_array[i][j][k]=temp_array[i][j*2][k];
            }
            
        }
    }
    //assigning values to the final pic
    for(int i=0;i<SIZE;i++)
    {
        
        for(int j=0;j<SIZE;j++)
        {
            
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[i][j][k]=temp_array[i][j][k];
            }
            
            
        }
    }
    //foo is just a random name used by the computer science students
    int foo=0;
    //Now the logic of skewing
    for(int i=0;i<SIZE;i++)
    {
        foo=i/(1+(1/tan(x)));
        for(int j=0;j<256;j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                if (j+foo>255)
            {
                break;
            }
            imageRGB_FILTERed[i][j][k]=imageRGB_FILTERed[i][j+foo][k];
            imageRGB_FILTERed[i][j+foo][k]=255;
            }
            
        }
        
    }
}

void filterF(double x)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for(int k = 0 ; k < RGB ; k++)
            {
            imageRGB_FILTERed[i][j][k] = 255;
            }
        }    
    }        
    double C,Jump,step = x;
    C=0;
    for (int i = 0; i < SIZE; i++)
    {
        Jump = SIZE * step;
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                imageRGB_FILTERed[int(C) + int(Jump)][j][k] = imageRGB[i][j][k];   
            }
            Jump -= step;
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
        cout<<"Enter angle of horizontal skew : ";
        cin>>fF_input;
        fF_input = fF_input*(M_PI/180);
        //cout<<fE_input;
        filterF(fF_input);

    }
}
