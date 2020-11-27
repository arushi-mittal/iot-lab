#include<ESP8266WiFi.h>
char ssid[20] = "phone", password[20] = "hotspot888";
String str, str1, str2;
WiFiServer my_server(80);
int state = 0, state1 = 0, state2 = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  digitalWrite(D0, HIGH);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { 
    delay(100);
  }
  if (WiFi.status() == WL_CONNECTED) {
    
    Serial.println("The Board is now connected to WiFi.");
  }
  my_server.begin();
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = my_server.available();
  if (client) {
    Serial.println("The client has connected");
  }
  else {
    return;
  }
  while (!client.available()) {
    delay(100);
  }
  if (client.available()) {
    str = client.readStringUntil('\r');
    Serial.println(str);
    client.flush();
  }
  if (str.indexOf("/LED=ON") != -1) {
    state = 1;
    digitalWrite(D0, LOW);
  }
  else if(str.indexOf("/LED=OFF") != -1) {
    state = 0;
    digitalWrite(D0, HIGH);
 }
  if (str.indexOf("/LED1=ON") != -1) {
    state1 = 1;
    digitalWrite(D1, LOW);
  }
  else if(str.indexOf("/LED1=OFF") != -1) {
    state1 = 0;
    digitalWrite(D1, HIGH);
  }
  if (str.indexOf("/LED2=ON") != -1) {
    state2 = 1;
    digitalWrite(D2, LOW);
  }
  else if(str.indexOf("/LED2=OFF") != -1) {
    state2 = 0;
    digitalWrite(D2, HIGH);
  }  
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  
  client.print("Led pin is now: ");
  if (state == 1) {
    client.print("On");
  }
  else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn On</button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn Off</button></a><br/><br><br>");
  
  client.println("LED 1 pin is now: ");
  if (state1 == 1) {
    client.print("On");
  }
  else {
    client.print("Off");
  }
  client.println("<br><br><a href=\"/LED1=ON\"\"><button>Turn On 1</button></a>");
  client.println("<a href=\"/LED1=OFF\"\"><button>Turn Off 1</button></a><br/>");
  
  client.println("LED 2 pin is now: ");
  if (state2 == 1) {
    client.print("On");
  }
  else {
    client.print("Off");
  }
  client.println("<br><br><a href=\"/LED2=ON\"\"><button>Turn On 2</button></a>");
  client.println("<a href=\"/LED2=OFF\"\"><button>Turn Off 2</button></a><br/>");
  
  client.println("</html>");
  if (!client) {
    Serial.println("Client has disconnected");
  }
}
