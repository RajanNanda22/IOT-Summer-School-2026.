# Q37. Wi-Fi Security for IoT

## Objective

Research common Wi-Fi security threats affecting IoT devices, identify best practices for securing ESP32 Wi-Fi connections, and explain why hardcoding Wi-Fi credentials in source code is a security risk.

---

# Wi-Fi Security for IoT

Wi-Fi connectivity is essential for modern IoT devices, but it also introduces security risks if not properly protected. One common attack vector is the exploitation of weaknesses in wireless authentication. Although **WPA2** is much more secure than older protocols, poorly chosen passwords can still be vulnerable to offline dictionary or brute-force attacks after an attacker captures the authentication handshake. Another significant threat is the **Evil Twin Attack**, where an attacker creates a fake wireless access point that imitates a legitimate network. If an IoT device connects to the fake access point, sensitive information can be intercepted or manipulated.

To improve security, ESP32 devices should use the latest Wi-Fi security features whenever possible. **WPA3** provides stronger authentication through Simultaneous Authentication of Equals (SAE), making password guessing attacks much more difficult than in WPA2. Developers should also enable **Protected Management Frames (PMF)** to reduce the risk of deauthentication attacks. When communicating with cloud services over HTTPS, **certificate pinning** should be used to verify the server's identity and prevent man-in-the-middle attacks. Additional best practices include using strong unique passwords, keeping firmware updated, securely storing credentials in encrypted flash or secure storage, and disabling unnecessary network services.

Hardcoding Wi-Fi usernames and passwords directly into source code is dangerous because anyone who gains access to the code repository or extracts the firmware can recover those credentials. If the same password is reused across multiple devices, a single compromise may expose the entire IoT deployment. Instead, credentials should be stored securely using encrypted storage, secure provisioning methods, or configuration files that are excluded from version control (for example, using a `secrets.h` file listed in `.gitignore`).

---

# Best Practices Summary

* Use **WPA3** instead of WPA2 whenever supported.
* Enable **Protected Management Frames (PMF)**.
* Use **certificate pinning** for HTTPS communication.
* Store credentials securely instead of hardcoding them.
* Keep ESP32 firmware and libraries updated.
* Use strong, unique Wi-Fi passwords.
* Disable unnecessary network services and ports.

---

# References

1. Espressif Systems. **ESP-IDF Programming Guide – Wi-Fi Security**
   https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/wifi-security.html

2. Espressif Systems. **ESP-IDF Programming Guide – WPA3 and Protected Management Frames**
   https://docs.espressif.com/projects/esp-idf/en/v5.1.2/esp32/api-guides/wifi-security.html

---

## Author

**Name:** Rajan Nanda

**Course:** IoT Summer School 2026

**Question:** Q37 – Wi-Fi Security for IoT
