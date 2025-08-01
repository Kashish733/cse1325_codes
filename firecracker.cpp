#include "firecracker.h"

Firecracker::Firecracker(int length)
            : _length{length}{
                if(length <3){
                    throw std::invalid_argument("Length must be greater than 3");
                }
            }
Firecracker::~Firecracker(){ }

bool Firecracker::tic(){
    if(_length>0){
        --_length;
    }
    return _length>0;

}

std::string Firecracker::firecracker(){
    return std::string(_length,'$');
}
