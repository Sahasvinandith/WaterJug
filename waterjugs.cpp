#include <iostream>
#include <cmath>
using namespace std;

int showsteps(int x,int y,int z,int currentX=0,int currentY=0){//y is bigger one
    if(currentX!=z && currentY!=z){ //checking if the required amount has been created. if it created currentX & currentY exists the loop
        if(currentX==0 && currentY==0){ //to print first state <0,0>
            cout<<"<"<<currentX<<","<<currentY<<">  ";
        }
        if(currentX==0){ //if the small jug is empty filling it
            currentX=x;
            cout<<"<"<<currentX<<","<<currentY<<">  ";
        }
        if(currentY==y){ //if the big jug is full empty the jug
            currentY=0;
            cout<<"<"<<currentX<<","<<currentY<<">  ";
        }
        currentY+=currentX; //after above 2 steps adding the water in the jug a to jug 2. If the total water volume is mora than than capacity of jug b rest of water stored again at jug a
        if (currentY>y)
        {
            currentX=currentY-y;
            currentY=y;
            cout<<"<"<<currentX<<","<<currentY<<">  ";
        }
        else{
            currentX=0;//this means all the water in the jug a can be fitted in jug b.then jug a would be empty
            cout<<"<"<<currentX<<","<<currentY<<">  ";
        }
        return showsteps(x,y,z,currentX,currentY);//calling the function with new values

    }

    if (currentX==z && currentY!=0){ //these are the states that measured required capacity.these if loops decides which jug should be ampty to get final answer like: <0,8> 
        cout<<"<"<<currentX<<","<<0<<">  ";
    }
    else if(currentX!=0){
        cout<<"<"<<0<<","<<currentY<<">  ";
    }
    
    return 0;
}

int gcd(int x,int y){//function for obtain greatcommon divisor usingeuclid's algorithm
    if ((x%y)==0){
        return y;
    }
    else{
        return gcd(y,(x%y));
    }
}

int checkerror(int x,int y,int z){//function for check any errors
    if((x>40000) || (y>40000)){
        cout<<"Invalid input!!!";
        return 0;

    }
    if (z>x && z>y){
        cout<<"Wrong inputs!";
        return -1;
    }
    if (x>y){
        int k=y;
        y=x;
        x=k;
    }
    int k=gcd(x,y);
    if (gcd(k,z)!=k){
        cout<<"This amount can't be measured";
        return -1;
    }
    else{
        showsteps(x,y,z);
        return 0;
    }
}


int main(){
    int a,b,c;
    cout<<"<Capacity of 1st jug> <Capacity of 1st jug> <Measuring capacity>";
    cin>>a;
    cin>>b;
    cin>>c;

    checkerror(a,b,c);
    std::cout<<endl;
    system("pause");
}