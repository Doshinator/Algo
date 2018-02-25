# Algo
algorithms

MasterMethod calculator.

Make a MasterMethod object with a constructor string argument.


    MasterMethod m3("7T(9n/2) + n^2");
    cout << "7T(n/2) + n^2 | Case_1 | ";
    result(&m3);

  
    MasterMethod m1("4T(n/2) + n^2");
    cout << "4T(n/2) + n^2 | Case_2 | ";
    result(&m1);

    MasterMethod m2("3T(n/2) + √10n^2");
    cout << "3T(n/2) + √10n^2 | Case_3 | ";
    result(&m2);

Output:
7T(n/2) + n^2 | Case_1 | Solution: T(n) =  Θ(n^(log base 2 of 7))
4T(n/2) + n^2 | Case_2 | Solution: T(n) =  Θ(n^(log base 2 of 4 * lg(n))
3T(n/2) + √10n^2 | Case_3 | Solution: T(n) =  Θ( √10n^2)

case_1 f(n) is less than n^log b of 1
case_2 f(n) is equal to n^log b of 1
case_1 f(n) is greater than n^log b of 1


