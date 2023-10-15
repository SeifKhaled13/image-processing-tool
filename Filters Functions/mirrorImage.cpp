//================================== Osama Eslam ======================================
void mirror(){
    char position;
    cout << "Enter the postition you want to mirror to (D)own, (U)pper, (L)eft and (R)right ";
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
//================================== Osama Eslam ======================================