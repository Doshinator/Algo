#include <iostream>
#include <string>
#include <iterator>

using namespace std;

class MasterMethod{
    public:
        MasterMethod(string function);
        int reverse_num(int n);
        int get_a(void) {return this->a;}
        int get_b(void) {return this->b;}

    private:
        int a;
        int b;

};
int MasterMethod::reverse_num(int n){
    int remainder;
    int value = 0;
    while(n != 0){
        remainder = n % 10;
        value = value*10 + remainder;
        n = n / 10;
    }
    return value;
}
MasterMethod::MasterMethod(string function){

    int n1 = 0;
    int i = 1;
    for(string::iterator it = function.begin() ; *it != 'T' ; it++){
       n1 = n1 + (*it - 48) * i;
       i = i * 10;
    }

    this->a = reverse_num(n1);

    
    int n2 = 0;

    for(string::iterator it = function.begin(); *it != ')' ; it++){
        n2 = *it - 48;
    }
    this->b = n2;
    
}


void summary(MasterMethod *m){
    cout << m->get_a() << " * log base " << m->get_b() << endl;
}


int main(void){


    //aT (n/b) + f(n)

    //2T(n/2) + n^2 ==> case 2
    MasterMethod m1("4T(n/2) + n^2");
    summary(&m1);
    
    


    return 0;
}