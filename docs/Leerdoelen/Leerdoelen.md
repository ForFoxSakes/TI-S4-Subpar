## Leeruitkomst 1 Analyseren

Student analyseert de vereisten en doelstellingen van de opdrachtgever betreffende een 'Digital Twin' van een bestaand embedded systeem. Op basis hiervan en rekening houdend met de mogelijke gebruikers deduceert de student requirements volgens een voorgeschreven methode. Deze requirements dienen na validatie door de opdrachtgever als basis voor het ontwerp.

---

### **Leeruitkomst 1 Persoonlijke opdrachten:**

| Portfolio-item     | Beschrijving                                           | Bewijslast               |
|--------------------|--------------------------------------------------------|--------------------------|
| `Data Analyse - Impact Weercondities` | `Uitgebreide Data analyse met adviesrapport gemaakt` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Leerdoelen/LD-1%20Analyseren/Data%20analyse%20-%20Impact%20weercondities%20luchtkwaliteit%20Breemarsweg%20Hengelo%2004-03-2025.pdf) |

---

#### **Data Analyse - Impact Weercondities**
##### Onderbouwing 
Voor deze analyse heb ik verschillende analyses uitgevoerd op de data die afkomstig is van de luchtkwaliteitsensoren aan de Breemarsweg in Hengelo. In deze analyse valideer ik eerst de data uit de verschillende bronnen met behulp van standaarddeviatie, variatiecoëfficiënt, gemiddelde absolute afwijking en Z-score stabiliteit. Hieruit blijkt dat de sensoren een hoge mate van betrouwbaarheid in hun metingen laten zien.
Daarna is de dataset gekoppeld aan winddata per windrichting, en zijn de piekmomenten van de PM-metingen in kaart gebracht. Ook is er een heatmap gemaakt waarin de winddata is afgezet tegen de luchtkwaliteitsmetingen over de meetmaanden.
Tot slot zijn zowel de hoge PM-waarden als de gemiddelde PM-waarden weergegeven in een windroos om trends te herkennen. Hieruit blijkt dat vooral westelijke en zuidoostelijke winden disproportioneel bijdragen aan verhoogde fijnstofconcentraties en uitschieters.

##### Feedback 
19-06-2025 Initieel was er de indruk dat de leeropdracht analyseren ook echt om een analyse ging. Maar na advies van Bart was verwezen dat het meer gaat om het kunnen deduceren van requirements. Ik heb vervolgens de onderbouwing aangepast naar hoe de requirements zijn gehaald uit de vraag van de opdrachtgever hieronder.

##### Verwerking ontvangen feedback
Op basis van de analyse heb ik een aantal functionele eisen opgesteld. De opdrachtgever wil inzicht krijgen in de relatie tussen fijnstofconcentraties en weersomstandigheden. Daarom moet het systeem fijnstofmetingen kunnen koppelen aan meteorologische data zoals windrichting en windsnelheid. Daarnaast is het belangrijk dat de data eerst gevalideerd wordt, zodat uitschieters en foutieve waarden buiten beschouwing blijven. Ook moet het systeem verschillende databronnen kunnen combineren, zoals lokale sensormetingen en KNMI-data. De requirements vormen een eerste basis van de analyse.

---

### **Leeruitkomst 1 Projectopdrachten:**

| Portfolio-item     | Beschrijving                                           | Bewijslast               |
|--------------------|--------------------------------------------------------|--------------------------|
| `Requirements Analyse` | `Requirements opgesteld vanuit stakeholderanalyse en interviews` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Verslagen/1.%20Requirement%20Analyse.md) |
| `Stakeholder Analyse` | `Belanghebbenden geïdentificeerd en geclassificeerd` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Verslagen/2.%20Systeem%20Design.md) |
| `Acceptatie Test` | `Omschrijving van acceptatiecriteria en testcases` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Verslagen/9.%20Acceptatie%20Testen.md) |
|`Lora Mesh onderzoek`|  `Voor de Deep Dive heb ik onderzoek gedaan naar Lora Mesh, dit heb ik gelijk toegepast op mijn werk als advies voor vervolgonderzoek naar de mogelijkheden` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Lora_mesh_achtergrondrappord.md) |

---

#### **Requirements Analyse**
Op basis van de stakeholderanalyse heb ik functionele en niet-functionele eisen afgeleid. Centraal stonden de behoeften van de brandweer (realistische simulatie, gebruiksvriendelijke interface) en ontwikkelaars (nauwkeurige firmware-emulatie, debuggingtools).

---

#### **Stakeholder Analyse**
Via een Power-Interest Matrix identificeerde ik de brandweer en ontwikkelaars als hoofd-stakeholders. Hun eisen zijn verwerkt in de Requirements Analyse.

Brandweer (eindgebruikers & trainers)
Realistische simulatie, gebruiksvriendelijke interface, trainingsscenario’s

Ontwikkelaars (firmware & simulatie)
Simulatie moet firmware correct nabootsen, logging- en debuggingtools

---

#### **Acceptatietest**
Er zijn acceptatietests opgesteld om te toetsen of het project voldoet aan de gestelde requirements. Deze zijn opgedeeld in:

Functionele tests – controleren of de functionaliteiten juist werken

Gebruikerstesten – eindgebruikers beoordelen bruikbaarheid

Prestatie- en belastingstesten – monitoren van systeemprestaties onder variërende condities

Veiligheidstesten –  beoordeling van beveiliging en risico’s

De tests zijn nog niet uitgevoerd, maar er is wel een analyse gedaan naar wat nodig is om tot een succesvol en bruikbaar eindproduct te komen.

---

### Feedback 

#### **Requirements Analyse/Stakeholder Analyse/Acceptatietest**
18-03-2025 Er heeft een gesprek plaatsgevonden met de Product Owner (Jan Halsema) waarin de requirements zijn besproken. Deze zijn goedgekeurd, met als belangrijke kanttekening dat er vanuit de Product Owner meer nadruk moest komen te liggen op de eindgebruiker in plaats van de ontwikkelaar.

Als reactie op deze feedback is afgesproken om in de ontwikkelvolgorde voorrang te geven aan de functionele requirements voor de brandweer, zodat hun behoeften eerder worden ingevuld dan die van de ontwikkelaars.

Ook was de voetnote gegeven dat de tests wel uitgebreid waren en mogelijk niet haalbaar voor een groep met een enkel lid. 

10-06-2025 Er is met Teun Pieter gepraat over welke dingen er nou nodig zijn voor de productowner voor mij om te slagen. Gezien het beperkte contact was het advies de focus te leggen op wat ik heb en daar proberen de leerdoelen uit te halen. De goede basis lag er maar nu moet er gewoon gefocussed worden om dingen af te tekenen en feedback te krijgen. Hieruit is het document [Plan voor leerdoelen](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Leerdoelen/oud/Plan%20voor%20Leerdoelen.md) uitgekomen

---

## Leeruitkomst 2 Ontwerpen

Student ontwerpt gebaseerd op de requirements en volgens voorgeschreven methoden een 'Digital Twin', inclusief grafische representatie, van een bestaand embedded systeem. Dit ontwerp omvat ook een ontwerp voor teststrategieën.

---


**Leeruitkomst 2 Projectopdrachten:**

| Portfolio-item     | Beschrijving                                           | Bewijslast               |
|--------------------|--------------------------------------------------------|--------------------------|
| `Systeemontwerp` | `Hoofdstructuur van de simulatie uitgewerkt` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Verslagen/2.%20Systeem%20Design.md) |
| `Architectuurontwerp` | `	Technische lagen en interacties gespecificeerd` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Verslagen/3.%20Architectuur%20Design.md) |
| `Moduleontwerp` | `Modules gedefinieerd met taken, interfaces en teststrategieën` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Verslagen/4.%20Module%20Design.md) |
| `Teststrategie` | `	Uitgewerkt kader voor unit-, integratie- en systeemtests` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Verslagen/9.%20Acceptatie%20Testen.md) |
| `Testplan opgesteld voor Lora Mesh`| `Omschrijving van acceptatiecriteria en testcases` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Lora_mesh_achtergrondrappord.md#6-technische-testopstelling-ttgo-lora32-en-rhmesh)|

---


### Systeemontwerp 
Op basis van de opgestelde requirements heb ik de hoofdstructuur van de simulatie uitgewerkt in een systeemontwerp. Hierin zijn de belangrijkste componenten en hun verantwoordelijkheden beschreven, waaronder de simulatie-engine, hardware-emulatie en gebruikersinterface. Dit ontwerp vormt het fundament voor de verdere technische uitwerking van de Digital Twin.

### Architectuurdesign
In het architectuurdesign heb ik de technische lagen en interacties binnen het systeem gespecificeerd. Later in het project is tot de conclusie gekomen dat er meer afhankelijk heid is vanaf Gazebo, hier is het ontwerp in de architectuur naar aangepast.

### Moduleontwerp
Elke module is afgebakend volgens het V-model, met duidelijke interfaces en bijbehorende teststrategieën.

### Acceptatietesten
De acceptatietesten zijn opgesteld om te toetsen of de simulatie voldoet aan de functionele en niet-functionele eisen vanuit de stakeholderanalyse. Door samen met eindgebruikers te testen op gebruiksvriendelijkheid, prestaties en veiligheid, wordt gevalideerd of de Digital Twin bruikbaar en betrouwbaar is in de praktijk.


--
### Feedback

18-03-2025 Jan Halsema : 
Zorg dat je conclusies en planningen op elke pagina helder worden afgesloten
Denk na over prioritering: wat is essentieel, wat kan eventueel later

10-06-2025 Teun-Pieter:
Het is belangrijk voor de productowner dat, als deze requirements binnen de afgesproken periode niet gehaald worden dat er wel een advies komt van de volgende stappen. Dit heb ik uitgewerkt in [project_outline](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/project_outline.md)


---

## Leeruitkomst 3 Adviseren

Student adviseert de opdrachtgever, na analyse van de vereisten en doelstellingen, over de inzet van een digital twin. Het advies is helder onderbouwd en gepresenteerd, zodat het begrijpelijk is voor alle stakeholders/betrokkenen. Het voorgestelde ontwerp is goed gedocumenteerd en het advies volgt een voorgeschreven methode, zodat de implementatie efficiënt kan worden voortgezet.

---

## **Leeruitkomst  Persoonlijke opdrachten:**

| Portfolio-item     | Beschrijving                                           | Bewijslast               |
|--------------------|--------------------------------------------------------|--------------------------|
|`Smartcity-IoT Analyse` | `Analyse luchtkwaliteit rondom gemeente Hengelo` | [link](https://github.com/ForFoxSakes/TI-S4-DEBUG/blob/main/Documents/Leerdoelen/LD-1%20Analyseren/Data%20analyse%20-%20Impact%20weercondities%20luchtkwaliteit%20Breemarsweg%20Hengelo%2004-03-2025.pdf) |
|`Lora Mesh onderzoek`|  `Onderzoek naar LoRa Mesh voor smart-city, vertaald naar adviesrapport` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Lora_mesh_achtergrondrappord.md) |
|`Advies vervolg project`|  `	Advies opgesteld voor de volgende stappen in het onderzeedrone-project` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/presentation_outline.md) |

--- 

#### Smartcity-IoT Analyse 
In opdracht van de gemeente heb ik de relatie tussen windrichting en fijnstofconcentraties in Hengelo onderzocht. Op basis van mijn bevindingen heb ik concrete aanbevelingen geformuleerd voor luchtkwaliteitsmonitoring en risicobeperking.

#### Lora Mesh Onderzoek
Ik vergeleek LoRa Mesh met LoRaWAN op techniek, toepasbaarheid en schaalbaarheid. De belangrijkste uitkomst is vertaald naar een adviesrapport en uitgegroeid naar een onderzoeksproject richting de mogelijkheden van LoRa Mesh binnen SmartCity-IoT.

### Feedback
Vanuit mijn werk was in overleg na de presentatie interesse getoond in de opstelling, en het argument bij mijn advies was dat het niet diep genoeg was. Dit was ook het geval bij sommige feedback bij de presentatie. Mijn doel was meer dat ik wilde kijken of het een mogelijkheid was en hoe het opweegt tegen LoRaWAN en of het de problemen waar wij bij LoRaWAN tegenaan lopen zou oplossen.

## Leeruitkomst 4 Realiseren

Student realiseert vanuit het ontwerp een 'Digital Twin' van een bestaand embedded systeem, inclusief grafische representatie. Hierbij wordt gewerkt volgens een voorgeschreven methode waarin testen centraal staat, ten behoeve van het uitvoeren van tests op verschillende ontwikkelniveaus. Testresultaten, omstandigheden en afhankelijkheden worden helder gedocumenteerd, omwille van het reproduceren van de testresultaten. 


**Leeruitkomst 4 Projectopdrachten:**


| Portfolio-item     | Beschrijving                                           | Bewijslast               |
|--------------------|--------------------------------------------------------|--------------------------|
| `Projectcode` | `	Alle code van de onderzee simulator` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/tree/main/subpar/simulator) |
| `Vision opdrachten` | `Basis beeldverwerking met neuraal netwerk` | [link](https://github.com/ForFoxSakes/TI-S4-opdrachten/tree/main/Vision) |
| `Standardlibrary C++` | `Opdrachten van STD C++` | [link ](https://github.com/ForFoxSakes/TI-S4-opdrachten/tree/main/CPP) |
| `ALDS` | `Algoritmes & datastructuren` | [link](https://github.com/ForFoxSakes/TI-S4-opdrachten/tree/main/ALDS) |
| `Gazebo Opdrachten` | `Modellen en viewerconfiguratie in Gazebo` | [link](https://github.com/ForFoxSakes/TI-S4-DEBUG/tree/main/src) |
| ` Ontwikkelomgeving ` | `Devcontainer met Docker en VSCode-debugger` | [link](https://github.com/ForFoxSakes/TI-S4-opdrachten/blob/main/.devcontainer/devcontainer.json) |



### Vision opdrachten
Voor de vision opdrachten is de basis van beelverwerking uitgelegd. Voor de eerste opdracht zijn gaussian filters toegevoegd en Hough lines gebruikt om een flatgebouw te herkennen. Vervolgens is er een begin gemaakt met neurale netwerken op de mnist dataset. De laatste opdracht is niet volledig want het kostte mij te lang om de camera goed werkend te krijgen. Wel zijn de eerste drie assignments gemaakt.

### ALDS
Voor ALDS heb ik gewerkt aan algoritmes en datastructuren en onderzocht hoe ze zich gedragen bij verschillende invoer. Ik heb keuzes gemaakt op basis van prestaties en geheugenverbruik, en testgevallen opgesteld om dat te onderbouwen. De uitkomsten van die tests heb ik vastgelegd, zodat duidelijk is wat de invloed was van bijvoorbeeld datastructuur of sorteermethode. Er een begin gemaakt aan het Dijkstra Algoritme met grafen, een interresant onderwerp, maar dit wat ook net voor de valreep niet voltooid.

### Ontwikkelomgeving (Devcontainer met Docker en debugger)
In VSCode heb ik een Docker-devcontainer opgezet met Gazebo en een C++-debugger. Ik documenteerde alle stappen en configuraties, zodat het probleem van 'it worked on my device' niet voor hoort te komen.

---

### Feedback

#### ALDS opdracht 1
De opdracht is correct uitgevoerd zoals bedoeld. Er zijn nettere manieren om dit op te lossen, bijvoorbeeld met behulp van decorators, maar dat viel buiten de opdracht. Hieronder een voorbeeld van een `memoize` decorator ter illustratie:

```python
def memoize(func):
    cache = {}
    def memoized_func(*args):
        if args in cache:
            return cache[args]
        result = func(*args)
        cache[args] = result
        return result
    return memoized_func

@memoize
def fibonacci(n):
    if n in [0, 1]:
        return n
    return fibonacci(n-1) + fibonacci(n-2)

print(fibonacci(10))
```



#### ALDS opdracht 2

De implementatie van de median-pivot lijkt niet helemaal correct. De redenering laat wel zien dat je de aanpak begrijpt en goed kunt uitleggen wat er zou moeten gebeuren. De opdracht is daarmee inhoudelijk behaald, al kan de uitwerking nog iets technischer verbeterd worden.

---

### CPP

De code met standaardbibliotheekfuncties ziet er goed uit. Er zijn wel een paar punten waar de efficiëntie verbeterd kan worden, met name bij de grote-O-complexiteit van bepaalde loops.

Let er ook op dat je bij functies zoals `std::transform` het predicaat (de functie die iets doet met elk element) los meegeeft, niet de container zelf. Dit kan je code korter en overzichtelijker maken.

Kijk eventueel ook naar de `ranges` uit de standaardbibliotheek voor modernere schrijfwijze:
[https://en.cppreference.com/w/cpp/algorithm.html](https://en.cppreference.com/w/cpp/algorithm.html)

---

### Devcontainer

De opdracht is goed uitgevoerd en werkt zoals bedoeld. Alles ziet er netjes uit en er zijn geen opvallende problemen.
\ Nick Goris

#### Gazebo Opdracht 
1 mrt op 12:14
Leuk gedaan! 
- Bart Bozon

#### Vision opdracht
Eerste feedback was dat er nog wat creativiteit ontbrak bij de CSV opgave. Dit heb ik opgelost door een image remapping functie toe te voegen die een lachspiegel effect creeerd, ook heb ik de edge detection die ik initieel toegepast heb in ee nstandaardfunctie van CSV gevonden en toegepast. Deze had een beter effect.

---


## Leeruitkomst 5 Beheren

Student zet een professionele ontwikkelomgeving op voor desktop development. Daarbij houdt hij rekening met de samenwerking tussen verschillende programmeertalen. De desktop debugging wordt op een gestructureerde manier uitgevoerd. De tests worden uitgevoerd volgens een vooraf beschreven testplan en moeten desgewenst op een later moment reproduceerbaar zijn. De student werkt volgens een voorgeschreven methodiek en maakt gebruik van geschikte tooling software debugging.

---

**Leeruitkomst 5 Projectopdrachten:**

| Portfolio-item     | Beschrijving                                           | Bewijslast               |
|--------------------|--------------------------------------------------------|--------------------------|
| `Ontwikkeldocument` | `Beheren van een ontwikkeldocument om de ontwikkeling van het project bij te houden` | [link](https://github.com/ForFoxSakes/TI-S4-DEBUG/blob/main/Documents/Ontwikkeldocument.md) |
| `Opdrachten ontwikkelomgeving` | `Opdrachten van College Ontwikkelomgeving opzetten` | [link](https://github.com/ForFoxSakes/TI-S4-VOS/tree/main/Opdrachten/Ontwikkelomgeving%20opzetten) |
| `Opdrachten debugging/tooling` | `Opdrachten van College Intro & Desktop-Environment (VSCode, CMake, Debugger)` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/tree/main/docs/Verslagen) |



Onderbouwing hoe deze portfolio-items hebben bijgedragen aan het aantonen van deze leeruitkomst.
 
#### Opdrachten ontwikkelomgeving
Voor de opdracht rondom het opzetten van de ontwikkelomgeving was het doel om een Docker-image te maken waarin de Gazebo-simulatie uitgevoerd kan worden. Ik heb dit verder uitgebreid door Gazebo binnen deze Docker-container te laten draaien en de omgeving in VSCode te onderhouden. Hierbij heb ik de benodigde extensies toegevoegd, zodat bijvoorbeeld SDF-bestanden voor de Gazebo-simulator eenvoudiger kunnen worden beheerd. Daarnaast bevat de Docker-container ook de documentatie, zodat ik op de dagen dat ik hieraan werk (maandag en dinsdag) direct aan de slag kan zonder alles opnieuw in te richten. Dit zorgt ervoor dat ik het project op een professionele en gestructureerde manier kan beheren.

#### Opdrachten debugging/tooling

Voor de opdrachten rondom debugging en tooling heb ik een debuggingomgeving opgezet. De basis staat, maar deze is nog niet intensief gebruikt. Verdere optimalisaties zullen volgen zodra de softwareontwikkeling verder gevorderd is.

--

#### Feedback
18/06 Nick Goris:
Zowel de ontwikkelomgeving als de debugging/tooling zijn volgens de opdracht uitgevoerd.


--
## Leeruitkomst 6 Toekomstgericht organiseren

De student kan een probleem vertalen naar een product door randvoorwaarden en requirements op te stellen in overleg met de opdrachtgever. Het project wordt gestructureerd opgezet, uitgevoerd en opgeleverd, met aandacht voor omgevingsfactoren, en maatschappelijke en ethische aspecten.

Indicatoren:
- Ontwikkeldocument
- Scrum board
- Sprintverslagen

---

**Leeruitkomst 6 Projectopdrachten:**

| Portfolio-item     | Beschrijving                                           | Bewijslast               |
|--------------------|--------------------------------------------------------|--------------------------|
| `Onwikkeldocument` | `In het ontwikkeldocument de randvoorwaarden en requirements opgesteld vanuit het problem` | [link](http://) |
| `Scrum Board` | `Scrum board bijgehouden tijdens het project` | [link](http://) |
| `Sprintverslagen` | `Bijhouden van sprintverslagen als reflectie op de sprints` | [link](https://github.com/ForFoxSakes/TI-S4-DEBUG/tree/main/Documents/Sprint) |


Onderbouwing hoe deze portfolio-items hebben bijgedragen aan het aantonen van deze leeruitkomst.

--

Beschrijving van de feedback die ik heb ontvangen op de portfolio-items.

--

---
## Leeruitkomst 7 Doelgericht interacteren

De student onderhoudt actief de relatie met relevante samenwerkingspartners (denk aan teamleden, opdrachtgevers, eindgebruikers, maatschappelijke organisaties en/of andere stakeholders) door middel van het geven van weloverwogen presentaties die afgestemd zijn op de doelgroep.

Indicatoren:
- Onderzoeksverslag(deepdive)
- Adviespresentatie
- Sprintverslagen (review)

---

**Leeruitkomst 7 Persoonlijke opdrachten:**

| Portfolio-item     | Beschrijving                                           | Bewijslast               |
|--------------------|--------------------------------------------------------|--------------------------|
| `Contact met Docenten` | `Gezien de afwijkende stuctuur van mijn opdracht was er veel interactie nodig om een goede structuur te kunnen ontwikkelen voor dit project` | [link](https://github.com/ForFoxSakes/TI-S4-DEBUG/blob/main/Documents/Contract.md) |
| `Salvagen van semester` | `Tegen het einde van het project proberen er het beste van te maken` | [link]()|


Onderbouwing hoe deze portfolio-items hebben bijgedragen aan het aantonen van deze leeruitkomst.


--

Beschrijving van de feedback die ik heb ontvangen op de portfolio-items.

--

**Leeruitkomst 7 Projectopdrachten:**

| Portfolio-item     | Beschrijving                                           | Bewijslast               |
|--------------------|--------------------------------------------------------|--------------------------|
| `Onderzoeksverslag(deepdive)` | `Tijdens de deepdive in het onderzoeksverslag contact gezocht met specialisten relevant voor het project` | [link naar ...](http://) |
| `Adviespresentatie` | `Presentatie waarin advies aan de productowner gegeven wordt gebaseerd op de bevindingen` | [link naar ...](http://) |
| `Deep Dive Presentatie` | `Deep dive van LoraWAN en LoRaMesh presenteren aan groep` | [link]()|
| `Sprintverslagen (review)` | `Review van de Sprintverslagen` | [link naar ...](http://) |


Onderbouwing hoe deze portfolio-items hebben bijgedragen aan het aantonen van deze leeruitkomst.

--

### Feedback

### Deep Dive Presentatie
Feedback van studenten:

De presentatie bevatte te veel tekst op de slides\
De toepassingen van LoRa waren interessant, maar er was behoefte aan meer technische voorbeelden

Feedback van docenten:

Nick Goris: Complimenteerde de opbouw van de presentatie, waarbij ik startte met een probleemstelling, vervolgens een technisch kader opstelde en daarna naar het antwoord toewerkte. Hij merkte wel op dat het jammer was dat de apparatuur ontbrak voor een praktische demonstratie.

Harm:
 Suggereerde dat er meer aandacht besteed had moeten worden aan de verschillende berichtgevingsklassen van LoRa (klasse A, B en C) en of mesh-netwerken hier wel bij aansluiten.


---


## Leeruitkomst 8 Persoonlijk leiderschap

De student bereidt zich voor op studie- en loopbaankeuzes. De student evalueert hierbij persoonlijke ambities en kwaliteiten in relatie tot de gewenste positionering in het werkveld. De student kan deze effectief communiceren in bv sollicitatie brief of gesprek.



**Leeruitkomst 8 Projectopdrachten:**

| Portfolio-item     | Beschrijving                                           | Bewijslast               |
|--------------------|--------------------------------------------------------|--------------------------|
| `Sollicitatiebrief` | `Solicitatiebrief geschreven voor de functie van Technisch lead voor Submarine project` | [link](https://github.com/ForFoxSakes/TI-S4-VOS/tree/main/Opdrachten/Solicitatiebrief%20en%20CV) |
| `Voorbereiding Evaluatiegesprek` | `Documentopstelling voor Evaluatiegesprek en vooruitgang` | [link naar ...](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Verslagen/Voorbereiding%20Evaluatiegesprek.md) |
| `Plan voor ontwikkeldocument / leerdoelen opgezet` | `Plan opgezet voor het aanvullen van ontwikkeldocument` | [link naar ...](https://github.com/ForFoxSakes/TI-S4-Subpar/blob/main/docs/Leerdoelen/oud/Plan%20voor%20Leerdoelen.md) |

Onderbouwing hoe deze portfolio-items hebben bijgedragen aan het aantonen van deze leeruitkomst.

### Voorbereiding Evaluatiegrespek :

Ik heb een begin gemaakt aan mijn voorbereiding voor het Evaluatiegesprek dat over een maand plaatsvind. Hierbij heb ik naar wat bronnen gekeken en punten verzamelen om uit te voeren komende periode ter voorbereiding. Verder kijk ik naar Inventarisatie Huidige Situatie,wil ik een kort Marktonderzoek doen om wat sterker in mijn schoenen te staan en Argumentatie Opbouwen voor commentaar dat ik zou krijgen. 


### Plan voor ontwikkeldocument / leerdoelen opgezet : 
Tijdens de laatste stretch van het Semester een opzet gemaakt met Teun Pieter om gepaalde leerdoelen proberen te halen
Hierin was ook weer de focus om te kijken of ik kan nog bepaalde doelen kan halen in de periode. 

--

### Feedback

### Feedback Bart 
Motivatie brief:

Ik zou het formeler doen, ik mis briefhoofd, aanhef, etc.
Dus je wilt je interesse tonen? Maar dat is het niet toch, je hebt interesse! En dat wil je aangeven of zo. Beetje rare eerste zin vind ik zelf. 
Het wordt voor mij niet duidelijk waarom je voor de technical lead voor onderzeeer wilt gaan. Waar ligt je passie? En wat heeft dat met TL en sub te maken? Is voor mij niet duidelijk. Het stuk over technische verbeteringen is wel sterk maar ik zou het iets meer toespitsen op de vacature. 
Tweede alinea wordt wel erg duidelijk waarom jij geschikt zou zijn, sterk stuk (maar ik weet nog steeds niet waarom je het wilt!). 
derde alina, zin loopt niet lekker, na de zowel verwacht ik : in A, waar ik bla, en B, waar ik flubber, etc... Nu valt het na de commerciele sector dood.
Waarom is schakkelen tussen verschillende bedrijfsculturen relevant voor de functie? Wordt mij niet duidelijk. 
Oei, flinke spelfout in laatste zin (voeldende). Taal puristen leggen nu je brief opzij en gaan lunchen (dat ben ik gelukkig niet, ik ben enigzins dyslectisch). Let op de details, sommige mensen gaan daar heel hard op. 
Het kopje koffie voelt voor mij te informeel. Het vrijblijvend ook. Jij WILT deze functie, toch? 
Ook einde brief voor mij (qua layout) veel te informeel.
CV:

Erg mooi introductie stukje. Echt erg sterk! Heel mooi compact met een superkern (dat "what gets me exited"  :hartje:).
Ik zou denken dat je afgestudeerd bent. Mischien stukje toevoegen over dat je nog niet klaar bent.  https://www-icslearn-co-uk.translate.goog/blog/career-development/how-to-list-an-in-progress-qualification-on-your-cv/?_x_tr_sl=en&_x_tr_tl=nl&_x_tr_hl=nl&_x_tr_pto=rq#:~:text=If%20the%20qualification%20you're,the%20top%20of%20your%20CV.
Voor de rest sterke CV. Let wel op spelfouten (broswer? severed?) daar haal je je hele werk mee naar beneden. 

--

---

## Leeruitkomst 9 Onderzoek probleem oplossen

De student kan een praktijkgericht probleem identificeren en de juiste oplossingsrichting kiezen door wensen van de opdrachtgever centraal te stellen. Gedurende het proces handelt de student onderzoekend, stelt kritische vragen en past verschillende (hbo-ICT) methoden toe om relevante informatie te verzamelen. Hierbij wordt de informatie op gestructureerde en grondige wijze geanalyseerd en worden daarmee keuzes onderbouwt, rekening houdend met maatschappelijke standaarden en ethische aspecten.

Indicatoren:
- Onderzoeksverslag (deepdive)
- Ontwikkeldocument
---

**Leeruitkomst 9 Persoonlijke opdrachten:**

| Portfolio-item     | Beschrijving                                           | Bewijslast               |
|--------------------|--------------------------------------------------------|--------------------------|
| `Portfolio-item A` | `plaats hier een korte uitleg over wat je hebt gedaan` | [link naar ...](http://) |

Onderbouwing hoe deze portfolio-items hebben bijgedragen aan het aantonen van deze leeruitkomst.

--

Beschrijving van de feedback die ik heb ontvangen op de portfolio-items.

--

**Leeruitkomst 9 Projectopdrachten:**

| Portfolio-item     | Beschrijving                                           | Bewijslast               |
|--------------------|--------------------------------------------------------|--------------------------|
| `Deep Dive` | `problemen identificeren tijdens de deepdive en gepast handelen om dit probleem op te lossen ` | [link naar ...](http://) |
| `Ontwikkeldocument` | `problemen identificeren in het ontwikkeldocumenten gepast handelen om dit probleem op te lossen ` | [link naar ...](http://) |


### Deep Dive

Tijdens deze deepdive heb ik een praktijkgericht probleem onderzocht, namelijk de geschiktheid van LoRa Mesh als alternatief of aanvulling op LoRaWAN binnen SmartCity-toepassingen. Ik heb de wensen van de opdrachtgever als uitgangspunt genomen, zoals de behoefte aan robuustheid, bereik in stedelijke omgevingen en decentrale communicatie. Door technische documentatie, praktijkvoorbeelden en bronnen over draadloze protocollen te analyseren, heb ik verschillende oplossingsrichtingen vergeleken. Daarbij heb ik onder andere gekeken naar factoren als energieverbruik, netwerktopologie en interoperabiliteit. Door deze informatie systematisch te structureren en kritisch te bevragen, ben ik tot een onderbouwd advies gekomen dat ook rekening houdt met privacyaspecten, onderhoud en schaalbaarheid. Dit vormt de basis voor het maken van bewuste ontwerpkeuzes in het vervolg van het project.

--

Beschrijving van de feedback die ik heb ontvangen op de portfolio-items.

--
