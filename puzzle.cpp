#include "puzzle.h"
#include <string>
#include <sstream>

Puzzle::Puzzle(std::string solution) : 
_solution(solution), _guesses(" "){
    if(solution.empty()){
        throw std::invalid_argument("Solution should be empty.");
    }
    for(char& b: _solution){
        b= std::tolower(b);
    }
}

Puzzle::~Puzzle() { }

bool Puzzle::contains(char c, std::string s){
    return s.find(c)!=std::string::npos;
}

int Puzzle::guess(char c){
    if('a' >c || c>'z' || !std::isalpha(c) || contains(c,_guesses)){
        throw std::invalid_argument("You guessed poorly");
    }
     
    _guesses +=c;
    return std::count(_solution.begin(), _solution.end(), c);
}

bool Puzzle::solve(std::string phrase){
    return phrase == _solution;
}

std::string Puzzle::board(){
    std::ostringstream oss;
    std::istringstream iss{_solution};
    char ch;
    while(iss.get(ch)){
        if(!std::isalpha(ch) || contains(ch, _guesses)){
            oss << static_cast<char>(ch);
        }
        else{
            oss<< '_';
        }
    }
    return oss.str();
}

std::string Puzzle::guesses(){
    return _guesses;
}

std::string Puzzle::solution(){
    return _solution;
}
