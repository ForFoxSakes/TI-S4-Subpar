#  LoRa Mesh vs. LoRaWAN – Achtergrondrapport voor sensornetwerken in de buitenruimte

## 1. Inleiding
De ontwikkeling van Smart City-omgevingen leidt tot een toenemende behoefte aan gedistribueerde, energie-efficiënte netwerken voor het verzamelen van gegevens uit de fysieke leefomgeving. Of het nu gaat om het monitoren van bodemvocht in stedelijke plantsoenen, het detecteren van vulgraden in ondergrondse afvalcontainers, of het meten van fijnstof in drukke verkeersaders – in al deze toepassingen vormt draadloze connectiviteit een cruciale schakel. Sensoren moeten over grote afstanden en onder moeilijke omstandigheden kunnen communiceren. De gekozen netwerkarchitectuur bepaalt daarbij in hoge mate de haalbaarheid, betrouwbaarheid en levensduur van de oplossing.

Binnen deze context zijn Low Power Wide Area Networks (LPWAN) populair geworden. Ze bieden lage energiebehoefte, eenvoudige hardware en kostenefficiënte dekking. Van deze LPWAN-oplossingen is LoRa (Long Range) het meest gangbaar in Europa. LoRa vormt de fysieke laag die in diverse netwerktopologieën kan worden toegepast. In dit rapport staan we stil bij twee implementaties: het conventionele **LoRaWAN**, dat werkt via een stertopologie en netwerkservers, en het meer experimentele **LoRa Mesh**, dat peer-to-peer werkt zonder centrale infrastructuur.

Het doel van dit document is tweeledig: enerzijds biedt het een technische verdieping van beide technologieën; anderzijds koppelt het deze inzichten aan een concrete smart-city usecase – het meten van bodemvocht op locaties met wisselende bereikbaarheid. In dat kader wordt ook een proefopstelling met TTGO-devices besproken, om LoRa Mesh onder realistische omstandigheden te testen.

## 2. Wat is LoRa?
LoRa staat voor "Long Range" en verwijst naar een draadloze communicatietechnologie ontwikkeld door Cycleo (nu onderdeel van Semtech). De technologie is gebaseerd op **Chirp Spread Spectrum (CSS)**, een modulatietechniek waarbij het signaal over een breed frequentiespectrum wordt verspreid, wat resulteert in een hoge ruisbestendigheid. Dankzij deze aanpak kunnen LoRa-signalen worden ontvangen zelfs wanneer ze ver onder het ruisniveau liggen (tot -137 dBm), iets wat met conventionele FSK- of QAM-systemen onmogelijk is.

Een belangrijk voordeel van LoRa is het **energieverbruik**. In typische toepassingen (zoals een sensor die slechts enkele keren per dag data verstuurt) kan een node meerdere jaren functioneren op een enkele batterij. Hierdoor is LoRa bij uitstek geschikt voor toepassingen waarbij sensoren niet gemakkelijk bereikbaar zijn voor onderhoud of vervanging.

### Technische kenmerken van LoRa:
- **Frequentieband**: 868 MHz (EU), 915 MHz (VS) – alle ISM (Industrial, Scientific and Medical) en licentievrij
- **Modulatietechniek**: Chirp Spread Spectrum (CSS)
- **Bitrates**: van 0.3 kbps tot maximaal 50 kbps
- **Spreading Factor (SF)**: bepaalt transmissietijd en bereik (SF7–SF12)
- **Bandbreedtes**: meestal 125 kHz, soms 250 kHz of 500 kHz
- **Maximaal zendvermogen**: +14 dBm in EU (afhankelijk van duty cycle)

De fysieke laag van LoRa is gesloten en wordt via licentie verstrekt door Semtech, maar het protocol dat erboven ligt (LoRaWAN of alternatieven) is open en publiek gedefinieerd.

## 3. LoRaWAN – een gevestigde standaard
LoRaWAN (Long Range Wide Area Network) is het communicatielaagprotocol bovenop LoRa dat verantwoordelijk is voor het organiseren van de netwerkcommunicatie. Het bepaalt hoe sensoren zich aanmelden, berichten coderen, data routeren via gateways en communiceren met back-end servers. Het is een initiatief van de **LoRa Alliance**, waarin honderden bedrijven wereldwijd samenwerken om de standaard te beheren en verbeteren.

LoRaWAN werkt via een **sterstructuur**. Sensoren (ook wel end-devices genoemd) zenden berichten uit die door één of meerdere gateways worden opgevangen. Deze gateways zijn ‘dom’ – ze doen enkel doorsturen – en verzenden de berichten via IP (Ethernet, 4G of glasvezel) naar een netwerkserver. De netwerkserver verwerkt duplicaten, regelt ADR (Adaptive Data Rate) en fungeert als controlelaag voor toegangsbeheer en applicatierouting.

### Sterke punten van LoRaWAN:
- **Gestandaardiseerd en ondersteund** door leveranciers wereldwijd
- **Beveiliging op twee niveaus**: netwerk- en applicatiesleutels (AES-128)
- **Cloud-integratie**: eenvoudig te koppelen aan platforms zoals The Things Stack, AWS IoT, Azure IoT Hub
- **ADR**: optimaliseert energieverbruik en airtime op basis van ontvangstkwaliteit
- **Schaalbaar**: duizenden sensoren kunnen één gateway bedienen bij lage datafrequentie

### Beperkingen:
- Afhankelijk van zichtlijn naar gateway
- Gevoelig voor obstructies (bomen, muren)
- Max. zendcapaciteit beperkt door duty cycle (1% in EU)
- Vereist infrastructuur: gateways met stroom en backhaul

LoRaWAN is geschikt voor duurzame, grootschalige netwerken in stedelijke en landelijke gebieden met geplande infrastructuur. In situaties waar plaatsing van gateways niet mogelijk is, of het signaal ernstig wordt gehinderd, biedt LoRaWAN echter onvoldoende dekking.

## 4. LoRa Mesh – een gedecentraliseerd alternatief
LoRa Mesh is een alternatieve implementatie bovenop de LoRa fysieke laag, waarbij gebruik wordt gemaakt van **multi-hop communicatie** tussen nodes in plaats van directe communicatie met een centrale gateway. Het concept is eenvoudig: als sensor A geen rechtstreeks bereik heeft tot een gateway of centrale ontvanger, kan het bericht via sensor B (en eventueel C) alsnog het eindpunt bereiken. Elke sensor fungeert daarmee als mogelijke router voor andere berichten in het netwerk.

In tegenstelling tot LoRaWAN, waar alle communicatie plaatsvindt via een gateway-infrastructuur, opereert een LoRa Mesh-netwerk op basis van lokale beslissingen en routeonderhandeling. Dit maakt de technologie interessant in omgevingen waar infrastructuur ontbreekt, zoals bossen, landbouwgebieden of tijdelijke opstellingen in de openbare ruimte.

### Technische architectuur:
De meeste LoRa Mesh-oplossingen bouwen voort op bestaande bibliotheken zoals **RadioHead (RHMesh)** of het open-source project **Meshtastic**. Deze stacks voorzien in:
- Toewijzing van node-ID’s
- Detectie van buren via beacon-pakketten
- Dynamische opbouw van routingtabellen
- Retry-logica met buffers en timeouts
- Ondersteuning voor acknowledgements (ACK’s)

Net zoals bij traditionele meshnetwerken (zoals bij Zigbee), vereist dit dat nodes niet alleen zenden maar ook **luisteractief zijn**. Dit betekent dat ze gedurende langere tijd de radio actief moeten houden om pakketten van buren op te vangen – wat een aanzienlijke impact heeft op het energieverbruik.

### Voor- en nadelen:
**Voordelen:**
- Overbrugt gaten in LoRaWAN-dekking zonder extra gateways
- Geen afhankelijkheid van infrastructuur (cloud, internet, backhaul)
- Robuust tegen lokale uitval – het netwerk past zichzelf aan

**Nadelen:**
- Hoger energieverbruik door actief luisteren en retransmissie
- Minder gestandaardiseerd; afhankelijk van specifieke implementaties
- Moeilijker te debuggen en beheren zonder centrale controlelaag
- Beperkte schaalbaarheid bij grote aantallen nodes (>50)

### Gebruik in Smart City-context:
LoRa Mesh is op dit moment nog **nauwelijks grootschalig toegepast** in operationele smart-city-infrastructuur. De technologie is vooral in opkomst bij makersgemeenschappen, onderzoeksprojecten en pilotimplementaties. Dat komt deels door het gebrek aan standaardisatie en tooling voor grootschalig beheer. Toch biedt het in bepaalde niches – zoals tijdelijke installaties of bereikloze zones – interessante perspectieven.

## 5. Praktijkvoorbeeld: Bodemvochtsensoren bij stadsbomen

In veel Nederlandse gemeenten is het beheer van jong groen en boomaanplant een terugkerend aandachtspunt binnen het fysieke domein. Nazorg bij nieuwe aanplant – met name tijdens de eerste drie jaar – is essentieel om uitval te beperken. Hierbij is inzicht in bodemvocht van groot belang: te droog betekent groeistagnatie of sterfte, te nat leidt tot wortelrot of schimmelvorming. Traditioneel gebeurt monitoring visueel of handmatig met steekproeven. Door inzet van sensoren wordt het mogelijk om dit proces te automatiseren, optimaliseren en objectiveren.

Een typische toepassing is het plaatsen van bodemvochtsensoren bij bomen in lanen, plantsoenen of parken. Deze sensoren sturen periodiek (bijv. 4–6 keer per dag) meetwaarden naar een centrale database. De gegevens worden vervolgens gevisualiseerd op kaarten of dashboards en vormen de input voor watergeefbeslissingen. 

### Technische vereisten en uitdagingen:
- **Lage datavolumes**: een enkele meting omvat meestal 10–20 bytes aan ruwe data (vochtpercentage, temperatuur, timestamp)
- **Meetfrequentie**: typisch tussen de 2 en 6 metingen per dag
- **Zeer laag stroomverbruik vereist**: sensoren moeten 2–5 jaar functioneren op een batterij van 2400 mAh (bijv. AA lithium)
- **Verspreide plaatsing**: bomen kunnen tientallen tot honderden meters uit elkaar staan
- **Geen stroom of netwerk aanwezig**: plaatsing van gateways vereist vaak netvoeding, wat in de openbare ruimte niet vanzelfsprekend is
- **Obstructies**: bomen, gebouwen of reliëf kunnen het LoRaWAN-signaal dempen of blokkeren

### Waarom is dit relevant voor LoRa Mesh?
In situaties waar LoRaWAN niet voldoende dekking biedt – bijvoorbeeld omdat bomen aan de 'achterzijde' van een park of in een schaduwzone staan – is mesh-routing een manier om toch connectiviteit te realiseren. In plaats van een gateway dichterbij te plaatsen, kunnen de sensoren zelf berichten via elkaar doorgeven totdat er een route naar een bereikbare uplink ontstaat.

Bijvoorbeeld: Sensor A staat aan de rand van een vijver in een park en heeft geen directe lijn naar een gateway. Sensor B staat iets verderop en ontvangt wel een LoRaWAN-signaal. Door toepassing van LoRa Mesh kan Sensor A zijn bericht via Sensor B (of zelfs via een tussenliggende node C) doorsturen. Hierdoor is slechts op enkele strategische punten een gateway nodig, en kunnen de andere sensoren als "relay" functioneren.

## 6. Technische testopstelling: TTGO LoRa32 en RHMesh

Om het potentieel van LoRa Mesh in een stedelijke sensortoepassing te evalueren, werd een proefopstelling ontwikkeld met behulp van goedkope, toegankelijke hardware: de TTGO LoRa32-modules met ingebouwde ESP32-microcontroller en SX1276 LoRa-radiochip. Deze boards zijn ideaal vanwege hun ingebouwde scherm, lage prijs, compatibiliteit met de Arduino IDE en volledige toegang tot GPIO-pinnen.

De gebruikte mesh-logica is gebaseerd op de open-source implementatie **RHMesh** uit de RadioHead-bibliotheek. Deze biedt een simpele, maar functionele peer-to-peer meshlaag waarbij nodes berichten kunnen routeren voor elkaar.

### Opstelling:
- **Hardware**: 4 TTGO LoRa32 boards (V1.0)
- **LoRa parameters**:
  - SF: 7 (lage latency)
  - BW: 125 kHz
  - Frequentie: 868 MHz
  - Vermogen: +13 dBm
- **Firmware**: aangepaste versie van RHMesh, met logging van hops, latency en retries
- **Opstelling**:
  - Node 1: verzender (simulateert sensor onder een boom)
  - Node 2 & 3: tussenliggende routers
  - Node 4: ontvanger/uplink

### Observaties:
- **Hopafstand**: gemiddeld betrouwbaar bereik per hop was 50–80 meter in stedelijk parklandschap met lichte bebouwing
- **Latency**: ~200–300 ms bij 2 hops
- **Retry-gedrag**: indien node 2 uitviel, werd binnen ~10 s een route via node 3 opnieuw opgebouwd
- **Stroomverbruik**: in actieve routingmodus tot 30 mA gemiddeld (versus 8–10 mA in LoRaWAN-slaapmodus)

De opstelling toonde aan dat eenvoudige mesh-routing tussen nodes succesvol mogelijk is, mits er voldoende dekking tussen nodes is. Wel werd duidelijk dat LoRa Mesh geen vervanger is voor een LoRaWAN-netwerk – het vult eerder de gaten die LoRaWAN niet bereikt. In de praktijk betekent dit dat een handvol mesh-nodes strategisch kan worden ingezet om "dode zones" of moeilijk bereikbare sensoren toch online te brengen.

## 7. Vergelijking: LoRaWAN versus LoRa Mesh

Om een geïnformeerde keuze te kunnen maken tussen LoRaWAN en LoRa Mesh, is het van belang hun technische eigenschappen, vereisten en prestaties naast elkaar te leggen. De tabel hieronder vat de belangrijkste verschillen samen:

| Kenmerk                  | LoRaWAN                                               | LoRa Mesh                                                   |
|--------------------------|--------------------------------------------------------|--------------------------------------------------------------|
| **Topologie**            | Sterstructuur: sensor → gateway                        | Meshstructuur: sensor → sensor → gateway                   |
| **Routing**              | Via netwerkserver en centrale uplink                  | Dynamisch, lokaal bepaald via routingtabellen               |
| **Energieverbruik**      | Zeer laag (slaap tussen uitzendingen)                 | Hoger (luisteractief en retransmissies)                     |
| **Schaalbaarheid**       | Goed schaalbaar mits voldoende gateways               | Beperkt door latency en energie bij veel hops               |
| **Standaardisatie**      | Ja, via LoRa Alliance (open specificaties)            | Nee, afhankelijk van firmware (bv. RHMesh, Meshtastic)      |
| **Infrastructuur nodig** | Ja: gateways met backhaul en stroomvoorziening        | Nee: nodes routeren zelf, geen centrale infrastructuur       |
| **Beheerbaarheid**       | Centrale logging en monitoring mogelijk               | Moeilijker beheer, vereist lokale debug of custom tools     |
| **Betrouwbaarheid**      | Hoog bij zichtlijn, maar kwetsbaar voor schaduwzones  | Veerkrachtig bij uitval of obstakels, adaptief              |
| **Kosten**               | Investering in gateways vereist                       | Meer nodes nodig, maar lagere infra-eisen                   |

Samengevat: LoRaWAN is de aangewezen keuze voor grootschalige, beheersbare netwerken met vaste infrastructuur en stabiele dekking. LoRa Mesh komt in beeld bij specifieke knelpunten, zoals sensoren die structureel geen verbinding krijgen met een gateway, tijdelijke installaties, of pilots zonder stroomvoorziening.

## 8. Advies en overwegingen

Op basis van de technische analyse en praktijkervaringen uit dit rapport is het belangrijk om de keuze tussen LoRaWAN en LoRa Mesh niet als een zwart-witbeslissing te benaderen, maar als een kwestie van afstemming op **context en randvoorwaarden**. Beide technologieën hebben hun sterktes, maar passen bij verschillende typen uitdagingen.

### LoRaWAN – aanbevolen wanneer:
- Er reeds infrastructuur aanwezig is (gateways met backhaul)
- Sensorlocaties zich binnen zichtlijn of bekende LoRa-dekking bevinden
- Onderhoudsarme en schaalbare oplossingen gewenst zijn
- Er behoefte is aan gestandaardiseerde integratie met cloud/backend systemen

LoRaWAN is bewezen technologie. Het is stabiel, energiezuinig, goed ondersteund, en schaalbaar voor grote aantallen devices. In 90% van de reguliere toepassingen is het daarom het beste vertrekpunt.

### LoRa Mesh – aanbevolen wanneer:
- Sensoren zich bevinden op plekken zonder LoRaWAN-bereik
- De installatie tijdelijk of mobiel is (bijv. pilots, natuurgebieden)
- Plaatsing van gateways om technische of financiële redenen onmogelijk is
- Er sprake is van gedecentraliseerde of ad-hoc netwerken

LoRa Mesh is met name relevant als ‘fallbackoptie’ voor situaties waar infrastructuur ontbreekt. Het biedt veerkracht en flexibiliteit, maar vergt wel meer energie, debugging en kennis van firmware.

### Aanbevolen aanpak:
Voor stedelijke toepassingen zoals bodemvochtsensoren in lanen of parken luidt het advies:
- **Gebruik LoRaWAN** als primaire backbone met strategisch geplaatste gateways
- **Identificeer gaten in dekking** op basis van veldmetingen (TTGO)
- **Vul deze gaten op met mesh-nodes** die via RHMesh of Meshtastic data kunnen doorsturen
- **Gebruik hybride softwarearchitectuur** waarbij mesh-nodes periodiek gegevens bufferen en via de eerstvolgende uplink-node afleveren

Zo ontstaat een robuust en uitbreidbaar netwerk waarin LoRaWAN efficiënt wordt benut en LoRa Mesh als vangnet functioneert. Deze aanpak combineert het beste van twee werelden.

## 9. Bronnen en referenties

Onderstaand overzicht bevat de belangrijkste geraadpleegde technische bronnen, whitepapers en projecten die als basis hebben gediend voor dit achtergrondrapport:

- **LoRa Alliance** – officiële documentatie en technische specificaties voor LoRa en LoRaWAN  
  https://lora-alliance.org
- **Semtech** – whitepapers over LoRa Physical Layer en CSS-modulatie  
  https://www.semtech.com/lora/what-is-lora
- **Meshtastic Project** – open-source firmware voor ESP32/LoRa mesh-netwerken  
  https://meshtastic.org/
- **RHMesh op GitHub (Royyandzakiy)** – Arduino-implementatie van RadioHead Mesh protocol  
  https://github.com/royyandzakiy/LoRa-RHMesh
- **Hackster.io project: ESP32 LoRa Mesh – The Basics**  
  https://www.hackster.io/davidefa/esp32-lora-mesh-1-the-basics-3a0920
- **IEEE Conference Paper** – "A Performance Evaluation of LoRa Mesh Networking for Smart Cities", IEEE 2020  
  DOI: 10.1109/WiMOB49888.2020.9253412
- **The Things Network Documentation** – LoRaWAN infrastructuur en usecases  
  https://www.thethingsnetwork.org/docs/
- **Adafruit en TTGO datasheets** – hardware-specificaties van ESP32 LoRa boards

Voor meetproeven en veldtesten werd gebruikgemaakt van TTGO LoRa32 boards in combinatie met aangepaste Arduino-firmware gebaseerd op de RHMesh-bibliotheek. De opgehaalde kennis is mede geïnformeerd door veldexperimenten in stadsparken en testopstellingen in stedelijk gebied.

---



