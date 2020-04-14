#pragma once
#include<plantbase.h>

class cucumberplant : plantbase
{
private:
 double height{0.0};
 int cucumbers{0};
 double growthrate{0.3};

public:
   void grow(int days) override;
    double getheight() override {return height;};

   int get_num_cucumbers(){return cucumbers;};
};


