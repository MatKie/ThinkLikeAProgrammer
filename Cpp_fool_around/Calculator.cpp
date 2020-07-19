#include <iostream>
class Calculator
{
public:
    float input_1;
    float input_2;

    float result;

    void add()
    {
        result = input_1 + input_2;
        std::cout
            << result << "\n";
    }

    void subtract()
    {

        result = input_1 - input_2;

        print();
    }

private:
    void print()
    {
        std::cout << "The result is: " << result << std::endl;
    }
};

int main()
{
    Calculator obj1;

    obj1.input_1 = 3;
    obj1.input_2 = 55;
    obj1.add();
    obj1.subtract();
}
