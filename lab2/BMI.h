#include <string>

using namespace std;

class BMI{
public:
    BMI(float height, float weight);
    float BMI_value();
    string BMI_category();

private:
    float hei, wei;
    float bmi;
};


