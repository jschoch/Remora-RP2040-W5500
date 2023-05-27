#ifndef REMORA_H
#define REMORA_H
#pragma pack(push, 1)


typedef union
{
  // this allow structured access to the incoming SPI data without having to move it
  struct
  {
    uint8_t rxBuffer[BUFFER_SIZE];
  };
  struct
  {
    int32_t header;
    volatile int32_t jointFreqCmd[JOINTS]; 	// Base thread commands ?? - basically motion
    float setPoint[VARIABLES];		  // Servo thread commands ?? - temperature SP, PWM etc
    uint8_t jointEnable;
    uint32_t outputs;
    uint8_t spare0;
  };
} rxData_t;

extern volatile rxData_t rxData;


typedef union
{
  // this allow structured access to the out going SPI data without having to move it
  struct
  {
    uint8_t txBuffer[BUFFER_SIZE];
  };
  struct
  {
    int32_t header;
    int32_t jointFeedback[JOINTS];	  // Base thread feedback ??
    float processVariable[VARIABLES];		     // Servo thread feedback ??
	  uint32_t inputs;
	  uint16_t NVMPGinputs;
  };
} txData_t;

extern volatile txData_t txData;


#pragma pack(pop)
#endif