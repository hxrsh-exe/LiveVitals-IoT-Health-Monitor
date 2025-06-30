//modified code.  lM35 with D4                                                                             
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

// I2C LCD module address
const int LCD_ADDRESS = 0x27;

const int LCD_COLS = 16;
const int LCD_ROWS = 2;

// Wi-Fi credentials
const char* WIFI_SSID = "Zfold";
const char* WIFI_PASSWORD = "aoss5145";

// ThingSpeak channel details
const unsigned long THINGSPEAK_CHANNEL_ID = 2222508;
const char* THINGSPEAK_API_KEY = "DHNDM48QDD7CIRDI";

const int PULSE_RATE_SENSOR_PIN = A0;

const int LM35_SENSOR_PIN = 2;

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLS, LCD_ROWS);

// ThingSpeak client
WiFiClient client;


void setup() {
  Serial.begin(115200);

  // Initialize I2C
  Wire.begin();

  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.backlight();



  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  ThingSpeak.begin(client);
}

void loop() {  int pulseRate = analogRead(PULSE_RATE_SENSOR_PIN);
int mybpm = map(pulseRate, 0, 1023, 0, 120);


  // Read temperature from LM35 sensor
  float voltage = analogRead(LM35_SENSOR_PIN) * (5.0 / 1023.0);
  float tmp = (voltage-0.5) * 10.0;
  float temperature = tmp - 8.2;

  //Display pulse rate and temperature on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BPM:");
  //lcd.setCursor(0, 1);
  lcd.print(mybpm);
  lcd.setCursor(0, 1);
  lcd.print("TMP (C):");
  lcd.print(temperature);

  //Display pulse rate and temperature on  monitor
  Serial.print("BPM:");
  Serial.println(mybpm);
  Serial.print("Tmp(C):");
  Serial.println(temperature);

  //ThingSpeak
  ThingSpeak.setField(1, mybpm);
  ThingSpeak.setField(2, temperature);
  int response = ThingSpeak.writeFields(THINGSPEAK_CHANNEL_ID, THINGSPEAK_API_KEY);

  // Check for successful update
  if (response == 200) {
    Serial.println("Channel update successful!!");
  } else {
    Serial.print("Error updating channel: ");
    Serial.println(response);
  }

  delay(10000); // 
}
