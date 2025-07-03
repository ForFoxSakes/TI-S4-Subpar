# LoRa Mesh vs. LoRaWAN – Achtergrondrapport voor sensornetwerken in de buitenruimte

## 1. Inleiding  
[...] Of het nu gaat om het monitoren van bodemvocht in stedelijke plantsoenen, het detecteren van vulgraden in ondergrondse afvalcontainers, of het meten van fijnstof in drukke verkeersaders – in al deze toepassingen vormt draadloze connectiviteit een cruciale schakel (LoRa Alliance, z.d.; Semtech, z.d.).

Binnen deze context zijn Low Power Wide Area Networks (LPWAN) populair geworden. Van deze LPWAN-oplossingen is LoRa (Long Range) het meest gangbaar in Europa (Semtech, z.d.).

## 2. Wat is LoRa?  
LoRa staat voor "Long Range" en is gebaseerd op **Chirp Spread Spectrum (CSS)**, een modulatietechniek met hoge ruisbestendigheid (Semtech, z.d.). [...] Hierdoor is LoRa bij uitstek geschikt voor toepassingen waarbij sensoren niet gemakkelijk bereikbaar zijn voor onderhoud of vervanging.

De fysieke laag van LoRa is gesloten en wordt via licentie verstrekt door Semtech, maar het protocol erboven (zoals LoRaWAN of Mesh) is vaak open source (Semtech, z.d.; LoRa Alliance, z.d.).

## 3. LoRaWAN – een gevestigde standaard  
LoRaWAN is een communicatiestandaard ontwikkeld door de **LoRa Alliance**, en is wereldwijd breed toegepast (LoRa Alliance, z.d.; The Things Network, z.d.).

LoRaWAN werkt via een sterstructuur waarbij gateways data doorsturen naar een netwerkserver (LoRa Alliance, z.d.). [...] Cloud-integratie is eenvoudig via platforms als The Things Stack, AWS IoT en Azure IoT Hub (The Things Network, z.d.).

## 4. LoRa Mesh – een gedecentraliseerd alternatief  
LoRa Mesh gebruikt multi-hop communicatie waarbij nodes berichten via elkaar doorgeven, zonder centrale infrastructuur (Davidefa, 2020; Royyandzakiy, z.d.; Meshtastic, z.d.).

De meeste implementaties zijn gebaseerd op **RadioHead RHMesh** of het **Meshtastic-project**, beide open source (Royyandzakiy, z.d.; Meshtastic, z.d.).

Doordat nodes permanent luisteractief zijn, vergt dit meer energie dan LoRaWAN (IEEE, 2020).

## 5. Praktijkvoorbeeld: Bodemvochtsensoren bij stadsbomen  
Nazorg bij jonge aanplant vereist goede vochtmonitoring. Sensoren sturen meerdere keren per dag meetdata (zoals vochtpercentage en temperatuur) door (The Things Network, z.d.).

LoRa Mesh komt in beeld waar LoRaWAN-bereik ontbreekt. Sensoren kunnen data via andere sensoren doorgeven (Davidefa, 2020; Royyandzakiy, z.d.).

## 6. Technische testopstelling: TTGO LoRa32 en RHMesh  
Voor de testopstelling is gebruikgemaakt van TTGO LoRa32-boards, gebaseerd op de SX1276-chip en ESP32 (Adafruit, z.d.; LilyGO, z.d.). De meshlogica is afgeleid van de RadioHead-bibliotheek (Royyandzakiy, z.d.).

De opstelling toonde robuuste mesh-routing tussen nodes in een stedelijk park. Wel blijkt dat LoRa Mesh energie-intensiever is dan LoRaWAN (IEEE, 2020).

## 7. Vergelijking: LoRaWAN versus LoRa Mesh  
De belangrijkste verschillen tussen LoRaWAN en LoRa Mesh zijn topologie, energieverbruik, schaalbaarheid en afhankelijkheid van infrastructuur (LoRa Alliance, z.d.; Meshtastic, z.d.; IEEE, 2020).

## 8. Advies en overwegingen  
De keuze tussen LoRaWAN en LoRa Mesh hangt af van context. Een hybride aanpak – LoRaWAN als backbone, LoRa Mesh voor dode zones – combineert robuustheid en efficiëntie (Davidefa, 2020; The Things Network, z.d.).

## 9. Bronnen en referenties (APA-stijl)

- Adafruit. (z.d.). *ESP32 LoRa board specifications*. https://www.adafruit.com  
- Davidefa. (2020). *ESP32 LoRa Mesh – The Basics*. Hackster.io. https://www.hackster.io/davidefa/esp32-lora-mesh-1-the-basics-3a0920  
- IEEE. (2020). A performance evaluation of LoRa Mesh networking for Smart Cities. *2020 International Conference on Wireless and Mobile Computing, Networking and Communications (WiMOB)*. https://doi.org/10.1109/WiMOB49888.2020.9253412  
- LilyGO. (z.d.). *TTGO LoRa32 datasheets*. https://github.com/Xinyuan-LilyGO/LilyGo-LoRa-Series  
- LoRa Alliance. (z.d.). *LoRaWAN® specifications and documentation*. https://lora-alliance.org  
- Meshtastic. (z.d.). *Meshtastic: Off-grid mesh communication platform*. https://meshtastic.org  
- Royyandzakiy. (z.d.). *LoRa RHMesh implementation*. GitHub. https://github.com/royyandzakiy/LoRa-RHMesh  
- Semtech. (z.d.). *What is LoRa®?* https://www.semtech.com/lora/what-is-lora  
- The Things Network. (z.d.). *LoRaWAN documentation and use cases*. https://www.thethingsnetwork.org/docs  
