//parvin RDAR finalized coding  
 #include <Servo.h> 
 #include <LiquidCrystal_I2C.h>  
 LiquidCrystal_I2C lcd(0x27, 16, 2);     
 #include <DHT.h>  
 DHT dht(3, DHT11); // DHT11 Sensor pin D3
 Servo myservo; 
   
 void setup()   
 {  
  Serial.begin(9600);  
  lcd.init();  
  lcd.backlight();  
  dht.begin();    
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
 }  
 void loop()  
 {  
  float h = dht.readHumidity();  
  float t = dht.readTemperature();  
  int r = analogRead(A0);    // Rain Drop Sensor Pin A0  
  delay(1000);  
  r = map(r, 0, 1023, 100, 0);
  if (r>10)     // set rain sensor range to trigger motor
  {
    myservo.write(180);              
    delay(15);
    }
    else
    {
    myservo.write(0);             
    delay(15);
   }  
   if (h>75 && t<26)     // set temp and humd range to trigger motor
   {
     myservo.write(180);              
     delay(15);
     }
     else
     {
     myservo.write(0);             
     delay(15);
    }  
 
  lcd.setCursor(0, 0);  
  lcd.print("T :");  
  lcd.print(t);  
  Serial.print("Temperature : ");  
   Serial.println(t);  
  lcd.setCursor(0, 1);  
  lcd.print("H :");  
  lcd.print(h);  
  Serial.print("Humidity : ");  
   Serial.println(h);  
  lcd.setCursor(9, 0);  
  lcd.print("R :");  
  lcd.print(r);  
  lcd.print(" ");  
  Serial.print("Rain Sensor : ");  
   Serial.println(r);  
   Serial.println("   " );  
 }  
