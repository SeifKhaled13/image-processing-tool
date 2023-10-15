//================================== Osama Eslam ======================================
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
//================================== Osama Eslam ======================================