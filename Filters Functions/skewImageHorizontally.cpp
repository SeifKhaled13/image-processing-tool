//================================== Seif Khaled ======================================
void skewImageHorizontally() {
    double rad;
    cout << "Enter the desired skewing degree (positive = right & negative = left): ";
    cin >> rad;
    rad = (rad * 22) / (180 * 7);
    double move = tan(rad) * 256;
    double step = move / SIZE;

    unsigned char newImage[SIZE][SIZE] = {0}; // initialize the output image with 0

    // set the entire output image to white
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            newImage[i][j] = 255; // white background
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            double original_j = j - (move - step * i); // adjust for skew
            int leftPixel = floor(original_j);
            int rightPixel = leftPixel + 1;
            double fraction = original_j - leftPixel;

            // ensure that the pixel coordinates are within the image bounds
            if (leftPixel >= 0 && rightPixel < SIZE) {
                newImage[i][j] = (1 - fraction) * image[i][leftPixel] + fraction * image[i][rightPixel];
            }
        }
        move -= step;
    }

    // copy the resulting image back to the original array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = newImage[i][j];
        }
    }
}
//================================== Seif Khaled ======================================