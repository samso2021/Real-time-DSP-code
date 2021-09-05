/*
 *  gammaContrast.h
 *
 *  Created on: Jul 21, 2012
 *      Author: BLEE
 *
 *  Description: This is the C header file for the gamma and contrast experiment
 *
 *  For the book "Real Time Digital Signal Processing:
 *                Fundamentals, Implementation and Application, 3rd Ed"
 *                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
 *                Publisher: John Wiley and Sons, Ltd
 *
 */

enum {
    GAMMA=0,
    LOWCONTRAST=1,
    HIGHCONTRAST=2,
    TABLESIZE = 256
    };
    
typedef struct {
    Uint16 len;               // Input: table length
    Uint16 *tablePtr;         // Input: pointer to lookup table
    Uint16 tblSelect;         // Select which table to generate
    float gamma;              // Gamma value for gamma table
    float lowContrast;        // Low contrast factor
    float highContrast;       // High contrast factor
} gcTbl;

typedef struct {
	Uint16 width;             // Input: image width
	Uint16 height;            // Input: image height
	Uint16 *r;                // Input: pointer to R element buffer
	Uint16 *g;                // Input: pointer to G element buffer
	Uint16 *b;                // Input: pointer to B element buffer
	Uint16 *pixelPtr;         // Input: pointer to pixel buffer
	Uint16 *tablePtr;         // Input: pointer to lookup table
} gcImg;

void imageMap(gcImg *img);
void tableGen(gcTbl *tbl);
