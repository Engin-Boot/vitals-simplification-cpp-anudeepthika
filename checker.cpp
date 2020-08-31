#include <iostream>
#include <assert.h>
using namespace std;
const int vitalLimitsArray[][2] = {{70,150},{90,101},{30,95}};
class AlertSystem
{
  public:
    virtual void raiseAlert(const char* vitalName, const char* LevelIndicationMessage) = 0;
};

class AlertWithSMS : public AlertSystem
{
  public:
     void raiseAlert(const char* vitalName, const char* LevelIndicationMessage)
     {
       cout << "SMS Alert:" << vitalName << " --- " << LevelIndicationMessage << endl;
     }
};

class AlertWithBuzzer : public AlertSystem
{
  public:
     void raiseAlert(const char* vitalName, const char* LevelIndicationMessage)
     {
       cout << "Buzzer Alert:" << vitalName << " --- " << LevelIndicationMessage << endl;
     }
};


/*bool IsVitalInsideRange(float value, float lowerlimit, float upperlimit){
  return (value>=lowerlimit && value<=upperlimit);
 }

bool vitalsAreOk(float bpm, float spo2, float respRate) {
return (IsVitalInsideRange(bpm,70,150) && IsVitalInsideRange(spo2,90,101) && IsVitalInsideRange(respRate,30,95));
}*/

int main() {
 /* assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);*/
 cout<<"passed"<<endl;
}
