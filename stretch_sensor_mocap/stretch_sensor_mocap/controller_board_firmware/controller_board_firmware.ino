//i2c commands
const int cmd_measure_adc1 = 11; //command to measure adc1
const int cmd_measure_adc2 = 12; //command to measure adc2
const int cmd_set_gain_1x = 1; //command to set the PGA to 1
const int cmd_set_gain_2x = 2; //command to set the PGA to 2
const int cmd_set_gain_4x = 4; //command to set the PGA to 4
const int cmd_set_gain_8x = 8; //command to set the PGA to 8
const int cmd_set_gain_16x = 16; //command to set the PGA to 16
volatile bool node_timer_fired = false; //flag for the timer interrupt

//USER MUST SET THESE VARIABLES BASED ON EACH USE CASE
const int gain = cmd_set_gain_16x; //select which gain you'd like to use
const bool measure_adc1 = true; //set to true if you'd like to measure adc1 (PIN_PA4)
const bool measure_adc2 = true; //set to true if you'd like to measure adc2 (PIN_PA5)
int nodes[] = {10, 11}; //array of addresses of each node in system
const int num_parameters = 14; //number of data points each node will send back to controller
const bool serial_print = true; //set to true if you'd like to print to the serial monitor and false if you'd like to use Serial.write() and a Python script for data collection
const bool ms_timer = false; //set to true if you'd like to use the ms timer (<= 100 Hz) and false if you'd like to use the us timer (> 100 Hz)

//other variables
const int num_nodes = sizeof(nodes) / sizeof(int); //calculates number of nodes in system
int data_array[num_nodes][num_parameters]; //array to store data from all nodes
int count = 0; //counter for how many nodes have had their data printed
volatile int frame_counter = 1; //frame counter to track data

//definitions for special ISR debugging, leave them alone for smooth operation
#define TIMER_INTERRUPT_DEBUG         0
#define _TIMERINTERRUPT_LOGLEVEL_     0
#define USING_TIMER_TC3               true
#define USING_TIMER_TC4               false
#define USING_TIMER_TC5               false
#define USING_TIMER_TCC               false
#define USING_TIMER_TCC1              false
#define USING_TIMER_TCC2              false

//files included for timer/interrupt functionality
#include "SAMDTimerInterrupt.h"
#include "SAMD_ISR_Timer.h"

//different USB stack used for faster controller to PC communication
#include <Adafruit_TinyUSB.h>

//Arduino I2C library
#include <Wire.h>

//select timer duration
#define TIMER_INTERVAL_US     5000
#define TIMER_INTERVAL_MS     100

//initialize hardware TIMER_TC3
SAMDTimer ITimer(TIMER_TC3);

//function called every time timer goes off
void TimerHandler() {
  node_timer_fired = true; //set timer interrupt flag to true
}

void setup() {
  Serial.begin(115200); //initialize serial monitor
  start_node_I2C(); //start controller to node I2C communication
  send_command(0, gain); //tell nodes which gain to use

  delay(100); //delay for smooth operation

  //attach interrupt function to timer
  if (ms_timer) ITimer.attachInterruptInterval_MS(TIMER_INTERVAL_MS, TimerHandler); //use this one if using TIMER_INTERVAL_MS
  else ITimer.attachInterruptInterval(TIMER_INTERVAL_US, TimerHandler); //use this one if using TIMER_INTERVAL_US

  //wait until user enters character into serial monitor before entering loop()
  char byteRead[10];
  while (Serial.available() <= 0) {
    delay(100);
  }
}

void loop() {
  if (node_timer_fired) { //if interrupt has fired
    if (measure_adc1) send_command(0, cmd_measure_adc1); //sends command to all nodes to measure adc1
    if (measure_adc2) send_command(0, cmd_measure_adc2); //sends command to all nodes to measure adc2
    for (int i = 0; i < num_nodes; i++) read_data(i); //reads data from each node
    for (int i = 0; i < num_nodes; i++) print_data(i); //prints data from each node
    node_timer_fired = false; //reset interrupt
  }
  count = 0;
}

//function to initialize I2C
void start_node_I2C() {
  Wire.begin(); //start I2C communication
  Wire.setClock(1000000); //set I2C clock to 1 MHz (max for ATtiny3226)
  #if defined (WIRE_HAS_TIMEOUT)
    Wire.setWireTimeout(3000, true); //if I2C times out, reset after 3000 us
  #endif
}

//function to send any command to any node
void send_command(int address, byte command) {
  Wire.beginTransmission(address); //begin transmission to specified node (or all if address is 0)
  Wire.write(command); //send byte to node(s)
  Wire.endTransmission(); //end transmission to node(s)
}

//function to read data from any node
void read_data(int node_i) {
  int address = nodes[node_i]; //find address of selected node
  Wire.requestFrom(address, num_parameters * 2, true); //request data from selected node (each data point is 2 bytes)
  for (int i = 0; i < num_parameters; i++) { //cycle through all parameters
    data_array[node_i][i] = read_int(); //write data to array
  }
}

//function to print data from node to serial monitor
void print_data(int node_i) {
  int address = nodes[node_i]; //find address of selected node

  //print data using Serial.print() (good for serial monitor)
  if (serial_print) {
    for (int i = 0; i < num_parameters; i++) {
      Serial.print(int16_t(data_array[node_i][i]));
      Serial.print(",");
    }
    count++;
    if (count == num_nodes) {
      Serial.print(frame_counter);
      frame_counter++;
      Serial.println();
    }
  }
  
  //print data using Serial.write() (faster speed, python script needed to decipher)
  else {
    for (int i = 0; i < num_parameters; i++) {
      uint8_t low = data_array[node_i][i] & 0b01111111;
      uint8_t middle = (data_array[node_i][i] >> 7) & 0b01111111;
      uint8_t high = (data_array[node_i][i] >> 14) & 0b01111111;
      Serial.write(0b10000000 | high);
      Serial.write(0b10000000 | middle);
      Serial.write(low);
    }
    count++;
    if (count == num_nodes) {
      uint8_t low = frame_counter & 0b01111111;
      uint8_t middle = (frame_counter >> 7) & 0b01111111;
      uint8_t high = (frame_counter >> 14) & 0b01111111;
      Serial.write(0b10000000 | high);
      Serial.write(0b10000000 | middle);
      Serial.write(low);
      frame_counter++;
    }
  }
}

//function for reading I2C messages from nodes
int read_int() {
  byte b0 = Wire.read();
  byte b1 = Wire.read();
  int val = (b0 << 8) | (b1 << 0);
  return val;
}