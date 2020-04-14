#include<tomatoplant.h>

void lemonbalm::grow(int days){
 growthrate = 2 * lemonbalm::soilgrowquality();
 height = height + days * growthrate;
 
}

double lemonbalm::soilgrowquality(){
    double Potassium = plantsoil.getPotassiumlevel();
    double Nitrate = plantsoil.getNitratelevel();
    double soil_moisturelevel = plantsoil.getMoisturelevel();
    if (Potassium == 0 || Nitrate == 0 && soil_moisturelevel > 0.30 && soil_moisturelevel < 0.70)
    {
        double growquality = 0.5;
        soil_moisturelevel -= 0.03;
        return(growquality);
    }
    else if (Potassium < 30 && Nitrate < 30 && soil_moisturelevel > 0.30 && soil_moisturelevel < 0.70)
    {
        double growquality = 1;
        if (Potassium < 4)
        {
         Potassium = 0;
        }
        if (Potassium > 4)
        {
         Potassium -= 4;
        }
        if (Nitrate < 4)
        {
         Nitrate = 0;
        }
        if (Nitrate > 4)
        {
         Nitrate -= 4;
        }
        soil_moisturelevel -= (growquality/2);
        return(growquality);
    }
  else if (Potassium > 30 || Nitrate > 30 && soil_moisturelevel > 0.30 && soil_moisturelevel < 0.70)
    {
        double growquality = 0.1;
        if (Potassium < 4)
        {
         Potassium = 0;
        }
        if (Potassium > 4)
        {
         Potassium -= 4;
        }
        if (Nitrate < 4)
        {
         Nitrate = 0;
        }
        if (Nitrate > 4)
        {
         Nitrate -= 4;
        }
        return(growquality);
    }
  else
  {
      return 0.1;
  }
}