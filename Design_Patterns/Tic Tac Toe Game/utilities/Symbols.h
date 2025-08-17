#ifndef SYMBOL_H
#define SYMBOL_H

// 
class Symbol
{
    char symbol;

public:
    Symbol(char s)
    {
        this->symbol = s;
    }
    char getMark()
    {
        return symbol;
    }
};

#endif