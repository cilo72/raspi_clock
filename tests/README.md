Die WLAN-Tests verwenden einen eigenen D-Bus mit einem simulierten NetworkManager.
Sie ändern keine WLAN-Verbindungen des Rechners.

Die aktuelle Alarmsteuerung und die Wiederholung der Wiedergabeliste lassen
sich unabhängig von den älteren Alarmtests prüfen:

```sh
cmake -S tests/alarm_playback -B /tmp/clock-alarm-playback-tests
cmake --build /tmp/clock-alarm-playback-tests
ctest --test-dir /tmp/clock-alarm-playback-tests --output-on-failure
```

Die Tests verwenden temporäre Einstellungen und spielen kein Audio ab. Sie
prüfen den automatischen Stopp, das Ende des Blinkens, den einmaligen
Abschalttimer, erneutes Auslösen sowie manuelles Ausschalten. Nach dem
automatischen Stopp bleibt der Wecker scharf; manuelles Ausschalten deaktiviert
ihn. Die Wiedergabeliste springt nach dem letzten Titel zum ersten zurück.

Die Systemzeittests verwenden einen eigenen D-Bus mit einem simulierten
systemd-timedated. Sie ändern weder Systemzeit noch echte NTP-Einstellungen:

```sh
cmake -S tests/system_clock -B /tmp/clock-system-time-tests
cmake --build /tmp/clock-system-time-tests
ctest --test-dir /tmp/clock-system-time-tests --output-on-failure
```

Benötigt werden Qt 5 Core, D-Bus und Test sowie `dbus-run-session`.
Geprüft werden lokales Datum und Uhrzeit, die Sekunden- und UTC-Umrechnung,
das vorherige Abschalten von NTP sowie Berechtigungsfehler und die
Wiederherstellung einer zuvor aktiven Synchronisierung bei Fehlern.
Der PC-Pfad wird zusätzlich geprüft: Er meldet eine Simulation, ohne einen
Aufruf an den Zeitdienst zu senden. Die Raspberry-Pi-Erkennung wird für die
Tests des echten Ablaufs gezielt simuliert; der D-Bus bleibt dabei ein Mock.
Die Berechtigungen auf dem Raspberry Pi sind in `deployment/README.md` erklärt.

Die Wischbedienung in `DialogSetTimeOrAlarm` lässt sich unabhängig testen:

```sh
cmake -S tests/time_input -B /tmp/clock-time-tests
cmake --build /tmp/clock-time-tests
ctest --test-dir /tmp/clock-time-tests --output-on-failure
```

Diese Tests benötigen Qt 5 Widgets und Test. Sie prüfen Mausziehen auf allen
vier Ziffern, Touch-Ereignisse, längeres Ziehen, kleine Bewegungen ohne Änderung,
den Übergang über Mitternacht sowie Bestätigen und Abbrechen.
Pro 32 Pixel vertikaler Bewegung wird ein Schritt ausgelöst: nach oben erhöht,
nach unten verringert den Wert wie die jeweilige Plus-/Minus-Taste.
Auf dem Raspberry Pi zusätzlich die Empfindlichkeit am echten Touchscreen prüfen.

Voraussetzungen: Qt 5 Widgets, Multimedia, D-Bus und Test (Entwicklungspakete), CMake sowie dbus-run-session.

```sh
cmake -S tests -B /tmp/clock-wifi-tests
cmake --build /tmp/clock-wifi-tests
ctest --test-dir /tmp/clock-wifi-tests --output-on-failure
```

Die Tests prüfen Adaptererkennung, SSIDs mit Sonderzeichen, Signalstärke,
Scannen, neue und gespeicherte Verbindungen, Trennen sowie Touch-Eingabe,
Passwortmaskierung und die Mindestgröße der Oberfläche.

Die Alarmtests verwenden ein temporäres Home-Verzeichnis und eine isolierte
Musikordnerauswahl, damit echte USB-Sticks die Tests nicht beeinflussen.
Ein simulierter USB-Einhängepfad prüft USB-Vorrang, einen leeren Stick und den
Rückfall auf `~/Music` nach dem Entfernen des Sticks. Sie prüfen, dass der
Alarm ohne eingehängten USB-Stick lokale MP3-Dateien aus `~/Music` einschließlich Unterordnern
lädt, Dateinamen mit Sonderzeichen und `.MP3` erkennt, die Wiedergabeliste
wiederholt und beim nächsten Alarm neu einliest. Bei jedem Alarm und Teststart
wird die Reihenfolge neu gemischt; innerhalb eines Durchlaufs kommt jedes Lied
einmal vor. Die Tests prüfen die enthaltenen Dateien unabhängig von ihrer
zufälligen Reihenfolge. Außerdem prüfen sie das Stoppen,
die MP3-Testwiedergabe in den Einstellungen und leere bzw. fehlende Musikordner.
Der Testknopf startet und stoppt die Musik mit der aktuell eingestellten
Lautstärke; OK und Abbrechen stoppen die Wiedergabe ebenfalls.
Das Label `labelMusicStatus` zeigt den gewählten Ordner als vollständigen Pfad;
auch Fehlermeldungen nennen diesen Pfad.
Auf dem Raspberry Pi zusätzlich mit einem eingehängten USB-Stick prüfen:
Dessen Wurzelverzeichnis hat Vorrang vor `~/Music`, einschließlich Unterordnern.
Bei mehreren USB-Laufwerken wird der alphabetisch erste Einhängepfad gewählt.
Ein leerer Stick zeigt eine Fehlermeldung; nur ohne Stick wird `~/Music` genutzt.
Nach dem Entfernen des Sticks müssen das erneute Öffnen der Einstellungen und
der nächste Test- bzw. Alarmstart wieder `~/Music` verwenden.
Die Testdateien enthalten kein Audio; die tatsächliche MP3-Wiedergabe muss auf
dem Raspberry Pi mit dessen Audioausgabe geprüft werden.

Auf echter Hardware zusätzlich prüfen: falsches Passwort, Verbindungsabbruch,
Neustart mit automatischer Wiederverbindung und NetworkManager-Berechtigungen
unter dem Benutzer, der die Wecker-App startet. Unterstützt werden offene Netze,
WPA/WPA2 Personal, WPA3 Personal und OWE. WEP und Unternehmens-WLAN benötigen
andere Eingabefelder und werden als nicht unterstützt angezeigt.
