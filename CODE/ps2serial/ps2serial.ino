//Use ATTiny with clock Configuration.
//Burn the bootloader so the configuration is stored within the controller
//Burn using programmer AVR ICE

#include <PS2Mouse.h>
#include <SoftwareSerial.h>


SoftwareSerial mySerial(0, 1); // RX, TX
SoftwareSerial debugSerial(3, 4); // RX, TX

#define PS2_MOUSE_CLOCK   8   /* Must connect to Pin 5 (clock) of PS/2 mouse */
#define PS2_MOUSE_DATA    7   /* Must connect to Pin 1 (data) of PS/2 mouse */
#define RTS_PROBE         2    
#define USE_MS_PROTOCOL

/* Uncomment to enable debug messages over USB serial (serial monitor must be active).
 * Debug messages are sent using the Serial class. Don't uncomment for Arduinos with a
 * single hardware UART.
 */
#define DEBUG

/* Status variables for keeping track of button/probe states */
bool left_status = false;
bool right_status = false;
bool rts_status = false;

int x_status = 0;
int y_status = 0;

/* Class from PS2Mouse for reading PS/2 mouse data */
PS2Mouse mouse( PS2_MOUSE_CLOCK, PS2_MOUSE_DATA, STREAM );

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


void setup()
{
  
  /* Set pin for RTS probe as input */
  pinMode( RTS_PROBE, INPUT );
  
  #ifdef DEBUG
  /* Init serial for debug messages */
  debugSerial.begin(115200);
  while( !debugSerial )
  {
    /* Wait for USB serial to be ready (monitor active) */
  }
  debugSerial.print( "DebugPort Start\n" );
  debugSerial.print( "Start Delay\n" );
  #endif

  delay(2000); // Needed for Stabilisation of power supplies before resetting.
  
  /* Initialize PS/2 mouse */
  mouse.initialize();
  #ifdef DEBUG 
    debugSerial.print( "Initialize mouse\n" ); 
  #endif
  mouse.set_sample_rate( 200 );
  #ifdef DEBUG 
    debugSerial.print( "Set Sample rate mouse\n" ); 
  #endif
  mouse.set_scaling_1_1();
  #ifdef DEBUG
    debugSerial.print( "Set Scaling mouse\n" ); 
  #endif

  
  /* Initialize serial for mouse data */
  mySerial.begin(1200);

  #ifdef DEBUG
  debugSerial.print("Program start!\n");
  #endif
}


void loop()
{
  short event = false;
  short event_mb = false;

  short left_changed = false;
  short right_changed = false;
  
  int data[2];
  unsigned char packet[4];
  int p_count = 3;
  
  /* Read mouse data 4 times as PS/2 is too fast for serial */
  for(int i=0; i<4; i++)
  {
    mouse.report( data );
    x_status += data[1];
    y_status += -data[2];

    /* Check mouse events */
    
    if ( !left_changed )
    {
      if ( data[0] & 0x1 ) /* Left mouse button */
      {
        if ( !left_status )
        {
          event = true;
          left_status = true;
          left_changed = true;
        }
      }
      else
      {
        if ( left_status )
        { 
          event = true;
          left_status = false;
          left_changed = true;
        }
      }
    }

    if ( !right_changed )
    {
      if ( data[0] & 0x2 )  /* Right mouse button */
      {
        if ( !right_status )
        {
          event = true;
          right_status = true;
          right_changed = true;
        }
      }
      else
      {
        if ( right_status )
        { 
          event = true;
          right_status = false;
          right_changed = true;
        }
      }
    }
  }

  /* Divide velocity values to smoothen the movement */
  int x_status_d = x_status / 2;
  int y_status_d = y_status / 2;
  
  /* Reset X Y counters when divided result is non-zero */
  if ( x_status_d != 0 )
  {
    x_status = 0;
    event = true;
  }

  if ( y_status_d != 0 )
  {
    y_status = 0;
    event = true;
  }
  
  /* Send mouse events if there's any */
  if ( event )
  {
    #ifdef DEBUG
    debugSerial.print( "LB:" );
    debugSerial.print( left_status );
    debugSerial.print( " RB:" );
    debugSerial.print( right_status );
    debugSerial.print( " X:" );
    debugSerial.print( x_status);
    debugSerial.print(", " );
    debugSerial.print( x_status_d);
    debugSerial.print( " Y:" );
    debugSerial.print( y_status );
    debugSerial.print(", " );
    debugSerial.print( y_status_d);
    debugSerial.println();
    #endif

    /* Encode the packet */
    encodePacket( x_status_d, y_status_d, 
      left_status, right_status, packet );

    /* Send packet */
    mySerial.write( packet, p_count );
  }

 
  /* Send init bytes when RTS has been toggled */
  if ( digitalRead( RTS_PROBE ) )
  {
    if ( !rts_status )
    {
      #ifdef DEBUG
      debugSerial.print("Send init byte!\n");
      #endif
      
      delay(14);
      mySerial.write( 'M' );
      
      left_status = false;
      right_status = false;
      
      rts_status = true;
    }
  }
  else
  {
    rts_status = false;
  }
  
}
