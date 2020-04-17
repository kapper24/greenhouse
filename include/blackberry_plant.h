#pragma once
#include <plantbase.h>
#include <soil.h>

class BlackberryPlant : public plantbase 
{
public:
soil plantsoil;
double getheight() override { return height;};
int getnumblackberries(){ return blackberries; };
void grow(int days) override;
double soilgrowquality();

private:
double height{0.0};
int blackberries{0};
double growthrate = 2;

};