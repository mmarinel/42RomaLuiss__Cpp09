#include <iostream>
#include <vector>

int main(void)
{
    int a, b, c;
    
    b = 11;
    c = 5;
    
    (a = b) = c;

    std::cout << "Val is: " << a << std::endl;
    return 0;
    std::vector<int>    vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    if (vec.begin() - 1 <  vec.begin())
        std::cout << "it works\n";
    else
        std::cout << "it doesn't works\n";
}
