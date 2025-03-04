

#include <WiFi.h>
#include <HTTPClient.h>  


const char* ssid = "Gustomo";     
const char* password = "1234567890";
const char* serverUrl = "http:// 192.168.56.1/GabiaM/api.php";

change the ssid with your broadcast id and defined password, identify your pc ip address to avoid errors
make sure the you define the correct path and file name of your api

float tempValue = 31.5;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

Inside the loop
Check if the wifi is still connected

if (WiFi.status() == WL_CONNECTED) { 
    HTTPClient http;

    http.begin(serverUrl);  
    http.addHeader("Content-Type", "application/json");

    // JSON payload
        String payload = "{\"name\":\"temp\", \"value\":\"" + String(tempValue) + "\"}";

    int httpResponseCode = http.POST(payload);

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      Serial.println(http.getString());
    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }

  delay(5000); // Wait 5 seconds before sending again


