## Исправлены ошибки, теперь работает без заземления

Схема: между пином, имеющим АЦП, и +5V или Vin ставится резистор на 1 мОм, а проводник (хоть гвоздь на проводе) цепляется на тот пин. 
Нагляднее в Cхема.png

#### Как пользоваться библиотекой?  
1) Подключаем библиотеку  
*#include "bb.h"*
2) Инициализация кнопки одним из способов:  
*bb button1(pin);*  
*bb button1(pin, num);*  
*num* - дополнительный параметр, подробнее в примере Time_display

3) Необходимо, чтобы информация о нажатиях всегда была актуальна, поэтому кидаем  
*button1.check();* в void loop()

4) Функции библиотеки:  
**boolean:**  
*button1.isSingle()* - true, если единичный клик, иначе false  
*button1.isDouble()* - true, если двойной клик, иначе false  
*button1.isTriple()* - true, если тройной клик, иначе false  
*button1.isHold()* - true, если кнопка зажата, и с начала зажатия прошло времени больше, чем при обычном клике, иначе false  
*button1.isHolded()* - то же, что и isHold(), но при одном зажатии возвращает true лишь один раз    
**byte (uint8_t):**  
*button1.getTaps()* - возвращает количество накликанных касаний
