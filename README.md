# Projekt
## Projektursprung
Bei meiner Arbeit als Straßenbahnfahrer kamen mir zwei Ideen, von denen ich mir erhoffe, dass sie die Sicherheit der Fahrgäste, Fahrer und Personen im Umfeld der Straßenbahn erhöhen können.
Da ich Angewandte Informatik studiere, möchte ich versuchen, diese Ideen in einem industrienahen Modell umzusetzen.

## Projektbeschreibung
Das Gesamtprojekt ist in zwei Teile gegliedert

### 1. Teil
Grundlage:
Die Türüberwachung der mir bekannten Straßenbahnen ist bereits sehr weit entwickelt. Eine Freigabe der Türen ist beispielsweise nur möglich, wenn sich die Bahn im Stillstand befindet. Wenn während der Fahrt mindestens eine Tür duch Dritte geöffnet wird, verlangsamt das Fahrzeug automatisch und der Fahrer wird gewarnt. Auch ein Anfahren ist nicht möglich, während noch mindestens eine Tür geöffnet oder die Türfreigabe aktiv ist.
Des Weiteren haben die Zustände der Türen bzw. des Türfreigabetasters - je nach Modell und Hersteller - auch Einfluss auf die Schaltung der Lichtsignalanlagen (LSA). LSA, die nah hinter einer Haltestelle sind, werden beispielsweise angefordert, sobald nach dem Fahrgastwechsel das erste Mal alle Türen der Bahn wieder geschlossen sind. Durch die Anforderung erhält die Straßenbahn an der nächsten Kreuzung Priorität. Es gibt auch Bahnen, bei denen die Anforderung geschickt wird, wenn der Türfreigabetaster herausgenommen wird, also die Türen nicht mehr von den Fahrgästen per Knopfdruck geöffnet werden können.

Problemstellung:
Die Fahrer nutzen den Türfreigabetaster, um die Anforderung an der nächsten LSA auszulösen. An vielen Haltestellen ist das exakt so vorgesehen und wird in der Ausbildung so vermittelt.
Allerdings kann es passieren, dass dieser Ablauf - "Türfreigabe schnell erneut setzen für Anforderung" - dazu führt, dass dies auch an LSAs genutzt wird, an denen das nicht vorgesehen ist, verursacht beispielsweise durch Gewöhnungseffekte. Für die Fahrgäste wäre das Risiko besonders hoch außerhalb des Haltestellenbereich nah am Individualverkehr (IV).

Lösungsidee:
Das System bestimmt an Hand von Sensordaten, ob sich das Fahrzeug vollständig innerhalb eines Haltestellenbereichs befindet.
- Fahrzeug innerhalb des Haltestellenbereichs: Türfreigabetaster verhält sich wie im Regelbetrieb
- Fahrzeug außerhalb des Haltestellenbereichs: Regelbetrieb des Türfreigabetaster wird unterdrückt, der Fahrer wird informiert
Für Notfälle oder Störungen wird zusätzlich eine separate Notfreigabe implementiert, welche bewusst vom regulären Türfreigabetaster getrennt ist, um beispielsweise zügige Evakuierungen zu ermöglichen.


### 2. Teil
Grundlage:
Viele Lichtsignalanlagen verhalten sich in ihrer Schaltung "immer" wieder gleich. Dadurch können sich bei Fahrern Gewöhnungseffekte einstellen.

Problemstellung:
Sei es auf Grund von Gewöhnung oder durch eine kurze Unaufmerksamkeit, können Fahrer Halt zeigende Signale zu spät wahrnehmen oder gar komplett übersehen. Dies geschieht sehr selten, da menschliche Fehler aber nicht vollständig vermeidbar sind, führen diese selten auftretenden Situationen zu gefährlichen Situationen.

Lösungsidee:
Bereitstellung von streckenseitigen Signalinformationsmodulen, welche folgende Informationen bereitstellen:
- Identifikation der spezifischen LSA
- Entfernung zur LSA
- aktueller Signalzustand (F0 bis F5)
- verbleibende Zeit bis zum Signalwechsel

Beim Überfahren dieses Moduls liest ein System in der Bahn diese Informationen aus und verarbeitet sie gemeinsam mit den Fahrdaten der Bahn, z.B. Geschwindigkeit und Beschleunigung. Auf Basis dieser Daten wird ermittelt, welches Signal an der LSA aktiv ist, wenn die Bahn dieses erreicht.
Im Rahmen dieses Projekts wird bei einem solchen Zustand eine Warnung an den Fahrer, falls das Signal F0 zeigen würde. Weiterführende Maßnahmen (automatische Bremsung oder Quittierungslogik) sind denkbar, werden aus Komplexitätsgründen zunächst aber nicht umgesetzt.

### Technologien
Für den ersten Teil des Projekts werden mindestens folgende Komponenten benötigt:
- 2 Microcontroller
- 2 CAN-Module
- ca. 1m Kabel (vorläufig aus Ethernetkabeln) zur Verbindung der CAN-Module
- 2 Abschlusswiderstände (120 Ohm)
- weitere elektronische Teile (LEDs, Push-Buttons, Potentiometer etc.)

### Vorgehensweise
Stand 17.04.2026
#### 1. Projekt-Teil
1. Grundlegende Funktionalitäten implementieren
1. 1. CAN-Bus-Kommunikation einrichten
1. 2. Geschwindigkeit Zustand simulieren (== 0, > 0)
1. 3. Türzustand simulieren (offen, geschlossen)
1. 4. Türfreigabezustand (aktiv, inaktiv)
2. Erweiterte Funktionalität implementieren
2. 1. Haltestellebereich simulieren + Zustand der Bahn (in Haltestelle oder nicht in Haltestelle)
2. 2. Abhängigkeit der Türfreigabe von Zustand der Bahn
2. 3. Störungs-/Not-Türfreigabe implementieren



## Projektziele
Ziel ist, neben Studium und Arbeit, das Projekt fachlich korrekt und möglichst vollständig zu bearbeiten.
Insbesonders soll praxisnahe Erfahrung in folgenden Bereichen gesammelt werden:
- Embedded-Programmierung
- verteilte Systemarchitektur
- CAN-Kommunikation
- sicherheitsorientierte Systemlogik


## Hinweis zur Nutzung von KI
Zur Unterstützung meines eigenen Lernprozesses setze ich Künstliche Intelligenzen ein, sei es als Hilfe bei der Programmierung oder generell zur Unterstützung beim Erlernen von Fachwissen.
Die klare Bedingung ist allerdings: Jeglicher Code im Projekt wird von mir verstanden, überprüft und verantwortet.