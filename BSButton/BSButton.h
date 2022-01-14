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
#define RESETTIME 250
#endif

class BSBtn {
  public:
    BSBtn(uint8_t pin);
    BSBtn(uint8_t pin, uint8_t numberOfCylces);

    void check();
    uint8_t getTaps();
    bool isSingle();
    bool isDouble();
    bool isTriple();
    bool isHold();
    bool isHolded();

  private:
    uint8_t _pin = 0;
    uint8_t _numberOfCylces = 8;

    uint32_t _previousTouchTime = 0;
    uint32_t _startTouchTime = 0;
    uint32_t _endTouchTime = 0;

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