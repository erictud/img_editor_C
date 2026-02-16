#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "img_io.h"


int main(int argc, char **argv){
    int w_img, h_img, **img;
    // Reading image
    img = read_file("A-Cat.ppm", &w_img, &h_img);
    if(img == NULL){
        printf("Unexpected error while reading! Check image compatibility and try again!\n");
        return -1;
    }

}