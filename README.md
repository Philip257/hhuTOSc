# Übungsblatt 1: Ausgabe: Bildschirm und Lautsprecher

## Lernziele
2. Einarbeiten in die Programmiersprache C++ bzw. Rust
Dazu soll in main.cc in der Einstiegsfunktion main das Objekt kout für verschieden formatierte Ausgaben genutzt werden. Diese sollen ähnlich wie bei der C++ IO-Streams Bibliothek verwendet werden können. Damit die Ausgabefunktionen überall in HHUos genutzt werden kann, ist in der gegebenen Klasse Gobals, ein globales CGA_Stream-Objekt kout bereits definiert.

`main.cc`, `user/aufgabe1/TextDemo.cc` und `devices/CGA.cc`

*Beachten Sie die Kommentare im Quelltext der Vorgabe, sowie die Datei* `HinweiseCGA.pdf`


## 2. Aufgabe: Lautsprecher
Dies ist eine unsaubere Lösung die wir später ersetzen werden.
Weitere Informationen zum PIT 8254 finden Sie hier: http://wiki.osdev.org/Programmable_Interval_Timer

In folgenden Dateien müssen Quelltexte einfügt werden:
`devices/PCSPK.cc` und `user/SoundDemo.cc`

![CGA](https://github.com/mschoett/hhuTOSc/blob/aufgabe-1/cga.jpg?raw=true)
