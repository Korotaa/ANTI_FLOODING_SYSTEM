#include <Adafruit_SSD1306.h>


//LED GPIO
#define LED_GPIO 2

//POMPE GPIO
#define POMPE_GPIO 27

//CAPTEUR DE NIVEAU GPIO
#define FLOAT_SENSOR_GPIO 26

//ULTRASONIC SENSOR GPIOS
#define TRIG_GPIO 25
#define ECHO_GPIO 33

//ALARM GPIO 
#define ALARM_GPIO 12

//MOTOR GPIO
#define MOTOR_GPIO 14

//SIM800L GPIO
#define SIM800L_RX_GPIO 1 
#define SIM800L_TX_GPIO 2
//#define TINY_GSM_MODEM_SIM800L

// Configuration de l'écran OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C
extern Adafruit_SSD1306 display;

//UART COMMUNICATION SPEED
#define BAUDERATE 115200

//WIFI INFO
extern const char  * SSID;
extern const char * PASSWORD;

//MQTT CONFIG
/*#define RASPBERRYPI_IP
#define BROKERADDRESS RASPBERRYPI_IP
#define PORT 1883
#define USERNAME root
#define PASSWORD root
*/
