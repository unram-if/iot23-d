#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// as broker

struct User
{
  String nim;
  String nama;
};

User users[3] = {
    {"F1D021143", "Zahrahtun Munirah"},
    {"F1D021066", "Salsabilla Mantika"},
    {"F1D021111", "Mochammad Dinta Alif Syaifuddin"}};

// initialize

const char *ssid = "@unram.ac.id";
const char *password = "";
const char *mqtt_topic = "unram/if/iot/2023/tugas/";
const char *mqtt_server = "10.200.13.33";
String mqtt_user = "f1d021111";
String mqtt_pass = "8844";
int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (50)

String msg;
int value = 0;

void setup_wifi()
{

  delay(10);
  //  connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect()
{
  // Loop until we're reconnected
  int counter = 0;
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-" + mqtt_user;
    // Attempt to connect
    if (client.connect(clientId.c_str(), mqtt_user.c_str(), mqtt_pass.c_str()))
    {
      Serial.println("connected");
      // client.publish(mqtt_topic, String("Connected from clientId : " + clientId));
      // client.subscribe(mqtt_topic));
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup()
{
  pinMode(BUILTIN_LED, OUTPUT);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop()
{
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();

  if (value > 2)
  {
    value = 0;
  }

  if (now - lastMsg > 2000)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    lastMsg = now;

    msg = (users[value].nim + '-' + users[value].nama);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish(mqtt_topic, msg.c_str());

    value++;
    delay(2000);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
