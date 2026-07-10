IIT Jammu Summer 
School 2026 
IOT Assignment - 3 
Name -  Rajan Nanda  
Course - IOT and Drones  
Submission Date - 8-7-2026 
Submitted to - Mr. Majid  
Roll no. - IOT35 
GITHUB Repository link - 
https://github.com/RajanNanda22/IOT-Su
mmer-School-2026..git 
Q35. REST API – Weather Data Fetcher 
Program ESP32 to fetch real weather data from OpenWeatherMap API (free tier). Display on 
Serial Monitor: City Name, Temperature (API value vs DHT11 local value), Humidity, Weather 
Description. Compare API data with your local DHT11 reading and print the difference. Store 
your API key in a separate config.h file (do NOT commit this file – add to .gitignore). 
GITHUB Link - 
https://github.com/RajanNanda22/IOT-Summer-School-20
26./tree/main/Assignments/IOTassignment3/Question-35 
 
 
 
Ans 36:  
MQTT vs HTTP Comparison 
Feature MQTT HTTP 
Architecture 
Pattern 
Publish/Subscribe through an 
MQTT broker 
Client/Server 
(Request–Response) 
Data Transfer 
Model 
Asynchronous; devices publish to 
topics and subscribers receive 
updates 
Synchronous; client sends 
a request and waits for the 
server's response 
Power 
Consumption 
Very low due to lightweight packets 
and persistent connections 
Higher because each 
request requires additional 
protocol overhead 
Latency Low latency; suitable for real-time 
communication 
Higher latency due to 
repeated request-response 
cycles 
Use Case 
Suitability for 
IoT 
Security 
Considerations 
Excellent for IoT applications such 
as smart homes, industrial 
monitoring, agriculture, and sensor 
networks 
Supports username/password 
authentication, TLS/SSL encryption, 
and access control through brokers 
Better suited for web 
services, REST APIs, 
dashboards, and 
occasional data retrieval 
Supports HTTPS 
(TLS/SSL), authentication 
tokens, API keys, OAuth, 
and other web security 
mechanisms 
For a 1000-node smart agriculture deployment, MQTT is the preferred 
communication protocol. 
Reasons: 
1. Low Bandwidth Usage: MQTT uses a lightweight messaging format, 
reducing network traffic even with thousands of sensor nodes. 
2. Low Power Consumption: Agricultural sensors are often battery- or 
solar-powered. MQTT minimizes communication overhead, helping 
devices operate longer between charges. 
3. Low Latency: Sensor readings such as soil moisture, temperature, and 
humidity can be delivered quickly to the central monitoring system. 
4. Scalability: A single MQTT broker can efficiently manage 
communication with thousands of connected devices using topics. 
5. Reliable Communication: MQTT supports different Quality of Service 
(QoS) levels (0, 1, and 2), allowing developers to choose the appropriate 
balance between reliability and network overhead. 
6. Efficient Data Distribution: Multiple applications (e.g., irrigation 
control, weather dashboard, and mobile app) can subscribe to the same 
sensor topics without increasing the workload on sensor nodes. 
7.      Reduced Network Traffic: Devices only publish data when necessary, 
and subscribers receive updates automatically, eliminating the need for 
continuous polling as required by HTTP. 
Ans 37:  
Wi-Fi Security for IoT 
Wi-Fi-enabled IoT devices such as the ESP32 are vulnerable to several wireless 
attacks if not properly secured. One common attack vector is exploiting 
weaknesses in WPA2, particularly through weak passwords or misconfigured 
networks. Attackers may also use an evil twin attack, where they create a fake 
Wi-Fi access point with the same network name (SSID) as a trusted network. If an 
IoT device connects to the fake access point, attackers can intercept data or steal 
login credentials. 
To improve the security of ESP32-based IoT systems, developers should follow 
several best practices. Using WPA3 instead of WPA2 provides stronger encryption 
and protection against password guessing attacks. When communicating with 
cloud services, HTTPS with certificate validation or certificate pinning should 
be used to verify the server's identity and prevent man-in-the-middle attacks. 
Regular firmware updates, strong unique passwords, and disabling unused network 
services further enhance device security. 
Hardcoding Wi-Fi passwords or API keys directly into the source code is 
dangerous because anyone with access to the code or firmware can retrieve these 
credentials. If the code is uploaded to a public GitHub repository, attackers can 
easily obtain sensitive information and gain unauthorized access to the network. A 
safer approach is to store credentials in a separate configuration file (such as 
config.h) that is excluded from version control using .gitignore, or use secure 
storage mechanisms provided by the device. 
References: 
1. Wi-Fi 
Alliance. 
WPA3™ 
https://www.wi-fi.org/discover-wi-fi/security 
Security. 
2. Open Worldwide Application Security Project (OWASP). OWASP 
Internet 
of 
Things 
https://owasp.org/www-project-internet-of-things/ 
Ans 38: 
LoRa & LPWAN – Long Range IoT 
Project. 
LPWAN (Low Power Wide Area Network) is a wireless communication 
technology designed for IoT devices that need to send small amounts of data over 
long distances while consuming very little power. It is commonly used in 
agriculture, smart cities, and environmental monitoring. 
LoRa (Long Range) achieves long-range communication by using a Chirp 
Spread Spectrum (CSS) modulation technique. It also uses a Spreading Factor 
(SF), where a higher SF increases communication range and reliability but lowers 
data rate. This allows battery-powered devices to transmit data over several 
kilometers while using minimal energy. 
Feature 
LoRa 
Zigbee 
Z-Wave 
Range 
2–15 km 
10–100 m 
30–100 m 
Power 
Consumption 
Data Rate 
Best Use 
Very Low 
Low 
Smart agriculture, smart 
cities 
Low 
High 
Home 
automation 
Low 
Medium 
Home 
automation 
A real-world example in India is the Smart City Mission, where LoRa-based 
sensor networks are deployed in cities such as Pune and New Delhi for 
applications like smart street lighting, water metering, waste management, and 
environmental monitoring. LoRa's long range, low power consumption, and ability 
to connect thousands of devices make it an ideal choice for large-scale IoT 
deployments. 
Ans 39: 
IoT Gateway 
An IoT gateway is a device that connects IoT sensor nodes to the internet or cloud. 
It collects data from sensors, converts different communication protocols if needed, 
performs basic processing, and securely forwards the data to cloud services. The 
gateway also sends commands from the cloud back to the IoT devices. 
Protocols Used 
Layer 
Common Protocols 
IoT Sensor → Gateway 
Gateway → Cloud 
Cloud → User Application 
Ans 40: 
LoRa, Zigbee, BLE, Wi-Fi 
MQTT, HTTP/HTTPS, CoAP 
HTTPS, MQTT, WebSockets 
MQTT QoS (Quality of Service) Levels 
QoS Level Description 
QoS 0 – At 
most once 
Message is sent only once without confirmation. It 
may be lost if the network fails. 
Reliability 
Lowest 
QoS 1 – At 
least once 
QoS 2 – 
Exactly once 
Message is delivered at least once. The receiver 
acknowledges it, but duplicate messages may 
occur. 
Message is delivered exactly once using a 
four-step handshake. No duplicates occur. 
Medium 
Highest 
Which QoS would I choose for an IoT Water Level Monitoring System? 
I would choose QoS 1 (At least once) because it provides reliable message 
delivery while keeping communication overhead low. In a water level monitoring 
system, receiving duplicate readings occasionally is acceptable, but losing critical 
water level data could lead to incorrect monitoring or delayed alerts. QoS 2 offers 
the highest reliability but requires more bandwidth and processing, making it less 
efficient for most IoT applications. Therefore, QoS 1 provides the best balance 
between reliability and performance. 
Q41. Smart Home Air Quality Monitor 
Problem Statement 
A family in a Milan(Europe) home is concerned about indoor air quality during winter when 
they burn wood for heating. Design an IoT-based Air Quality Monitoring System that 
continuously measures CO/smoke levels (MQ-2 sensor), temperature and humidity 
(DHT11), and alerts residents when air quality drops below safe thresholds. The system 
must work without the internet when the router is down. 
GITHUB link - 
https://github.com/RajanNanda22/IOT-Summer-School-2026./tree/main/Assignme
nts/IOTassignment3/Question41 
 
 
Q42. Automated Plant Watering System 
Problem Statement 
A J&K horticulture farmer wants to automate irrigation for a small saffron farm plot. The 
system should read soil moisture every 30 minutes and activate a water pump only when the 
soil is dry. Saffron is sensitive to overwatering — the system must also prevent watering if it 
rained recently (use LDR to detect low light/overcast sky as a rain proxy and also leverage 
the use of api also). The farmer must be able to manually override via a button. 
GITHUB link - 
https://github.com/RajanNanda22/IOT-Summer-School-2026./tree/main/Assignme
nts/IOTassignment3/Question42 
  
Q43. Smart Door Lock with OTP 
Problem Statement 
A university hostel wants to replace physical keys with a PIN-based entry system that also 
generates a One-Time Password. Design a system where a student enters their 4-digit ID on 
a keypad, the system generates a 6-digit OTP, sends it over Bluetooth to their phone, and 
only grants access if they enter the OTP within 30 seconds. 
GITHUB Link - 
https://github.com/RajanNanda22/IOT-Summer-School-2026./tree/main/Assignme
nts/IOTassignment3/Question43 
Q44. PIR-Based Security Camera Trigger 
Problem Statement 
A small shop in Haryana, Rohtak wants a low-cost security alert system. When motion is 
detected after shop hours (manually configured time window), the system should sound an 
alarm, flash lights, and optionally send a notification. Build the motion-detection and alerting 
module. 
GITHUB Link - 
https://github.com/RajanNanda22/IOT-Summer-School-2026./tree/main/Assignme
nts/IOTassignment3/Question44 
Q45. Smart Greenhouse Controller 
Problem Statement 
Floriculture farmers in Kashmir growing tulips and roses need automated greenhouse 
climate control. Design a multi-parameter monitoring and control system that maintains 
optimal growing conditions: Temperature 18–22°C, Humidity 60–70%, and sufficient light for 
12 hours per day. 
GITHUB Link - 
https://github.com/RajanNanda22/IOT-Summer-School-2026./tree/main/Assignme
nts/IOTassignment3/Question45 
Q46. River Water Level Alert (Flood Detection) 
Problem Statement 
Given the frequent flooding near the Tawi and Chenab rivers, design a low-cost IoT 
flood-early-warning sensor node using an HC-SR04 ultrasonic sensor to monitor water level 
in a model river (a glass tank). Trigger alerts at predefined levels and transmit data 
wirelessly. 
GITHUB Link - 
https://github.com/RajanNanda22/IOT-Summer-School-2026./tree/main/Assignme
nts/IOTassignment3/Question46 
Q47. Heart Rate & SpO2 Monitor (Simulation) 
Problem Statement 
Using a MAX30102 pulse oximeter module (or simulate with an LDR as a proxy sensor), 
build a health monitoring prototype that measures pulse rate and blood oxygen saturation, 
displays values, and alerts on abnormal readings. This is a simulation for learning sensor 
interfacing, not a medical device. 
GITHUB Link - 
https://github.com/RajanNanda22/IOT-Summer-School-2026./tree/main/Assignme
nts/IOTassignment3/Question47 
Q48. Design Challenge: IoT for Jammu Smart City 
J&K Government is planning a Smart City project for Jammu. As an IoT engineer, propose a 
system to monitor and manage 3 of the following (choose any 3): Street lighting, Traffic flow, 
Parking availability, Air quality, Water supply pressure, Waste bin fill levels. For each: 
• Identify the sensor(s) needed 
• Identify the microcontroller / connectivity module 
• Describe the data flow: Sensor → Protocol → Cloud → Dashboard 
• Estimate approximate cost per node (in INR) 
Present your answer as a structured proposal (500–700 words) uploaded as 
/final_project/smart_city_proposal.md in GitHub. 
1. Write the code for each problem separately. 
GITHUB Link - 
https://github.com/RajanNanda22/IOT-Summer-School-2026./tree/main/Assignme
nts/IOTassignment3/Question48 
Q49. Security Vulnerability Analysis 
You are given a poorly written IoT code snippet that connects an ESP8266 to a public Wi-Fi 
network. The code hardcodes the SSID and password, uses unencrypted HTTP (not HTTPS), 
publishes sensor data to a public MQTT broker without authentication, and never validates 
incoming commands. Identify at least 5 security vulnerabilities, explain the risk of each, and 
provide corrected code for at least 2 vulnerabilities. 
GITHUB Link - 
https://github.com/RajanNanda22/IOT-Summer-School-2026./tree/main/Assignme
nts/IOTassignment3/Question49 
Q50. Reflection & Learning Portfolio 
Describe what you built and what you learned. How will you apply IoT skills in your field of study 
or future career? What would you build next — describe your own IoT project idea with sensors, 
connectivity, and application. (Minimum 400 words, personal and reflective) 
GITHUB Link - 
https://github.com/RajanNanda22/IOT-Summer-School-2026./tree/main/Assignme
nts/IOTassignment3/Question50 
