#pragma once
#include <string>

class Enemy
{
public:
    explicit Enemy(std::string name);
    void ShowInfo() const;

private:
    std::string name;
};
