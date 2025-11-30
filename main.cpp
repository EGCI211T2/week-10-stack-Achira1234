#include<iostream>
using namespace std;
#include "cstring"
#include "stack.h"

int main(int argc, char **argv){
    Stack s;
     s.push(5);
      s.push(1);
      s.push(7);
      s.pop();
      s.push(6);
      s.pop();

 /*
  Exercise 1*/

    int i;
    for(i=1;i<argc;i++){
      if(strcmp(argv[i],"x")==0)  s.pop();
      else s.push(atoi(argv[i]));

    }
    

   return 0;
}
