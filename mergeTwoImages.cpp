//================================== Mohamed Ezz ======================================
void merge_two_img() {
    char merged_one[100];
    cout << "Enter the second image you would like to combine: " << endl;
    cin >> merged_one;
    strcat(merged_one, ".bmp");
    readGSBMP(merged_one, image2);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image3[i][j] = (image[i][j] + image2[i][j]) / 2;// every pixel equal the average gray level of the corresponding pixels in the images to merge


        }
    }
}
//==================================  Mohamed Ezz ======================================