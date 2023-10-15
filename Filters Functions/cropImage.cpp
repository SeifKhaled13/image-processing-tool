//================================== Osama Eslam ======================================
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
//================================== Osama Eslam ======================================