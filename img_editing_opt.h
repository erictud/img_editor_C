#ifndef IMG_EDITING_OPT_H
#define IMG_EDITING_OPT_H

// OPT1 - ASCII Art generator
int **resizeImg(int w, int h, int **img, int *new_w, int *new_h);
int transformAscii(char *nume_fis, int **img, int w, int h);

// OPT 2 - Black and white filter
void applyTransformationBW(int **img, int **new_img, int i, int j);

// OPT 3 - Invert image colors 
void applyTransformationInvert(int **img, int **new_img, int i, int j);

// OPT 4 - Color filter
void applyTransformationFilterRed(int **img, int **new_img, int i, int j);
void applyTransformationFilterGreen(int **img, int **new_img, int i, int j);
void applyTransformationFilterBlue(int **img, int **new_img, int i, int j);

#endif // IMG_EDITING_OPT_H