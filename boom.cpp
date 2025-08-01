#include "firecracker.h"
#include "puzzle.h"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]){
    srand(time(NULL));
    Firecracker firecracker(8);
    std::string result;

    std::ifstream ist{std::string{argv[1]}};
    if(!ist) throw std::runtime_error{"can't open input file"};

    std::set<std::string> s;
    std::string a;
    while(std::getline(ist, a)) s.insert(a);

    int index= rand()%s.size();
    std::set <std::string>::iterator it = s.begin();
    std::advance(it,index);
    Puzzle puzzle(*it);


    while(true){
        std::cout << "Firecracker: " << firecracker.firecracker() << '\n';
        std::cout << "Guesses: " << puzzle.guesses() << '\n';
        std::cout << "Board: " << puzzle.board() << '\n';
        char c;

        std::cout << "Enter the letter, '!' to solve and '0' to lose :( " ;
        std::cin >> c;

        if(c=='0'){
            result = "Game end. The phrase was: " + puzzle.solution();
            break;
        }
        if(c=='!'){
            std::string s;
            std::cout << "Enter your phrase: ";
            std::getline(std::cin,s);
            if(puzzle.solve(s)){
                result = "YAY! You won" ;
                }
                else{
                    result = "That's not the word. You lost." ;
                }
                break;
            }
            try{
                    int count = puzzle.guess(c);
                    std::cout <<'\n'<< c << " appeared " << count << " times" << '\n';
                    if(!firecracker.tic()){
                        result= "You lose. The phrase was: " + puzzle.solution();
                        break;
                    }
                    else if(puzzle.board()==puzzle.solution()){
                        result= "Yay! You won";
                        break;
                    }
                }
                    catch(std::exception& e){
                        std::cerr <<"Exception: " << e.what() << '\n';
                    }
                }

        
                std::cout << '\n' << result << std::endl;
                return 0;
            }
