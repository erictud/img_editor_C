char *buildFileResName(char *img_name, const char *extension);
int transformImage(char *res_name, int **img, int w_img, int h_img, void (*applyTransformation)(int **img, int **new_img, int i, int j));