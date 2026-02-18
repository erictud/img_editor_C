int invertImg(char *res_name, int **img, int w_img, int h_img){
    // creating pixel map with just gray
    int **img_invert =  (int **)malloc(h_img * sizeof(int *));
    if(img_invert == NULL) return 0;
    for(int i = 0; i < h_img; i++){
        img_invert[i] = (int *)malloc(3 * w_img * sizeof(int));
        if(img_invert[i] == NULL) return 0;
        for(int j = 0; j < w_img; j++){
            img_invert[i][j*3] = 255 - img[i][j*3];
            img_invert[i][j*3+1] = 255 - img[i][j*3+1];
            img_invert[i][j*3+2] = 255 - img[i][j*3+2];
        }
    }

    // creating image result file name
    write_img(res_name, img_invert, w_img, h_img);

    // deallocating
    for(int i = 0; i < h_img; i++)
        free(img_invert[i]);
    free(img_invert);
    return 1;
}