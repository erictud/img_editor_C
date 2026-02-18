int transformBlachWhite(char *res_name, int **img, int w_img, int h_img){
    // creating pixel map with just gray
    int **img_bw =  (int **)malloc(h_img * sizeof(int *));
    if(img_bw == NULL) return 0;
    for(int i = 0; i < h_img; i++){
        img_bw[i] = (int *)malloc(3 * w_img * sizeof(int));
        if(img_bw[i] == NULL) return 0;
        for(int j = 0; j < w_img; j++){
            float grey = 0.29 * img[i][j*3] + 0.58 * img[i][j*3+1] + 0.11 * img[i][j*3+2];
            img_bw[i][j*3] = (int)grey;
            img_bw[i][j*3+1] = (int)grey;
            img_bw[i][j*3+2] = (int)grey;
        }
    }

    // creating image result file name
    write_img(res_name, img_bw, w_img, h_img);

    // deallocating
    for(int i = 0; i < h_img; i++)
        free(img_bw[i]);
    free(img_bw);
    return 1;
}