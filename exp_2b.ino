float ip;
float op;

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
  
}

void loop()
{
  ip = analogRead(A0);
  op = ip/4;
  analogWrite(3,op);
  
}