#include <iostream>
#include <ostream>
#include <string>
class Puzzle{
    private:
        std::string _solution;
        std::string _guesses;
        static bool contains(char c, std::string s);

    public:
        Puzzle(std::string solution);
        virtual ~Puzzle();
        int guess(char c);
        bool solve(std::string phrase);
        std::string board();
        std::string guesses();
        std::string solution();

};
