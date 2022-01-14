#include "BSButton.h"
#include <Arduino.h>

//Конструктор1
BSBtn::BSBtn(uint8_t pin) {
  _pin = pin;
#ifdef BSBTest
  while (true) Serial.println(String(isTouched()));
#endif
}

//Конструктор2
BSBtn::BSBtn(uint8_t pin, uint8_t numberOfCylces) {
  _pin = pin;
  _numberOfCylces = numberOfCylces;
}

//Обработка качания
bool BSBtn::isTouched() {
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  pinMode(_pin, INPUT);
  byte counter = 0;
  while (!digitalRead(_pin)) {
    counter++;
  }
#ifdef BSBTest
  Serial.print(counter);
  Serial.print(", ");
  delay (30);
#endif
  if (counter > _numberOfCylces) return true;
  else return false;
}

void BSBtn::check() {
  uint32_t t = millis();

  bool touched = isTouched();

  //Запись времени начала нажатия
  if (_wasReleased == touched && touched == true && t - _endTouchTime >= STICKING) {
    _wasReleased = !_wasReleased;
    _startTouchTime = t;
  }

  //Запись времени окончания нажатия
  if (_wasReleased == touched && touched == false && t - _previousTouchTime >= STICKING) {
    _wasReleased = !_wasReleased;
    _endTouchTime = t;
    //Инскримент клика в случае если времени прошло меньше чем на удержание
    if (_endTouchTime - _startTouchTime < HoldTIME) {
      _numberOfTouches++;
      _wasCleaned = false;
    }
  }

  //Пишем ужержание
  if (!_wasReleased && t - _startTouchTime >= HoldTIME) {
    _isHolded = true;
    _wasCleaned = false;
  }

  //Записываем сколько нажатий произведено и скидываем счётчик
  if (!_wasCleaned && _wasReleased && t - _endTouchTime >= TouchInterval) {
    _numberOfTouchesInTheEnd = _numberOfTouches;
    _numberOfTouches = 0;
    _wasCleaned = true;
  }

  //При отпускании кнопки
  if (_wasReleased && t + TouchInterval - _endTouchTime >= RESETTIME) {
    _isHolded = false;
    _isHoldedYet = false;
    _numberOfTouchesInTheEnd = 0;
  }

  //Антидребезг
  if (touched) _previousTouchTime = t;
}

//Получить количество кликов
uint8_t BSBtn::getTaps() {
  uint8_t num = _numberOfTouchesInTheEnd;
  _numberOfTouchesInTheEnd = 0;
  return num;
}

//Один клик
bool BSBtn::isSingle() {
  if (_numberOfTouchesInTheEnd == 1) {
    _numberOfTouchesInTheEnd = 0;
    return true;
  }
  else return false;
}

//Два клика
bool BSBtn::isDouble() {
  if (_numberOfTouchesInTheEnd == 2) {
    _numberOfTouchesInTheEnd = 0;
    return true;
  }
  else return false;
}

//Три клика
bool BSBtn::isTriple() {
  if (_numberOfTouchesInTheEnd == 3) {
    _numberOfTouchesInTheEnd = 0;
    return true;
  }
  else return false;
}

//Удержание
bool BSBtn::isHold() {
  if (_isHolded) return true;
  else return false;
}

//После удержания
bool BSBtn::isHolded() {
  if (_isHolded && !_isHoldedYet) {
    _isHoldedYet = true;
    return true;
  }
  else return false;
}