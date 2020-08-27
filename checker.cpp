#include <assert.h>
 bool isOutOfRange(float value, float lowerlimit, float upperlimit){
  return !(value<lowerlimit && value>upperlimit);
 }
 /*int bpmcheck(float bpm){
   int state1;
    if(bpm < 70 || bpm > 150){
    state1 = 0;
    } else state1 = 1;
    return state1;
 }
 int spo2check(float spo2){
   int state2;
    if(spo2 < 90){
    state2 = 0;
    } else state2 = 1;
  return state2;
 }
 int respRatecheck(float respRate){
   int state3;
    if(respRate < 30 || respRate > 95){
    state3 = 0;
    } else state3 = 1;
  return state3;
 }*/
bool vitalsAreOk(float bpm, float spo2, float respRate) {
int vitalsresult;
vitalsresult = isOutOfRange(bpm,70,150) * isOutOfRange(spo2,90,100) * isOutOfRange(respRate,30,95);
 if(vitalsresult == 0){
   return false;
 }
 else return true;
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
