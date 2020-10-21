//libs
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

//network settings
IPAddress ip(192,168,1,90);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

//wifi settings
char* ssid     = "MyWLAN";
char* password = "";

//setting default states 
bool buttonLLStatus = false;
bool buttonLStatus = false;
bool buttonRRStatus = false;
bool buttonRStatus = false;
 
//setting webserver port
ESP8266WebServer server(80);

//main index webpage
void buttonIndex() 
{
  
  //webpage
  server.send(200, "text/html", "\
  <html lang="">\
    <head>\
      <title>Switches</title>\
      <style>\
        .inline {\
          display: inline;\
        }\
      </style>\
    </head>\
    <body>\
      <div>\
        <h1>Switches: (JavaScript required!!)</h1>\
        <br>\
        <div>\
          <h2 class=\"inline\">Vyp. : </h2>\
          <form class=\"inline\" method=\"post\" action=\"/buttonvyp/\">\
            <input type=\"submit\" value=\"Click\">\
          </form>\
        </div>\
        <br>\
        <div>\
          <h2 class=\"inline\">LL: </h2>\
          "+getStatus(buttonLLStatus)+"\
          <form class=\"inline\" method=\"post\" action=\"/buttonll/\">\
            <input type=\"submit\" value=\"Click\">\
          </form>\
        </div>\
        <br>\
        <div>\
          <h2 class=\"inline\">L: </h2>\
          "+getStatus(buttonLStatus)+"\
          <form class=\"inline\" method=\"post\" action=\"/buttonl/\">\
            <input type=\"submit\" value=\"Click\">\
          </form>\
        </div>\
        <br>\
        <div>\
          <h2 class=\"inline\">R: </h2>\
          "+getStatus(buttonRStatus)+"\
          <form class=\"inline\" method=\"post\" action=\"/buttonr/\">\
            <input type=\"submit\" value=\"Click\">\
          </form>\
        </div>\
        <br>\
        <div>\
          <h2 class=\"inline\">RR: </h2>\
          "+getStatus(buttonRRStatus)+"\
          <form class=\"inline\" method=\"post\" action=\"/buttonrr/\">\
            <input type=\"submit\" value=\"Click\">\
          </form>\
        </div>\
      </div>\
    </body>\
  </html>");
  
}

String getStatus(bool status)
{
  
  if(status)
  {
    
    return "<h3 class=\"inline\" style=\"color:green\">On </h3>";
    
  }
  else
  {
    
    return "<h3 class=\"inline\" style=\"color:red\">Off </h3>";
    
  }
  
}

void buttonVYP() 
{
  
  //Checks if this was a post request
  if (server.method() != HTTP_POST) 
  {
    
    //if it wasn't a post request webpage
    server.send(405, "text/plain", "Method Not Allowed");
    
  } 
  else 
  {

    //settings var for switch to current state
    buttonLLStatus = false;
    buttonLStatus = false;
    buttonRRStatus = false;
    buttonRStatus = false;

    //changes the state of the pin
    digitalWrite(4, LOW);

    //debug
    Serial.println("Reset pin to LOW");
    
    //delay
    delay(2250);

    //changes the state of the pin
    digitalWrite(4, HIGH);

    //debug
    Serial.println("Reset pin to HIGH");
      
    //webpage
    server.send(200, "text/html", "\
    <html>\
      <head>\
        <script>\
            if(typeof window.history.pushState == 'function'){\
                window.history.pushState({}, \"Hide\", \"/\");\
                location.reload();\
            }\
        </script>\
      </head>\
    </html>");
    
  }
  
}

void buttonLL() 
{
  
  //Checks if this was a post request
  if (server.method() != HTTP_POST) 
  {
    
    //if it wasn't a post request webpage
    server.send(405, "text/plain", "Method Not Allowed");
    
  } 
  else 
  {

    //reads the state and switches it on/off
    if(buttonLLStatus)
	  {

      //settings var for switch to current state
      buttonLLStatus = false;

      //changes the state of the pin
      digitalWrite(4, LOW);
      
      //debug
      Serial.println("reset switched to LOW");

      //delay
      delay(2250);
      
      //changes the state of the pin
      digitalWrite(4, HIGH);
      
      //debug
      Serial.println("reset switched to HIGH");

    }
	  else
	  {
      
      //settings var for switch to current state
      buttonLStatus = false;
      buttonRRStatus = false;
      buttonRStatus = false;
      buttonLLStatus = true;

      //changes the state of the pin
      digitalWrite(2, LOW);
      
      //debug
      Serial.println("buttonLL switched to LOW");

      //delay
      delay(2250);
      
      //changes the state of the pin
      digitalWrite(2, HIGH);
      
      //debug
      Serial.println("buttonLL switched to HIGH");
      
    }

    //webpage
    server.send(200, "text/html", "\
    <html>\
      <head>\
        <script>\
            if(typeof window.history.pushState == 'function'){\
                window.history.pushState({}, \"Hide\", \"/\");\
                location.reload();\
            }\
        </script>\
      </head>\
    </html>");
  }
  
}

void buttonL() 
{
  
  //Checks if this was a post request
  if (server.method() != HTTP_POST) 
  {
    
    //if it wasn't a post request webpage
    server.send(405, "text/plain", "Method Not Allowed");
    
  } 
  else 
  {

    //reads the state and switches it on/off
    if(buttonLStatus)
	  {

      //settings var for switch to current state
      buttonLStatus = false;

      //changes the state of the pin
      digitalWrite(4, LOW);

      //debug
      Serial.println("reset switched to LOW");

      //delay
      delay(2250);
      
      //changes the state of the pin
      digitalWrite(4, HIGH);
      
      //debug
      Serial.println("reset switched to HIGH");
      
    }
	  else
	  {
      
      //settings var for switch to current state
      buttonLLStatus = false;
      buttonRStatus = false;
      buttonRRStatus = false;
      buttonLStatus = true;
      
      //changes the state of the pin
      digitalWrite(0, LOW);
      
      //debug
      Serial.println("buttonL switched to LOW");
      
      //delay
      delay(2250);

      //changes the state of the pin
      digitalWrite(0, HIGH);
      
      //debug
      Serial.println("buttonL switched to HIGH");
      
    }

    //webpage
    server.send(200, "text/html", "\
    <html>\
      <head>\
        <script>\
            if(typeof window.history.pushState == 'function'){\
                window.history.pushState({}, \"Hide\", \"/\");\
                location.reload();\
            }\
        </script>\
      </head>\
    </html>");
  }
  
}

void buttonR() 
{
  
  //Checks if this was a post request
  if (server.method() != HTTP_POST) 
  {
    
    //if it wasn't a post request webpage
    server.send(405, "text/plain", "Method Not Allowed");
    
  } 
  else 
  {

    //reads the state and switches it on/off
    if(buttonRStatus)
	  {

      //settings var for switch to current state
      buttonRStatus = false;

      //changes the state of the pin
      digitalWrite(4, LOW);

      //debug
      Serial.println("reset switched to LOW");

      //delay
      delay(2250);
      
      //changes the state of the pin
      digitalWrite(4, HIGH);
      
      //debug
      Serial.println("reset switched to HIGH");
      
    }
	  else
	  {
      
      //settings var for switch to current state
      buttonLLStatus = false;
      buttonLStatus = false;
      buttonRRStatus = false;
      buttonRStatus = true;
      
      //changes the state of the pin
      digitalWrite(5, LOW);
  
      //debug
      Serial.println("buttonR switched to LOW");
  
      //delay
      delay(2250);
      
      //changes the state of the pin
      digitalWrite(5, HIGH);
  
      //debug
      Serial.println("buttonR switched to HIGH");
      
    }

    //webpage
    server.send(200, "text/html", "\
    <html>\
      <head>\
        <script>\
            if(typeof window.history.pushState == 'function'){\
                window.history.pushState({}, \"Hide\", \"/\");\
                location.reload();\
            }\
        </script>\
      </head>\
    </html>");
  }
  
}

void buttonRR() 
{
  
  //Checks if this was a post request
  if (server.method() != HTTP_POST) 
  {
    
    //if it wasn't a post request webpage
    server.send(405, "text/plain", "Method Not Allowed");
    
  } 
  else 
  {

    //reads the state and switches it on/off
    if(buttonRRStatus)
	  {

      //settings var for switch to current state
      buttonRRStatus = false;

      //changes the state of the pin
      digitalWrite(4, LOW);

      //debug
      Serial.println("reset switched to LOW");

      //delay
      delay(2250);
      
      //changes the state of the pin
      digitalWrite(4, HIGH);
      
      //debug
      Serial.println("reset switched to HIGH");
      
    }
	  else
	  {
      
      //settings var for switch to current state
      buttonLLStatus = false;
      buttonLStatus = false;
      buttonRStatus = false;
      buttonRRStatus = true;

      //changes the state of the pin
      digitalWrite(16, LOW);
      
      //debug
      Serial.println("buttonRR switched to LOW");
      
      //delay
      delay(2250);
      
      //changes the state of the pin
      digitalWrite(16, HIGH);
      
      //debug
      Serial.println("buttonRR switched to HIGH");
      
    }

    //webpage
    server.send(200, "text/html", "\
    <html>\
      <head>\
        <script>\
            if(typeof window.history.pushState == 'function'){\
                window.history.pushState({}, \"Hide\", \"/\");\
                location.reload();\
            }\
        </script>\
      </head>\
    </html>");
  }
  
}

//switch wasn't listed
void buttonNotFound() 
{
  
  //error msg
  String message = "Button not found!\n\n";

  //webpage
  server.send(404, "text/plain", message);
  
}

void setup(void) 
{
  
  //pins output
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(16, OUTPUT);

  //setting pins to default state
  digitalWrite(4, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(0, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(16, HIGH);

  //serial monitor
  Serial.begin(115200);
  
  //connect to wifi
  WiFi.begin(ssid, password);

  //setting static ip
  WiFi.config(ip, gateway, subnet);

  //wait until it's connected to the wifi
  while (WiFi.status() != WL_CONNECTED) 
  {
	  
    delay(500);
	
  }
  
  //prints connection
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  //listen for index
  server.on("/", buttonIndex);

  //listen for buttonVYP
  server.on("/buttonvyp/", buttonVYP);

  //listen for buttonLL
  server.on("/buttonll/", buttonLL);

  //listen for buttonL
  server.on("/buttonl/", buttonL);

  //listen for buttonR
  server.on("/buttonr/", buttonR);

  //listen for buttonRR
  server.on("/buttonrr/", buttonRR);      

  //if event is not found/listed
  server.onNotFound(buttonNotFound);

  //starts the webserver
  server.begin();
  
  //prints status
  Serial.println("Webserver started!");
  
}

void loop(void) 
{
  
  //handles webserver connetions
  server.handleClient();
  
}
