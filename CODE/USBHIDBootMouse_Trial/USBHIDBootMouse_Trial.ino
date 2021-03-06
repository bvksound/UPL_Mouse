#include <hidboot.h>
#include <usbhub.h>
#include <SoftwareSerial.h>



// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
//#include <spi4teensy3.h>
#endif
#include <SPI.h>

int xMovement = 0;
int yMovement = 0;
long xMovementConstrain = 0;
long yMovementConstrain = 0;
bool leftButton = false;
bool rightButton = false;
static const int RS232_RTS = 3;
static const int RS232_TX  = 4;
SoftwareSerial mySerial(11, 12); // RX, TX

//static void sendSerialBit(int data) {
//  // Delay between the signals to match 1200 baud
//  static const auto usDelay = 1000000 / 1200;
//  digitalWrite(RS232_TX, data);
//  delayMicroseconds(usDelay);
//}

//static void sendSerialByte(byte data) {
//
//  // Start bit
//  sendSerialBit(0);
//
//  // Data bits
//  for (int i = 0; i < 7; i++) {
//    sendSerialBit((data >> i) & 0x01);
//  }
//
//  // Stop bit
//  sendSerialBit(1);
//
//  // 7+1 bits is normal mouse protocol, but some serial controllers
//  // expect 8+1 bits format. We send additional stop bit to stay
//  // compatible to that kind of controllers.
//  sendSerialBit(1);
//}

static void sendToSerial(int xMovement,int yMovement,bool leftButton,bool rightButton) {
  auto dx = constrain(xMovement, -127, 127);
  auto dy = constrain(-yMovement, -127, 127);
  byte lb = leftButton ? 0x20 : 0;
  byte rb = rightButton ? 0x10 : 0;
//  sendSerialByte(0x40 | lb | rb | ((dy >> 4) & 0xC) | ((dx >> 6) & 0x3));
//  sendSerialByte(dx & 0x3F);
//  sendSerialByte(dy & 0x3F);
  mySerial.write(0x40 | lb | rb | ((dy >> 4) & 0xC) | ((dx >> 6) & 0x3));
  mySerial.write(dx & 0x3F);
  mySerial.write(dy & 0x3F & 0x80);
//  if (threeButtons) {
//    byte mb = data.middleButton ? 0x20 : 0;
//    sendSerialByte(mb);
//  }
}

static void initSerialPort() {
  //Serial.println("Starting serial port");
  //mySerial.write('M');
  //delayMicroseconds(10000);

//  Serial.println("Listening on RTS");
//  void (*resetHack)() = 0;
//  attachInterrupt(digitalPinToInterrupt(RS232_RTS), resetHack, FALLING);
}
  
class MouseRptParser : public MouseReportParser
{
protected:
	void OnMouseMove	(MOUSEINFO *mi);
	void OnLeftButtonUp	(MOUSEINFO *mi);
	void OnLeftButtonDown	(MOUSEINFO *mi);
	void OnRightButtonUp	(MOUSEINFO *mi);
	void OnRightButtonDown	(MOUSEINFO *mi);
	void OnMiddleButtonUp	(MOUSEINFO *mi);
	void OnMiddleButtonDown	(MOUSEINFO *mi);
};
void MouseRptParser::OnMouseMove(MOUSEINFO *mi)
{
    
    xMovementConstrain = (mi->dX, DEC);
    yMovementConstrain = (mi->dY, DEC);
    Serial.print("dx=");
    Serial.print(xMovementConstrain);
    Serial.print(" dy=");
    Serial.println(yMovementConstrain);

    //sendToSerial(0,0,0,0);
};
void MouseRptParser::OnLeftButtonUp	(MOUSEINFO *mi)
{
    Serial.println("L Butt Up");
    sendToSerial(0,0,1,0);
};
void MouseRptParser::OnLeftButtonDown	(MOUSEINFO *mi)
{
    Serial.println("L Butt Dn");
};
void MouseRptParser::OnRightButtonUp	(MOUSEINFO *mi)
{
    Serial.println("R Butt Up");
    sendToSerial(0,0,0,1);
};
void MouseRptParser::OnRightButtonDown	(MOUSEINFO *mi)
{
    Serial.println("R Butt Dn");
};
void MouseRptParser::OnMiddleButtonUp	(MOUSEINFO *mi)
{
    Serial.println("M Butt Up");
};
void MouseRptParser::OnMiddleButtonDown	(MOUSEINFO *mi)
{
    Serial.println("M Butt Dn");
};

USB     Usb;
USBHub     Hub(&Usb);
HIDBoot<USB_HID_PROTOCOL_MOUSE>    HidMouse(&Usb);

MouseRptParser                               Prs;

void setup()
{
    //pinMode(RS232_TX, OUTPUT);
    Serial.begin( 115200 );
    mySerial.begin(1200);
    //initSerialPort();

    Serial.println("Start");

    if (Usb.Init() == -1)
        Serial.println("OSC did not start.");

    delay( 200 );

    HidMouse.SetReportParser(0, &Prs);
}

void loop()
{
  Usb.Task();
}
