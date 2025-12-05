#include<iostream>
using namespace std;

int main (){
  int height = 512;
  int width = 512;

  cout<<"P3\n"<<width<<" "<<height<<" "<<"\n255\n";
  
  for (int i = height; i>0; --i) {
    for(int j=0; j<width; j++){
      double grad_r = double(j)/(width-1);
      double grad_g = double(i)/(width-1);
      double grad_b = double(i+j)/(height+width-2);

      int sc_r = static_cast<int>(255.999*grad_r);
      int sc_b = static_cast<int>(255.999*grad_b);
      int sc_g = static_cast<int>(255.999*grad_g);

      cout<<sc_r<<" "<<sc_g<<" "<<sc_b<<"\n";
    }
  }
  return 0;
}
