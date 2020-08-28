#include <iostream>
#include <assert.h>
using namespace std;
 
class AlertWithSMS
{
  public:
     void raiseAlert(const char* vitalName, const char* level)
     {
       cout << "SMS:" << vitalName << " " << level;
     }
};

class AlertWithSound
{
  public:
     void raiseAlert(const char* vitalName, const char* level)
     {
       cout << "SMS:" << vitalName << " " << level;
     }
};


bool IsVitalInsideRange(float value, float lowerlimit, float upperlimit){
  return (value>=lowerlimit && value<=upperlimit);
 }

bool vitalsAreOk(float bpm, float spo2, float respRate) {
return (IsVitalInsideRange(bpm,70,150) && IsVitalInsideRange(spo2,90,100) && IsVitalInsideRange(respRate,30,95));
}

int main() {
  assert(IsVitalInsideRange(70,60,100) == true);
  assert(IsVitalInsideRange(40,60,100) == false);
  assert(IsVitalInsideRange(120,60,100) == false);
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
