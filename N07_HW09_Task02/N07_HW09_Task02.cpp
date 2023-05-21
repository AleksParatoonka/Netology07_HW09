// N07_HW09_Task02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

class big_integer {

public:
    std::string numb;
    big_integer(std::string numb_) {
        numb = numb_;
    }
    ~big_integer() // деструктор
    {}

    big_integer(const big_integer& other) // конструктор копирования
        : big_integer(other.numb){}

    big_integer(big_integer&& other) noexcept { // конструктор перемещения
        numb = std::move(other.numb);
    } 

    big_integer& operator=(const big_integer& other) // оператор копирующего присваивания
    {
        return *this = big_integer(other);
    }

    big_integer& operator=(big_integer&& other) noexcept // оператор перемещающего присваивания
    {
        if (&other != this){
            std::swap(numb, other.numb);
        }
       return *this;
    }

    big_integer operator+(big_integer other) {
        //std::cout << numb << "\n";
        //std::cout << other.numb << "\n";

        int delta = numb.length() - other.numb.length();
        int additional = 0;
        std::string res = "";
        if (numb.length() >= other.numb.length()) {
            for (int i = numb.length(); i > 0; i--) {
                int sum = int(numb[i - 1] - '0') + additional;
                if (i - delta > 0) {
                    sum += int(other.numb[i - delta - 1] - '0') ;
                    
                }
                additional = sum / 10;

                res += std::to_string(sum % 10);

            }
        }
        reverse(res.begin(), res.end());

        return big_integer(res);
    }
    big_integer operator*(big_integer other) {
        if (numb == "0" || other.numb == "0") {
            return big_integer("0");
        }
        //std::cout << numb << "\n";
        //std::cout << other.numb << "\n";
        int additional1 = 0;

        std::string res(numb.size() + other.numb.size(), 0 );
        std::string num1 ;
        std::string num2 ;
        if (numb.length() >= other.numb.length()) {
            num1 = other.numb;
            num2 = numb;
        }
        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j = num2.length() - 1; j >= 0; j--) {

                int n = (num1[i] - '0') * (num2[j] - '0') + res[i + j + 1];
                res[i + j + 1] = n % 10;
                res[i + j] += n / 10; 
            }
        }
        for (int i = 0; i < res.size(); i++) {
            res[i] += '0';
        }
        if (res[0] == '0') {
            return res.substr(1);
        }
        return big_integer(res);
    }
        
};

std::ostream& operator<<(std::ostream& os, big_integer const& m) {
    return os << m.numb;
}

int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    std::cout << number1 << std::endl;
    std::cout << number2 << std::endl;

    auto result=number1 + number2;
    std::cout << result << std::endl;; // 193099

    result = number1 * number2;
    std::cout << result << std::endl;; // 

}


