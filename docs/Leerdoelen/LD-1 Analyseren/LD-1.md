### Leeruitkomst 1 Analyseren

Student analyseert de vereisten en doelstellingen van de opdrachtgever betreffende een 'Digital Twin' van een bestaand embedded systeem. Op basis hiervan en rekening houdend met de mogelijke gebruikers deduceert de student requirements volgens een voorgeschreven methode. Deze requirements dienen na validatie door de opdrachtgever als basis voor het ontwerp.

Indicatoren
- Requirements analyse
- Stakeholder analyse
- Testplan
- Ontwikkeldocument (eerste deel)
---

### **Leeruitkomst 1 Persoonlijke opdrachten:**

| Portfolio-item     | Beschrijving                                           | Bewijslast               |
|--------------------|--------------------------------------------------------|--------------------------|
| `Data Analyse - Impact Weercondities` | `Uitgebreidde Data analyse met adviesrapport gemaakt` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Leerdoelen/LD-1%20Analyseren/Data%20analyse%20-%20Impact%20weercondities%20luchtkwaliteit%20Breemarsweg%20Hengelo%2004-03-2025.pdf) |

#### **Data Analyse - Impact Weercondities**

Voor deze analyse heb ik verschillende analyses uitgevoerd op de data die afkomstig is van de luchtkwaliteitsensoren aan de Breemarsweg in Hengelo. In deze analyse valideer ik eerst de data uit de verschillende bronnen met behulp van standaarddeviatie, variatiecoëfficiënt, gemiddelde absolute afwijking en Z-score stabiliteit. Hieruit blijkt dat de sensoren een hoge mate van betrouwbaarheid in hun metingen laten zien.

Daarna is de dataset gekoppeld aan winddata per windrichting, en zijn de piekmomenten van de PM-metingen in kaart gebracht. Ook is er een heatmap gemaakt waarin de winddata is afgezet tegen de luchtkwaliteitsmetingen over de meetmaanden.

Tot slot zijn zowel de hoge PM-waarden als de gemiddelde PM-waarden weergegeven in een windroos om trends te herkennen. Hieruit blijkt dat vooral westelijke en zuidoostelijke winden disproportioneel bijdragen aan verhoogde fijnstofconcentraties en uitschieters.

#### Herstel

Op basis van de analyse heb ik een aantal functionele eisen opgesteld. De opdrachtgever wil inzicht krijgen in de relatie tussen fijnstofconcentraties en weersomstandigheden. Daarom moet het systeem fijnstofmetingen kunnen koppelen aan meteorologische data zoals windrichting en windsnelheid. Daarnaast is het belangrijk dat de data eerst gevalideerd wordt, zodat uitschieters en foutieve waarden buiten beschouwing blijven. Ook moet het systeem verschillende databronnen kunnen combineren, zoals lokale sensormetingen en KNMI-data. Tot slot is het van belang dat de meetresultaten bruikbaar zijn voor langere termijnanalyses en het opstellen van vervolgonderzoek. Deze vereisten vormen een eerste basis voor het ontwerp van een digitale representatie van het systeem, waarmee toekomstige patronen en effecten beter in kaart kunnen worden gebracht.


### Feedback Persoonlijke Opdrachten
Initieel was er de indruk dat de leeropdracht analyseren ook echt om een analyse ging. Maar na advies van Bart was verwezen dat het meer gaat om het kunnen deducerent van requirements. Dit is vervolgens aangepast hoe de requirements zijn gehaald uit de vraag van de opdrachtgever.

####  **Data Analyse - Impact Weercondities**
Geen

---

### **Leeruitkomst 1 Projectopdrachten:**

| Portfolio-item     | Beschrijving                                           | Bewijslast               |
|--------------------|--------------------------------------------------------|--------------------------|
| `Requirements Analyse` | `Requirements analyse opgesteld vanuit de stakeholderanalyse en interviews` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Verslagen/1.%20Requirement%20Analyse.md) |
| `Stakeholder Analyse` | `Belanghebbenden van het project geïdentificeerd, geanalyseerd en geclassificeerd op basis van hun belangen, invloed en betrokkenheid bij het project` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Verslagen/2.%20Systeem%20Design.md) |
| `Acceptatie Test` | `Teststrategie opgezet om te valideren of het systeem voldoet aan de verwachtingen van de stakeholders` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Verslagen/9.%20Acceptatie%20Testen.md) |
|`Lora Mesh onderzoek`|  `Voor de Deep Dive heb ik onderzoek gedaan naar Lora Mesh, dit heb ik gelijk toegepast op mijn werk als advies voor vervolgonderzoek naar de mogelijkheden` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Lora_mesh_achtergrondrappord.md) |

---
### Onderbouwing hoe deze portfolio-items hebben bijgedragen aan het aantonen van deze leeruitkomst.
 
#### **Requirements Analyse**
Op basis van de stakeholderanalyse heb ik functionele en niet-functionele eisen opgesteld voor de simulatie van de onderzeedrone. De behoeften van de brandweer en ontwikkelaars stonden centraal, zoals het trainen in realistische scenario’s en het testen van firmware zonder fysieke hardware. Door deze eisen systematisch af te leiden uit belangen en invloed van stakeholders, is een eerste basis gelegd voor het ontwerp van een Digital Twin die aansluit op de doelstellingen van de opdrachtgever.

#### **Stakeholder Analyse**
De stakeholderanalyse brengt de behoeften en belangen van de betrokken partijen in kaart via een Power-Interest Matrix. Hieruit komen vooral de brandweer en ontwikkelaars naar voren als hoofd-stakeholders. Hun algemene eisen zijn verder uitgewerkt in de requirement analyse:

Brandweer (eindgebruikers & trainers)
Realistische simulatie, gebruiksvriendelijke interface, trainingsscenario’s

Ontwikkelaars (firmware & simulatie)
Simulatie moet firmware correct nabootsen, logging- en debuggingtools

#### **Acceptatietest**
Er zijn acceptatietests opgesteld om te toetsen of het project voldoet aan de gestelde requirements. Deze zijn opgedeeld in:

Functionele tests – Controleren of de functionaliteiten juist werken

Gebruikerstesten – Eindgebruikers testen het systeem op bruikbaarheid en intuïtiviteit

Prestatie- en belastingstesten – Evaluatie van systeemprestaties onder verschillende omstandigheden

Veiligheidstesten – Beoordeling van de beveiliging en risico's

De tests zijn nog niet uitgevoerd, maar er is wel een analyse gedaan naar wat nodig is om tot een succesvol en bruikbaar eindproduct te komen.

### Feedback Project Opdrachten

#### **Requirements Analyse/Stakeholder Analyse/Acceptatietest**
18-03 Er heeft een gesprek plaatsgevonden met de Product Owner (Jan Halsema) waarin de requirements zijn besproken. Deze zijn goedgekeurd, met als belangrijke kanttekening dat er vanuit de Product Owner meer nadruk moest komen te liggen op de eindgebruiker in plaats van de ontwikkelaar.

Als reactie op deze feedback is afgesproken om in de ontwikkelvolgorde voorrang te geven aan de functionele requirements voor de brandweer, zodat hun behoeften eerder worden ingevuld dan die van de ontwikkelaars.

Ook was de voetnote gegeven dat de tests wel uitgebreid waren en mogelijk niet haalbaar voor een groep met een enkel lid. 

10-06 Er is met Teun Pieter gepraat over welke dingen er nou nodig zijn voor de productowner voor mij om te slagen. Gezien het beperkte contact was het advies de focus te leggen op wat ik heb en daar proberen de leerdoelen uit te halen. De goede basis lag er maar nu moet er gewoon gefocussed worden om dingen af te tekenen en feedback te krijgen.

---