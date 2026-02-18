#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// custom headers
#include "utils.h"
#include "img_io.h"
#include "img_editing_opt_ASCII.h"
#include "img_editing_opt_bw.h"
#include "app_menu.h"


int main(int argc, char **argv){
    int w_img, h_img, **img, print_long = 1;
    char opt;
// Reading image
    img = read_img(argv[1], &w_img, &h_img);
    if(img == NULL){
        printf("Unexpected error while reading! Check image compatibility and try again!\n");
        return -1;
    }

    printWelcomeMessage();
    while(1){
        printOptionMenu(&opt, print_long);
        print_long = 0;
        if(opt == '1'){
            opt1(argv[1], img, w_img, h_img);
        }else if(opt == '2'){
            opt2(argv[1], img, w_img, h_img);
        }else if(opt == '3'){

        }else if(opt == '4'){
            printf("Thank you for using the app!\n");
            return 0; 
        }else{
            print_long = 1;
            printf("It seems that option %c doesnt exist!\nChoose a valid option!\n", opt);
        }
    }

// Writing image
    

    // int w = write_img(res_img_name, img, w_img, h_img);
    // if(w == 0){
    //     printf("Unexpected error while reading! Check image compatibility and try again!\n");
    //     return -1;
    // }
}