#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "img_io.h"
#include "img_editing_opt.h"


int main(int argc, char **argv){
    int w_img, h_img, **img;
// Reading image
    img = read_img(argv[1], &w_img, &h_img);
    if(img == NULL){
        printf("Unexpected error while reading! Check image compatibility and try again!\n");
        return -1;
    }

// Writing image
    // builds the result image file name (<name>_res.ppm)
    int l_img_name = strlen(argv[1]);
    char *res_img_name = (char *)malloc(l_img_name + 5);

    // copies just the name of the file without the .ppm extension
    strcpy(res_img_name, strtok(argv[1], "."));
    strcat(res_img_name, "_res");
    res_img_name[l_img_name + 4] = '\0';
   
    transformAscii(res_img_name, img, w_img, h_img);

    // int w = write_img(res_img_name, img, w_img, h_img);
    // if(w == 0){
    //     printf("Unexpected error while reading! Check image compatibility and try again!\n");
    //     return -1;
    // }
}