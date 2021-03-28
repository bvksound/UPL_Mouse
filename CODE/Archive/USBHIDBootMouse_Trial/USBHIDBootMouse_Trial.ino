#include <hidboot.h>
#include <usbhub.h>
#include <SoftwareSerial.h>



// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
//#include <spi4teensy3.h>
#endif
#include <SPI.h>

SoftwareSerial mySerial(12, 11); // RX, TX

#define RTS_PROBE         7   /* Must connect to Pin 7 (RTS) of PC serial port */
                              /* (NOTE: must go through a 5v regulator and */
                              /* 200ohm resistor first or you'll blow the pin) */

#define USE_MS_PROTOCOL
#define USE_SERIAL1
#define DEBUG

/* Status variables for keeping track of button/probe states */
bool left_status = false;
bool right_status = false;
bool middle_status = false;
bool rts_status = false;

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

    Serial.print("dx=");
    Serial.print(mi->dX, DEC);
    Serial.print(" dy=");
    Serial.println(mi->dY, DEC);

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
    /* Set pin for RTS probe as input */
    pinMode( RTS_PROBE, INPUT );
    
    Serial.begin( 115200 );
    mySerial.begin(1200);
    Serial.println("Start");

    if (Usb.Init() == -1)
        Serial.println("OSC did not start.");

    delay( 200 );

    HidMouse.SetReportParser(0, &Prs);
}

void loop()
{
  //Usb.Task();
  
   /* Send init bytes when RTS has been toggled */
  if ( digitalRead( RTS_PROBE ) )
  {
    if ( !rts_status )
    {
      #ifdef DEBUG
      Serial.print("Send init byte!\n");
      #endif
      
      delay(14);
      #ifdef USE_SERIAL1
      mySerial.write( 'M' );
      #else
      Serial.write( 'M' );
      #endif
      
      delay(63);
      
      #ifndef USE_MS_PROTOCOL
      
      #ifdef USE_SERIAL1
      mySerial.write( '3' );
      #else
      Serial.write( '3' );
      #endif

      /*#else
      
      #ifdef USE_SERIAL1
      Serial1.write( '3' );
      #else
      Serial.write( '3' );
      #endif*/
      
      #endif
      
      left_status = false;
      right_status = false;
      middle_status = false;
      
      rts_status = true;
      digitalWrite( 13, HIGH );
      delay( 500 );
      digitalWrite( 13, LOW );
    }
  }
  else
  {
    rts_status = false;
  }
  
}
