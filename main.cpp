#include <iostream>
#include <fstream>
#include <string>

void ReadFile(const std::string& path){
    std::ifstream temp(path);
    if(temp){
        std::string line;
        while(getline(temp, line)){
            std::cout << line << std::endl;
        }
    }
};
int main() {
    std::srand(time(nullptr));
    std::string username;
    int num = std::rand() % 100, n, count = 0;
    std::cout << num << std::endl;
    std::cout << "Enter your username:" << std::endl;
    std::cin >> username;
    std::cout << "Enter your guess:" << std::endl;
    do{
        count++;
        std::cin >> n;
        if (n > num){
            std::cout << "Less then " << n << std::endl;
        }
        else if(n < num){
            std::cout << "Greater then " << n << std::endl;
        }
    }while(n!=num);

    std::cout << "You're right, it's " << num << std::endl << "Attempts' count is " << count << std::endl << std::endl;
    std::string path = "history.txt";
    std::ofstream temp(path, std::ios::app);
    if (temp){
        temp << username << " " << count << std::endl;
    }
    std::cout << "Record table:" << std::endl;
    ReadFile(path);

    return 0;
}
