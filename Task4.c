//necessary header files
#include<stdio.h>
#include "lodepng.h"
#include<stdlib.h>


unsigned	char* Image;unsigned	char* blurredImage;
unsigned	int w , h , r, g, b, a , red , green , blue;

void GaussianBlurr(){  //function to implement Gaussian blurr
     int i , j ; 
      for(i=0;i<h;i++) {   
        for (j = 0 ; j <w ; j++ ){
                   r = Image[4 * w * i + 4 * j + 0];
			       g =Image[4 * w * i + 4 * j + 1];
			       b = Image[4 * w * i + 4 * j + 2];
		           a = Image[4 * w * i + 4 * j + 3];
 
            //top row 
            if (i == 0){

                if (j == 0){                 //left most column 
                    red = (r + Image[4 * w * i + 4 * (j + 1)+ 0] + Image[4 * w * (i + 1) + 4 * j + 0] + Image[4 * w * (i + 1)+ 4 * (j + 1 )+0])/4;  //c
                    green = (g + Image[4 * w * i + 4 * (j + 1)+ 1] + Image[4 * w * (i + 1) + 4 * j + 1] + Image[4 * w * (i + 1)+ 4 * (j + 1 )+1])/4;
                    blue = (b + Image[4 * w * i + 4 * (j + 1)+ 2] + Image[4 * w * (i + 1) + 4 * j + 2] + Image[4 * w * (i + 1)+ 4 * (j + 1 )+2])/4;
                }else if (j == w-1){         //right most column 
                    red = (r + Image[4 * w * i + 4 * (j - 1)+ 0] +  Image[4 * w * (i+1) + 4 * (j - 1)+ 0] +  Image[4 * w * (i+1) + 4 * j + 0])/4;
                    green = (g + Image[4 * w * i + 4 * (j - 1)+ 1] +  Image[4 * w * (i+1) + 4 * (j - 1)+ 1] +  Image[4 * w * (i+1) + 4 * j + 1])/4;
                    blue = (b + Image[4 * w * i + 4 * (j - 1)+ 2] +  Image[4 * w * (i+1) + 4 * (j - 1)+ 2] +  Image[4 * w * (i+1) + 4 * j + 2])/4;

                }else {                     //middle columns  
                    red = (r + Image[4 * w * i + 4 * (j - 1) + 0] + Image[4 * w * i + 4 * (j + 1) + 0] + Image[4 * w * (i+1) + 4 * (j - 1) + 0] + Image[4 * w * ( i + 1) + 4 * j  + 0] + Image[4 * w * ( i + 1) + 4 * (j + 1) + 0] )/6;
                    green = (g + Image[4 * w * i + 4 * (j - 1) + 1] + Image[4 * w * i + 4 * (j + 1) + 1] + Image[4 * w * (i+1) + 4 * (j - 1) + 1] + Image[4 * w * ( i + 1) + 4 * j  + 1] + Image[4 * w * ( i + 1) + 4 * (j + 1) + 1] )/6;
                    blue = (b + Image[4 * w * i + 4 * (j - 1) + 2] + Image[4 * w * i + 4 * (j + 1) + 2] + Image[4 * w * (i+1) + 4 * (j - 1) + 2] + Image[4 * w * ( i + 1) + 4 * j  + 2] + Image[4 * w * ( i + 1) + 4 * (j + 1) + 2] )/6; 
                }

            }else if (i == h - 1){           //middle rows
                if (j == 0){                 //left most column 

                    red = ( r + Image[4 * w * i + 4 * (j + 1) + 0] + Image[4 * w * (i-1) + 4 * j  + 0] + Image[4 * w *(i-1) + 4 * (j + 1) + 0])/4;
                    green = ( g + Image[4 * w * i + 4 * (j + 1) + 1] + Image[4 * w * (i-1) + 4 * j  + 1] + Image[4 * w *(i-1) + 4 * (j + 1) + 1])/4;
                    blue = ( b + Image[4 * w * i + 4 * (j + 1) + 2] + Image[4 * w * (i-1) + 4 * j  + 2] + Image[4 * w *(i-1) + 4 * (j + 1) + 2])/4;

                }else if (j == w-1){         //right most column    
                
                    red = ( r + Image[4 * w * i + 4 *  (j - 1) + 0] + Image[4 * w * ( i- 1 ) + 4 * j  + 0] + Image[4 * w * ( i- 1 ) + 4 * ( j - 1 ) + 0])/4;
                    green = ( g + Image[4 * w * i + 4 * (j - 1) + 1] + Image[4 * w * ( i- 1 ) + 4 * j  + 1] + Image[4 * w * ( i- 1 ) + 4 * ( j - 1 ) + 1])/4;
                    blue = ( b + Image[4 * w * i + 4 * (j - 1) + 2] + Image[4 * w * ( i- 1 ) + 4 * j  + 2] + Image[4 * w * ( i- 1 ) + 4 * ( j - 1 ) + 2])/4;
                
                }else {                     //middle columns 

                 red = ( r + Image[4 * w * i + 4 * (j - 1) + 0] + Image[4 * w * i + 4 * (j + 1) + 0] + Image[4 * w * (i - 1) + 4 * j  + 0] + Image[4 * w * ( i - 1 ) + 4 * (j - 1) + 0] + Image[4 * w * (i - 1) + 4 * (j + 1) + 0] )/6;
                 green = ( g + Image[4 * w * i + 4 * (j - 1) + 1] + Image[4 * w * i + 4 * (j + 1) + 1] + Image[4 * w * (i - 1) + 4 * j  + 1] + Image[4 * w * ( i - 1 ) + 4 * (j - 1) + 1] + Image[4 * w * (i - 1) + 4 * (j + 1) + 1] )/6;
                 blue = ( b + Image[4 * w * i + 4 * (j - 1) + 2] + Image[4 * w * i + 4 * (j + 1) + 2] + Image[4 * w * (i - 1) + 4 * j  + 2] + Image[4 * w * ( i - 1 ) + 4 * (j - 1) + 2] + Image[4 * w * (i - 1) + 4 * (j + 1) + 2] )/6;
                    
                }
            }else {                         //Bottom row
                if (j == 0){                 //left most coulumn  
                    red = (r + Image[4 * w * i + 4 * (j + 1) + 0]  + Image[4 * w * (i - 1) + 4 * j + 0]  + Image[4 * w * (i - 1) + 4 * (j + 1) + 0]  + Image[4 * w * (i  +  1) + 4 * j + 0]  + Image[4 * w * (i  + 1) + 4 * (j + 1) + 0] )/6;
                    green = (g + Image[4 * w * i + 4 * (j + 1) + 1]  + Image[4 * w * (i - 1) + 4 * j + 1]  + Image[4 * w * (i - 1) + 4 * (j + 1) + 1]  + Image[4 * w * (i  +  1) + 4 * j + 1]  + Image[4 * w * (i  + 1) + 4 * (j + 1) + 1] )/6;
                    blue = (b + Image[4 * w * i + 4 * (j + 1) + 2]  + Image[4 * w * (i - 1) + 4 * j + 2]  + Image[4 * w * (i - 1) + 4 * (j + 1) + 2]  + Image[4 * w * (i  +  1) + 4 * j + 2]  + Image[4 * w * (i  + 2) + 4 * (j + 1) + 2] )/6;   

                }else if (j == w - 1){             //right most column 

                    red = ( r + Image[4 * w * i + 4 * (j - 1) + 0] + Image[4 * w * (i + 1) + 4 * (j - 1) + 0] + Image[4 * w * (i + 1) + 4 * j + 0] + Image[4 * w * (i - 1) + 4 * (j - 1) + 0] + Image[4 * w * (i - 1) + 4 * j  + 0])/6;
                    green = ( g + Image[4 * w * i + 4 * (j - 1) + 1] + Image[4 * w * (i + 1) + 4 * (j - 1) + 1] + Image[4 * w * (i + 1) + 4 * j + 1] + Image[4 * w * (i - 1) + 4 * (j - 1) + 1] + Image[4 * w * (i - 1) + 4 * j  + 1])/6;
                    blue = ( b + Image[4 * w * i + 4 * (j - 1) + 2] + Image[4 * w * (i + 1) + 4 * (j - 1) + 2] + Image[4 * w * (i + 1) + 4 * j + 2] + Image[4 * w * (i - 1) + 4 * (j - 1) + 2] + Image[4 * w * (i - 1) + 4 * j  + 2])/6;
                }else {                         //middle columns
                    
                    red = ( r + Image[4 * w * i + 4 * (j - 1) + 0] + Image[4 * w * i + 4 * (j + 1) + 0] + Image[4 * w * (i - 1) + 4 * (j - 1) + 0] + Image[4 * w * (i - 1) + 4 * j  + 0] + Image[4 * w * (i - 1) + 4 * (j + 1)  + 0] + Image[4 * w * (i + 1) + 4 * (j - 1)  + 0] + Image[4 * w * (i + 1) + 4 * j + 0] + Image[4 * w * (i + 1) + 4 * (j + 1)  + 0])/9;
                    green = ( g + Image[4 * w * i + 4 * (j - 1) + 1] + Image[4 * w * i + 4 * (j + 1) + 1] + Image[4 * w * (i - 1) + 4 * (j - 1) + 1] + Image[4 * w * (i - 1) + 4 * j  + 1] + Image[4 * w * (i - 1) + 4 * (j + 1)  + 1] + Image[4 * w * (i + 1) + 4 * (j - 1)  + 1] + Image[4 * w * (i + 1) + 4 * j + 1] + Image[4 * w * (i + 1) + 4 * (j + 1)  + 1])/9;
                    blue = ( b + Image[4 * w * i + 4 * (j - 1) + 2] + Image[4 * w * i + 4 * (j + 1) + 2] + Image[4 * w * (i - 1) + 4 * (j - 1) + 2] + Image[4 * w * (i - 1) + 4 * j  + 2] + Image[4 * w * (i - 1) + 4 * (j + 1)  + 2] + Image[4 * w * (i + 1) + 4 * (j - 1)  + 2] + Image[4 * w * (i + 1) + 4 * j + 2] + Image[4 * w * (i + 1) + 4 * (j + 1)  + 2])/9;
                }
            }
     
            blurredImage[4 * w * i + 4 * j + 0] = red;
			blurredImage[4 * w * i + 4 * j + 1] = green;
			blurredImage[4 * w * i + 4 * j + 2] = blue;
            blurredImage[4 * w * i + 4 * j + 3] = a; 
         
    }
  }
          
}

void main(){
  lodepng_decode32_file(&Image,&w,&h,"InputImage.png");     //decoding the input image
  
  blurredImage = (unsigned char *) malloc(w * h * 4  * sizeof(unsigned char )); //dynamic memory allocation for the output image
   
  GaussianBlurr();          //Gaussian Blurr Function 

  lodepng_encode32_file("Output.png",blurredImage,w,h);                  //Encoding the Image

  printf("\nNew Image with Gaussian blurr has been saved sucessfully.");     

  //freeing the dynamically allocated memory space    
  free(Image);
  free(blurredImage);


}