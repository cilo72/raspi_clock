Die WLAN-Tests verwenden einen eigenen D-Bus mit einem simulierten NetworkManager.
Sie ändern keine WLAN-Verbindungen des Rechners.

Voraussetzungen: Qt 5 Widgets, D-Bus und Test (Entwicklungspakete), CMake sowie dbus-run-session.

```sh
cmake -S tests -B /tmp/clock-wifi-tests
cmake --build /tmp/clock-wifi-tests
ctest --test-dir /tmp/clock-wifi-tests --output-on-failure
```

Die Tests prüfen Adaptererkennung, SSIDs mit Sonderzeichen, Signalstärke,
Scannen, neue und gespeicherte Verbindungen, Trennen sowie Touch-Eingabe,
Passwortmaskierung und die Mindestgröße der Oberfläche.

Auf echter Hardware zusätzlich prüfen: falsches Passwort, Verbindungsabbruch,
Neustart mit automatischer Wiederverbindung und NetworkManager-Berechtigungen
unter dem Benutzer, der die Wecker-App startet. Unterstützt werden offene Netze,
WPA/WPA2 Personal, WPA3 Personal und OWE. WEP und Unternehmens-WLAN benötigen
andere Eingabefelder und werden als nicht unterstützt angezeigt.
