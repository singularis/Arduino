int i=0;

void setup() {
  Serial.begin(9600);
  Serial.println("I am arduino mega");
  Serial.print("Hi");
}

void loop(){
  delay(1000);
  Serial.print("I am here + ");
  Serial.println(i);
  i++;
}
