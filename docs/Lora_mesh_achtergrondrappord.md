# LoRa Mesh vs. LoRaWAN – Achtergrondrapport voor sensornetwerken in de buitenruimte

## 1. Inleiding

De ontwikkeling van Smart City-omgevingen leidt tot een toenemende behoefte aan gedistribueerde, energie-efficiënte netwerken voor het verzamelen van gegevens uit de fysieke leefomgeving. Of het nu gaat om het monitoren van bodemvocht in stedelijke plantsoenen, het detecteren van vulgraden in ondergrondse afvalcontainers, of het meten van fijnstof in drukke verkeersaders – in al deze toepassingen vormt draadloze connectiviteit een cruciale schakel (LoRa Alliance, z.d.; Semtech, z.d.). Sensoren moeten over grote afstanden en onder moeilijke omstandigheden kunnen communiceren. De gekozen netwerkarchitectuur bepaalt daarbij in hoge mate de haalbaarheid, betrouwbaarheid en levensduur van de oplossing.

Binnen deze context zijn Low Power Wide Area Networks (LPWAN) populair geworden. Ze bieden lage energiebehoefte, eenvoudige hardware en kostenefficiënte dekking. Van deze LPWAN-oplossingen is LoRa (Long Range) het meest gangbaar in Europa (Semtech, z.d.). LoRa vormt de fysieke laag die in diverse netwerktopologieën kan worden toegepast. In dit rapport staan we stil bij twee implementaties: het conventionele **LoRaWAN**, dat werkt via een stertopologie en netwerkservers, en het meer experimentele **LoRa Mesh**, dat peer-to-peer werkt zonder centrale infrastructuur.

Het doel van dit document is tweeledig: enerzijds biedt het een technische verdieping van beide technologieën; anderzijds koppelt het deze inzichten aan een concrete smart-city usecase – het meten van bodemvocht op locaties met wisselende bereikbaarheid. In dat kader wordt ook een proefopstelling met TTGO-devices besproken, om LoRa Mesh onder realistische omstandigheden te testen.

## 2. Wat is LoRa?

LoRa staat voor "Long Range" en verwijst naar een draadloze communicatietechnologie ontwikkeld door Cycleo (nu onderdeel van Semtech). De technologie is gebaseerd op **Chirp Spread Spectrum (CSS)**, een modulatietechniek waarbij het signaal over een breed frequentiespectrum wordt verspreid, wat resulteert in een hoge ruisbestendigheid (Semtech, z.d.). Dankzij deze aanpak kunnen LoRa-signalen worden ontvangen zelfs wanneer ze ver onder het ruisniveau liggen (tot -137 dBm), iets wat met conventionele FSK- of QAM-systemen onmogelijk is.

Een belangrijk voordeel van LoRa is het **energieverbruik**. In typische toepassingen (zoals een sensor die slechts enkele keren per dag data verstuurt) kan een node meerdere jaren functioneren op een enkele batterij. Hierdoor is LoRa bij uitstek geschikt voor toepassingen waarbij sensoren niet gemakkelijk bereikbaar zijn voor onderhoud of vervanging.

De fysieke laag van LoRa is gesloten en wordt via licentie verstrekt door Semtech, maar het protocol dat erboven ligt (LoRaWAN of alternatieven) is open en publiek gedefinieerd (LoRa Alliance, z.d.; Semtech, z.d.).

## 3. LoRaWAN – een gevestigde standaard

LoRaWAN (Long Range Wide Area Network) is het communicatielaagprotocol bovenop LoRa dat verantwoordelijk is voor het organiseren van de netwerkcommunicatie. Het bepaalt hoe sensoren zich aanmelden, berichten coderen, data routeren via gateways en communiceren met back-end servers. Het is een initiatief van de **LoRa Alliance**, waarin honderden bedrijven wereldwijd samenwerken om de standaard te beheren en verbeteren (LoRa Alliance, z.d.; The Things Network, z.d.).

LoRaWAN werkt via een **sterstructuur**. Sensoren (ook wel end-devices genoemd) zenden berichten uit die door één of meerdere gateways worden opgevangen. Deze gateways zijn ‘dom’ – ze doen enkel doorsturen – en verzenden de berichten via IP (Ethernet, 4G of glasvezel) naar een netwerkserver. De netwerkserver verwerkt duplicaten, regelt ADR (Adaptive Data Rate) en fungeert als controlelaag voor toegangsbeheer en applicatierouting.

Cloud-integratie is eenvoudig via platforms als The Things Stack, AWS IoT en Azure IoT Hub (The Things Network, z.d.).

## 4. LoRa Mesh – een gedecentraliseerd alternatief

LoRa Mesh is een alternatieve implementatie bovenop de LoRa fysieke laag, waarbij gebruik wordt gemaakt van **multi-hop communicatie** tussen nodes in plaats van directe communicatie met een centrale gateway. Het concept is eenvoudig: als sensor A geen rechtstreeks bereik heeft tot een gateway of centrale ontvanger, kan het bericht via sensor B (en eventueel C) alsnog het eindpunt bereiken. Elke sensor fungeert daarmee als mogelijke router voor andere berichten in het netwerk (Davidefa, 2020; Royyandzakiy, z.d.; Meshtastic, z.d.).

De meeste LoRa Mesh-oplossingen bouwen voort op bestaande bibliotheken zoals **RadioHead (RHMesh)** of het open-source project **Meshtastic**. Deze stacks voorzien in:

* Toewijzing van node-ID’s
* Detectie van buren via beacon-pakketten
* Dynamische opbouw van routingtabellen
* Retry-logica met buffers en timeouts
* Ondersteuning voor acknowledgements (ACK’s)

Net zoals bij traditionele meshnetwerken vereist dit dat nodes niet alleen zenden maar ook **luisteractief zijn**. Dit betekent dat ze gedurende langere tijd de radio actief moeten houden om pakketten van buren op te vangen – wat een aanzienlijke impact heeft op het energieverbruik (IEEE, 2020).

## 5. Praktijkvoorbeeld: Bodemvochtsensoren bij stadsbomen

In veel Nederlandse gemeenten is het beheer van jong groen en boomaanplant een terugkerend aandachtspunt binnen het fysieke domein. Nazorg bij nieuwe aanplant – met name tijdens de eerste drie jaar – is essentieel om uitval te beperken. Hierbij is inzicht in bodemvocht van groot belang. Traditioneel gebeurt monitoring visueel of handmatig met steekproeven. Door inzet van sensoren wordt het mogelijk om dit proces te automatiseren, optimaliseren en objectiveren (The Things Network, z.d.).

Een typische toepassing is het plaatsen van bodemvochtsensoren bij bomen in lanen, plantsoenen of parken. Deze sensoren sturen periodiek meetwaarden naar een centrale database. In situaties waar LoRaWAN niet voldoende dekking biedt, kan LoRa Mesh uitkomst bieden. Sensoren kunnen data via andere sensoren doorgeven (Davidefa, 2020; Royyandzakiy, z.d.).

## 6. Technische testopstelling: TTGO LoRa32 en RHMesh

Om het potentieel van LoRa Mesh te testen, werd een proefopstelling ontwikkeld met goedkope hardware: TTGO LoRa32-modules met ESP32 en SX1276-radiochip (Adafruit, z.d.; LilyGO, z.d.). De mesh-logica is gebaseerd op de RadioHead-bibliotheek (Royyandzakiy, z.d.).

De opstelling toonde robuuste mesh-routing tussen nodes in een stedelijk park. Wel blijkt dat LoRa Mesh energie-intensiever is dan LoRaWAN (IEEE, 2020).

## 7. Vergelijking: LoRaWAN versus LoRa Mesh

De belangrijkste verschillen tussen LoRaWAN en LoRa Mesh zijn topologie, energieverbruik, schaalbaarheid en afhankelijkheid van infrastructuur (LoRa Alliance, z.d.; Meshtastic, z.d.; IEEE, 2020).

## 8. Advies en overwegingen

De keuze tussen LoRaWAN en LoRa Mesh hangt af van context. Een hybride aanpak – LoRaWAN als backbone, LoRa Mesh voor dode zones – combineert robuustheid en efficiëntie (Davidefa, 2020; The Things Network, z.d.).

---

## 9. Bronnen en referenties (APA-stijl)

* Adafruit. (z.d.). *ESP32 LoRa board specifications*. [https://www.adafruit.com](https://www.adafruit.com)
* Davidefa. (2020). *ESP32 LoRa Mesh – The Basics*. Hackster.io. [https://www.hackster.io/davidefa/esp32-lora-mesh-1-the-basics-3a0920](https://www.hackster.io/davidefa/esp32-lora-mesh-1-the-basics-3a0920)
* IEEE. (2020). A performance evaluation of LoRa Mesh networking for Smart Cities. *2020 International Conference on Wireless and Mobile Computing, Networking and Communications (WiMOB)*. [https://doi.org/10.1109/WiMOB49888.2020.9253412](https://doi.org/10.1109/WiMOB49888.2020.9253412)
* LilyGO. (z.d.). *TTGO LoRa32 datasheets*. [https://github.com/Xinyuan-LilyGO/LilyGo-LoRa-Series](https://github.com/Xinyuan-LilyGO/LilyGo-LoRa-Series)
* LoRa Alliance. (z.d.). *LoRaWAN® specifications and documentation*. [https://lora-alliance.org](https://lora-alliance.org)
* Meshtastic. (z.d.). *Meshtastic: Off-grid mesh communication platform*. [https://meshtastic.org](https://meshtastic.org)
* Royyandzakiy. (z.d.). *LoRa RHMesh implementation*. GitHub. [https://github.com/royyandzakiy/LoRa-RHMesh](https://github.com/royyandzakiy/LoRa-RHMesh)
* Semtech. (z.d.). *What is LoRa®?* [https://www.semtech.com/lora/what-is-lora](https://www.semtech.com/lora/what-is-lora)
* The Things Network. (z.d.). *LoRaWAN documentation and use cases*. [https://www.thethingsnetwork.org/docs](https://www.thethingsnetwork.org/docs)

