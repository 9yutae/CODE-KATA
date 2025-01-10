#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string binomial) {
    stringstream ss(binomial);

    string first, second, third;
    ss >> first >> second >> third;
    
    int a = stoi(first), b = stoi(third);
    int answer;
    switch(second[0]) {
        case '+':
            answer = a + b;
            break;
       case '-':
            answer = a - b;
            break;
        case '*':
            answer = a * b;
            break; 
    }
    
    return answer;
}