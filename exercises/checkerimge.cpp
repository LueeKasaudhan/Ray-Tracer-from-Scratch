#include<iostream>
using namespace std; 
int main(){
  int height = 1000;
  int width = 1000;

  int tile_size= 125;

  cout<<"P3\n"<<width<<" "<<height<<" "<<"\n255\n";
  
  for (int i = height; i>0; --i) {
    for(int j=0; j<width; j++){
      double r = 1;
      double g = 1;
      double b = 1;
      int tile = ((i/tile_size)+(j/tile_size))%2;
      
      int sr = static_cast<int>(255.999*tile*r);
      int sg = static_cast<int>(255.999*tile*g);
      int sb = static_cast<int>(255.999*tile*b);
      
      cout<<sr<<" "<<sg<<" "<<sb<<"\n";
    }
  }
  return 0;
}
