## Empiiriset kokeet

### Ohjelmat

Kirjoitin kanditutkielmaa varten C++ -ohjelmia, joilla eri algoritmien tehokkuutta voidaan mitata empiirisesti. Ohjelmilla voidaan vertailla yhden, kahden ja kolmen jakoalkion algoritmeja toisiinsa.
Ohjelmat löytyvät kansiosta src. Ohjelmat perustuvat pääosin julkaistuihin pseudokoodeihin (Wild ja Aumüller ja Dietzfelbinger)

Käytetyt algoritmit ovat ns. perusversioita. Jakoalkioiden valintaa ei ole optimoitu, ne valitaan aina samalla tavalla vakiopaikoista. Ainoastaan lisäysjärjestäminen otetaan käyttöön, kun osataulukon koko pienenee tietyn rajan alle.
Algoritmien optimoinnilla voitaisiin käsittääkseni saada vielä usean kymmenen prosentin arannus tehokkuuteen

### Ajoaikakokeet

Testikoneena käytettiin Macbook Pro tietokonetta, jossa on 2.5GHz Intel Core I7 -prosessori ja 16GB keskusmuistia. Mittauksissa järjestettiin eri kokoisia satunnaiskokonaislukutaulukoita. Taulukoiden koko vaihteli välillä 210 − 230 (1 024 − 1 073 741 824).
Aikavaativuusvertailujen tulokset ovat varsin hyvin yhtäpitävät aikaisemmin julkaistujen tulosten kanssa (kuva 6.1). Tehokkuus riippuu toki paljon vertailuissa käytetyn tietokoneen arkkitehtuurista, joten suora vertailu toisiin tutkimuksiin on vaikeaa.
Kahden jakoalkion algoritmi on testien mukaan noin 10% klassista pikajärjestämistä nopeampi. Kolmen jakoalkion algoritmi on puolestaan noin 6–7% parempi kuin kahden jakoalkion menetelmä.

<img src="dokumentaatio/png/runrime_own.png" width="750">

### Suorituskyvyn testaus

Suorituskykyä on vertailu eri kokoisilla random-kartoilla.  Paras reitti on haettu samalla kartalla eri menetelmillä.  Suorituskykyvertailun lisäksi on tarkastettu, että menetelmät antavat yhtäpitävät tulokset (polut voivat joskus olla hieman eroavat jos löytyy useampi yhtä hyvä reitti).  Suorituskykytestin tulokset löytyvät toteutusdokumentista.
