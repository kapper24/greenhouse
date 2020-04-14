#pragma once
#include<plantbase.h>
#include<soil.h>

class lemonbalm : public plantbase
{
public:
soil plantsoil;
double getheight() override { return height;};
int getnumtomatoes(){ return tomatoes; };
void grow(int days) override;
double soilgrowquality();

private:
double height{0.0};
int tomatoes{0};
double growthrate = 2;




};