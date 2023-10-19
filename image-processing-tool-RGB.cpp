// FCAI - OOP Programming - 2023 - Assignment 1
// Program Name: Image Processing Tool
// Author1 and ID and Group: Seif Eldin Khaled - 20221077 - A
// Author2 and ID and Group: Mohammed Ahmed ezz_eldin - 20221118 - A
// Author3 and ID and Group: Osama Eslam - 20220053 - A
// Teaching Assistant: NA
// Last Modification Date: 18 October 2023
// Purpose: Learning more about how to use bmp library and C++
#include <iostream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include "bmplib.h"


unsigned char image[SIZE][SIZE][RGB];
unsigned char toMirror[SIZE][SIZE][RGB];
unsigned char newImage[SIZE][SIZE][RGB];
unsigned char tempImage2[SIZE][SIZE][RGB];


void loadImage() {
    char imageFileName[100];

    // Get gray scale image file name
    std::cout << "Enter the source image file name: ";
    std::cin >> imageFileName;

    // Add ".bmp" extension and load image
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}

void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    std::cout << "Enter the target image file name: ";
    std::cin >> imageFileName;

    // Add ".bmp" extension and save image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
    cout << "Filter(s) applied successfully!" << endl;
}

//==================================1st Filter======================================
void blackAndWhiteRGB(){
    // first calculate average gray level
    int number = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            int check = 0 ;
            for(int k = 0; k < RGB; k++){
                // to take the average between the pixel levels
                check +=image[i][j][k];
            }
            check/=3;
            number += check;
        }
    }
    number /= (SIZE*SIZE*RGB); // to get the average
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // the pixel greater than average be white
            int check = 0;
            for(int k = 0; k < RGB; k++){
                check += image[i][j][k];
            }
            check /=3;
            if (check > number) {
                for(int k = 0; k < RGB; k++){
                    image[i][j][k] = 255;
                }
            }
                // the pixel lower than the average be black
            else {
                for(int k = 0; k < RGB; k++){
                    image[i][j][k] = 0;
                }
            }
        }
    }
}
//==================================2st Filter======================================
void invertImageRGB() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                // invert the pixel value by subtracting it from 255
                image[i][j][k] = 255 - image[i][j][k];
            }
        }
    }
}
//==================================3rd Filter======================================
void mergeTwoImagesRGB() {
    char imageFileName[100];
    // Get gray scale image target file name to merge
    cout << "Enter the source image file name to merge: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");

    readRGBBMP(imageFileName, tempImage2);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                image[i][j][k] = (image[i][j][k] + tempImage2[i][j][k]) / 2;
            }
        }
    }
}
//==================================4th Filter======================================
void flipImageRGB(){
    // first we need to ask the user to know how he wants the flip
    cout << "Do you want to rotate H or V ? ";
    char c; cin >> c;

    if(c=='H' || c=='h'){
        /*
        in this loops we will take every pixel in the left and assign it to the pixel
        in the right and when reach the middle pixel it will do vice virsa
        */
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                for(int k = 0; k < RGB; k++) {
                    toMirror[i][255 - j][k] = image[i][j][k];
                }
            }
        }
    }
        /*
        here we will take pixels from top and assign them to bottom pixels
        and also when we will get to the middle pixel it will do the vice versa
        */
    else if(c=='v' || c=='V'){
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                for(int k = 0; k < RGB; k++) {
                    toMirror[255 - i][j][k] = image[i][j][k];
                }
            }
        }
    }
    else{
        cout << "wrong position please enter it again" << endl;
        flipImageRGB();
    }
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++) {
            for(int k = 0; k < RGB; k++) {
                image[i][j][k] = toMirror[i][j][k];
            }
        }
    }
}
//==================================5th Filter======================================
void rotateImageRGB() {
    int choice;
    cout << "Choose rotation angle (90 degrees, 180 degrees or 270 degrees): ";
    cin >> choice;

    if (choice == 90) {
        unsigned char temp[SIZE][SIZE][RGB];
        int degrees = 90;
        // determine the number of 90-degree rotations needed
        int rotations = degrees / 90;

        for (int r = 0; r < rotations; r++) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        temp[j][SIZE - 1 - i][k] = image[i][j][k]; // rotate clockwise
                    }
                }
            }

            // copy the rotated image from temp to the original image array
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        image[i][j][k] = temp[i][j][k];
                    }
                }
            }
        }
    } else if (choice == 180) {
        unsigned char temp[SIZE][SIZE][RGB];
        int degrees = 180;
        // determine the number of 90-degree rotations needed
        int rotations = degrees / 90;

        for (int r = 0; r < rotations; r++) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        temp[j][SIZE - 1 - i][k] = image[i][j][k]; // rotate clockwise
                    }
                }
            }

            // copy the rotated image from temp to the original image array
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        image[i][j][k] = temp[i][j][k];
                    }
                }
            }
        }
    } else if (choice == 270) {
        unsigned char temp[SIZE][SIZE][RGB];
        int degrees = 270;
        // determine the number of 90-degree rotations needed
        int rotations = degrees / 90;

        for (int r = 0; r < rotations; r++) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        temp[j][SIZE - 1 - i][k] = image[i][j][k]; // rotate clockwise
                    }
                }
            }

            // copy the rotated image from temp to the original image array
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        image[i][j][k] = temp[i][j][k];
                    }
                }
            }
        }
    } else {
        cerr << "Invalid choice. Please select 90, 180, or 270." << endl;
        rotateImageRGB();
    }
}
//==================================6th Filter======================================
void darkenLightenImageRGB(){
    cout<<"enter the filter you want darken or lighten"<<endl<<"d : darken\n"<<"l : lighten\n";
    char choice;
    cin>>choice;
    if(choice=='d' || choice=='D'){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                for(int k=0;k<RGB;k++){
                    image[i][j][k] *=0.5;
                }
            }
        }
    }else if(choice=='l' || choice=='L') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    image[i][j][k] +=(255 - image[i][j][k]) / 2;
                }

            }

        }
    }else{
        cout<<"Invalid choice,please try again\n";
        darkenLightenImageRGB();
    }
}
//==================================7th Filter======================================
void pencilEffectRGB(){
    int n = 0;
    for(int i =0;i<SIZE;i++){
        for(int j = 0;j<SIZE;j++){
            int check = 0;
            for(int k = 0; k < RGB; k++) {
                check += image[i][j][k];
            }
            check /= 3;
            n += check;
        }
    }
    n/=(256*256*3);
    for(int i = 1; i < SIZE-1; i++){
        for(int j = 1; j < SIZE-1; j++){
            int check = 0;
            for(int k = 0; k < RGB; k++) {
                toMirror[i][j][k] = image[i][j][k];
                if ((image[i][j + 1][k] > n && image[i + 1][j][k] < n) || (image[i + 1][j][k] > n && image[i][j + 1][k] < n)) {
                    toMirror[i][j][k] = 0;
                } else {
                    toMirror[i][j][k] = 255;
                }
            }
        }
    }
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            for(int k = 0; k < RGB; k++){
                image[i][j][k] = toMirror[i][j][k];
            }
        }
    }
}
//==================================8th Filter======================================
void enlargeImageRGB() {
    int quarterToEnlarge;
    cout << "Enter the quarter you want to enlarge (1, 2, 3, or 4): ";
    cin >> quarterToEnlarge;

    // check for valid input
    if (quarterToEnlarge < 1 || quarterToEnlarge > 4) {
        cerr << "Invalid input. Enter a number from 1 to 4." << endl;
        return;
    }

    int quarterWidth = SIZE / 2;
    int quarterHeight = SIZE / 2;

    int sourceRowStart = ((quarterToEnlarge - 1) / 2) * quarterHeight;
    int sourceColStart = ((quarterToEnlarge - 1) % 2) * quarterWidth;

    unsigned char enlargedImage[256][256][RGB]; // create a new 256x256x3 image

    // reduce the selected quarter into a new 256x256x3 image
    for (int row = 0; row < 256; row++) {
        for (int col = 0; col < 256; col++) {
            int originalRow = sourceRowStart + row / 2;
            int originalCol = sourceColStart + col / 2;
            for (int k = 0; k < RGB; k++) {
                enlargedImage[row][col][k] = image[originalRow][originalCol][k];
            }
        }
    }

    // copy the enlarged image back to the original image array
    for (int row = 0; row < 256; row++) {
        for (int col = 0; col < 256; col++) {
            for (int k = 0; k < RGB; k++) {
                image[row][col][k] = enlargedImage[row][col][k];
            }
        }
    }
}
//==================================9th Filter======================================
void shrinkImageRGB() {
    unsigned char shrunked[SIZE][SIZE][RGB];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                shrunked[i][j][k] = 255;
            }
        }
    }

    cout << "Choose the size of the image you want" << endl
         << "1 : 0.5" << endl
         << "2 : 0.333333333" << endl
         << "3 : 0.25" << endl;
    double  block;
    cin >> block;

    if (block == 0.5 || block == 0.25 || block == 0.333333333) {
        block = 1 / block;
        int sum_of_pixels_in_blocks[RGB] = {0};

        for (int i = 0; i < SIZE; i += block) {
            for (int j = 0; j < SIZE; j += block) {
                for (int k = 0; k < RGB; k++) {
                    for (int x = i; x < i + block; x++) {
                        for (int y = j; y < j + block; y++) {
                            sum_of_pixels_in_blocks[k] += image[x][y][k];
                        }
                    }
                    shrunked[i / (int)block][j / (int)block][k] = sum_of_pixels_in_blocks[k] / (block * block);
                    sum_of_pixels_in_blocks[k] = 0;
                }
            }
        }

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; k++) {
                    image[i][j][k] = shrunked[i][j][k];
                }
            }
        }
    } else {
        cout << "Invalid choice, please try again" << endl;
        shrinkImageRGB();
    }
}
//==================================10th Filter======================================
void mirrorImageRGB(){
    char position;
    cout << "Enter the position you want to mirror to (D)own, (U)pper, (L)eft and (R)right: ";
    cin >>  position;
    if(position == 'l' || position == 'L'){
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < 128; j++){
                for(int k = 0; k < RGB; k ++) {
                    image[i][256 - j][k] = image[i][j][k];
                }
            }
        }
    }
    else if(position == 'r' || position == 'R'){
        for(int i = 0; i < SIZE; i++){
            for(int j = 127; j < SIZE; j++){
                for(int k = 0; k < RGB; k++) {
                    image[i][256 - j][k] = image[i][j][k];
                }
            }
        }
    }
    else if(position == 'u' || position == 'U'){
        for(int i = 0; i < 128; i++){
            for(int j = 0; j < SIZE; j++){
                for(int k = 0; k < RGB; k++) {
                    image[256 - i][j][k] = image[i][j][k];
                }
            }
        }
    }
    else if(position == 'd' || position == 'D'){
        for(int i = 127; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                for(int k = 0; k < RGB; k++) {
                    image[256 - i][j][k] = image[i][j][k];
                }
            }
        }
    }
    else{
        cout << "Wrong answer please try again " << endl;
        mirrorImageRGB();
    }

}
//==================================11th Filter======================================
void shuffleImageRGB() {
    int quartersOrder[4];
    cout << "Enter the desired order of quarters: ";

    for (int i = 0; i < 4; i++) {
        cin >> quartersOrder[i];

        // Check for valid input
        if (quartersOrder[i] < 1 || quartersOrder[i] > 4) {
            cerr << "Invalid input. Enter numbers from 1 to 4." << endl;
            return;
        }
    }

    unsigned char newImage[SIZE][SIZE][RGB];
    int quarterWidth = SIZE / 2;
    int quarterHeight = SIZE / 2;

    for (int i = 0; i < 4; i++) {
        int sourceRowStart = ((quartersOrder[i] - 1) / 2) * quarterHeight;
        int sourceColStart = ((quartersOrder[i] - 1) % 2) * quarterWidth;

        for (int row = 0; row < quarterHeight; row++) {
            for (int col = 0; col < quarterWidth; col++) {
                for (int k = 0; k < RGB; k++) {
                    newImage[row + quarterHeight * (i / 2)][col + quarterWidth * (i % 2)][k] = image[row + sourceRowStart][col + sourceColStart][k];
                }
            }
        }
    }

    // Copy the shuffled image back to the original image array
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            for (int k = 0; k < RGB; k++) {
                image[row][col][k] = newImage[row][col][k];
            }
        }
    }
}
//==================================12th Filter======================================
void blurImageRGB(){
    for(int i=1;i<SIZE-1;i++){
        for(int j=1;j<SIZE-1;j++){
            for(int k=0;k<RGB;k++){
                int neighbour_pixels=0;
                for(int dx=-1;dx<=10;dx++){
                    for(int dy=-1;dy<=10;dy++){

                        neighbour_pixels +=image[i+dx][j+dy][k];

                    }
                }tempImage2[i][j][k]=neighbour_pixels/144;
            }
        }
    }for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<SIZE;k++){
                image[i][j][k]=tempImage2[i][j][k];
            }
        }
    }
}
//==================================13th Filter======================================
void cropImageRGB(){
    int x, y, width, height;
    cout << "enter x position : ";
    cin >> x;
    cout << "enter y position : ";
    cin >> y;
    cout << "enter width : ";
    cin >> width;
    cout << "enter height : ";
    cin >> height;
    while((x + width) > 256){
        cout << "Wrong position or width please enter x and width again : " << endl;
        cout << "enter x : ";
        cin >> x;
        cout << "enter width : ";
        cin >> width;
    }
    while((y + height) > 256){
        cout << "Wrong position or height please enter y and height again : " << endl;
        cout << "enter y : ";
        cin >> y;
        cout << "enter height : ";
        cin >> height;
    }
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            for(int k = 0; k < RGB; k++)
                newImage[i][j][k] = 255;
        }
    }
    for(int i = x; i <= (x + width); i++){
        for(int j = y; j <= (y + height); j++){
            for(int k = 0; k < RGB; k++) {
                newImage[i][j][k] = image[i][j][k];
            }
        }
    }
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            for(int k = 0; k < RGB; k++) {
                image[i][j][k] = newImage[i][j][k];
            }
        }
    }
}
//==================================14th Filter======================================
void skewImageHorizontallyRGB() {
    double rad;
    cout << "Enter the desired skewing degree (positive = right & negative = left): ";
    cin >> rad;
    rad = (rad * 22) / (180 * 7);
    double move = tan(rad) * 256;
    double step = move / SIZE;

    unsigned char newImage[SIZE][SIZE][RGB] = {0}; // initialize the output image with 0

    // Set the entire output image to white
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                newImage[i][j][k] = 255; // white background
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            double original_j = j - (move - step * i); // Adjust for skew
            int leftPixel = floor(original_j);
            int rightPixel = leftPixel + 1;
            double fraction = original_j - leftPixel;

            // Ensure that the pixel coordinates are within the image bounds
            if (leftPixel >= 0 && rightPixel < SIZE) {
                for (int k = 0; k < RGB; k++) {
                    newImage[i][j][k] = (1 - fraction) * image[i][leftPixel][k] + fraction * image[i][rightPixel][k];
                }
            }
        }
        move -= step;
    }

    // Copy the resulting image back to the original array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                image[i][j][k] = newImage[i][j][k];
            }
        }
    }
}
//==================================15th Filter======================================
void skewImageVerticallyRGB(double degrees) {
    double radians = degrees * M_PI / 180.0; // Convert degrees to radians
    unsigned char tempImage[SIZE][SIZE][RGB];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                tempImage[i][j][k] = 255; // Set the background color
            }
        }
    }

    double maxShift = SIZE / tan(radians); // Calculate the maximum shift in pixels

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {


                int newY = j + (maxShift * i / SIZE) - (maxShift / 2); // Calculate the new y-coordinate
                if (newY >= 0 && newY < SIZE) {
                    tempImage[i][j][k] = image[i][newY][k]; // Perform the vertical skew transformation
                }
            }
        }
    }

    // Copy the skewed image back to the original image
    memcpy(image, tempImage, sizeof(image));
}
//===================================================================================

int main() {
    char choice;
    loadImage();
    cout << "Please select a filter to apply or 0 to exit: " << endl;
    cout << "1- Black & White Filter" << endl;
    cout << "2- Invert Filter" << endl;
    cout << "3- Merge Filter" << endl;
    cout << "4- Flip Image" << endl;
    cout << "5- Rotate Image " << endl;
    cout << "6- Darken and Lighten Image " << endl;
    cout << "7- Detect Image Edges " << endl;
    cout << "8- Enlarge Image" << endl;
    cout << "9- Shrink Image" << endl;
    cout << "a- Mirror 1/2 Image" << endl;
    cout << "b- Shuffle Image" << endl;
    cout << "c- Blur Image" << endl;
    cout << "d- Crop Image" << endl;
    cout << "e- Skew Image Horizontally" << endl;
    cout << "f- Skew Image Vertically" << endl;
    cout << "s- Save the image to a file" << endl;
    cout << "0- Exit" << endl;
    cout << "Your Choice Here --> ";
    cin >> choice;
    while (choice != '0') {

        if (choice == '1') {
            blackAndWhiteRGB();
        } else if (choice == '2') {
            invertImageRGB();
        } else if (choice == '3') {
            mergeTwoImagesRGB();
        } else if (choice == '4') {
            flipImageRGB();
        } else if (choice == '5') {
            rotateImageRGB();
        } else if (choice == '6') {
            darkenLightenImageRGB();
        } else if (choice == '7') {
            pencilEffectRGB();
        } else if (choice == '8') {
            enlargeImageRGB();
        } else if (choice == '9') {
            shrinkImageRGB();
        } else if (choice == 'a' || choice == 'A') {
            mirrorImageRGB();
        }else if (choice == 'b' || choice == 'B') {
            shuffleImageRGB();
        } else if (choice == 'c' || choice == 'C') {
            blurImageRGB();
        } else if (choice == 'd' || choice == 'D') {
            cropImageRGB();
        } else if (choice == 'e' || choice == 'E') {
            skewImageHorizontallyRGB();
        } else if (choice == 'f' || choice == 'F') {
            cout << "enter the degree : ";
            double degree;
            cin >> degree;
            skewImageVerticallyRGB(degree);
        } else if (choice == 's' || choice == 'S') {
            saveImage();
        }
        else {
            cerr << "Error, Invalid Choice" << endl;\
            cout << "Please select a filter to apply or 0 to exit: " << endl;
            cout << "1- Black & White Filter" << endl;
            cout << "2- Invert Filter" << endl;
            cout << "3- Merge Filter" << endl;
            cout << "4- Flip Image" << endl;
            cout << "5- Rotate Image " << endl;
            cout << "6- Darken and Lighten Image " << endl;
            cout << "7- Detect Image Edges " << endl;
            cout << "8- Enlarge Image" << endl;
            cout << "9- Shrink Image" << endl;
            cout << "a- Mirror 1/2 Image" << endl;
            cout << "b- Shuffle Image" << endl;
            cout << "c- Blur Image" << endl;
            cout << "d- Crop Image" << endl;
            cout << "e- Skew Image Horizontally" << endl;
            cout << "f- Skew Image Vertically" << endl;
            cout << "s- Save the image to a file" << endl;
            cout << "0- Exit" << endl;
            cout << "Your Choice Here --> ";
            cin >> choice;
            continue;
        }
        cout << "Do You Want to Apply Another Filter? (Y)es, (S)ave or 0 to Exit: ";
        char c;
        cin >> c;
        while (c != 'Y' && c != 'y' && c != '0' && c != 's' && c != 'S') {
            cerr << "Error, Invalid Choice" << endl;
            cout << "Do You Want to Apply Another Filter? (Y)es, (S)ave or 0 to Exit: ";
            cin >> c;
        }
        if (c == 'Y' || c == 'y') {
            cout << "Please select a filter to apply or 0 to exit: " << endl;
            cout << "1- Black & White Filter" << endl;
            cout << "2- Invert Filter" << endl;
            cout << "3- Merge Filter" << endl;
            cout << "4- Flip Image" << endl;
            cout << "5- Rotate Image " << endl;
            cout << "6- Darken and Lighten Image " << endl;
            cout << "7- Detect Image Edges " << endl;
            cout << "8- Enlarge Image" << endl;
            cout << "9- Shrink Image" << endl;
            cout << "a- Mirror 1/2 Image" << endl;
            cout << "b- Shuffle Image" << endl;
            cout << "c- Blur Image" << endl;
            cout << "d- Crop Image" << endl;
            cout << "e- Skew Image Horizontally" << endl;
            cout << "f- Skew Image Vertically" << endl;
            cout << "s- Save the image to a file" << endl;
            cout << "0- Exit" << endl;
            cout << "Your Choice Here --> ";
            cin >> choice;
        } else if (c == '0') {
            choice = '0';
        }else if(c == 's' || c == 'S'){
            choice = 's';
        }
    }
}