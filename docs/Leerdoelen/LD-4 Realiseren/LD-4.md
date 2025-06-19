### Leeruitkomst 4 Realiseren

Student realiseert vanuit het ontwerp een 'Digital Twin' van een bestaand embedded systeem, inclusief grafische representatie. Hierbij wordt gewerkt volgens een voorgeschreven methode waarin testen centraal staat, ten behoeve van het uitvoeren van tests op verschillende ontwikkelniveaus. Testresultaten, omstandigheden en afhankelijkheden worden helder gedocumenteerd, omwille van het reproduceren van de testresultaten. 

Indicatoren:
- Broncode simulatie
- Projectcode
- Vision opdrachten
- Algoritmiek opdrachten
- C++ STL opdrachten
- C++<->Python opdrachten
- Creational/Structural design pattern opdrachten
---

**Leeruitkomst 4 Projectopdrachten:**


| Portfolio-item     | Beschrijving                                           | Bewijslast               |
|--------------------|--------------------------------------------------------|--------------------------|
| `Projectcode` | `Alle code met betrekking tot het project` | [link](https://github.com/ForFoxSakes/TI-S4-Subpar/tree/main/subpar/simulator) |
| `Vision opdrachten` | `Opdrachten Vision van College Computer Vision I (Basis beeldverwerking)` | [link](https://github.com/ForFoxSakes/TI-S4-opdrachten/tree/main/Vision) |
| `Standardlibrary C++` | `Opdrachten van STD C++` | [link ](https://github.com/ForFoxSakes/TI-S4-opdrachten/tree/main/CPP) |
| `C++ STL Opdrachten` | `Opdrachten van het College Labmda's ` | [link](https://github.com/ForFoxSakes/TI-S4-opdrachten/tree/main/Vision) |
| `ALDS` | `Opgaven ALDS` | [link](https://github.com/ForFoxSakes/TI-S4-opdrachten/tree/main/ALDS) |
| `Gazebo Opdrachten` | `Opdrachten met betrikking tot maken van een Gazebo model en viewer` | [link](https://github.com/ForFoxSakes/TI-S4-DEBUG/tree/main/src) |
| ` Ontwikkelomgeving ` | `(Devcontainer met Docker en debugger)` | [link](https://github.com/ForFoxSakes/TI-S4-opdrachten/blob/main/.devcontainer/devcontainer.json) |


Onderbouwing hoe deze portfolio-items hebben bijgedragen aan het aantonen van deze leeruitkomst.

### Vision opdrachten
Voor de vision-opgaven heb ik gewerkt aan beeldherkenning met behulp van een neuraal netwerk. Ik heb verschillende modellen ontworpen, getest en vergeleken op nauwkeurigheid. Daarbij heb ik testresultaten vastgelegd en gezorgd dat de omstandigheden reproduceerbaar zijn, zoals gebruikte datasets, trainingsinstellingen en validatiemethoden. Door telkens kleine aanpassingen te testen, kreeg ik inzicht in wat werkt en waarom.

Bij het verder werken aan de vision-opgaven heb ik meer gelet op overfitting, trainingstijd en visuele output. Ik heb meerdere versies van het netwerk vergeleken, met aangepaste lagen of filters, en gekeken wat het effect was op de resultaten. Die uitkomsten heb ik vergeleken in grafieken en meetwaarden, zodat de testresultaten goed te volgen zijn en makkelijk opnieuw getest kunnen worden.

### ALDS
Voor ALDS heb ik gewerkt aan algoritmes en datastructuren en onderzocht hoe ze zich gedragen bij verschillende invoer. Ik heb keuzes gemaakt op basis van prestaties en geheugenverbruik, en testgevallen opgesteld om dat te onderbouwen. De uitkomsten van die tests heb ik vastgelegd, zodat duidelijk is wat de invloed was van bijvoorbeeld datastructuur of sorteermethode.

### Ontwikkelomgeving (Devcontainer met Docker en debugger)
Ik heb een ontwikkelomgeving opgezet in Visual Studio Code met behulp van een devcontainer. Daarbij heb ik Docker gebruikt om de juiste omgeving te configureren, en een C++ debugger toegevoegd om mijn code goed te kunnen testen. Ik heb vastgelegd welke instellingen ik heb gebruikt, hoe ik de omgeving werkend heb gekregen en hoe ik tests uitvoer. Zo kan ik mijn werkwijze makkelijk opnieuw toepassen of delen met anderen.


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
\~Nick

---

