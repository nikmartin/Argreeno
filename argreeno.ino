/*
  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____  _____
  |  P  ||  S  ||  S  ||  S  ||  S  ||  S  ||  S  ||  S  ||  S  ||  S  ||  S  ||  S  ||  S  ||  S  ||  S  ||  S  |
  |  1  ||  L  ||  L  ||  L  ||  L  ||  L  ||  L  ||  L  ||  L  ||  L  ||  L  ||  L  ||  L  ||  L  ||  L  ||  L  |
  |  A  ||  O  ||  O  ||  O  ||  O  ||  O  ||  O  ||  O  ||  O  ||  O  ||  O  ||  O  ||  O  ||  O  ||  O  ||  O  |
  |  M  ||  T  ||  T  ||  T  ||  T  ||  T  ||  T  ||  T  ||  T  ||  T  ||  T  ||  T  ||  T  ||  T  ||  T  ||  T  |
  |  -  ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |
  |  1  ||  0  ||  0  ||  0  ||  0  ||  0  ||  0  ||  0  ||  0  ||  0  ||  1  ||  1  ||  1  ||  1  ||  1  ||  1  |
  |  0  ||  1  ||  2  ||  3  ||  4  ||  5  ||  6  ||  7  ||  8  ||  9  ||  0  ||  1  ||  2  ||  3  ||  4  ||  5  |
  |  0  ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     ||     |
  ¯¯¯¯¯  ¯¯¯¯¯  ¯¯¯¯¯  ¯¯¯¯¯  ¯¯¯¯¯  ¯¯¯¯¯  ¯¯¯¯¯  ¯¯¯¯¯  ¯¯¯¯¯  ¯¯¯¯¯  ¯¯¯¯¯  ¯¯¯¯¯  ¯¯¯¯¯  ¯¯¯¯¯  ¯¯¯¯¯  ¯¯¯¯¯
   cpu
*/

#include <P1AM.h>

void setup() {

  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ;
  }
  // connect to any p1 modules
  //while (!P1.init()) {
  //  ;
 // }
  Serial.println("Argreeno Setup");
  //P1.printModules();
  Serial.println(P1.getFwVersion());  //print the Base Controller's firmware version to the console
  //Serial.println();   //print a blank line to look more organized

  pinMode(LED_BUILTIN, OUTPUT); //Set our LED (Pin 32) to be an output
  pinMode(SWITCH_BUILTIN, INPUT); //Set our Switch (Pin 31) to be an input

}

bool switchState = 0; //Variable to hold the current state of the switch

void loop() {
  // put your main code here, to run repeatedly:

  switchState = digitalRead(SWITCH_BUILTIN);//Read the state of the switch
  digitalWrite(LED_BUILTIN, switchState); //Update the LED

}

/*
  void doServer() {
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // output the value of each analog input pin
          for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
            int sensorReading = analogRead(analogChannel);
            client.print("analog input ");
            client.print(analogChannel);
            client.print(" is ");
            client.print(sensorReading);
            client.println("<br />");
          }
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
  }
*/
