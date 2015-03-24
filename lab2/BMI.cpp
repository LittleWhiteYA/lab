#include "BMI.h"

BMI::BMI(float height, float weight)
{
    hei = height;
    wei = weight;
}

float BMI::BMI_value()
{
    hei = hei/100;
    bmi = wei/(hei*hei);
    return bmi;
}

string BMI::BMI_category()
{
    string category;

    if(bmi<15)
        category="Very severely underweight";
    else if(bmi>=15 && bmi<16)
        category="Severely underweight";
    else if(bmi>=16 && bmi<18.5)
        category="Underweight";
    else if(bmi>=18.5 && bmi<25)
        category="Normal";
    else if(bmi>=25 && bmi<30)
        category="Overweight";
    else if(bmi>=30 && bmi<35)
        category="Obese Class I (Moderately obese)";
    else if(bmi>=35 && bmi<40)
        category="Obese Class II (Severely obese)";
    else if(bmi>=40)
        category="Obese Class III (Very severely obese)";

    return category;

}

