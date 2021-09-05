/*
 * 2DWavelet.c
 *
 *  Created on: July 29, 2012
 *      Author: BLEE, modified from Texas Instruments example
 *
 *  Description: This C header file with wavelet exmaple
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

#include "tistdtypes.h"
#include "wavelet.h"

#pragma DATA_SECTION(db2, "wavecoef");
#pragma DATA_SECTION(db3, "wavecoef");
#pragma DATA_SECTION(db4, "wavecoef");
#pragma DATA_SECTION(db5, "wavecoef");
#pragma DATA_SECTION(db6, "wavecoef");
#pragma DATA_SECTION(db7, "wavecoef");
#pragma DATA_SECTION(db8, "wavecoef");
#pragma DATA_SECTION(db9, "wavecoef");
#pragma DATA_SECTION(db10, "wavecoef");

Int16 db2[17] =
{       4,                            // N
   15825,   27410,    7345,   -4240,  // h3  h2 h1  h0
   -4240,   -7345,   27410,  -15825,  // h0 -h1 h2 -h3
    7345,   27410,   15825,   -4240,  // h1  h2 h3  h0
   -4240,  -15825,   27410,   -7345   // h0 -h3 h2 -h1
};

Int16 db3[25] =
{       6,
   10900,   26440,   15068,   -4423,   -2799,    1154,
    1154,    2799,   -4423,  -15068,   26440,  -10900,
   -2799,   26440,   15068,   -4423,   10900,    1154,
    1154,  -10900,   -4423,  -15068,   26440,    2799
};

Int16 db4[33] =
{       8,
    7548,   23423,   20672,    -916,   -6128,    1010,    1077,    -347,
    -347,   -1077,    1010,    6128,    -916,  -20672,   23423,   -7548,
    1077,   23423,   -6128,    -916,   20672,    1010,    7548,    -347,
    -347,   -7548,    1010,  -20672,    -916,    6128,   23423,   -1077
};

Int16 db5[41] =
{      10,
    5245,   19784,   23733,    4534,   -7939,   -1055,    2542,    -203,    -412,     108,
     108,     412,    -203,   -2542,   -1055,    7939,    4534,  -23733,   19784,   -5245,
    -412,   19784,    2542,    4534,   -7939,   -1055,   23733,    -203,    5245,     108,
     108,   -5245,    -203,  -23733,   -1055,    7939,    4534,   -2542,   19784,     412
};

Int16 db6[49] =
{      12,
    3653,   16206,   24611,   10331,   -7415,   -4253,    3194,     901,   -1035,      19,     157,     -36,
     -36,    -157,      19,    1035,     901,   -3194,   -4253,    7415,   10331,  -24611,   16206,   -3653,
     157,   16206,   -1035,   10331,    3194,   -4253,   -7415,     901,   24611,      19,    3653,     -36,
     -36,   -3653,      19,  -24611,     901,    7415,   -4253,   -3194,   10331,    1035,   16206,    -157
};

Int16 db7[57] =
{      14,
    2552,   12992,   23890,   15393,   -4715,   -7339,    2336,    2641,   -1245,    -543,     412,      13,     -58,      13,
      13,      58,      13,    -412,    -543,    1245,    2641,   -2336,   -7339,    4715,   15393,  -23890,   12992,   -2552,
     -58,   12992,     412,   15393,   -1245,   -7339,    2336,    2641,   -4715,    -543,   23890,      13,    2552,      13,
      13,   -2552,      13,  -23890,    -543,    4715,    2641,   -2336,   -7339,    1245,   15393,    -412,   12992,      58
};

Int16 db8[65] =
{      16,
    1782,   10252,   22137,   19181,    -517,   -9305,      16,    4217,    -570,   -1445,     458,     285,    -160,     -13,      22,      -3,
      -3,     -22,     -13,     160,     285,    -458,   -1445,     570,    4217,     -16,   -9305,     517,   19181,  -22137,   10252,   -1782,
      22,   10252,    -160,   19181,     458,   -9305,    -570,    4217,      16,   -1445,    -517,     285,   22137,     -13,    1782,      -3,
      -3,   -1782,     -13,  -22137,     285,     517,   -1445,     -16,    4217,     570,   -9305,    -458,   19181,     160,   10252,     -22
};

Int16 db9[73] =
{      18,
    1248,    7988,   19817,   21537,    4364,   -9610,   -3171,    4865,    1005,   -2215,       9,     733,    -154,    -140,      58,       6,      -9,       0,
       0,       9,       6,     -58,    -140,     154,     733,      -9,   -2215,   -1005,    4865,    3171,   -9610,   -4364,   21537,  -19817,    7988,   -1248,
      -9,    7988,      58,   21537,    -154,   -9610,       9,    4865,    1005,   -2215,   -3171,     733,    4364,    -140,   19817,       6,    1248,       0,
       0,   -1248,       6,  -19817,    -140,   -4364,     733,    3171,   -2215,   -1005,    4865,      -9,   -9610,     154,   21537,     -58,    7988,       9
};

Int16 db10[81] =
{      20,
     874,    6166,   17274,   22560,    9214,   -8185,   -6419,    4174,    3050,   -2339,    -966,    1087,     117,    -350,      45,      65,     -22,      -3,       3,       0,
       0,      -3,      -3,      22,      65,     -45,    -350,    -117,    1087,     966,   -2339,   -3050,    4174,    6419,   -8185,   -9214,   22560,  -17274,    6166,    -874,
       3,    6166,     -22,   22560,      45,   -8185,     117,    4174,    -966,   -2339,    3050,    1087,   -6419,    -350,    9214,      65,   17274,      -3,     874,       0,
       0,    -874,      -3,  -17274,      65,   -9214,    -350,    6419,    1087,   -3050,   -2339,     966,    4174,    -117,   -8185,     -45,   22560,      22,    6166,      -3
};

void IMG_wave_decom_two_dim( Int16 **image, Int16 *ws, Int16 Width, Int16 Height, Int16 *wavename, Int16 Level )
{
	Int16	i, k, half, ImgWid;
	
	ImgWid = Width;	
	for( k = 0; k < Level; k++ )
	{	
		half = Height>>1;	
		for( i = 0; i < Height; i++ )   
			decomInplace( image[i], ws, Width, wavename );
		for( i = 0; i < Width; i++ )
		{
			col2row( &image[0][i], ws, ImgWid, Height );
			decomCol( ws, &image[0][i], &image[half][i], ImgWid, Height, wavename ); 
		}
		Width>>=1; Height>>=1;
	}
}

void IMG_wave_recon_two_dim( Int16 **image, Int16 *ws, Int16 Width, Int16 Height, Int16 *wavename, Int16 Level )
{ 
	Int16	i, k, half, ImgWid;
	
	ImgWid = Width;   
	Width>>=(Level-1); Height>>=(Level-1);
	for( k = 0; k < Level; k++ )
	{
		half = Height>>1;
		for( i = 0; i < Width; i++ )
   		{
   			interlaceCol( &image[0][i], &image[half][i], ws, ImgWid, Height, wavename[0] );
   			reconCol( ws, &image[0][i], ImgWid, Height, wavename );
   		}
   		for( i = 0; i < Height; i++ ) 
			reconInplace( image[i], ws, Width, wavename );
		Width<<=1; Height<<=1;
	}
}
void IMG_wavep_decom_two_dim( Int16 **image, Int16 *ws, Int16 Width, Int16 Height, Int16 *wavename, Int16 Level )
{
	Int16	i, j, k, half, ImgWid, ImgHt;
	Int16	row_start, col_start, seg_num;
	
	ImgWid = Width;	ImgHt = Height;
	seg_num = 1;
	for( k = 0; k < Level; k++ )
	{	
		//Do the decomposition for each row         
		//-----------------------------------------------------------
		for( i = 0; i < ImgHt; i++ )
		{
			row_start = 0;
			for( j = 0; j < seg_num; j++ )
			{   
				decomInplace( &image[i][row_start], ws, Width, wavename );
				row_start += Width;    
			}   
		}
		//===========================================================  
			
		//Do the decomposition for each column
		//----------------------------------------------------------- 
		for( i = 0; i < ImgWid; i++ )
		{
			col_start = 0; 
			for( j = 0; j < seg_num; j++)
			{
				half = col_start + (Height>>1);
				col2row( &image[col_start][i], ws, ImgWid, Height );
				decomCol( ws, &image[col_start][i], &image[half][i], ImgWid, Height, wavename ); 
				col_start += Height;
			}
		}       
		//===========================================================
		Width>>=1; Height>>=1;
		seg_num<<=1;   
	}
}

void IMG_wavep_recon_two_dim( Int16 **image, Int16 *ws, Int16 Width, Int16 Height, Int16 *wavename, Int16 Level )
{         
	Int16	i, j, k, half, ImgWid, ImgHt;
	Int16	row_start, col_start, seg_num;
	
	ImgWid  = Width;	
	ImgHt   = Height;    
	Width >>=(Level-1);         
	Height>>=(Level-1);
	seg_num = 1<<(Level-1);
	
	for( k = 0; k < Level; k++ )
	{	
		//Do the reconstruction for each column
		//----------------------------------------------------------- 
		for( i = 0; i < ImgWid; i++ )
		{
			col_start = 0; 
			for( j = 0; j < seg_num; j++)
			{
				half = col_start + (Height>>1);
				interlaceCol( &image[col_start][i], &image[half][i], ws, ImgWid, Height, wavename[0] );
				reconCol( ws, &image[col_start][i], ImgWid, Height, wavename ); 
				col_start += Height;
			}
		}       
		//Do the reconstruction for each row         
		//-----------------------------------------------------------
		for( i = 0; i < ImgHt; i++ )
		{
			row_start = 0;
			for( j = 0; j < seg_num; j++ )
			{   
				reconInplace( &image[i][row_start], ws, Width, wavename );
				row_start += Width;    
			}   
		}
		
		Width<<=1; Height<<=1;
		seg_num>>=1;  
	}
}


