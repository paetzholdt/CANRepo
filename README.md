# Projekt
## Projektursprung
Bei meiner Arbeit als Straßenbahnfahrer kamen mir zwei Ideen, von denen ich mir erhoffe, dass sie die Sicherheit der Fahrgäste, Fahrer und Personen im Umfeld der Straßenbahn erhöhen könnte.
Da ich Angewandte Informatik studiere, will ich probieren, diese Ideen in einem industrienahen Modell zu implementieren.

## Projektbeschreibung
Das Gesamtprojekt ist aufgeteilt in zwei Teile.

### 1. Teil
Grundlage:
Die Türüberwachung der mir bekannten Straßenbahnen ist bereits sehr gut. Eine Freigabe der Türen ist beispielsweise nur möglich, wenn die Bahn sich wirklich im Stillstand befindet. Wenn während der Fahrt (mindestens) eine Tür duch Dritte geöffnet wird, verlangsamt sich die Fahrt automatisch und der Fahrer wird gewarnt. Auch ein Anfahren ist nicht möglich so lange mindestens noch eine Tür geöffnet ist oder die Türfreigabe nicht herausgenommen wurde. Bei Bahnen, die mir bekannt sind, haben die Zustände der Türen bzw. des Türfreigabetasters auch Einfluss auf die Schaltung der Lichtsignalanlagen. Das bedeutet beispielsweise, wenn sich nah hinter der Haltestelle eine Lichtsignalanlage (LSA) befindet, wird diese angefordert, sobald alle Türen der Bahnen geschlossen sind. Dadurch erlangt die Straßenbahn an der nächsten Kreuzung Priorität. Es gibt auch Bahnen, bei denen die Anforderung geschickt wird, wenn der Türfreigabetaster herausgenommen wird, also die Türen nicht mehr von den Fahrgästen per Knopfdruck geöffnet werden können.

Die Realität und das mögliche Problem, das dadurch entstehen kann:
Die Fahrer nutzen den Türfreigabetaster, um die Anforderung an der nächsten LSA zu erhalten. Es wird ihnen häufig so beigebracht und an vielen Haltestellen mit folgender LSA ist auch das genau der Sinn. Allerdings kann es passieren, dass die Abfolge "Türfreigabe kurz erneut geben, um Anforderung zu erhalten" dazu führt, dass dies auch an LSAs genutzt wird, an denen das nicht vorgesehen ist - einfach weil der Vorgang schon im Muskelgedächtnis ist. Besonders problematisch wäre das an großen Kreuzungen mit viel Individualverkehr (IV). Wenn dort ein Fahrer fahrlässig (z.B. aus Unachtsamkeit am Ende einer langen Schicht) die Türfreigabe setzt, könnten Fahrgäste im schlimmsten Fall auf die Fahrbahn laufen oder fallen und vom IV erfasst werden.

Meine Lösungsidee:
Die Bahn erkennt über einen Sensor, ob sie tatsächlich vollständig innerhalb eines Haltestellenbereichs steht. Wenn ja, ist erzielt der Türfreigabentaster die gewöhnliche Wirkung und der Fahrgastwechsel kann normal vonstattengehen. Wenn nicht, löst der Türfreigabentaster nicht die tatsächliche Freigabe der Türen aus und es erscheint eine Meldung an den Fahrer.
Allerdings muss es in Notfällen oder bei Störungen einen Override dafür geben. Dieser könnte mit Hilfe eines weiteren Türfreigabetasters implementiert werden. Dieser wäre dann nicht als Standard zu benutzen und ist räumlich vom normalen Taster getrennt. Sollte eine Störung im System vorliegen könnte so übergangsweise aber noch ein Fahrgastwechsel ermöglicht werden oder eine schnelle Evakuierung im Haltestellenbereich ermöglicht werden.


### 2. Teil
Grundlage:
Beim Fahren einer Straßenbahn kann Gewohnheit sehr gefährlich werden. Es gibt viele LSAs, die "immer gleich" schalten. Man fährt auf sie zu und man erhält das Signal F1 (Fahrt freigegeben). Ein Mal, zwei Mal, drei Mal - alles am selben Tag. Bei der nächsten Schicht, geschieht es genauso. So kann man Signale hunderte Male sehen und es verhält sich immer gleich. Doch es reicht einmal, dass die LSAs nicht wie gewohnt schaltet und Querverkehr stattdessen freie Fahrt erhält. Dann kommt es auf den Fahrer an, aufmerksam zu sein und korrekt zu handeln und zu bremsen.

Die Realität:
Menschen machen Fehler, so aufmerksam sie auch versuchen zu sein, und können Lichtsignalanlagen tatsächlich "übersehen".

Meine Lösungsidee:
Diese Idee ist komplexer und wahrscheinlich deutlich komplizierter umzusetzen. Theoretisch wäre es möglich, dass in entsprechendem Abstand zur LSA (so weit weg wie nötig, so nah wie möglich) ein (streckenseitiges) Signalinformationsmodul verbaut ist. Dieses enthält Informationen über die ID der LSA, wie weit es von der LSA entfernt ist, welches Signal auf der LSA steht und wie viel Zeit noch ist, bis das Signal fällt (von F1 auf F0 beispielsweise). Ein Sensor in der Bahn könnte diese Information auslesen und an einen Microcontroller in der Bahn senden. Dieser Microcontroller würde diese Informationen verarbeiten und kombinieren mit den Fahrdaten (also z.B. der Geschwindigkeit und Beschleunigung) der Bahn und so errechnen, ob die Tram bei Ankunft am LSA mit den aktuellen Bedingungen F0 ("rot") oder F1 ("grün") hat. Es gäbe dann verschiedene Möglichkeiten, wie die Bahn reagieren könnte, sollte bei errechneter Ankunft F0 signalisiert sein. Theoretisch könnte sie versuchen selbst eine Bremsung einzuleiten. Um den Rahmen dieses Projekts realistisch zu halten, bevorzuge ich derzeit die Lösung, dass die Bahn eine Warnung an den Fahrer sendet. (Dieser könnte dann noch ggf. dazu gezwungen werden, diese zu quittieren, um beispielsweise eine Zwangsbremsung zu verhindern, falls das System fehlerhaft ist. Aber auch dieser Teil, würde aktuell den Rahmen des Projekts sprengen.)

### Technologien
Für den 1. Teil des Projekts werden folgende Teile mindestens benötigt:
- 2 Microcontroller
- 2 CAN-Module
- ca. 1m Kabel (vorläufig aus Ethernetkabeln) zur Verbindung der CAN-Module
- 2 120 Ohm Widerstände
- weitere kleinere Technikteile (LEDs, Push-Buttons, Potentiometer)

### Vorgehensweise
Stand 17.04.2026
#### 1. Projekt-Teil
1. Grundlegende Funktionalitäten implementieren
1. 1. CAN-Bus-Kommunikation einrichten
1. 2. Geschwindigkeit Zustand simulieren (== 0, > 0)
1. 3. Türzustand simulieren (offen, geschlossen)
1. 4. Türfreigabezustand (eingeschaltet, ausgeschaltet)
2. Zusatzfunktionalität aus meiner Idee implementieren
2. 1. Haltestellebereich simulieren + Zustand der Bahn (in Haltestelle oder nicht in Haltestelle)
2. 2. Abhängigkeit der Türfreigabe von Zustand aus 2. 1.
2. 3. Störungs-/Not-Türfreigabe implementieren



## Projektziele
Ziel ist, neben Studium und Arbeit, das Projekt möglichst korrekt und weit zu bearbeiten. Persönlich erhoffe ich mir, praxisnahe Übung sowie Wissen zu erlangen, welche den Start in mein Praktikum erleichtern und den Beitrag, den ich dann leisten will, erhöht. 


## Hinweis zur Nutzung von KI
Ich werde beispielsweise für mein eigenes Verständnis mir selbst Dinge von Künstlichen Intelligenzen erläutern lassen. Auch werde ich diese, wenn es mir angemessen scheint, beispielsweise als Programmier-Hilfe nutzen. Die klare Bedingung ist allerdings: Ich bin für jeglichen Code selbst verantwortlich! Ob generiert oder aus eigener Feder - mein Anspruch ist, den Code verstehen, erklären sowie für seine Richtigkeit gewähren zu können.