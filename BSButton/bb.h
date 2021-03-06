#ifndef BSButton_h
#define BSButton_h
#include <Arduino.h>

#ifndef STICKING
#define STICKING 50
#endif
#ifndef TouchInterval
#define TouchInterval 125
#endif
#ifndef HoldTIME
#define HoldTIME 250
#endif
#ifndef RESETTIME
#define RESETTIME 300
#endif
#ifndef DISCHARGETIME
#define DISCHARGETIME 5
#endif

class bb {
  public:
    bb(uint8_t pin);
    bb(uint8_t pin, uint8_t numberOfCylces);

    void check();
    uint8_t getTaps();
    bool isSingle();
    bool isDouble();
    bool isTriple();
    bool isHold();
    bool isHolded();

  private:
    uint8_t _pin = 0;
    uint8_t _numberOfCylces = 15;

    uint32_t _previousTouchTime = 0;
    uint32_t _startTouchTime = 0;
    uint32_t _endTouchTime = 0;
    uint32_t _startDischargeTime = 0;

    bool _pressedNow = false;
    bool _wasReleased = true;
    bool _isHolded = false;
    bool _wasisHolded = false;
    bool _isHoldedYet = false;
    bool _wasCleaned = true;
    uint8_t _numberOfTouches = 0;
    uint8_t _numberOfTouchesInTheEnd = 0;

    bool isTouched();
};

#endif