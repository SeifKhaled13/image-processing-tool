// FCAI - OOP Programming - 2023 - Assignment 1
// Program Name: Image Processing Tool
// Last Modification Date: 18 October 2023
// Author1 and ID and Group: Seif Eldin Khaled - 20221077 - A
// Author2 and ID and Group: Mohammed Ahmed Ezz_eldin - 20221118 - A
// Author3 and ID and Group: Osama Eslam - 20220053 - A
// Teaching Assistant: NA
// Purpose: Learning more about how to use bmp library and C++
#include <iostream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include "bmplib.h"


unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
unsigned char toMirror[SIZE][SIZE];
unsigned char newImage[SIZE][SIZE];

void loadImage() {
    char imageFileName[100];

    // Get gray scale image file name
    std::cout << "Enter the source image file name: ";
    std::cin >> imageFileName;

    // Add ".bmp" extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    std::cout << "Enter the target image file name: ";
    std::cin >> imageFileName;

    // Add ".bmp" extension and save image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
    cout << "Filter(s) applied successfully!" << endl;
}

//==================================1st Filter======================================
void blackAndWhite()
{
    // first calculate average gray level
    int number = 0;
    for(int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            number+=image[i][j];
        }
    }
    number /= (SIZE*SIZE); // to get the average
    for(int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // the pixel greater than average be white
            if(image[i][j] > number){
                image[i][j]=255;
            }
                // the pixel lower than the average be black
            else{
                image[i][j]=0;
            }
        }
    }
}
//==================================2nd Filter======================================
void invertImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Invert the pixel value by subtracting it from 255
            image[i][j] = 255 - image[i][j];
        }
    }
}
//==================================3rd Filter======================================
void mergeTwoImages() {
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
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++) {
            image[i][j] = image3[i][j];
        }
    }
}
//==================================4th Filter======================================
void flipImage(){
    // first we need to ask the user to know how he wants the flip
    cout << "Do you want to rotate (H)orizontally or (V)ertically ? ";
    char c; cin >> c;

    if(c == 'H' || c == 'h'){
        /*
        in these loops we will take every pixel in the left and assign it to the pixel
        in the right and when reach the middle pixel it will do vice versa
        */
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                toMirror[i][255-j]=image[i][j];
            }
        }
    }
        /*
        here we will take pixels from top and assign them to bottom pixels
        and also when we will get to the middle pixel it will do the vice versa
        */
    else if (c == 'V' || c == 'v'){
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                toMirror[255-i][j]=image[i][j];
            }
        }
    }
    else{
        cerr << "Error, Please enter a valid choice (h or v)" << endl;
        flipImage();
    }
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++) {
            image[i][j] = toMirror[i][j];
        }
    }
}
//==================================5th Filter======================================
void rotateImage() {
    int choice;
    cout << "Choose rotation angle (90 degrees, 180 degrees or 270 degrees): ";
    cin >> choice;

    if (choice == 90) {
        unsigned char temp[SIZE][SIZE];
        int degrees = 90;
        // determine the number of 90-degree rotations needed
        int rotations = degrees / 90;

        for (int r = 0; r < rotations; r++) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    temp[j][SIZE - 1 - i] = image[i][j]; // rotate clockwise
                }
            }

            // copy the rotated image from temp to the original image array
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[i][j] = temp[i][j];
                }
            }
        }
    } else if (choice == 180) {
        unsigned char temp[SIZE][SIZE];
        int degrees = 180;
        // determine the number of 90-degree rotations needed
        int rotations = degrees / 90;

        for (int r = 0; r < rotations; r++) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    temp[j][SIZE - 1 - i] = image[i][j]; // rotate clockwise
                }
            }

            // copy the rotated image from temp to the original image array
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[i][j] = temp[i][j];
                }
            }
        }
    } else if (choice == 270) {
        unsigned char temp[SIZE][SIZE];
        int degrees = 270;
        // determine the number of 90-degree rotations needed
        int rotations = degrees / 90;

        for (int r = 0; r < rotations; r++) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    temp[j][SIZE - 1 - i] = image[i][j]; // rotate clockwise
                }
            }

            // copy the rotated image from temp to the original image array
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    image[i][j] = temp[i][j];
                }
            }
        }
    } else {
        cerr << "Invalid choice. Please select 90, 180, or 270." << endl;
        rotateImage();
    }
}
//==================================6th Filter======================================
void darkenAndLighten() {
    cout << "Do you want to (D)arken or (L)ighten ?" << endl; // to enter the choice of user
    char a;
    cin >> a;
    if (a == 'l' || a == 'L') { //if his choice is lighten
        for (int i = 0; i < SIZE; i++) { //loop for all pixels in the image
            for (int j = 0; j < SIZE; j++) {
                image[i][j] += (255 - image[i][j]) / 2; //this equation to be guarnteed that the pixel was more lighter
            }
        }
    } else if (a == 'd' || a == 'D') { // if his choice is darken
        for (int i = 0; i < SIZE; i++) { // loop for all pixels
            for (int j = 0; j < SIZE; j++) {
                image[i][j] *= 0.5; // this equation to be guarnteed that the pixel was more darker
            }
        }

    }else {
        cout<<"Invalid input, Please enter valid choice (d or l)"<<endl;
        darkenAndLighten();
    }
}
//==================================7th Filter======================================
void pencilEffect(){
    int n = 0;
    for(int i =0;i<SIZE;i++){
        for(int j = 0;j<SIZE;j++){
            n+=image[i][j];
        }
    }
    n/=(256*256);
    n+=30;
    for(int i = 1; i < SIZE-1; i++){
        for(int j = 1; j < SIZE-1; j++){
            toMirror[i][j] = image[i][j];
            if((image[i][j+1]>n && image[i+1][j]<n) || (image[i+1][j]>n && image[i][j+1]<n)){
                toMirror[i][j]=0;
            }
            else{
                toMirror[i][j]=255;
            }
        }
    }
}
//==================================8th Filter======================================
void enlargeImage() {
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

    unsigned char enlargedImage[256][256]; // create a new 256x256 image

    // reduce the selected quarter into a new 256x256 image
    for (int row = 0; row < 256; row++) {
        for (int col = 0; col < 256; col++) {
            int originalRow = sourceRowStart + row / 2;
            int originalCol = sourceColStart + col / 2;
            enlargedImage[row][col] = image[originalRow][originalCol];
        }
    }

    // copy the enlarged image back to the original image array
    for (int row = 0; row < 256; row++) {
        for (int col = 0; col < 256; col++) {
            image[row][col] = enlargedImage[row][col];
        }
    }
}
//==================================9th Filter======================================
void shrinkImage() {
    int shrunked[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            shrunked[i][j] = 255;
        }
    }
    cout << "choose the size of the image you want" << endl << "1 : 0.5\n" << "2 : 0.3\n" << "3 : 0.25\n";
    float block;
    cin >> block; // allowing user for choose the size he wants to shrink
    if (block == 0.5 || block == 0.25 || block == (float) 1 / 3 || block == (float) 1 / 2 || (float) block == 1 / 4) {
        block = 1 / block;
        for (int i = 0; i < SIZE; i += block) { // loop for all pixels and increment by the size he choose
            for (int j = 0; j < SIZE; j += block) {
                int sum_array_of_block = 0;
                for (int x = i; x < i + block; x++) {
                    for (int y = j; y < j + block; y++) {
                        sum_array_of_block += image[x][y];
                    }
                }
                shrunked[i / (int) block][j / (int) block] =
                        sum_array_of_block / (block * block); //calculate the everage of the asked array of the block
            }

        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = shrunked[i][j];
            }
        }

    } else {
        cout << "Invalid choice,please try again" << endl;
        shrinkImage();
    }
}
//==================================10th Filter======================================
void mirror(){
    char position;
    cout << "Enter the postition you want to mirror to (D)own, (U)pper, (L)eft and (R)right: ";
    cin >>  position;
    if(position == 'l' || position == 'L'){
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < 128; j++){
                image[i][256-j]=image[i][j];
            }
        }
    }
    else if(position == 'r' || position == 'R'){
        for(int i = 0; i < SIZE; i++){
            for(int j = 127; j < SIZE; j++){
                image[i][256-j]=image[i][j];
            }
        }
    }
    else if(position == 'u' || position == 'U'){
        for(int i = 0; i < 128; i++){
            for(int j = 0; j < SIZE; j++){
                image[256-i][j]=image[i][j];
            }
        }
    }
    else if(position == 'd' || position == 'D'){
        for(int i = 127; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                image[256-i][j]=image[i][j];
            }
        }
    }
    else{
        cout << "Wrong answer please try again " << endl;
        mirror();
    }

}
//==================================11th Filter======================================
void shuffleImage() {
    int quartersOrder[4];
    cout << "Enter the desired order of quarters: ";

    for (int i = 0; i < 4; i++) {
        cin >> quartersOrder[i];

        // check for valid input
        if (quartersOrder[i] < 1 || quartersOrder[i] > 4) {
            cerr << "Invalid input. Enter numbers from 1 to 4." << endl;
            return;
        }
    }

    unsigned char newImage[SIZE][SIZE];
    int quarterWidth = SIZE / 2;
    int quarterHeight = SIZE / 2;

    for (int i = 0; i < 4; i++) {
        int sourceRowStart = ((quartersOrder[i] - 1) / 2) * quarterHeight;
        int sourceColStart = ((quartersOrder[i] - 1) % 2) * quarterWidth;

        for (int row = 0; row < quarterHeight; row++) {
            for (int col = 0; col < quarterWidth; col++) {
                newImage[row + quarterHeight * (i / 2)][col + quarterWidth * (i % 2)] = image[row + sourceRowStart][col + sourceColStart];
            }
        }
    }

    // copy the shuffled image back to the original image array
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            image[row][col] = newImage[row][col];
        }
    }
}
//==================================12th Filter======================================
void blurImage() {
    unsigned char tempImage[SIZE][SIZE];

    for (int x = 1; x <= SIZE-1 ; x++) { // loop for all pixels
        for (int y = 1; y < SIZE-1 ; y++) {
            int neighbored_pixels = 0;

            for (int dx = -1; dx <= 4; dx++) { // loop for all pixels and calculate the neighbours of 6*6 array of the current pixel
                for (int dy = -1; dy <= 4; dy++) {
                    neighbored_pixels += image[x + dx][y + dy];

                }
            }

            tempImage[x][y] = neighbored_pixels / 36; //here when i calculate 6*6 array of the neighbour current pixel,we calculate the average to blur the pixel as we can
        }
    }
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) { // loop for all pixels and copy the image we do operations on it to the original image
            image[x][y] = tempImage[x][y];
        }
    }
}
//==================================13th Filter======================================
void cropImage(){
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
            newImage[i][j] = 255;
        }
    }
    for(int i = x; i <= (x + width); i++){
        for(int j = y; j <= (y + height); j++){
            newImage[i][j] = image[i][j];
        }
    }
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            image[i][j] = newImage[i][j];
        }
    }

}
//==================================14th Filter======================================
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
//==================================15th Filter======================================
void skewImageVertically(double degrees) {
    double radians = degrees * M_PI / 180.0; // Convert degrees to radians
    unsigned char tempImage[SIZE][SIZE];
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            tempImage[i][j]=255;
        }
    }
    for (int i = 0; i <SIZE; i++) {
        for (int j = SIZE-1; j >=0; j--) {
            int newX =  i- (SIZE/2)+j * tan(radians); // Calculate the new x-coordinate
            if (newX >= 0 && newX < SIZE) {
                tempImage[i][j] = image[newX][j]; // Perform the skew transformation
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
    cout << "e- Skew Image Right" << endl;
    cout << "f- Skew Image Up" << endl;
    cout << "s- Save the image to a file" << endl;
    cout << "0- Exit" << endl;
    cout << "Your Choice Here --> ";
    cin >> choice;
    while (choice != '0') {

        if (choice == '1') {
            blackAndWhite();
        } else if (choice == '2') {
            invertImage();
        } else if (choice == '3') {
            mergeTwoImages();
        } else if (choice == '4') {
            flipImage();
        } else if (choice == '5') {
            rotateImage();
        } else if (choice == '6') {
            darkenAndLighten();
        } else if (choice == '7') {
            pencilEffect();
        } else if (choice == '8') {
            enlargeImage();
        } else if (choice == '9') {
            shrinkImage();
        } else if (choice == 'a' || choice == 'A') {
            mirror();
        }else if (choice == 'b' || choice == 'B') {
            shuffleImage();
        } else if (choice == 'c' || choice == 'C') {
            blurImage();
        } else if (choice == 'd' || choice == 'D') {
            cropImage();
        } else if (choice == 'e' || choice == 'E') {
            skewImageHorizontally();
        } else if (choice == 'f' || choice == 'F') {
            cout << "enter the degree : ";
            double degree;
            cin >> degree;
            skewImageVertically(degree);
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
            cout << "e- Skew Image Right" << endl;
            cout << "f- Skew Image Up" << endl;
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
            cout << "e- Skew Image Right" << endl;
            cout << "f- Skew Image Up" << endl;
            cout << "s- Save the image to a file" << endl;
            cout << "0- Exit" << endl;
            cout << "Your Choice Here --> ";
            cin >> choice;
        } else if (c == '0') {
            choice = '0';
        }
        else if(c == 's' || c == 'S'){
            choice = 's';
        }

    }

}