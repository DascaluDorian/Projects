#include <BleKeyboard.h>

#define DO_NOTHING                 0

#define BUTTON_PRESS_CONTINOUS     3
#define BUTTON_PRESS_ONCE          1

#define BUTTON_KEY_SEARCH_CAMERA   12
#define BUTTON_KEY_RETURN_HOME     11
#define BUTTON_KEY_LEFT_RECENT     10
#define BUTTON_KEY_RIGHT_BACK      9

BleKeyboard bleKeyboard("Golf 5 Steering Wheel", "Dori", 100);
int value = 0;
int valuePrev = 0;
int indexRepeat = 0;
boolean flag = false;

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();
  attachInterrupt(digitalPinToInterrupt(23), SetReadFlag, RISING);
}

void loop()
{
  if (true == flag)
  {
    ReadValue();

    if (bleKeyboard.isConnected())
    {
      checkSpecialKey_RIGHT_BACK();
      checkSpecialKey_RETURN_HOME();
      checkSpecialKey_LEFT_RECENT();
	    checkSpecialKey_SEARCH_CAMERA();

      if(indexRepeat)
      {
        switch (value)
        {
         case 1 :
            bleKeyboard.write(KEY_MEDIA_NEXT_TRACK); break;
          case 2 :
            bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK); break;
          case 3 :
            bleKeyboard.write(KEY_MEDIA_MUTE); break;
          case 4 :
            bleKeyboard.write(KEY_MEDIA_VOLUME_UP); break;
          case 5 :
            bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN); break;
          case 6 :
            bleKeyboard.write(KEY_UP_ARROW); break;
          case 7 :
            bleKeyboard.write(KEY_DOWN_ARROW); break;
          case 8 :
            bleKeyboard.write(KEY_F1); break;
          default : break;
        }
      }
    }
    flag = false;
  }
}

void checkSpecialKey_RIGHT_BACK()
{
  static int counter1 = 0;

  if (BUTTON_KEY_RIGHT_BACK == value)
  {
    counter1++;
    if (BUTTON_PRESS_CONTINOUS == counter1) {bleKeyboard.write(KEY_ESC);}
  }
  else
  {
    if ((counter1 >= BUTTON_PRESS_ONCE) && (counter1 < BUTTON_PRESS_CONTINOUS))
    { bleKeyboard.write(KEY_RIGHT_ARROW);counter1 = 0;}
    else
    {counter1 = 0;}
  }
}

void checkSpecialKey_RETURN_HOME()
{
  static int counter2 = 0;

  if (BUTTON_KEY_RETURN_HOME == value)
  {
    counter2++;
    if (BUTTON_PRESS_CONTINOUS == counter2) {bleKeyboard.press(KEY_LEFT_ALT);bleKeyboard.press(KEY_ESC);bleKeyboard.releaseAll();}
  }
  else
  {
    if ((counter2 >= BUTTON_PRESS_ONCE) && (counter2 < BUTTON_PRESS_CONTINOUS))
    {bleKeyboard.write(KEY_RETURN);counter2 = 0;}
    else
    {counter2 = 0;}
  }
}

void checkSpecialKey_LEFT_RECENT()
{
  static int counter3 = 0;

  if (BUTTON_KEY_LEFT_RECENT == value)
  {
    counter3++;
    if (BUTTON_PRESS_CONTINOUS == counter3) {bleKeyboard.press(KEY_LEFT_ALT);bleKeyboard.press(KEY_TAB);bleKeyboard.releaseAll();}
  }
  else
  {
    if ((counter3 >= BUTTON_PRESS_ONCE) && (counter3 < BUTTON_PRESS_CONTINOUS))
    {bleKeyboard.write(KEY_LEFT_ARROW);counter3 = 0;}
    else
    {counter3 = 0;}
  }
}

void checkSpecialKey_SEARCH_CAMERA()
{
  static int counter4 = 0;

  if (BUTTON_KEY_SEARCH_CAMERA == value)
  {
    counter4++;
    if (BUTTON_PRESS_CONTINOUS == counter4) {bleKeyboard.press(KEY_F3);}
  }
  else
  {
    if ((counter4 >= BUTTON_PRESS_ONCE) && (counter4 < BUTTON_PRESS_CONTINOUS))
    {bleKeyboard.write(KEY_F2);counter4 = 0;}
    else
    {counter4 = 0;}
  }
}

void ReadValue()
{
  if (Serial.available())
  {
    uint8_t idx = 0;
    char buff[7];
    while (Serial.available() > 0)
    {
      char c = Serial.read();
      if ('0' <= c && c <= '9')
      {
        buff[idx] = c;
        idx++;
      }
    }
    value = atoi(buff);
  }
  else
  {
    value = DO_NOTHING;
  }

  if(valuePrev == value)
  {
    indexRepeat++;
    indexRepeat = indexRepeat % 2;
  }
  else
  {
    indexRepeat = 0;
  }
  valuePrev = value;
}

void SetReadFlag()
{
  flag = true;
}
