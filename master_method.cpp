/*Author: Rushabh Doshi*/
#include <iostream>
#include <string>
#include <iterator>
#include <math.h>

using namespace std;

class MasterMethod{
    public:
        MasterMethod(string function);
        int reverse_num(int n);
        int get_a(void) {return this->a;}
        int get_b(void) {return this->b;}
        string get_right_of_str(string const& str, string const& token);
        string get_str_between_two_str(const string &s, const string &start_delim, const string &stop_delim);
        string label;
        enum {case_1, case_2, case_3} cases;
        int a;
        int b;
        float fnpow;
        float power;

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
    this->label = function;
    //getting a
    string start_delim = "";
    string stop_delim = "T";
    this->a = stoi(get_str_between_two_str(function, start_delim, stop_delim));

    //getting b
    start_delim = "n/";
    stop_delim = ")";
    this->b = stoi(get_str_between_two_str(function, start_delim, stop_delim));


    //calculating which is greater
    this->power = log10(a) / log10(b);
    this->fnpow = stoi(get_right_of_str(function, "^"));

}

string MasterMethod::get_str_between_two_str(const string &s, const string &start_delim, const string &stop_delim){
    unsigned first_delim_pos = s.find(start_delim);
    unsigned end_pos_of_first_delim = first_delim_pos + start_delim.length();
    unsigned last_delim_pos = s.find(stop_delim);

    return s.substr(end_pos_of_first_delim, last_delim_pos - end_pos_of_first_delim);
}

string MasterMethod::get_right_of_str(string const& str, string const& token){
  return str.substr(str.find(token) + token.size());
}

void summary(MasterMethod *m){
    cout << "n^(log base " << m->get_b() << " of " << m->get_a() << "))"<< endl;
}

enum cases {case_1, case_2, case_3};

void result(MasterMethod *m){
    cases kases;
    if(m->fnpow < m->power){
        kases = case_1;
    } else if(m->fnpow == m->power){
        kases = case_2;
    } else {
        kases = case_3;
    }


    switch(kases){
        case case_1:
            cout << "Solution: T(n) =  Θ("; 
            summary(m);
            break;
        case case_2:
            cout << "Solution: T(n) =  Θ(n^(log base " << m->get_b() << " of " << m->get_a() << " * lg(n))" << endl;
            break;
        case case_3:
            string start_delim = "+";
            string stop_delim = "\0";
            cout << "Solution: T(n) =  Θ(" << m->get_str_between_two_str(m->label, start_delim, stop_delim) << ")" << endl;
            break;
    }
}


int main(void){

    
    //aT (n/b) + f(n)

    MasterMethod m3("7T(9n/2) + n^2");
    cout << "7T(n/2) + n^2 | Case_1 | ";
    result(&m3);

  
    MasterMethod m1("4T(n/2) + n^2");
    cout << "4T(n/2) + n^2 | Case_2 | ";
    result(&m1);

    MasterMethod m2("3T(n/2) + √10n^2");
    cout << "3T(n/2) + √10n^2 | Case_3 | ";
    result(&m2);

    


    return 0;
}