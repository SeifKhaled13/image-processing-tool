// FCAI - OOP Programming - 2023 - Assignment 1
// Program Name: Image Processing Tool
// Last Modification Date: 8 October 2023
// Author1 and ID and Group: Mohammed Ahmed Ezz_eldin - 20221118 - A
// Author2 and ID and Group: Seif Eldin Khaled - 20221077 - A
// Author3 and ID and Group: Osama Eslam - 20220053 - A
// Teaching Assistant: NA
// Purpose: Learning more about how to use bmp library and C++
#include <iostream>
#include <cstring>
#include "bmplib.cpp"
#include "bmplib.h"


unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
unsigned char toMirror[SIZE][SIZE];

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

//==================================8th Filter======================================

//==================================9th Filter======================================

//==================================10th Filter======================================

//==================================11th Filter======================================

//==================================12th Filter======================================

//==================================13th Filter======================================

//==================================14th Filter======================================

//==================================15th Filter======================================


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
//    cout << "7- Detect Image Edges " << endl;
//    cout << "8- Enlarge Image" << endl;
//    cout << "9- Shrink Image" << endl;
//    cout << "a- Mirror 1/2 Image" << endl;
//    cout << "b- Shuffle Image" << endl;
//    cout << "c- Blur Image" << endl;
//    cout << "d- Crop Image" << endl;
//    cout << "e- Skew Image Right" << endl;
//    cout << "f- Skew Image Up" << endl;
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
        }
//        else if (choice == '7') {
//
//        } else if (choice == '8') {
//
//        } else if (choice == '9') {
//
//        } else if (choice == 'a') {
//
//        } else if (choice == 'b') {
//
//        } else if (choice == 'c') {
//
//        } else if (choice == 'd') {
//
//        } else if (choice == 'e') {
//
//        } else if (choice == 'f') {
//}
        else if (choice == 's') {
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
//    cout << "7- Detect Image Edges " << endl;
//    cout << "8- Enlarge Image" << endl;
//    cout << "9- Shrink Image" << endl;
//    cout << "a- Mirror 1/2 Image" << endl;
//    cout << "b- Shuffle Image" << endl;
//    cout << "c- Blur Image" << endl;
//    cout << "d- Crop Image" << endl;
//    cout << "e- Skew Image Right" << endl;
//    cout << "f- Skew Image Up" << endl;
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
//    cout << "7- Detect Image Edges " << endl;
//    cout << "8- Enlarge Image" << endl;
//    cout << "9- Shrink Image" << endl;
//    cout << "a- Mirror 1/2 Image" << endl;
//    cout << "b- Shuffle Image" << endl;
//    cout << "c- Blur Image" << endl;
//    cout << "d- Crop Image" << endl;
//    cout << "e- Skew Image Right" << endl;
//    cout << "f- Skew Image Up" << endl;
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