#include <assert.h>

bool vitalsAreOk(float bpm, float spo2, float respRate) {
        /*  if(bpm < 70 || bpm > 150) {
            return false;
          } else if(spo2 < 90) {
            return false;
          } else if(respRate < 30 || respRate > 95) {
            return false;
          }
          return true;*/
 int bpmcheck(float bpm){
   int state1;
    if(bpm < 70 || bpm > 150){
    state1 = 0;
    } else state1 = 1;
 }
 int spo2check(float spo2){
   int state2;
    if(spo2 < 90){
    state2 = 0;
    } else state2 = 1;
 }
 int respRatecheck(float bpm){
   int state3;
    if(respRate < 30 || respRate > 95){
    state3 = 0;
    } else state3 = 1;
 }
int vitalsresult;
vitalresult = state1 * state2 * state3;
 if(vitalresult == 0){
   return false;
 }
 else return true;
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
