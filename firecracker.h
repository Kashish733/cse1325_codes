#include<iostream>
#include<string>

class Firecracker{
    public:
        Firecracker(int length);
        virtual ~Firecracker();
        bool tic();
        std::string firecracker();
    
    private:
        int _length;
};
