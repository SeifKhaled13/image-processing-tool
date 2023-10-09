//==================================  Mohamed Ezz ======================================
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

    } else {
        cout<<"Invalid input, Please enter valid choice (d or l)"<<endl;
        darkenAndLighten();
    }
}
//==================================  Mohamed Ezz ======================================