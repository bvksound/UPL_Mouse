#include <hidboot.h>
#include <usbhub.h>

#include <SPI.h>
#include <SoftwareSerial.h>
#define RTS_PROBE         7

SoftwareSerial mySerial(12, 11); // RX, TX
/* Uncomment to use Logitech serial mouse protocol. Not exactly recommended as holding
 * down the middle button will cause choppy mouse movement while the Microsoft protocol
 * does not but the option is still here to those who want to use Logitech protocol.
 */
#define USE_MS_PROTOCOL

/* Status variables for keeping track of button/probe states */
bool left_status = false;
bool right_status = false;
bool middle_status = false;
bool rts_status = false;

int x_status = 0;
int y_status = 0;

/* Serial mouse packet encoding routine */
/* Encodes a 3 byte mouse packet that complies with Microsoft Mouse/Logitech protocol */
void encodePacket(int x, int y, bool lb, bool rb, unsigned char* output)
{  
  /* Cap values just in case to avoid overflow errors */
  if ( x > 127 )
  {
    x = 127;
  }
  else if ( x < -127 )
  {
    x = -127;
  }
  
  if ( y > 127 )
  {
    y = 127;
  }
  else if ( y < -127 )
  {
    y = -127;
  }
  
  char cx = x;
  char cy = y;
    
  /* Packet 0 */
  output[0] = ((cx>>6)&0x3) | /* last 2 bits of X */
    (((cy>>6)&0x3)<<2) |      /* Last 2 bits of Y */
    (rb<<4)|(lb<<5)|0x40;     /* Mouse buttons and start packet bit */

  output[1] = cx&0x3f;        /* Packet 1 ( first 6 bits of X ) */
  output[2] = cy&0x3f;        /* Packet 2 ( first 6 bits of Y ) */
}

class MouseRptParser : public MouseReportParser
{
  protected:
    void OnMouseMove(MOUSEINFO *mi);
    void OnLeftButtonUp(MOUSEINFO *mi);
    void OnLeftButtonDown(MOUSEINFO *mi);
    void OnRightButtonUp(MOUSEINFO *mi);
    void OnRightButtonDown(MOUSEINFO *mi);
};
void MouseRptParser::OnMouseMove(MOUSEINFO *mi)
{
  Serial.print("dx=");
  Serial.print(mi->dX, DEC);
  Serial.print(" dy=");
  Serial.println(mi->dY, DEC);

//  x_status = mi->dX, DEC;
//  y_status = mi->dY, DEC;
//
//  short event = false;
//  short event_mb = false;
//
//  short left_changed = false;
//  short right_changed = false;
//  short middle_changed = false;
//  
//  int data[2];
//  unsigned char packet[4];
//  int p_count = 3;
//  /* Divide velocity values to smoothen the movement */
//  int x_status_d = x_status / 2;
//  int y_status_d = y_status / 2;
//  
//  /* Reset X Y counters when divided result is non-zero */
//  if ( x_status_d != 0 )
//  {
//    x_status = 0;
//    event = true;
//  }
//
//  if ( y_status_d != 0 )
//  {
//    y_status = 0;
//    event = true;
//  }
//  
//  /* Send mouse events if there's any */
//  if ( event )
//  {
//    /* Encode the packet */
//    encodePacket( x_status_d, y_status_d, 
//      left_status, right_status, packet );
//    /* Send packet */
//    mySerial.write( packet, p_count );
//  }
};
void MouseRptParser::OnLeftButtonUp	(MOUSEINFO *mi)
{
  Serial.println("L Butt Up");
};
void MouseRptParser::OnLeftButtonDown	(MOUSEINFO *mi)
{
  Serial.println("L Butt Dn");
};
void MouseRptParser::OnRightButtonUp	(MOUSEINFO *mi)
{
  Serial.println("R Butt Up");
};
void MouseRptParser::OnRightButtonDown	(MOUSEINFO *mi)
{
  Serial.println("R Butt Dn");
};


USB     Usb;
USBHub     Hub(&Usb);

HIDBoot < USB_HID_PROTOCOL_KEYBOARD | USB_HID_PROTOCOL_MOUSE > HidComposite(&Usb);
HIDBoot<USB_HID_PROTOCOL_MOUSE>    HidMouse(&Usb);

MouseRptParser MousePrs;

void setup()
{
  /* Set pin for RTS probe as input */
  pinMode( RTS_PROBE, INPUT );
  
  mySerial.begin(1200);
  Serial.begin(115200);
  
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  
  Serial.println("Start");

//  if (Usb.Init() == -1)
//    Serial.println("OSC did not start.");

  HidComposite.SetReportParser(1, &MousePrs);
  HidMouse.SetReportParser(0, &MousePrs);
}

void loop()
{
  Usb.Task();

    /* Send init bytes when RTS has been toggled */
  if ( digitalRead( RTS_PROBE ) )
  {
    if ( !rts_status )
    {    
      delay(14);
      mySerial.write( 'M' );
   
      left_status = false;
      right_status = false;
      middle_status = false;
      
      rts_status = true;
    }
  }
  else
  {
    rts_status = false;
  }
}
