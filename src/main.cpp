#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

unsigned int contains(int min_left,int max_left,int min_right,int max_right){//part 1 of the assignment
    if((min_left <= min_right && max_left >= max_right) || (min_right <= min_left && max_right >= max_left)){
        return 1;
    }else{
        return 0;
    }
}

int main() 
{
    std::ifstream file("input.txt");
    if (file.is_open()){
        std::string line;
        std::istringstream iss;
        unsigned int result = 0;
        while (std::getline(file, line)){
            iss.str(line); // Reset the istringstream with the new line
            iss.clear(); // Clear any error flags
            int min_left, max_left, min_right, max_right;
            char c;
            iss >> min_left >> c >> max_left >> c >> min_right >> c >> max_right;
            //std::cout << "min_left: " << min_left << " max_left: " << max_left << " min_right: " << min_right << " max_right: " << max_right <<std::endl;
            //END of line parsing code
            result += contains(min_left, max_left, min_right, max_right);
        }
        std::cout << "number of matching pairs: " << result << std::endl;
        file.close();
    } else {
        throw std::runtime_error("Unable to open file :(");
    }
    return 0;
}