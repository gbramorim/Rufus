#include <Stepper.h>

#define powerButton 7 // Button to START counting.
#define stopButton 6  // Emergency STOP button.
#define activeTime 20 // Change this constant to set the ACTIVE time (in SECONDS).

const int EngineTurns = 200; // Defined by the Engine Manufacturer.
bool clickFloodgate;         // Variable for activating the Power Button.
bool clickEmergency;
unsigned long currentMilliseconds;

Stepper stepperMotor(EngineTurns, 8, 10, 9, 11); // Defining Engine Object.

void setup()
{
    stepperMotor.setSpeed(60); // Speed in RPM.

    pinMode(powerButton, INPUT);
    pinMode(stopButton, INPUT);
}

void loop()
{
    clickFloodgate = digitalRead(powerButton);
    if (clickFloodgate == HIGH)
    {
        openFloodgate(activeTime * 1000);
    }
}

/* Causes the motor to activate for a turn unit thus releasing the passage of food, soon after it returns to the initial shape
however if there is an emergency a button can be pressed to stop the gate */
void openFloodgate(unsigned long int time)
{
    currentMilliseconds = millis();
    while (millis() - currentMilliseconds <= time)
    {
        stepperMotor.step(EngineTurns);
        if ((clickEmergency = digitalRead(stopButton) == HIGH) 
        {
            stepperMotor.step(-EngineTurns);
        }
    }
    stepperMotor.step(-EngineTurns);
}
