Die manuelle Zeiteinstellung verwendet systemd-timedated über den System-D-Bus.
Die App läuft als normaler Benutzer. Der Raspberry Pi benötigt systemd-timedated
und Polkit; ein fehlender Dienst oder fehlende Rechte werden im Dialog gemeldet.

Für die Bedienung ohne Passwortdialog auf dem Raspberry Pi die beiliegende
Regel installieren und den Benutzer der App in die Gruppe aufnehmen:

```sh
sudo groupadd -f raspi-clock
sudo usermod -aG raspi-clock DEIN_BENUTZER
sudo install -o root -g root -m 0644 deployment/50-raspi-clock-time.rules /etc/polkit-1/rules.d/50-raspi-clock-time.rules
```

`DEIN_BENUTZER` durch den Benutzer ersetzen, unter dem die Wecker-App läuft.
Danach neu anmelden bzw. den Raspberry Pi neu starten, damit die
Gruppenmitgliedschaft wirksam wird. Die Regel erlaubt ausschließlich das Setzen
der Uhrzeit und das Umschalten der Zeitsynchronisierung für diese Gruppe.
Die Installation erfolgt bewusst nicht automatisch durch den App-Build.

Beim Bestätigen setzt die App die ausgewählte lokale Uhrzeit am heutigen Datum
mit Sekunden auf null. Eine aktive automatische Zeitsynchronisierung wird zuvor
ausgeschaltet und bleibt nach erfolgreichem Setzen ausgeschaltet. Schlägt das
Setzen fehl, versucht die App, die zuvor aktive Synchronisierung wieder
einzuschalten; auch ein Fehler dabei wird angezeigt.

Automatische Zeitsynchronisierung bei Bedarf wieder einschalten:

```sh
sudo timedatectl set-ntp true
```

Prüfung auf dem Raspberry Pi: Uhrzeit ändern und mit `timedatectl status`
vergleichen. Berechtigungsfehler zusätzlich mit einem Benutzer außerhalb der
Gruppe prüfen. Die automatisierten Tests in `tests/system_clock` verwenden
ausschließlich einen simulierten Zeitdienst auf einem eigenen D-Bus und ändern
keine echte Uhrzeit oder NTP-Einstellung.
