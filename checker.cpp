#include <iostream>
#include <assert.h>
#include<string.h>
using namespace std;
class AlertSystem
{
public:
    virtual void raiseAlert(string vitalName, const char* LevelIndicationMessage) = 0;
};

class AlertWithSMS : public AlertSystem
{
public:
    void raiseAlert(string vitalName, const char* LevelIndicationMessage)
    {
        cout << "SMS Alert:" << vitalName << " --- " << LevelIndicationMessage << endl;
    }
};

class AlertWithBuzzer : public AlertSystem
{
public:
    void raiseAlert(string vitalName, const char* LevelIndicationMessage)
    {
        cout << "Buzzer Alert:" << vitalName << " --- " << LevelIndicationMessage << endl;
    }
};

class PatientVitals
{
private:
    string* vitalName;
    float* vitalValue;
    float* vitalLowerLimit;
    float* vitalUpperLimit;
public:
    PatientVitals(string* name, float* value, float* LowerLimit, float* UpperLimit) : vitalName(name), vitalValue(value), vitalLowerLimit(LowerLimit), vitalUpperLimit(UpperLimit) { }
    
    void checkVital(int totalNoOfVitalsToBeChecked, string* name, float* value, float* Lower, float* Upper, AlertSystem* alertptr)
    {
        for (int i = 0; i < totalNoOfVitalsToBeChecked; i++)
        {
            if (value[i] < Lower[i])
            {
                alertptr->raiseAlert(name[i], "TOO LOW!!!");
            }
            else if (value[i] >= Upper[i])
            {
                alertptr->raiseAlert(name[i], "TOO HIGH!!!");
            }
        }
        
    }
};

int main()
{
    /*Depending on the age group of the patient limits of vital range may differ!! So provide the lower and upper limits in the order of the vitals in the arrays respectively*/
    /*For eg.: respiratory rate is different for different age groups*/
    /*every patient may not require all the vital check. Here we can provide the required vitals for checking*/
    AlertWithSMS alertwithsms;
    AlertWithBuzzer alertwithbuzzer;
    cout << "....Vital check for patient1...." << endl;
    string vitalNames1[] = {"bpm","spo2","respRate"}; //patient1 needs check for 3 vitals
    float vitalLowerLimits1[] = { 70,90,24 };
    float vitalUpperLimits1[] = { 150,100,30 };
    float vitalValues1[] = { 60,93,35 };
    PatientVitals Patient1(vitalNames1, vitalValues1, vitalLowerLimits1, vitalUpperLimits1);
    Patient1.checkVital(3,vitalNames1, vitalValues1, vitalLowerLimits1, vitalUpperLimits1, &alertwithsms); //alerting with SMS
    cout << "....Vital check for patient2...." << endl;
    string vitalNames2[] = { "bpm","spo2","respRate","Body Temperature"};
    float vitalLowerLimits2[] = { 70,90,12,97};  //patient2 needs check for 3 vitals
    float vitalUpperLimits2[] = { 150,100,20,99 };
    float vitalValues2[] = { 90,83,10,100};
    PatientVitals Patient2(vitalNames2, vitalValues2, vitalLowerLimits2, vitalUpperLimits2);
    Patient2.checkVital(4, vitalNames2, vitalValues2, vitalLowerLimits2, vitalUpperLimits2, &alertwithbuzzer); //alerting with buzzer sound

}
