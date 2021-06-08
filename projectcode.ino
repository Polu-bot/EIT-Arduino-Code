#include <CD74HC4067.h>
#include <TrueRMS.h>
#define LPERIOD 1000
#define ADC_INPUT 0
#define RMS_WINDOW 40
unsigned long nextLoop;
int adcVal;
int cnt=0;
float VoltRange = 5.00;
Rms readRms ;
CD74HC4067 my_mux(22,23,24,25);
CD74HC4067 my_mux2(26,27,28,29);
CD74HC4067 my_mux3(30,31,32,33);
CD74HC4067 my_mux4(34,35,36,37);
void setup()
{
Serial.begin(9600);
Serial.println("LABEL,v");
Serial.print("DATA, ");
readRms.begin(VoltRange, RMS_WINDOW, ADC_10BIT, BLR_ON,CNT_SCAN);
readRms.start();
nextLoop = micros() + LPERIOD;

//electrode 0 & 1
my_mux.channel(0);
my_mux2.channel(1);
for (int k=2;k<15;k++)
{
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
// publish every 0.5s
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
// wait until the end of the time interval
while(nextLoop > micros());
// set next loop time to current time + LOOP_PERIOD
nextLoop += LPERIOD;
}
}

//electrode 1 & 2
my_mux.channel(1);
my_mux2.channel(2);
for (int k=3;k<15;k++)
{
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
// publish every 0.5s
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}
my_mux3.channel(15);
my_mux4.channel(0);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}

//electrode 2&3

my_mux.channel(2);
my_mux2.channel(3);
my_mux3.channel(0);
my_mux4.channel(1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
for (int k=4;k<15;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}
my_mux3.channel(15);
my_mux4.channel(0);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}

//electrode 3&4
my_mux.channel(3);
my_mux2.channel(4);

for (int k=0;k<2;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}

for (int k=5;k<15;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}
my_mux3.channel(15);
my_mux4.channel(0);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}

//electrode 4&5

my_mux.channel(4);
my_mux2.channel(5);

for (int k=0;k<3;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}

for (int k=6;k<15;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}
my_mux3.channel(15);
my_mux4.channel(0);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
//electrode 5&6

my_mux.channel(5);
my_mux2.channel(6);

for (int k=0;k<4;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}

for (int k=7;k<15;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}
my_mux3.channel(15);
my_mux4.channel(0);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}

//electrode 6&7

my_mux.channel(6);
my_mux2.channel(7);

for (int k=0;k<5;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}

for (int k=8;k<15;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}
my_mux3.channel(15);
my_mux4.channel(0);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}

//electrode 7 & 8
my_mux.channel(7);
my_mux2.channel(8);

for (int k=0;k<6;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}

for (int k=9;k<15;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}
my_mux3.channel(15);
my_mux4.channel(0);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}

//electrode 8&9

my_mux.channel(8);
my_mux2.channel(9);

for (int k=0;k<7;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}

for (int k=10;k<15;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}
my_mux3.channel(15);
my_mux4.channel(0);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}


//electrode 9 & 10

my_mux.channel(9);
my_mux2.channel(10);

for (int k=0;k<8;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}

for (int k=11;k<15;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}
my_mux3.channel(15);
my_mux4.channel(0);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}

//electrode 10&11
my_mux.channel(10);
my_mux2.channel(11);

for (int k=0;k<9;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}

for (int k=12;k<15;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}
my_mux3.channel(15);
my_mux4.channel(0);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}


//electrode 11&12
my_mux.channel(11);
my_mux2.channel(12);

for (int k=0;k<10;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}

for (int k=13;k<15;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}
my_mux3.channel(15);
my_mux4.channel(0);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}

//electrode 12&13
my_mux.channel(12);
my_mux2.channel(13);

for (int k=0;k<11;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}

for (int k=14;k<15;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}
my_mux3.channel(15);
my_mux4.channel(0);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}

//electrode 13&14
my_mux.channel(13);
my_mux2.channel(14);

for (int k=0;k<12;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}

my_mux3.channel(15);
my_mux4.channel(0);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}

//electrode 14&15
my_mux.channel(14);
my_mux2.channel(15);

for (int k=0;k<13;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}

//electrode 15&16
my_mux.channel(15);
my_mux2.channel(0);

for (int k=1;k<14;k++){
my_mux3.channel(k);
my_mux4.channel(k+1);
for(int i=0;i<500;i++)
{
adcVal = analogRead(ADC_INPUT);
readRms.update(adcVal);
cnt++;
if(cnt >= 500)
{
readRms.publish();
Serial.print(readRms.rmsVal,3);
Serial.println();
Serial.print("DATA, ");
cnt=0;
}
while(nextLoop > micros());
nextLoop += LPERIOD;
}
}



}
void loop() {
  // put your main code here, to run repeatedly:

}
