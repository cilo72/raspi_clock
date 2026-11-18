Die WLAN-Tests verwenden einen eigenen D-Bus mit einem simulierten NetworkManager.
Sie ändern keine WLAN-Verbindungen des Rechners.

Voraussetzungen: Qt 5 Widgets, Multimedia, D-Bus und Test (Entwicklungspakete), CMake sowie dbus-run-session.

```sh
cmake -S tests -B /tmp/clock-wifi-tests
cmake --build /tmp/clock-wifi-tests
ctest --test-dir /tmp/clock-wifi-tests --output-on-failure
```

Die Tests prüfen Adaptererkennung, SSIDs mit Sonderzeichen, Signalstärke,
Scannen, neue und gespeicherte Verbindungen, Trennen sowie Touch-Eingabe,
Passwortmaskierung und die Mindestgröße der Oberfläche.

Die Alarmtests verwenden ein temporäres Home-Verzeichnis. Sie prüfen, dass der
Alarm ausschließlich lokale MP3-Dateien aus `~/Music` einschließlich Unterordnern
lädt, Dateinamen mit Sonderzeichen und `.MP3` erkennt, die Wiedergabeliste
wiederholt und beim nächsten Alarm neu einliest. Außerdem prüfen sie das Stoppen,
die MP3-Testwiedergabe in den Einstellungen und leere bzw. fehlende Musikordner.
Der Testknopf startet und stoppt die Musik mit der aktuell eingestellten
Lautstärke; OK und Abbrechen stoppen die Wiedergabe ebenfalls.
Die Testdateien enthalten kein Audio; die tatsächliche MP3-Wiedergabe muss auf
dem Raspberry Pi mit dessen Audioausgabe geprüft werden.

Auf echter Hardware zusätzlich prüfen: falsches Passwort, Verbindungsabbruch,
Neustart mit automatischer Wiederverbindung und NetworkManager-Berechtigungen
unter dem Benutzer, der die Wecker-App startet. Unterstützt werden offene Netze,
WPA/WPA2 Personal, WPA3 Personal und OWE. WEP und Unternehmens-WLAN benötigen
andere Eingabefelder und werden als nicht unterstützt angezeigt.
